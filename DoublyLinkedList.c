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

int enqueue(DoublyLinkedList *list, void *data){
    log_info("Entrando na funçao enqueue");
    log_trace("enqueue <-");

    log_info("criado o novo Nó");
    Node *newNode = (Node*)malloc(sizeof(Node));
    log_info("teste para ver se o Nó foi criado");
        if(newNode == NULL){
        log_error("**Erro: ao criar o Nó!");
        log_debug("newNode: %p", newNode);
        return -1;
    }

    newNode->data = data;
    newNode->next = list->first;
    log_debug("newNode->data: %d", newNode->data);
    log_debug("newNode->next: %p", newNode->next);



    newNode->previous = list->first->previous;
    list->first->previous->next = newNode;
    list->first->previous = newNode;
    list->size++;
    return 1;
}

void* dequeue(DoublyLinkedList *list) {
    log_info("Entrando na funçao dequeue");
    log_trace("dequeue <-");

    if (isEmpty(list)== true) {
        log_error("ERRO** A lista está vazia!");
        return NULL;
    }


    Node *trash = list->first;
    Node *first = list->first->next;
    first->next->previous = trash;
    trash->next = first->next;
    void *data = first->data;
    log_debug("variável data recebe o dado do nó removido: %d", data);

    log_debug("variável trash é liberada com free: %p", trash);
    free(first);
    list->size--;
    log_debug("decrementaçao de list->size: %d", list->size);
    log_trace("dequeue ->");
    return data;
}

void* first(DoublyLinkedList *list) {
    log_info("verificando o primeiro dado da lista:");
    log_trace("first ->");

    if(isEmpty(list) == true){
        log_error("ERRO** A lista esta vazia !!");
        log_debug("lista: %p", list->first);
        log_trace("first <-");
        return NULL;
    }
    else{
        log_debug("valor contido na lista: %d", list->first->next->data);
        log_trace("first <-");
    } 
    return list->first->next->data;
}

void* last(DoublyLinkedList *list) {
    log_info("verificando o ultimo elemento da lista");
    log_trace("last <-");

    if (isEmpty(list)== true) {
        log_error("ERRO** A lista está vazia!");
        return NULL;
    }
    log_debug("o ultimo elemento da lista: %d", list->first->previous->data);
    log_trace("last <-");
    return list->first->previous->data;
}

int push(DoublyLinkedList *list, void *data) {
    log_info("Entrando na funçao push");
    log_trace("push <-");
    
    log_info("criado o novo Nó");
    Node *newNode = (Node*) malloc(sizeof(Node));
    log_info("teste para ver se o no foi criado");
    if(newNode == NULL){
        log_error("**Erro ao criar o nó");
        log_debug("newNode: %p", newNode);
        return -1;
    }

    newNode->data = data;
    newNode->next = list->first->next;
    newNode->previous = list->first;
    list->first->next->previous = newNode;
    list->first->next = newNode;
    list->size++;
    log_debug("incrementaçao de list->size: %d", list->size);
    log_trace("push ->");
    return 1;
}

void* pop(DoublyLinkedList *list) {
   log_info("Entrando na funçao pop");
   log_trace("pop <-");
   
   if(isEmpty(list)==true){
        log_error("**Erro: a lista está vazia!");
        return -1;
    }  
    log_trace("pop ->");
    return dequeue(list);
}

void* top(DoublyLinkedList *list) {
    return first(list);
}

bool isEmpty(DoublyLinkedList *list) {
    return (list->size==0);
}

Node* getNodeByPos(DoublyLinkedList *list,int pos) {
    log_info("Entrando na funçao getNodeByPos");
    log_trace("getNodeByPos <-");

    if(isEmpty(list)==true){
        log_error("**Erro a lista está vazia");
        return NULL;
        }

    if(pos>=list->size){
        log_error("**Erro elemento está fora do alcance de size");
        return NULL;
    }
    
    Node *aux = list->first->next;
    for (int count=0; (aux!=list->first && count<pos); count++){
        aux=aux->next
        log_debug("variavel aux recebe o aux->next: %p", aux);
    }
    log_debug("Dado do endereço localizado: %d", aux->data);
    log_debug("endereço localizado: %p", aux);
    log_trace("getNodeByPos ->");
    return aux;
}

void* getPos(DoublyLinkedList *list,int pos) {
    log_info("Entrando na funçao getPos");
    log_trace("getPos <-");

    Node *res = getNodeByPos(list,pos);
    
    return (res==NULL)?NULL:res->data; //oq esta acontecendo aqui
}

int add(DoublyLinkedList *list, int pos, void *data) {
    log_info("Entrando na funçao add");
    log_trace("add <-");
    
    Node *aux = getNodeByPos(list, pos);
    if (aux==NULL) return -2;
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode==NULL) return -1;
    newNode->data = data;
    newNode->next = aux;
    newNode->previous = aux->previous;
    aux->previous->next = newNode;
    aux->previous = newNode;
    list->size++;
    return 1;
}


