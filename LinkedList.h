#ifndef DataStructure_LinkedList_h
#define DataStructure_LinkedList_h
#include <stdbool.h>

//no que guarda os p
typedef struct Node {
  void *data;
  struct Node *next;
}Node;

//nó que guarda 
typedef struct LinkedList {
  Node *first;
  int size;
}LinkedList;

typedef bool (*compare)(void*,void*);

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

//adiciona vários elementos a partir de qualquer posição
int addAll(LinkedList *listDest, int pos, LinkedList *listSource);

//busca o endereço de um elemento em uma posição específica
Node* getNodeByPos(LinkedList *list, int pos);

//descobre a posição de um elemento específico
int indexOf(LinkedList *list, void *data, compare equal);

//?????????????????????????????????????????????????
void* getPos(LinkedList *list, int pos);

//remove o elemento de uma determinada posição
void* removePos(LinkedList *list, int pos);

//remove determinado dado da lista
bool removeData(LinkedList *list, void *data, compare equal);

#endif