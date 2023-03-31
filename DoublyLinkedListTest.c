#include <stdlib.h>
#include <stdio.h>
#include "DoublyLinkedList.h"
#include "log.h"

///////////////////////////////
//ARRUMAR TODAS AS CHAMADAS COM PONTEIRO VOID

bool compara(void *data1, void *data2) {
    log_info("Comparando se os dados são iguais:");
    log_trace("compara <-");

    log_info("Convertendo os dados fornecidos em ponteiros int:");
    int *d1 = (int*)data1;
    int *d2 = (int*)data2;
    log_debug("dado1: %p", d1);
    log_debug("dado2: %p", d2);

    if(d1 == d2){
        log_info("Os dados são iguais:");
        log_debug("dado1: %d \n dado2: %d", *d1, *d2);
        log_trace("compara ->");    
        return true;
    }
    else{
        log_error("**ERRO: os dados são diferentes!");
        log_debug("dado1: %d \n dado2: %d", *d1, *d2);
        log_trace("compara ->");    
        return false;
    }
}

void impressao(void *data) {
    log_info("Imprimindo os dados da lista:");
    log_trace("impressao <-");
    int *dado = (int*)data;
    printf("o dado é: %d",*dado);
    log_trace("impressao ->");

}

int main(){
   log_set_level(LOG_TRACE);
   log_info("criada a variavel lista do tipo DoublyLinkedList");
   DoublyLinkedList list;
   
   log_info("chamada da funçao init");
   init(&list);


   int *aux = (int *)malloc(sizeof(int));
    *aux=1;

    log_info("chamada da funçao enqueue");
    enqueue(&list, aux);

    log_info("chamada da funçao first");
    first(&list);

    log_info("chamada da funçao show");
    show(&list, impressao);

    log_info("chamada da funçao removeDate");
    removeData( &list, aux, compara);



   return 0;
}