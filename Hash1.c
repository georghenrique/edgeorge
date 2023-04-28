#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"
#include "log.h"
#include "DoublyLinkedList.c" //para usar as implementaçoes de doublyLinkedLista



void initHash(HashStruct *hashStruct) {
    log_info("inicializando o hash");
    log_trace("initHash <-");
    
    for (int i=0; i<MAX; i++) {
        //log_trace("for <-");
        //log_info("chamando init de DoublyLinkedList para inicializar cada lista do vetor");
        init(&(hashStruct->hashes[i]));
        log_debug("a posição %d do vetor foi inicializada", i);
    }
    //log_trace("for ->");

    hashStruct->size = 0;
    log_debug("hashStruct->size: %d", hashStruct->size); 
    log_trace("initHash ->\n");
}

int hash(char *key) {
    log_info("calculo: hash");
    log_trace("hash <-");
    log_debug("chave hash: %s", key);
    
    int sum = 0;
    //log_debug("criação da variavel sum que guardará o valor ASCII da string: %d", sum);

    //log_info("percorremos todos os caracteres da string passada");
    for (int i = 0; key[i]!=0; i++){
        //log_trace("for <-");
        //log_info("acumulamos os códigos ascii de cada letra com um peso");
        sum+=key[i]*(i+1);//ñ entendi o motivo de multiplicar o key por (i+1)
        //log_debug("sum = sum + key[i]*(i+1): %d", sum);

    }
    //log_trace("for ->");
    //log_debug("chave hash informada: %s", key);
    log_debug("MOD de key: %d", sum%MAX);
    log_trace("hash ->\n");
    return sum%MAX; //retorna o resto da divisão
}

bool containsKey(HashStruct *hashStruct, char *key, compare equal) {
    log_info("calcula a posição");
    log_trace("containsKey <-");


    int hashValue = hash(key);
    log_debug("hasValue armazena a posição da chave fornecida: %d", hashValue);
    
    log_info("chamada de indexOF que buscará na DoublyLinkedList a posição da chave");
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal);
    
    if(pos==-1){
        log_error("**Erro: a Chave NÃO ESTÁ NA LISTA!");
        log_trace("containsKey ->\n");
        return false;
    }
    else{
        log_debug("a chava ESTÁ NA LISTA, na posição: %d", pos);
        log_trace("containsKey ->\n");
        return true;
    }
}

int put(HashStruct *hashStruct, char *key, void *data, compare equal) {
    log_info("Add um hash na lista");
    log_trace("put <-");

    log_info("teste: a chave Ñ está na Lista?");
    if (containsKey(hashStruct, key, equal)==false) {
        log_trace("If <-");
        log_info("chamada de Enqueue que adicionará a chave na fila segundo a posição devolvida pela função hash");
        int res = enqueue(&hashStruct->hashes[hash(key)],data);
        
        //incrementa a qtde de elementos baseado na quantidade inserida por enqueue
        hashStruct->size+=res;
        log_debug("incrementaçao de hashStruct->size: %d", hashStruct->size);
        log_trace("If ->");
        log_trace("put -> \n");
        return res;
    }
    
    log_trace("put -> \n");
    return 0;
}

void* get(HashStruct *hashStruct, char *key, compare equal) {
    log_info("descobre em qual lista está um dado fornecido");
    log_trace("get <-");

    int hashValue = hash(key);
    log_debug("hasValue armazena a posição da chave fornecida: %d", hashValue);
    
    //first é nó sentinela, começamos do segundo nó
    Node *aux = hashStruct->hashes[hashValue].first->next;
    log_debug("Criação de aux que recebe hashStruct->hashes[hashValue].first->next: %p", aux);
    //log_info("aux recebeu o endereço de memória de hashStruct na posição da chave");
    
    log_info("Procurando o dado na lista");
    while(aux!=hashStruct->hashes[hashValue].first && !equal(aux->data, key)){
        log_trace("while <-");
        aux=aux->next;
        log_debug("aux recebe aux->next: %p", aux);
    }
    log_trace("while ->");
    log_trace("get -> \n");
    return aux->data;
}

void* removeKey(HashStruct *hashStruct, char *key, compare equal) {
    log_info("Apaga uma chave da lista");
    log_trace("removeKey <-");

    int hashValue = hash(key);
    log_debug("hasValue armazena a posição da chave fornecida: %d", hashValue);

    log_info("chamada de indexOF que buscará na DoublyLinkedList a posição da chave");
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal);
    
    void* result = removePos(&hashStruct->hashes[hashValue], pos);

    if (result!=NULL){
        hashStruct->size--;
        log_debug("decrementaçao de hashStruct->size: %d", hashStruct->size);
    }

    log_trace("removeKey <- \n");
    return result;
}

void showHashStruct(HashStruct *hashStruct, printNode print) {
    printf("There are %d elements in the Hash\n\n",hashStruct->size);
    for (int i=0; i < MAX; i++) {
        printf("Hash %d has %d elements: ",i,hashStruct->hashes[i].size);
        show(&hashStruct->hashes[i],print);
        printf("\n");
    }
}


