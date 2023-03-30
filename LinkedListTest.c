#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "log.h"

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
        log_debug("dado1: %d \n dado2: %d", d1, d2);
        log_trace("compara ->");    
        return true;
    }
    else{
        log_error("**ERRO: os dados são diferentes!");
        log_debug("dado1: %d \n dado2: %d", d1, d2);
        log_trace("compara ->");    
        return false;
    }
}

/*bool compara(void *data1, void *data2) {
    int *d1 = (int*)data1;
    int *d2 = (int*)data2;

    return (*d1==*d2)?true:false;
}*/

int main(){
    log_set_level(LOG_TRACE);
    log_info("criada a variavel lista do tipo LinkedList");
    LinkedList lista;

    log_info("chamada da funçao init");
    init(&lista);

    /*log_info("chamada da funçao last");//duvida aqui pq ficou zero
    last(&lista);
    
    log_info("chamada da funçao isEmpty");
    isEmpty(&lista);

    log_info("chamada da funçao first");
    first(&lista);

    log_info("chamada da funçao dequeue");
    dequeue(&lista);

    log_info("chamada da funçao enqueue");
    enqueue(&lista, 8);

    log_info("chamada da funçao getNodeByPos");
    getNodeByPos(&lista, 0);//size se inicia apartir da POSIÇÃO ZERO
    
    log_info("chamada da funçao getPos");
    getPos(&lista, 0);

    log_info("chamada da funçao first");
    first(&lista);

    log_info("chamada da funçao isEmpty");
    isEmpty(&lista);

    log_info("chamada da funçao push");
    push(&lista, 833);

    log_info("chamada da funçao enqueue");
    enqueue(&lista, 25);

    log_info("chamada da funçao first");
    first(&lista);

    log_info("chamada da funçao last");
    last(&lista);

    log_info("chamada da funçao dequeue");
    dequeue(&lista);

    log_info("chamada da funçao first");
    first(&lista);
    
    removePos(&lista, 1);

    log_info("chamada da funçao last");//duvida aqui pq ficou zero
    last(&lista);*/

    log_info("chamada da funçao enqueue");
    enqueue(&lista, 8);

    log_info("chamada da funçao enqueue");
    enqueue(&lista, 25);

    log_info("chamada da funçao first");
    top(&lista);

    log_info("chamada da funçao push");
    push(&lista, 833);

    log_info("chamada da funçao first");
    first(&lista);

   
    
    removeData(&lista, 13, compara);

    removeData(&lista, 25, compara);



    return EXIT_SUCCESS;
}