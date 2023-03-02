#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "log.h"


void init(LinkedList *list){
    log_info("inicializando a lista");
    log_trace("init->");
    list->first = NULL;
    list->size= 0;
    log_debug("list->first: %p",list->first);
    log_debug("list->size: %d",list->size);
    log_trace("init <-");

}

bool isEmpty(LinkedList *list){
    log_info("Verificando se a lista esta vazia");
    log_trace("isEmpty ->");
    if(list==NULL){
        log_error("parametro invalido");
        log_debug("list: %p", list);
        return true;
    }

    log_debug("list->size: %d", list->size);
    log_trace("isEmpty <-");
    if(list->size == 0){
        return true;
    } 
    else{
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
        log_debug("valor contido na lista: %p", list->data);
        log_trace("first <-");
        return list->data;
    }     
}

int enqueue(LinkedList *list, void *data){
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
