all: clean ponteiro ponteiro_duplo linkedlist

ponteiro:
	@echo
	@echo ==========================
	@echo      PONTEIRO SIMPLES
	@echo ==========================
	@echo Compilando o programa ponteiros
	gcc ponteiro.c -o ponteiro
	@echo Tornando o arquivo executável
	chmod +x ponteiro
	@echo Executando o programa ponteiros
	@echo ======================================================
	@echo
	./ponteiro

ponteiro_duplo:
	@echo
	@echo ==========================
	@echo      PONTEIRO DUPLO
	@echo ==========================
	@echo Compilando o programa ponteiro duplo
	gcc ponteiro_duplo.c -o ponteiro_duplo
	@echo Tornando o arquivo executável
	chmod +x ponteiro_duplo
	@echo Executando o programa ponteiro duplo
	@echo ======================================================
	@echo
	./ponteiro_duplo

linkedlist:
	@echo
	@echo ==========================
	@echo      LISTA SIMPLES
	@echo ==========================
	@echo Compilando o programa linkedlist
	gcc --std=c99 -DLOG_USE_COLOR log.h log.c LinkedList.h LinkedList.c LinkedListTest.c -o linkedlist
	@echo Tornando o arquivo executável
	chmod +x linkedlist
	@echo Executando o programa linkedlist
	@echo ======================================================
	@echo
	./linkedlist

clean:
	@echo
	@echo ==========================
	@echo APAGANDO TODOS OS PROGRAMAS
	@echo ==========================
	@echo Removendo o programa ponteiro
	rm -f ponteiro
	@echo Removendo o programa ponteiro duplo
	rm -f ponteiro_duplo
	@echo Removendo o programa linkedlist
	rm -f linkedlist
	@echo Removendo o programa doublylinkedlist
	rm -f doublylinkedlist
	
doublylinkedlist:
	@echo
	@echo ==========================
	@echo      LISTA DUPLA
	@echo ==========================
	@echo Compilando o programa doublylinkedlist
	gcc --std=c99 -DLOG_USE_COLOR log.h log.c DoublyLinkedList.h DoublyLinkedList.c DoublyLinkedListTest.c -o doublylinkedlist
	@echo Tornando o arquivo executável
	chmod +x doublylinkedlist
	@echo Executando o programa doublylinkedlist
	@echo ======================================================
	@echo
	./doublylinkedlist

hash:
	@echo
	@echo ======================================================
	@echo    				  HASH
	@echo ======================================================
	@echo Compilando o programa hash
	gcc --std=c99 -DLOG_USE_COLOR log.h log.c Hash.h Hash.c HashTest.c -o hash
	@echo Tornando o arquivo executável
	chmod +x hash
	@echo Executando o programa hash
	@echo ======================================================
	@echo
	./hash

hash1:
	@echo
	@echo ======================================================
	@echo    				  HASH Trabalho
	@echo ======================================================
	@echo Compilando o programa hash
	gcc --std=c99 -DLOG_USE_COLOR log.h log.c Hash.h Hash1.c HashTest1.c -o hash1
	@echo Tornando o arquivo executável
	chmod +x hash1
	@echo Executando o programa hash1
	@echo ======================================================
	@echo
	./hash1

tree:
	@echo
	@echo ======================================================
	@echo    				  ARVORE BINARIA
	@echo ======================================================
	@echo Compilando o programa tree
	gcc --std=c99 -DLOG_USE_COLOR log.h log.c BinarySearchTree.h BinarySearchTree.c BinarySearchTreeTest.c -o tree
	@echo Tornando o arquivo executável
	chmod +x tree
	@echo Executando o programa tree
	@echo ======================================================
	@echo
	./tree		