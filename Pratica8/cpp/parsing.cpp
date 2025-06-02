#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *filePtr;
    char buffer[100]; // Buffer para armazenar cada linha do arquivo
    char *token;

    // Abre o arquivo para leitura (caminho relativo ou absoluto)
    filePtr = fopen("C:/Users/20221en20108/Documents/LingProgGit/Pratica8/test_file.txt", "r");
    if (filePtr == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1; // Sai do programa se falhar ao abrir
    }

    // Lê e faz o parsing de cada linha do arquivo
    while (fgets(buffer, sizeof(buffer), filePtr) != NULL) {
        // Considerando que cada linha está no formato CSV (valores separados por vírgula)
        token = strtok(buffer, ",");
        while (token != NULL) {
            // Processa cada token (campo) da linha
            printf("%s\n", token);
            token = strtok(NULL, ",");
        }
    }

    fclose(filePtr); // Fecha o arquivo
    return 0;
}
