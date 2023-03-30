#ifndef DataStructure_DoublyLinkedList_h
#define DataStructure_DoublyLinkedList_h //funcao que testa se a biblioteca já foi incluida pelo menos uma vez
#include <stdbool.h>

//definição do Tipo Node: responsavel por armazenar um dado e o endereço do proximo No (next) e o No anterior (previous) da lista
typedef struct Node {
    void *data;
    struct Node *previous;
    struct Node *next;
}Node;

//definição do Tipo DoublyLinkedList: responsavel por armazenar o primeiro no da lista e sua quantidade de elementos
typedef struct DoublyLinkedList {
    Node *first;
    int size;
}DoublyLinkedList;

//definição de Tipo compare: responsavel por criar um tipo para passar funções com parametro, toda função será do tipo COMPARE se possuir um bool como retorno e possuir 2 void como parametro
typedef bool (*compare)(void*,void*);

typedef void (*printNode)(void*); //que isso??????????????????????????????????????????/

//////////////////////////////////////////////////
//INPLEMENTAÇOES PARA FILA
//função inicializadora
void init(DoublyLinkedList *list);

//insere no final da fila
int enqueue(DoublyLinkedList *list, void *data);

//remove do início da fila
void* dequeue(DoublyLinkedList *list);

//consulta quem é o primeiro da fila
void* first(DoublyLinkedList *list);

void* last(DoublyLinkedList *list);

int push(DoublyLinkedList *list, void *data);

void* pop(DoublyLinkedList *list);

void* top(DoublyLinkedList *list);

bool isEmpty(DoublyLinkedList *list);

int indexOf(DoublyLinkedList *list,void *data, compare equal);

Node* getNodeByPos(DoublyLinkedList *list,int pos);

void* getPos(DoublyLinkedList *list,int pos);

int add(DoublyLinkedList *list, int pos, void *data);

int addAll(DoublyLinkedList *listDest, int pos, DoublyLinkedList *listSource);

void* removePos(DoublyLinkedList *list, int pos);

bool removeData(DoublyLinkedList *list, void *data, compare equal);

void show(DoublyLinkedList *list, printNode print);

void showMem(DoublyLinkedList *list);

#endif