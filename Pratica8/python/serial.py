filename = "C:/Users/20221en20108/Documents/LingProgGit/Pratica8/test_file.txt"

try:
    with open(filename, 'r') as file:
        for line in file:
            print(line.rstrip('\n'))
except IOError:
    print("Erro ao abrir o arquivo.")
