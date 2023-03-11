#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 2

void calculaPi(float *pi) {
    pi = (float *) malloc(sizeof(float));
    printf("Valor de pi depois de alocado: %p\n", pi);
    *pi = 3.1415;
    printf("Valor de pi: %f\n", *pi);
}

void calculaPi1(float **pi) {
  *pi = (float *) malloc(sizeof(float));
  **pi = 3.1415;
}


int main(){
    int number = 10;
    int *numberP = &number;
    int **numberPP = &numberP;

    printf("Valor da variável number: %d\n", number);
    printf("Endereço da variável number: %p\n", &number);
    printf("Valor da variável numberP: %p\n", numberP);
    printf("Endereço da variável numberP: %p\n", &numberP);
    printf("Valor da variável numberPP: %p\n", numberPP);
    printf("Valor de *numberPP: %p\n", *numberPP);
    printf("Valor **numberPP: %d\n", **numberPP);
    
    printf("\n================================================\n");
    int i;
    int **matriz;
    matriz = (int **) malloc(sizeof(int *) * TAMANHO);
    if (matriz == NULL) {
        printf("Erro ao alocar memória");
        free(matriz);
    }

    for (i = 0; i < TAMANHO; i++) {
        *(matriz+i) = (int *) malloc(TAMANHO * sizeof(int));
        if (*(matriz+i) == NULL) {
            printf("Erro ao alocar memória");
            free(matriz);
        }
    }

    *(*(matriz+0)+0) = 1;
    *(*(matriz+0)+1) = 2;
    *(*(matriz+1)+0) = 3;
    *(*(matriz+1)+1) = 4;

    printf("%d %d\n", matriz[0][0], matriz[0][1]);
    printf("%d %d\n", matriz[1][0], matriz[1][1]);

    free(matriz);

    printf("\n================================================\n");
    
    /*float *pi;
    calculaPi(&pi);
    printf("Valor de pi: %p\n", pi);
    printf("Valor de pi: %f\n", *pi);*/

    printf("\n================================================\n");
    
    float *pi = NULL;
    calculaPi1'z(&pi);
    printf("Valor de pi: %p\n", pi);
    printf("Valor do conteúdo apontado por pi: %.4f\n", *pi);
    return EXIT_SUCCESS;
}