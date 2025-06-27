// Protótipo da função que exibe um número em um display específico
void mostrarNumero(int num, bool noDisplay1, bool ponto = false);

// Pinos dos segmentos do display (a até g)
const int segmentos[] = {2, 3, 4, 5, 6, 7, 8};
const int pinDP = 13;  // Pino do ponto decimal

// Pinos dos displays controlados por transistores PNP (ânodo comum)
const int digito1 = 10;
const int digito2 = 11;

// Mapeamento dos números para displays de 7 segmentos ânodo comum
const byte numeros[10] = {
  B11000000, B11111001, B10100100, B10110000, B10011001,
  B10010010, B10000010, B11111000, B10000000, B10010000
};

// Sensor ultrassônico HC-SR04
const int TRIG = 9;
const int ECHO = 12;

// Zonas de referência para medir velocidade
const int REF1 = 60; // Primeira zona (cm)
const int REF2 = 30; // Segunda zona (cm)
const int TOL = 5;   // Tolerância de leitura (± cm)

// Variáveis de controle de estado
bool iniciou = false, medido = false, exibindoVelocidade = false;
unsigned long t0 = 0, t1 = 0;   // Tempo de detecção nas zonas
float d1 = 0, d2 = 0;           // Distâncias detectadas
float velocidade = 0.0;         // Velocidade calculada (m/s)

// Controle da multiplexação dos displays
unsigned long lastDisplaySwitch = 0;
const unsigned int displayInterval = 5; // Tempo entre trocas dos displays
bool display1Ativo = true;

// Tempo de exibição da velocidade nos displays
unsigned long tempoInicioExibicao = 0;
const unsigned long tempoExibicao = 3000; // Tempo (ms)

void setup() {
  // Inicializa os pinos dos segmentos e displays
  for (int i = 0; i < 7; i++) pinMode(segmentos[i], OUTPUT);
  pinMode(pinDP, OUTPUT);
  pinMode(digito1, OUTPUT);
  pinMode(digito2, OUTPUT);

  // Configura o sensor ultrassônico
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  // Desliga tudo inicialmente
  digitalWrite(digito1, HIGH); // PNP desligado
  digitalWrite(digito2, HIGH);
  digitalWrite(pinDP, HIGH);

  // Inicia o monitor serial
  Serial.begin(9600);
}

void loop() {
  unsigned long now = millis();

  // Exibição da velocidade no display
  if (exibindoVelocidade) {
    if (now - tempoInicioExibicao < tempoExibicao) {
      if (now - lastDisplaySwitch >= displayInterval) {
        lastDisplaySwitch = now;
        exibirVelocidadeMultiplexada(velocidade, display1Ativo);
        display1Ativo = !display1Ativo;
      }
    } else {
      apagarDisplays();
      exibindoVelocidade = false;
      resetar();
    }
    return;
  }

  // Mede a distância em tempo real com alta frequência
  float dist = medirDistancia();

  // Exibe no serial
  Serial.print("Distância atual: ");
  Serial.print(dist);
  Serial.println(" cm");

  if (dist == 0 || dist > 300) {
    resetar();
    return;
  }

  // Captura a primeira zona
  if (!iniciou && dentroDaZona(dist, REF1)) {
    d1 = dist;
    t0 = micros(); // Usa micros() para maior precisão
    iniciou = true;
    medido = false;

    Serial.print("Captura 1: ");
    Serial.print(d1);
    Serial.print(" cm em ");
    Serial.print(t0);
    Serial.println(" µs");
  }

  // Captura a segunda zona
  if (iniciou && !medido && dentroDaZona(dist, REF2)) {
    d2 = dist;
    t1 = micros();

    medido = true;

    Serial.print("Captura 2: ");
    Serial.print(d2);
    Serial.print(" cm em ");
    Serial.print(t1);
    Serial.println(" µs");

    // Calcula velocidade
    float deltaT = t1 - t0;
    float dt = deltaT / 1e6;           // Tempo em segundos
    float dx = abs(d1 - d2) / 100.0;   // Espaço em metros
    velocidade = dx / dt;

    Serial.print("Velocidade: ");
    Serial.print(velocidade, 2);
    Serial.println(" m/s");

    exibindoVelocidade = true;
    tempoInicioExibicao = millis();
  }
}

// Função para medir a distância com o HC-SR04
float medirDistancia() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long dur = pulseIn(ECHO, HIGH, 30000); // Timeout de 30ms
  if (dur == 0) return 0;

  return dur * 0.0343 / 2; // Conversão para cm
}

// Verifica se a distância está dentro da zona de referência
bool dentroDaZona(float d, int ref) {
  return (d >= ref - TOL && d <= ref + TOL);
}

// Exibe a velocidade nos dois displays com ponto decimal
void exibirVelocidadeMultiplexada(float v, bool noDisplay1) {
  int n1, n2;
  bool ponto1 = false;

  if (v < 10.0) {
    int val = int(v * 10 + 0.5); // Transforma em dois dígitos
    n1 = val / 10;
    n2 = val % 10;
    ponto1 = true;
  } else {
    int val = int(v + 0.5); // Arredonda para inteiro
    n1 = val / 10;
    n2 = val % 10;
    ponto1 = false;
  }

  if (noDisplay1)
    mostrarNumero(n1, true, ponto1);
  else
    mostrarNumero(n2, false, false);
}

// Mostra um número em um dos displays
void mostrarNumero(int num, bool noDisplay1, bool ponto) {
  digitalWrite(digito1, HIGH);
  digitalWrite(digito2, HIGH);

  byte bits = numeros[num];
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentos[i], bitRead(bits, i) ? HIGH : LOW);
  }

  digitalWrite(pinDP, (ponto && noDisplay1) ? LOW : HIGH);

  if (noDisplay1)
    digitalWrite(digito1, LOW);
  else
    digitalWrite(digito2, LOW);
}

// Apaga os dois displays
void apagarDisplays() {
  digitalWrite(digito1, HIGH);
  digitalWrite(digito2, HIGH);
  digitalWrite(pinDP, HIGH);
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentos[i], HIGH);
  }
}

// Reseta o estado da medição
void resetar() {
  iniciou = false;
  medido = false;
}
