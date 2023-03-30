#include <stdlib.h>
#include <stdio.h>
#include "DoublyLinkedList.h"
#include "log.h"



int main(){
   log_set_level(LOG_TRACE);
   log_info("criada a variavel lista do tipo DoublyLinkedList");
   DoublyLinkedList list;
   
   log_info("chamada da funçao init");
   init(&list);

   isEmpty(&list);

   enqueue(&list, 12);

   first(&list);


   return 0;
}