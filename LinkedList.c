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
        log_error("A lista esta Vazia: list->first == NULL");
        log_debug("list->first: %p", list->first);
        log_trace("isEmpty ->");
        return true;
    }

    if(list->size == 0){
        log_error("A lista esta Vazia: list->size == 0");
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
    log_trace("last <-");
    return data;
    }
    else{
        log_error("ERRO** A lista esta vazia !!");
        log_trace("last <-");
        return NULL;
    }
}

int enqueue(LinkedList *list, void *data){
    log_info("Entrando na funçao enqueue");
    log_trace("enqueue <-");
    Node *newNode = (Node*)malloc(sizeof(Node));
    log_info("criado o novo Nó");
    
    log_info("teste para ver se o Nó foi criado");
        if(newNode == NULL){
        log_error("**Erro: ao criar o Nó!");
        log_debug("newNode: %p", newNode);
        return -1;
    }

    newNode->data = data;
    newNode->next = NULL;
    log_debug("newNode->data: %d", newNode->data);
    log_debug("newNode->next: %p", newNode->next);

    log_info("Teste para saber qual é o primeiro Nó");
    if(isEmpty(list) == true){
        log_info("a lista está vazia! adicionando o primeiro Nó");
        list->first = newNode;
        log_debug("list->first: %p", list->first);
    }
    else{
        log_info("a lista possui elementos, ache o ultimo e add o novo Nó");
        Node *aux = list->first;
        log_debug("Criaçao de uma variavel auxiliar: %p", *aux);
        log_info("laço para achar o ultimo elemento da lista");
        while(aux->next != NULL){
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

    if(isEmpty(list)==true){
        log_error("**Erro: a lista está vazia!");
        log_trace("dequeue <-");
        return -1;
    }

    Node *trash = list->first;
    list->first = list->first->next; 
    void *data = trash->data;
    log_debug("variável trash recebe o endereço do nó que será removido: %p", trash);
    log_debug("variável list->first recebe list->first->next, fazendo o com que o segundo elemento se torne o primeiro %p", list->first);
    log_debug("variável data recebe o dado do nó removido: %d", data);
    
    log_debug("variável trash é liberada com free: %p", trash);
    free(trash);
    list->size--;
    log_debug("decrementaçao de list->size: %d", list->size);
    log_trace("dequeue ->");
    return data;
}

void* pop(LinkedList *list){
    log_info("Entrando na funçao pop");
    log_trace("pop <-");
        if(isEmpty(list)==true){
        log_error("**Erro: a lista está vazia!");
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
    log_info("Entrando na funçao top");
    log_trace("top <-");
    void *data = first(list);
    log_trace("top ->");
    return data;

}

int push(LinkedList *list, void *data){
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
    log_debug("Endereço contido em aux: %p", aux);

    if (aux==NULL){
        log_error("**Erro: Dado Ñ encontrado!");
        log_debug("Endereço contido em aux: %p", aux);
        return NULL;
    }
    else
        log_debug("Dado localizado: %d", aux->data);
        log_trace("getPos ->");
        return aux->data;
}

int add(LinkedList *list, int pos, void *data){
    log_info("Entrando na funçao add");
    log_trace("add <-");

    log_info("teste: add no inicio da lista");
    if (pos <= 0){
        log_info("o dado será add ao inicio da lista, chamada da funçao PUSH");
        return push(list,data);
    }

    Node *aux = getNodeByPos(list, (pos-1));
    log_debug("aux recebe o endereço do nó anterior ao que será add: %p", aux);

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
    newNode->next = NULL;
    log_debug("newNode->data: %d", newNode->data);
    log_debug("newNode->next: %p", newNode->next);
    
    newNode->next = aux->next;
    aux->next = newNode;
    list->size++;
    log_debug("incrementaçao de list->size: %d", list->size);
    log_trace("add ->");
    return 1;
}

int addAll(LinkedList *listDest, int pos, LinkedList *listSource){
    log_info("Entrando na funçao addAll");
    log_trace("addll <-");
    
    log_info("Teste de conteudo das listas listDest e listSource: elas estão vazias?");
    if (listDest==NULL || isEmpty(listDest)){
        log_error("**Erro a lista listDest está vazia");
        log_debug("listDest: %p", listDest);
        return -1;
    }

    if (listSource == NULL || isEmpty(listSource)){
        log_error("**Erro a lista listSource está vazia");
        log_debug("listSource: %p", listSource);
        return -2;
    }

    Node *last = NULL;
    log_info("inicio do laço que achara o ultino Nó da lista de origem");
    for (last = listSource->first; last->next!=NULL; last=last->next){
    log_debug("last: %p", last);
    }
    log_debug("variavel que guarda a ultima posição da lista de origem, last: %p", last);

    if (pos == 0) {
        log_info("a lista de ORIGEM sera add no inicio da lista de DESTINO");
        last->next = listDest->first;
        log_debug("O Ultimo NÓ da lista de ORIGEM (last->next) aponta para o inicio da lista de DESTINO: %p", last->next);
        listDest->first = listSource->first;
        log_debug("O inicio da lista de DESTINO (listDest->first) agora aponta para o primeiro Nó da lista de ORIGEM (listSource->first) : %p", listDest->first);
    }
    else {
        log_debug("a lista de ORIGEM será add na posição %d da lista de DESTINO", pos);
        Node *aux = getNodeByPos(listDest, (pos-1));
        log_debug("aux recebe o endereço do nó anterior ao que será add : %p", aux);

        log_info("teste para ver se o aux é valido");
        if(aux == NULL){
            log_error("**Erro: aux Ñ pode achar o Nó solicitado");
            log_debug("aux: %p", aux);
            return -3;
        }
        last->next = aux->next;
        log_debug("O Ultimo NÓ da lista de ORIGEM (last->next) para a posição selecionada na lista de DESTINO (aux->next): %p", last->next);
        aux->next = listSource->first;
        log_debug("aux->next vai apontar para o inicio da lista de ORIGEM: %p", aux->next);
    }
    listDest->size += listSource->size;
    log_debug("soma das quantidades de list->size: %d", listDest->size);
    log_trace("addAll ->");
    return listSource->size;
}

void* removePos(LinkedList *list, int pos){
    log_info("Entrando na funçao remosvePos");
    log_trace("remosvePos <-");

    if (isEmpty(list) == true || pos>=list->size){
        log_error("**Erro: a lista está vazia ou a posiçao é invalida");
        return NULL;
    }
    
    Node *nodeRemove = NULL;
    Node *aux = NULL;
    log_debug("nodeRemove: %p", nodeRemove);
    log_debug("aux: %p", aux);
    
    if (pos<=0){
        log_info("O elemento a ser removido encontra-se na primeira posição da lista");
        return dequeue(list);
    }
    else{
        log_info("buscando o endereço do elemento na lista");
        aux = getNodeByPos(list, pos-1);
        log_debug("aux recebeu o endereço do Nó anterior ao que será removido: %p", aux);
    }

    nodeRemove = aux->next; 
    log_debug("nodeRemove = aux->next, ou seja identificamos o nó que será removido (que é o próximo) e colocamos ele em nodeRemove: %p", nodeRemove);

    aux->next = nodeRemove->next;
    log_debug("o Nó anterior agora aponta para o nó seguinte ao nó que será removido, aux->next: %p", aux->next);

    void* dataRemove = nodeRemove->data;
    log_debug("guardamos uma referência ao dado guardado no nó que será removido: %d", dataRemove);
    
    log_debug("removemos o nó da memória, nodeRemove: %p", nodeRemove);
    free(nodeRemove); 
    
    list->size--;
    log_debug("decrementamos a quantidade de elementos da lista, list->size: %d", list->size);
    log_debug("dado do nó que foi removido: %d", dataRemove);
    log_trace("removePos ->");
    return dataRemove;
}

bool removeData(LinkedList *list, void *data, compare equal) {
    log_info("Entrando na funçao removeData");
    log_trace("removeData <-");

    if(isEmpty(list)==true){
        log_error("**Erro: a lista está vazia!");
        log_trace("removeData ->");
        return -1;
    }

    Node *nodeRemove = NULL;
    if (equal(list->first->data,data)==true) {
        log_info("O dado está na primeira posição da lista:");
        nodeRemove = list->first;
        list->first = list->first->next;
        log_debug("nodeRemove recebe o endereço do primeiro Nó da lista: %p", nodeRemove);
        log_debug("variável list->first recebe list->first->next, fazendo o com que o segundo elemento se torne o primeiro %p", list->first);
        log_debug("dado a ser removido: %d", nodeRemove->data);

        nodeRemove->data=NULL; //só funciona com essa linha
        free(nodeRemove->data);
        free(nodeRemove);
        log_debug("free em nodeRemove->data: %p", nodeRemove->data);
        log_debug("free em nodeRemove: %p", nodeRemove);
        list->size--;
        log_debug("decrementaçao de list->size: %d", list->size);
        log_trace("removeData ->");
        return true;
    }
    else {
        log_info("Procurando a posição do dado na lista");
        Node *aux = list->first;
        log_debug("aux recebe o endereço do primeiro Nó da lista: %p", aux);
        while(aux->next!=NULL && equal(aux->next->data,data)==false){
            log_trace("while <-");
            aux=aux->next;
            log_debug("aux recebe o endereço do proximo Nó da lista: %p", aux);
        }
        log_trace("while ->");
        
        if (aux->next!=NULL){
            
            Node *nodeRemove = aux->next;
            aux->next = nodeRemove->next;
            log_debug("nodeRemove recebe o endereço aux->next: %p", nodeRemove);
            log_debug("aux->next recebe o endereço nodeRemove->next: %p", aux->next);
            log_debug("dado a ser removido: %d", nodeRemove->data);
            

            nodeRemove->data=NULL; //só funciona com essa linha
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
}

int indexOf(LinkedList *list, void *data, compare equal){
    
    return 0;
}












