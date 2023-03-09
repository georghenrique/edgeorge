#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"
#include "log.h"

void init(DoublyLinkedList *list){
    log_info("inicializando a lista");
    log_trace("init <-");
    Node *trashNode = (Node*)malloc(sizeof(Node));
    log_debug("trashNode: %p",trashNode);
    trashNode->data=NULL;
    trashNode->previous=trashNode;
    trashNode->next=trashNode;
    list->first=trashNode;
    list->size=0;
    log_debug("trashNode->data: %p", trashNode->data);
    log_debug("trashNode->previous: %p", trashNode->previous);
    log_debug("trashNode->next: %p", trashNode->next);  
    log_debug("list->first: %p", list->first);  
    log_debug("list->size: %d", list->size);  
    log_trace("init <-");
}



void show(DoublyLinkedList *list, printNode print) {
    log_info("entrando na função Show que exibe os dados contidos na lista");
    log_info("Criando a variavel auxiliar");
    log_trace("aux <-");
    Node *aux = list->first->next;
    log_debug("list->first->next: %p",aux);
    log_trace("while <-");
    while (aux!=list->first) {
        print(aux->data); //criar funcao 
        aux=aux->next;
        log_debug("aux->list->next: %p",aux);
    }
    log_debug("aux: %p",aux);
    log_trace("aux ->");
}


