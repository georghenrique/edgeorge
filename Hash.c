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
        log_trace("for <-");
        log_info("chamando init de DoublyLinkedList para inicializar cada lista do vetor");
        init(&(hashStruct->hashes[i]));
        log_debug("a posição %d do vetor foi inicializada", i);
    }
    log_trace("for ->");

    hashStruct->size = 0;
    log_debug("hashStruct->size: %d", hashStruct->size); 
    log_trace("initHash ->\n");
}


int hash(char *key) {
    log_info("calculo: hash");
    log_trace("hash <-");
    
    int sum = 0;
    log_debug("criação da variavel sum que guardará o valor ASCII da string %d", sum);

    log_info("percorremos todos os caracteres da string passada");
    for (int i = 0; key[i]!=0; i++){
        log_trace("for <-");
        log_info("acumulamos os códigos ascii de cada letra com um peso");
        sum+=key[i]*(i+1);//ñ entendi o motivo de multiplicar o key por (i+1)
        log_debug("sum = sum + key[i]*(i+1): %d", sum);

    }
    log_trace("for ->");
    log_debug("MOD de sum: %d", sum%MAX);
    log_trace("hash ->\n");
    return sum%MAX; //retorna o resto da divisão
}

bool containsKey(HashStruct *hashStruct, char *key, compare equal) {
    //calcula a posição
    int hashValue = hash(key);
    //busca na fila a posição da chave
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal);
    return (pos!=-1)?true:false;
}

int put(HashStruct *hashStruct, char *key, void *data, compare equal) {
    if (!containsKey(hashStruct, key, equal)) {
        //adiciona na fila que está na posição devolvida pela função hash
        int res = enqueue(&hashStruct->hashes[hash(key)],data);
        //incrementa a qtde de elementos baseado na quantidade inserida por enqueue
        hashStruct->size+=res;
        return res;
    }
    return 0;
}

void* get(HashStruct *hashStruct, char *key, compare equal) {
    // descobre em qual fila/lista está o dado
    int hashValue = hash(key);
    //first é nó sentinela, começamos do segundo nó
    Node *aux = hashStruct->hashes[hashValue].first->next;
    // procuramos o dado na lista
    while(aux!=hashStruct->hashes[hashValue].first && !equal(aux->data, key))
        aux=aux->next;
    return aux->data;
}

void* removeKey(HashStruct *hashStruct, char *key, compare equal) {
    int hashValue = hash(key);
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal);
    void* result = removePos(&hashStruct->hashes[hashValue], pos);
    if (result!=NULL) hashStruct->size--;
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


