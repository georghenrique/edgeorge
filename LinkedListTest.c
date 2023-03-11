#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "log.h"




int main(){
    log_set_level(LOG_TRACE);
    log_info("criada a variavel lista do tipo LinkedList");
    LinkedList lista;
    log_info("chamada da funçao init");
    init(&lista);
    log_info("chamada da funçao isEmpty");
    isEmpty(&lista);
    return EXIT_SUCCESS;
}