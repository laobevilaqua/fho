#include <stdio.h>
#include <locale.h>
#include "core/main.c"

int main () {
    setlocale(LC_ALL, "portuguese-brazilian");

    // Menu e arquivo de lista encadeada
    // getDataAndOrder();
    // showMenuLinkedList(selectedOptionMenu);
    
    // Menu e arquivo de BST
    getDataAndOrderBST();
    showMenuBST(selectedOptionMenuBST);
   
    return 0;
}
