#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"
#include "log.h"


void init(DoublyLinkedList *list){
    log_info("inicializando a lista");
    log_trace("init <-");
    Node *trashNode = (Node*)malloc(sizeof(Node));
    //log_debug("trashNode: %p",trashNode);
    trashNode->data=NULL;
    trashNode->previous=trashNode;
    trashNode->next=trashNode;
    list->first=trashNode;
    list->size=0;
    //log_debug("trashNode->data: %p", trashNode->data);
    //log_debug("trashNode->previous: %p", trashNode->previous);
    //log_debug("trashNode->next: %p", trashNode->next);  
    //log_debug("list->first: %p", list->first);  
    //log_debug("list->size: %d", list->size);  
    //log_trace("init ->\n");
}

int enqueue(DoublyLinkedList *list, void *data){
    log_info("Entrando na funçao enqueue");
    log_trace("enqueue <-");

    log_info("criado o novo Nó");
    Node *newNode = (Node*)malloc(sizeof(Node));
        if(newNode == NULL){
        log_info("teste para ver se o Nó foi criado");
        log_error("**Erro: ao criar o Nó!");
        log_debug("newNode: %p", newNode);
        log_trace("enqueue -> \n");
        return -1;
    }

    newNode->data = data;
    newNode->next = list->first;
    //log_debug("newNode->data: %d", newNode->data);
    //log_debug("newNode->next: %p", newNode->next);

    newNode->previous = list->first->previous;
    list->first->previous->next = newNode;
    list->first->previous = newNode;
    list->size++;
    
    log_debug("incrementaçao de list->size: %d", list->size);
    log_trace("enqueue -> \n");
    return 1;
}

void* dequeue(DoublyLinkedList *list) {
    log_info("Entrando na funçao dequeue");
    log_trace("dequeue <-");

    if (isEmpty(list)== true) {
        log_error("ERRO** A lista está vazia!");
        log_trace("dequeue -> \n");
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
    log_trace("dequeue -> \n");
    return data;
}

void* first(DoublyLinkedList *list) {
    log_info("verificando o primeiro dado da lista:");
    log_trace("first <-");

    if(isEmpty(list) == true){
        log_error("ERRO** A lista esta vazia !!");
        log_debug("lista: %p", list->first);
        log_trace("first -> \n");
        return NULL;
    }
    else{
        log_debug("valor contido na lista: %d", list->first->next->data);
        log_trace("first -> \n");
    } 
    return list->first->next->data;
}

void* last(DoublyLinkedList *list) {
    log_info("verificando o ultimo elemento da lista");
    log_trace("last <-");

    if (isEmpty(list)== true) {
        log_error("ERRO** A lista está vazia!");
        log_trace("last -> \n");
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
        return false;
    }  
    log_trace("pop ->");
    return dequeue(list);
}

void* top(DoublyLinkedList *list) {
    log_info("Entrando na funçao top");
    log_trace("top <-");
    void *data = first(list);
    log_trace("top ->");
    return data;
}

bool isEmpty(DoublyLinkedList *list) {
    log_info("Verificando se a lista esta vazia");
    log_trace("isEmpty <-");
    
    if(list->size == 0){
        log_error("ERRO** A lista esta Vazia: list->size == 0");
        log_debug("list->size: %d", list->size);
        log_trace("isEmpty ->");
        return true;
    } 
    else{
        log_trace("isEmpty ->");
        return false;
    }
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
        aux=aux->next;
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
    
    if(res==NULL){
        log_error("**Erro: Dado Ñ encontrado!");
        log_debug("Endereço contido em aux: %p", res);
        return NULL;
    }
    else{
        log_debug("Dado localizado: %d", res->data);
        log_trace("getPos ->");
        return res->data;
    }
}

int add(DoublyLinkedList *list, int pos, void *data) {
    log_info("Entrando na funçao add");
    log_trace("add <-");
    
    Node *aux = getNodeByPos(list, pos);
    log_debug("aux recebe o endereço do Nó: %p", aux);

    log_info("teste para ver se o aux é valido");
        if(aux == NULL){
        log_error("**Erro: aux Ñ pode achar o Nó solicitado");
        log_debug("aux: %p", aux);
        return -2;
    }

    Node *newNode = (Node*) malloc(sizeof(Node));
    log_info("teste para ver se o Nó foi criado");
        if(newNode == NULL){
        log_error("**Erro ao criar o nó");
        log_debug("newNode: %p", newNode);
        return -1;
    }

    newNode->data = data;
    newNode->next = aux;
    newNode->previous = aux->previous;
    aux->previous->next = newNode;
    aux->previous = newNode;
    list->size++;
    log_debug("incrementaçao de list->size: %d", list->size);
    log_trace("add ->");
    return 1;
}

int addAll(DoublyLinkedList *listDest, int pos, DoublyLinkedList *listSource) {
    log_info("Entrando na funçao addAll");
    log_trace("addll <-");
    
    Node *aux = getNodeByPos(listDest, pos);
    if (aux==NULL){
        log_error("**Erro: Dado Ñ encontrado!");
        log_debug("Endereço contido em aux: %p", aux);
        return -1;
    }

    if (isEmpty(listSource)){
        log_error("**Erro a lista listSource está vazia");
        log_debug("listSource: %p", listSource);
        return -2;
    }

    listSource->first->previous->next = aux;
    listSource->first->next->previous = aux->previous;
    aux->previous->next = listSource->first->next;
    aux->previous = listSource->first->previous;
    listDest->size+=listSource->size;
    log_debug("soma das quantidades de list->size: %d", listDest->size);
    log_trace("addAll ->");
    return listSource->size;
}

void* removePos(DoublyLinkedList *list, int pos) {
    log_info("Entrando na funçao remosvePos");
    log_trace("remosvePos <-");
    
   if (isEmpty(list) || pos>=list->size){
        log_error("**Erro: a lista está vazia ou a posiçao é invalida");
        return NULL;
    }
    
    log_info("buscando o endereço do elemento na lista");
    Node *nodeRemove = getNodeByPos(list, pos);
    log_debug("nodeRemove: %p", nodeRemove);

    nodeRemove->previous->next = nodeRemove->next;
    nodeRemove->next->previous = nodeRemove->previous;
    void* dataRemove = nodeRemove->data;
    
    log_debug("removemos o nó da memória, nodeRemove: %p", nodeRemove);
    free(nodeRemove);

    list->size--;
    log_debug("decrementamos a quantidade de elementos da lista, list->size: %d", list->size);
    log_debug("dado do nó que foi removido: %d", dataRemove);
    log_trace("removePos ->");
    return dataRemove;
}

bool removeData(DoublyLinkedList *list, void *data, compare equal) {
    log_info("Entrando na funçao removeData");
    log_trace("removeData <-");

    if(isEmpty(list)==true){
        log_error("**Erro: a lista está vazia!");
        log_trace("removeData ->");
        return false;
    }

    Node *nodeRemove = list->first->next;
    log_debug("nodeRemove recebe o endereço do primeiro No da lista: %p", nodeRemove);

    log_trace("while <-");
    while(nodeRemove!=list->first && !equal(nodeRemove->data,data)){
        nodeRemove=nodeRemove->next;
        log_debug("nodeRemove recebe nodeRemove->next: %p", nodeRemove);
    }
    log_trace("while ->");

    if (nodeRemove!=list->first){
        nodeRemove->previous->next = nodeRemove->next;
        nodeRemove->next->previous = nodeRemove->previous;
        free(nodeRemove->data);
        free(nodeRemove);
        log_debug("free em nodeRemove->data: %p", nodeRemove->data);
        log_debug("free em nodeRemove: %p", nodeRemove);
        list->size--;
        log_debug("decrementaçao de list->size: %d", list->size);
        log_trace("removeData ->");
        return true;
    }
    else{
        log_error("**Erro: Ñ foi posssivel remover o dado");
        log_trace("removeData ->");
        return false;
    }
}

int indexOf(DoublyLinkedList *list,void *data,compare equal) {
    log_info("Entrando na funçao indexOf");
    log_trace("indexOf <-");

    if (isEmpty(list)==true){
        log_error("**Erro: a lista está vazia!");
        log_trace("indexOf ->");
        return -1;
    }
    
    int count=0;
    Node *aux = list->first->next;
    //log_debug("VAR contadora é criada: %d", count);
    //log_debug("aux recebe o endereço do primeiro Nó da lista: %p", aux);

    log_trace("while <-");
    while(aux!=list->first && !equal(aux->data,data)) {
        aux=aux->next;
        count++;
        //log_debug("aux recebe o endereço do proximo Nó da lista: %p", aux);
        //log_debug("count é incrementado: %d", count);
    }
    log_trace("while ->");
    
    if(aux==list->first){
        log_error("**ERRO! posição do dado Ñ localizada");
        return -1;
    }
    else{
        log_debug("O dado se encontra na posição %d da lista", count);
        return count;
    }
}

void show(DoublyLinkedList *list, printNode print) {
    log_info("entrando na função Show");
    log_trace("show <-");

    Node *aux = list->first->next;
    log_debug("aux recebe o endereço do primriro Nó da lista: %p",aux);
    log_trace("while <-");
    while (aux!=list->first) {
        print(aux->data); //criar funcao 
        aux=aux->next;
        log_debug("aux->list->next: %p",aux);
    }
    log_trace("aux ->");
}

