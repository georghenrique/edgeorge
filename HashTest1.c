#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"
#include "log.h"
#define MAX 30

bool comparaChaves(void *data1, void *data2) {
    char *d1 = (char*)data1;
    char *d2 = (char*)data2;

     if(strcmp(d1,d2)==0){
        log_debug("Os dados são iguais! String1: %s, String2: %s", d1, d2);
        return true;

    }
    else{
        log_debug("Os dados NÃO são iguais! String1: %s, String2: %s", d1, d2);
        return false;
    }
    //return strcmp(d1,d2)==0?:false;
}
//typedef char WORD[MAX];


int main() {
    log_info("Criação da var hashes do tipo HashStruct");
    HashStruct has;
    log_info("Chamada a função initHash");
    initHash(&has);

    char palavra[MAX];
    
    log_info("");

    log_info("Abertura do arquivo ListaDePalavras no modo leitura:");
    FILE *file = fopen("ListaDePalavrasPT.txt", "r");
    if(file == NULL){
        log_error("ERRO** o arquivo Ñ foi aberto!");
        return -3;
    }
    log_info("Chamada de while para percorrer todas as palavras contidas no arquivo");
     while(fscanf(file, "%[^\n]%*c\n",palavra)!=EOF){
        log_debug("String: %s", palavra);
        put(&has, palavra, palavra, comparaChaves);
     }
     fclose(file);

    log_info("Calculo do maior numero de colisoes:");
    int cont,i = 0;
    HashStruct * a = &has;
    Node *aux = &a->hashes[i].first->next;
    int teste = a->hashes[i].size;
            log_debug("teste: %d", teste);

    log_info("aux recebeu o endereco de memoria de HashStruct na 1 posicao");
    while((aux != a->hashes[i].first)==true){
        log_trace("while <-");
        if(cont<a->hashes[i].size){
            log_debug("size na posicao %d, valor de cont: %d", i, a->hashes[i].size);

            log_trace("if <-");
            cont = a->hashes[i].size;
            log_debug("valor do contador de colisoes: %d", cont);
        }
        log_trace("if ->");
        aux = a->hashes[i].first->next;
        i++;
    }
    log_trace("while ->");

    log_debug("maior colisao encontrada: %d", cont);













   
    return 0;
}