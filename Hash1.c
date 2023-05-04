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
    //log_info("calculo: hash");
    log_trace("hash <-");
    //log_debug("chave hash: %s", key);
    
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
    log_debug("MOD de %s: %d", key, sum%MAX);
    log_trace("hash ->");
    return sum%MAX; //retorna o resto da divisão
}
/*
int hash(char *key) {
    unsigned long hash = 5381;
    int c;
    while ((c = *key++))
        hash = c + (hash << 6) + (hash << 16) - hash;
        return hash % MAX;
}*/

bool containsKey(HashStruct *hashStruct, char *key, compare equal) {
    log_info("calcula a posição");
    log_trace("containsKey <-");


    int hashValue = hash(key);
    //log_debug("hasValue armazena a posição da chave fornecida: %d", hashValue);
    
    //log_info("chamada de indexOF que buscará na DoublyLinkedList a posição da chave");
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal);
    
    if(pos==-1){
        log_error("**Erro: a Chave NÃO ESTÁ NA LISTA!");
        log_trace("containsKey ->");
        return false;
    }
    else{
        log_debug("a chave ESTÁ NA LISTA, na posição: %d", pos);
        log_trace("containsKey ->");
        return true;
    }
}

int put(HashStruct *hashStruct, char *key, void *data, compare equal) {
    log_info("Add um hash na lista");
    log_trace("put <-");

    log_info("Chamada de containsKey para testar se chave Ñ está na Lista");
    /*if (containsKey(hashStruct, key, equal)==false) {
        log_trace("If <-");
        log_info("chamada de Enqueue que adicionará a chave na fila segundo a posição devolvida pela função hash");*/
        int res = enqueue(&hashStruct->hashes[hash(key)],data);
        
        //incrementa a qtde de elementos baseado na quantidade inserida por enqueue
        hashStruct->size+=res;
        log_debug("incrementaçao de hashStruct->size: %d", hashStruct->size);
        log_trace("If ->");
        log_trace("put -> \n");
        return res;
    //}
    
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

void mapaEspalhamento(HashStruct *hashStruct){
    log_info("Gerador de .PPM");
    log_trace("mapaEspalhamento <-");
    int var;//Variavel para receber o valor da cor do ppm
    int dim_tab=raiz_Qd(); //Variavel que recebe a dimensão da matriz
    FILE *imageFile; //criação do arquivo do tipo FILE
    int larg=dim_tab;
    int alt=dim_tab;
    log_debug("a matriz tem a dimensão %d X %d", larg, alt);
    log_info("Criação e abertura de um Arquivo imagem.ppm");
    imageFile = fopen("imagem.ppm","wb");
    if(imageFile==NULL){
        log_error("ERRO** o arquivo Ñ foi aberto!");
        return -3;
    }
    
    log_info("Escreve o cabeçalho do arquivo");
    //fprintf(imageFile, "P3\n%d %d\n255\n", larg, alt);
    fprintf(imageFile,"P3\n");               // P3 tipo do PPM
    fprintf(imageFile,"%d %d\n",larg,alt);   // dimensão da imagem
    fprintf(imageFile,"255\n");              // Valor máximo da cor em RGB

    for (int i=0; i < MAX; i++) {
        //Caso a lista não esteja vazia, é escrito no PPM uma variação de cor conforme a quantidade de elementos.
        if ((hashStruct->hashes[i].size)!= 0){  
            if ((hashStruct->hashes[i].size) >= 1){
                var=255/(hashStruct->hashes[i].size);
                fprintf(imageFile,"0 %d 0\n",var);//Impressão da variação de cor.
            }
        }else//Caso a posição da hash esteja vazia, imprima a cor mais clara possível.
            fprintf(imageFile,"241 255 162\n");
    }
    log_info("Arquivo PPM gerado com sucesso !!");
    log_trace("mapaEspalhamento ->\n");
    fclose(imageFile);
}

int raiz_Qd(){
    log_info("Calculo de raiz");
    log_trace("raiz_Qd <-");
    int n;
    float result = MAX;
   
    for (n = 0; n < 10; ++n)
          result = result/2 + MAX/(2*result);
    
    log_trace("raiz_Qd ->");       
    return(result);    
}    



