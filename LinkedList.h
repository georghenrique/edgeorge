#ifndef DataStructure_LinkedList_h
#define DataStructure_LinkedList_h
#include <stdbool.h>

//definição do Tipo Node: responsavel por armazenar um dado e o endereço do proximo No da lista
typedef struct Node {
  void *data;
  struct Node *next;
}Node;

//definição do Tipo LinkedList: responsavel por armazenar o primeiro no da lista e sua quantidade de elementos
//definição do Tipo LinkedList: responsavel por armazenar o primeiro no da lista e sua quantidade de elementos
typedef struct LinkedList {
  Node *first;
  int size;
}LinkedList;

//definição de Tipo compare: responsavel por criar um tipo para passar funções com parametro, toda função será do tipo COMPARE se possuir um bool como retorno e possuir 2 void como parametro
typedef bool (*compare)(void*,void*);

//////////////////////////////////////////////////
//INPLEMENTAÇOES PARA FILA
//função inicializadora
void init(LinkedList *list);

//insere no final da fila
int enqueue(LinkedList *list, void *data);

//remove do início da fila
void* dequeue(LinkedList *list);

//consulta quem é o primeiro da fila
void* first(LinkedList *list);

//consulta quem é o último da fila
void* last(LinkedList *list);

//verifica se a fila está vazia
bool isEmpty(LinkedList *list);

//////////////////////////////////////////////////
//INPLEMENTAÇOES PARA PILHA
//insere no topo da pilha
int push(LinkedList *list, void *data);

//remove do topo da pilha
void* pop(LinkedList *list);

//consulta o topo da pilha
void* top(LinkedList *list);

//////////////////////////////////////////////////
//FUNÇOES DINAMICAS 

//adiciona em qualquer posição
int add(LinkedList *list, int pos, void *data);

//adiciona vários elementos a partir de qualquer posição, ou seja, add uma lista dentro de outra lista
int addAll(LinkedList *listDest, int pos, LinkedList *listSource);

//busca o endereço de um elemento em uma posição específica e retorna seu endereço
Node* getNodeByPos(LinkedList *list, int pos);

//busca o endereço de um elemento em uma posição específica e retorna o dado contido nessa posição
void* getPos(LinkedList *list, int pos);

//remove um elemento da lista com base em uma posição passada por referencia, retornando o dado contido nessa posição
void* removePos(LinkedList *list, int pos);

//remove um elemento da lista com base em um dado passado por referencia 
bool removeData(LinkedList *list, void *data, compare equal);

//recebe um dado e encontra sua posição dentro da lista
int indexOf(LinkedList *list, void *data, compare equal);

#endif