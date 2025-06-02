filename = "C:/Users/20221en20108/Documents/LingProgGit/Pratica8/test_file.txt"

try:
    with open(filename, 'r') as file:
        for line in file:
            tokens = line.strip().split(',')
            for token in tokens:
                print(token)
except IOError:
    print("Erro ao abrir o arquivo.")
