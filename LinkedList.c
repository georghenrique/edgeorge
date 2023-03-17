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
        log_trace("isEmpty ->");
        return true;
    }

    if(list->size == 0){
        log_error("A lista esta Vazia");
        log_debug("list->size: %d", list->size);
        log_trace("isEmpty ->");
        return true;
    } 
    else{
        log_trace("isEmpty ->");
        return false;
    }
}

void* first(LinkedList *list){
    log_info("verificando o primeiro dado da lista:");
    log_trace("first ->");
    if(isEmpty(list) == true){
        log_error("ERRO** A lista esta vazia !!");
        log_debug("lista: %p", list->first);
        log_trace("first <-");
        return NULL;
    }
    else{
        log_debug("valor contido na lista: %d", list->first->data);
        log_trace("first <-");
        return list->first->data;
    }     
}

void* last(LinkedList *list){
    log_info("verificando o ultimo elemento da lista");
    log_trace("last <-");
    void *data = NULL;
    if(isEmpty(list) == false){
        Node *aux = list->first;
        log_debug("aux: %p", aux);
        while(aux->next != NULL){
            aux = aux->next;
            data = aux->data;
            log_debug("aux: %p", aux);
            log_debug("data: %d", data);
    }
    log_debug("o ultimo elemento da lista: %d", data);
    return data;
    }
    else{
        log_error("ERRO** A lista esta vazia !!");
        return NULL;

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
    log_info("Entrando na funçao dequeue");
    log_trace("dequeue <-");
    //log_info("teste para ver se há elementos na lista");
        if(isEmpty(list)==true){
        log_error("**Erro aa lista está vazia");
        return -1;
    }
    Node *trash = list->first;
    list->first = list->first->next; 
    void *data = trash->data;
    log_debug("variável trash recebe o endereço do nó que será removido: %p", trash);
    log_debug("variável list->first recebe list->first->next, fazendo o com que o segundo elemento se torne o primeiro %p", list->first);
    log_debug("variável data recebe o dado do nó removido: %d", data);
    
    free(trash);
    list->size--;
    log_debug("variável trash é liberada com free: %p", trash);
    log_debug("decrementaçao de list->size: %d", list->size);
    log_trace("dequeue ->");
    return data;
}

void* pop(LinkedList *list){
    log_info("Entrando na funçao pop");
    log_trace("pop <-");
        if(isEmpty(list)==true){
        log_error("**Erro aa lista está vazia");
        return -1;
    }
    Node *trash = list->first;
    list->first = list->first->next; 
    void *data = trash->data;
    log_debug("variável trash recebe o endereço do nó que será removido: %p", trash);
    log_debug("variável list->first recebe list->first->next, fazendo o com que o segundo elemento se torne o primeiro %p", list->first);
    log_debug("variável data recebe o dado do nó removido: %d", data);
    
    free(trash);
    list->size--;
    log_debug("variável trash é liberada com free: %p", trash);
    log_debug("decrementaçao de list->size: %d", list->size);
    log_trace("pop ->");
    return data;
}

void* top(LinkedList *list){
    /*log_info("Entrando na funçao top");
    log_trace("top <-");
    first(list);
    log_trace("pop ->");*/
    return NULL;

}


int push(LinkedList *list, void *data){
    log_info("Entrando na funçao push");
    log_trace("push <-");

        if(isEmpty(list)==true){
        log_error("**Erro aa lista está vazia");
        return -1;
    }
    log_info("criado o novo Nó");
    Node *newNode = (Node*) malloc(sizeof(Node));

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
        log_info("a lista possui elementos, add o novo elemento no topo da lista");
        newNode->next = list->first;
        list->first = newNode;
        log_debug("o topo atual será o segundo da lista: %p", newNode->next);
        log_debug("o novo nó será o topo: %p", list->first);
    }
  
    list->size++;
    log_debug("incrementaçao de list->size: %d", list->size);
    log_trace("push ->");
    return 1;
}


Node* getNodeByPos(LinkedList *list, int pos){
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

    Node *aux = list->first;
    log_debug("variavel aux recebe o endereço do  primeiro elemento da lista: %p", aux);
  
    log_info("inicio do laço for, para buscar a posiçao elemento na lista");
    for (int count=0; aux!=NULL && count<pos; count++){
        aux=aux->next;
        log_debug("variavel aux recebe o aux->next: %p", aux);
    }
    
    log_debug("Dado do endereço localizado: %d", aux->data);
    log_debug("endereço localizado: %p", aux);
    log_trace("getNodeByPos ->");

    return aux;
}

void* getPos(LinkedList *list, int pos){
    log_info("Entrando na funçao getPos");
    log_trace("getPos <-");
    Node *aux = getNodeByPos(list,pos);
    log_debug("endereço contido em aux: %p", aux);

    if (aux==NULL){
        log_error("**Erro: Dado Ñ encontrado!");
        log_debug("endereço contido em aux: %p", aux);
        return NULL;
    }
    else
        log_debug("Dado localizado: %d", aux->data);
        log_trace("getPos ->");
        return aux->data;
}

int indexOf(LinkedList *list, void *data, compare equal){
    
    return 0;
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
