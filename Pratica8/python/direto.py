filename = "C:/Users/20221en20108/Documents/LingProgGit/Pratica8/data.bin"
tamanho_bloco = 10  # tamanho fixo do bloco em bytes

try:
    with open(filename, 'rb') as file:
        bloco = int(input("Digite o número do bloco que deseja ler (começando do 0): "))
        if bloco < 0:
            print("Número de bloco inválido.")
        else:
            file.seek(bloco * tamanho_bloco)
            buffer = file.read(tamanho_bloco)
            if not buffer:
                print("Não há dados para ler nesta posição.")
            else:
                print(f"Conteúdo do bloco {bloco}: {buffer.decode('utf-8', errors='replace')}")
except IOError:
    print("Erro ao abrir o arquivo.")
except ValueError:
    print("Entrada inválida. Por favor, digite um número inteiro.")
