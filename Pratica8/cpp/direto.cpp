#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream file("C:/Users/20221en20108/Documents/LingProgGit/Pratica8/data.bin", ios::in | ios::out | ios::binary);

    if (!file) {
        cerr << "Erro ao abrir o arquivo.\n";
        return 1;
    }

    const int tamanho_bloco = 10;  // tamanho fixo do bloco para leitura
    int bloco;

    cout << "Digite o número do bloco que deseja ler (começando do 0): ";
    cin >> bloco;

    if (bloco < 0) {
        cerr << "Número de bloco inválido.\n";
        return 1;
    }

    char buffer[tamanho_bloco + 1];
    buffer[tamanho_bloco] = '\0';

    // Move o cursor para a posição desejada
    file.seekg(bloco * tamanho_bloco, ios::beg);

    if (!file) {
        cerr << "Erro ao posicionar o cursor no arquivo.\n";
        return 1;
    }

    // Lê o bloco
    file.read(buffer, tamanho_bloco);

    if (file.gcount() == 0) {
        cerr << "Não há dados para ler nesta posição.\n";
    } else {
        cout << "Conteúdo do bloco " << bloco << ": " << buffer << '\n';
    }

    file.close();
    return 0;
}
