#include "BinarySearchTree.h"
#include "log.h"

int add(TreeNode **root, void *element, TreeComparator f) {
    log_info("add novo nó");
    log_trace("add <-");
    
    if ((*root) == NULL) {
        log_info("alcançou o local da folha, atualiza o pai");
        log_info("criação de novo Nó: FOLHA");
        TreeNode *newnode = (TreeNode *) malloc(sizeof(TreeNode));
        
        if (newnode == NULL){
            log_error("**ERRO: nó NÃO alocado");
            log_debug("newnode: %p", newnode);
            log_trace("add -> \n");
            return 0;
        }

        newnode->element = element;
        newnode->left = newnode->right = NULL;
        *root = newnode;
        log_debug("newnode->left e newnode->right recebem NULL ");
        log_info("**Folha add com sucesso**");
        log_trace("add -> \n");
        return 1;
    }

    log_info("chamada da função que verifica se o elemente já existe na arvore");
    int compvalue = f(element, (*root)->element);
    if (compvalue > 0){
        log_info("compvalue é maior que (*root)->element");
        log_info("add é chamado novamente para adicionar o Nó a DIREITA da arvore");
        return add(&(*root)->right, element, f);
    }
    else
        if (compvalue < 0) {
            log_info("compvalue é menor que (*root)->element");
            log_info("add é chamado novamente para adicionar o Nó a ESQUERDA da arvore");
            return add(&(*root)->left, element, f);
        }
    else
        if(compvalue == 0){
            log_error("**ERRO: o elemento já se encontra na lista");
            log_trace("add -> \n");
            return -1;
    }
}

int find(TreeNode *root, void *key, TreeComparator f, void **element) {
    // Passamos a folha
    if (root == NULL){
        log_error("**ERRO: chave não encontrada n arvore");
        log_debug("root: %p", root);
        log_trace("find -> \n");
        return 0;
    }
    log_info("chamada da função que compara elementos");
    int compvalue = f(key, root->element);
    if (compvalue == 0) {
        log_info("Valor LOCALIZADO");
        *element = root->element;//DUVIDA- pq o valor é atribuido a um pondeiro duplo
        log_trace("find -> \n");
        return 1;
    }
    // desce no nível da árvore
    if (compvalue > 0){
        log_info("compvalue é MAIOR que zero, deceremos a DIREITA na arvore");
        return find(root->right, key, f, element);
    }
    if (compvalue < 0){
        log_info("compvalue é MENOR que zero, deceremos a ESQUERDA na arvore");
        return find(root->left, key, f, element);
    }
}

//Imprime os elementos na ordem Esquerda Raiz Direita
void in_order(TreeNode *root, printNode print) {
    if (root!=NULL) {
        in_order(root->left, print);//esquerda
        print(root->element);
        in_order(root->right, print);//direita
    }
}

//Imprime os elementos Raiz Esquerda Direita
void pre_order(TreeNode *root, printNode print) {
    if (root!=NULL) {
        print(root->element);
        pre_order(root->left, print);
        pre_order(root->right, print);
    }
}

//Imprime os elementos Esquerda Direita Raiz
void post_order(TreeNode *root, printNode print) {
    if (root!=NULL) {
        post_order(root->left, print);
        post_order(root->right, print);
        print(root->element);
    }
}

TreeNode *greaterRight(TreeNode **no){
    if((*no)->right != NULL)
        return greaterRight(&(*no)->right);
    else{
        TreeNode *aux = *no;
        if((*no)->left != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
            *no = (*no)->left;
        else
            *no = NULL;
        return aux;
    }
}

int removeTreeNode(TreeNode **root, void *key, TreeComparator f) {
    if(*root == NULL){ // caso a chave nao exista na arvore
        return 0;
    }
    int compvalue = f(key, (*root)->element);
    if(compvalue < 0)
        removeTreeNode(&(*root)->left, key, f);
    else {
        if(compvalue > 0) {
            removeTreeNode(&(*root)->right, key, f);
        } else { // se nao eh igual
            TreeNode *aux = *root;
            // Se nao tem filhos
            if (((*root)->left == NULL) && ((*root)->right == NULL)){
                free(aux);
                (*root) = NULL;
            } else { // so tem o filho da direita
                if ((*root)->left == NULL){
                    (*root) = (*root)->right;
                    aux->right = NULL;
                    free(aux); aux = NULL;
                } else { //so tem filho da esquerda
                    if ((*root)->right == NULL){
                        (*root) = (*root)->left;
                        aux->left = NULL;
                        free(aux); aux = NULL;
                    } else { //Busco o maior filho à direita da subarvore esquerda.
                        aux = greaterRight(&(*root)->left);
                        aux->left = (*root)->left;
                        aux->right = (*root)->right;
                        (*root)->left = (*root)->right = NULL;
                        free((*root)); *root = aux; aux = NULL;
                    }
                }
            }
        }
    }
    return 1;
}

//tenho duvida sobre o funcionamento 
int height (TreeNode *root) {
    //log_info("verificando a altura da arvore");
    log_trace("height <-");
    if (root == NULL){
        //log_error("**ERRO: a arvore está vazia!");
        //log_trace("height ->\n");
        return -1;
    }
    else {
        
        int hl = height(root->left); //altura esquerda
        int hr = height(root->right); //altura direita
        if (hl < hr) return hr + 1;
        else return hl + 1;
    }
}

//navegar em pos-ordem
void destroy (TreeNode **root) {
    if (*root==NULL) return;
    destroy(&(*root)->left);
    destroy(&(*root)->right);
    free(*root);
    *root=NULL;
}
