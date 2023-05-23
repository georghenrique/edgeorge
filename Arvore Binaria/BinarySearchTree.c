#include "BinarySearchTree.h"
#include "log.h"

int add(TreeNode **root, void *element, TreeComparator f) {
    log_info("add novo nó");
    log_trace("add <-");
    
    if ((*root) == NULL) {
        log_info("alcançou o local da folha, atualiza o pai");
        TreeNode *newnode = (TreeNode *) malloc(sizeof(TreeNode));
        
        if (newnode == NULL){
            log_error("**ERRO: nó NÃO alocado");
            log_debug("newNode: %p", newNode);
            log_trace("add -> \n");
            return 0;
        }

        newnode->element = element;
        newnode->left = newnode->right = NULL;
        *root = newnode;
        log_trace("add -> \n");
        return 1;
    }
    int compvalue = f(element, (*root)->element);
    if (compvalue > 0) {
        return add(&(*root)->right, element, f);
    } else if (compvalue < 0) {
        return add(&(*root)->left, element, f);
    } else {
        return -1;
    }
}