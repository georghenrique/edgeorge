#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"
#include "log.h"


typedef struct Cliente {
    char nome[50];
    char email[50];
}Cliente;

bool comparaChaves(void *key, void *data) {
    log_info("comparando chaves");
    log_trace("comparaChaves <-");
    
    char *chave = (char*)key;
    Cliente *c = (Cliente*)data;
    
    if(strcmp (chave, c->email) == 0){
    log_info("Usando strcmp que as strings são igauis");
    log_trace("comparaChaves ->\n");
    return true;
    }
    else{
        log_info("Usando strcmp que as strings NÃO são igauis");
        log_trace("comparaChaves ->\n");
        return false;
    }
}

void printCliente(void *data) {
    Cliente *cliente = (Cliente*)data;
    printf("{%s,%s} - ", cliente->nome, cliente->email);
}

int main() {
    log_info("Criação da var hashes do tipo HashStruct");
    HashStruct hashes;
    
    log_info("Chamada a função initHash");
    initHash(&hashes);

    printf("%d\n", hash("george"));
    printf("%d\n", hash("GH@email.com"));
    
    
    log_info("");


    log_info("criação de um ponteiro c do tipo cliente");
    Cliente *c = (Cliente *)malloc(sizeof(Cliente));
    log_debug("*c foi alocada dimanicamente: %p", c);

    strcpy(c->nome,"george");
    strcpy(c->email,"GH@email.com");
    log_debug("strcpy atribui a string george em c->nome: %s", c->nome);
    log_debug("strcpy atribui a string GH@email.com em c->email: %s", c->email);
    
    log_info("chamada de put");
    put(&hashes, c->email, c, comparaChaves);

    log_info("teste para saber se deu certo");

    put(&hashes, c->email, c, comparaChaves);



   /* 
    
    printf("%d\n",hash(c->email));
    printf("%d\n",hashes.hashes[hash("joao.preti@cba.ifmt.edu.br")].size);
    printf("%d\n",hashes.size);
    printf("%d\n",containsKey(&hashes, "joao.preti@cba.ifmt.edu.br", comparaChaves));
    Cliente *cliente = (Cliente*)get(&hashes, "joao.preti@cba.ifmt.edu.br", comparaChaves);
    printf("%s\n",cliente->nome);
    c = (Cliente *)malloc(sizeof(Cliente));
    strcpy(c->nome,"Maria") ;
    strcpy(c->email,"maria@email.br");
    put(&hashes, c->email, c, comparaChaves);
    c = (Cliente *)malloc(sizeof(Cliente));
    strcpy(c->nome,"Pedro") ;
    strcpy(c->email,"pedro@email.com.br");
    put(&hashes, c->email, c, comparaChaves);
    c = (Cliente *)malloc(sizeof(Cliente));
    strcpy(c->nome,"Carla") ;
    strcpy(c->email,"carla@gmail.com.br");
    put(&hashes, c->email, c, comparaChaves);
    //showHashStruct(&hashes, printCliente);*/
    return 0;
}