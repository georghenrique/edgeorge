#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"
#include "log.h"
#define MAX 30

bool comparaChaves(void *data1, void *data2) {
    char *d1 = (char*)data1;
    char *d2 = (char*)data2;
    
    /*if(strcmp((d1,d2)==0)){
        log_info("Os dados são iguais:");  
        return true;

    }
    else{
        log_error("**ERRO: os dados são diferentes!");
        return false;
    }*/
    return strcmp(d1,d2)==0?:false;
}
//typedef char WORD[MAX];


int main() {
    log_info("Criação da var hashes do tipo HashStruct");
    HashStruct hashes;
    log_info("Chamada a função initHash");
    initHash(&hashes);

    char palavra[MAX];
    
    log_info("");

    FILE *file = fopen("ListaDePalavrasPT.txt", "r");
    if(file == NULL){
        log_error("ERRO** o arquivo Ñ foi aberto!");
        return -3;
    }
    
     while(fscanf(file, "%[^\n]%*c\n",palavra)!=EOF){
        log_debug("teste de string: %s", palavra);
        put(&hashes, palavra, palavra, comparaChaves);
        //log_debug("list->first: %p", list->first);

     }
     fclose(file);















   
    return 0;
}