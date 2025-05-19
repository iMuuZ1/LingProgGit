#include <stdio.h>

#include <stdlib.h> // Required for malloc



int main() {

    int size = 5, n = 5, i = 0;
    int *vector = (int *)calloc(size, sizeof(int)); // Aloca a memória para o vetor

    while (n >= 1){ // Insere e exibe o conteudo do vetor
        vector[i] = n;
        n--;
        if(i != 4){
            printf("%d, ", vector[i]);
        }
        i++;
    }
    printf("%d", vector[4]);
    free(vector); // Libera a memória alocada
    return 0;
}