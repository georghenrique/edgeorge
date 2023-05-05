#ifndef EstruturaDeDados_Hash_h
#define EstruturaDeDados_Hash_h
#include "DoublyLinkedList.h"

//Bloco para escolha do tamanho da tabela hash
//#define MAX 10000 // tabela 100 x 100
//#define MAX 4900 // tabela 70 x 70
//#define MAX 3025 // tabela 55 x 55
//#define MAX 900   // tabela  30 x 30



typedef struct HashStruct {
    DoublyLinkedList hashes[MAX];
    int size;
}HashStruct;

void initHash(HashStruct *hashStruct);
bool isHashEmpty(HashStruct *hashStruct);
int hash(char *key);
int put(HashStruct *hashStruct, char *key, void *data, compare equal);
bool containsKey(HashStruct *hashStruct, char *key, compare equal);
void* get(HashStruct *hashStruct, char *key, compare equal);
void* removeKey(HashStruct *hashStruct, char *key, compare equal);

//Gera arquivo no formato PPM para visuzalização do espalhamento da hash.
void mapaEspalhamento(HashStruct *hashStruct);
int raiz_Qd();
//void showHashStruct(HashStruct *hashStruct);

#endif