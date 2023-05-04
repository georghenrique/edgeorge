#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"
#include "log.h"
#define MAX1 50 //tamanho do vetor para guardar as Strings

bool comparaChaves(void *data1, void *data2) {
    char *d1 = (char*)data1;
    char *d2 = (char*)data2;

     /*if(strcmp(d1,d2)==0){
        log_debug("Os dados são iguais! String1: %s, String2: %s", d1, d2);
        return true;

    }
    else{
        log_debug("Os dados NÃO são iguais! String1: %s, String2: %s", d1, d2);
        return false;
    }*/
    return strcmp(d1,d2)==0?:false;
}

int main() {
    log_info("Criação da var hashes do tipo HashStruct");
    HashStruct has;
    log_info("Chamada a função initHash");
    initHash(&has);
    
    log_info("Criação da var palavra do tipo char com tamanho MAX1");
    char palavra[MAX1];
    
    log_info("Abertura do arquivo ListaDePalavras no modo leitura:");
    FILE *file = fopen("ListaDePalavrasPT.txt", "r");
    if(file == NULL){
        log_error("ERRO** o arquivo Ñ foi aberto!");
        return -3;
    }

    log_info("Chamada de while para percorrer todas as palavras contidas no arquivo");
     while(fscanf(file, "%[^\n]%*c\n",palavra)!=EOF){
        //while ira ler todas as palavras do arquivo linha a linha indo para proxima palavra ao encontra o \n
        log_debug("String: %s", palavra);
        //put faz as o calculo do hash das palavras e inserindo-as na posições do vetor hashes 
        put(&has, palavra, palavra, comparaChaves);
     }
    log_info("O arquivo é fechado");
    fclose(file);

    mapaEspalhamento(&has);
    return 0;
}