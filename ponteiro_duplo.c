#include <stdio.h>
#include <stdlib.h>

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
    return EXIT_SUCCESS;
}
