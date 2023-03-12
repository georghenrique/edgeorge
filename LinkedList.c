#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "log.h"


void init(LinkedList *list){
    log_info("inicializando a lista");
    log_trace("init <-");
    list->first = NULL;
    list->size= 0;
    log_debug("list->first: %p",list->first);
    log_debug("list->size: %d",list->size);
    log_trace("init ->");

}

bool isEmpty(LinkedList *list){
    log_info("Verificando se a lista esta vazia");
    log_trace("isEmpty <-");
    if(list->first == NULL){
        log_error("A lista esta Vazia");
        log_debug("list->first: %p", list->first);
        log_trace("isEmpty <-");
        return true;
    }

    if(list->size == 0){
        log_error("A lista esta Vazia");
        log_debug("list->size: %d", list->size);
        log_trace("isEmpty <-");
        return true;
    } 
    else{
        log_trace("isEmpty ->");
        return false;
    }
}

void* first(LinkedList *list){
    log_info("verificando o primeiro termo da lista:");
    log_trace("first ->");
    if(!isEmpty(list)){
        log_error("A lista esta vazia !!");
        log_debug("lista: %p", list);
        log_trace("first <-");
        return NULL;
    }
    else{
        /*log_debug("valor contido na lista: %p", list->data);
        log_trace("first <-");
        return list->data;*/
    }     
}

int enqueue(LinkedList *list, void *data){
    log_info("Entrando na funçao enqueue");
    log_trace("enqueue <-");
    Node *newNode = (Node*)malloc(sizeof(Node));
    log_info("criado o novo Nó");
    
    log_info("teste para ver se o no foi criado");
        if(newNode == NULL){
        log_error("**Erro ao criar o nó");
        log_debug("newNode: %p", newNode);
        return -1;
    }

    newNode->data = data;
    newNode->next = NULL;
    log_debug("newNode->data: %d", newNode->data);
    log_debug("newNode->next: %p", newNode->next);

    log_info("Teste para saber qual é o primeiro Nó");
    if(isEmpty(list)){
        log_info("a lista está vazia! adicionando o primeiro Nó");
        list->first = newNode;
        log_debug("list->first: %p", list->first);
    }
    
    else{
        log_info("a lista possui elementos, ache o ultimo e add o novo Nó");
        Node *aux = list->first;
        log_debug("Criaçao de uma variavel auxiliar: %p", *aux);
        while(aux->next != NULL){
            log_info("laço para achar o ultimo elemento da lista");
            aux = aux->next;
            log_debug("aux->next: %p", aux);
        }
        log_debug("ultimo Nó encontrado aux->next: %p", aux);
        aux->next = newNode;  
    }
    list->size++;
    log_debug("incrementaçao de list->size: %d", list->size);
    log_trace("enqueue ->");
    return 0;

}

void* dequeue(LinkedList *list){
    return NULL;
}


void* last(LinkedList *list){
    return NULL;
}

int push(LinkedList *list, void *data){
    return 0;
}

void* pop(LinkedList *list){
    return NULL;
}

void* top(LinkedList *list){
    if( first == NULL){
        log_info("a lista esta vazia");
        
    }
    return first;
}



int indexOf(LinkedList *list, void *data, compare equal){
    return 0;
}

void* getPos(LinkedList *list, int pos){
    return NULL;
}

Node* getNodeByPos(LinkedList *list, int pos){
    return NULL;
}

int add(LinkedList *list, int pos, void *data){
    return 0;
}

int addAll(LinkedList *listDest, int pos, LinkedList *listSource){
    return 0;
}

void* removePos(LinkedList *list, int pos){
    return NULL;
}

bool removeData(LinkedList *list, void *data, compare equal){
    return 1;
}
