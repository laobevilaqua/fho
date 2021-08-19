#include <stdio.h>
#include <stdlib.h>

typedef struct _no {
    int dado;
    struct _no *pai;
    struct _no *esq;
    struct _no *dir;
} NO;

void preOrdem (NO *tree);
void posOrdem (NO *tree);
void emOrdem (NO *tree);

void preOrdem (NO *tree) {
    if (tree != NULL) {
        printf("%d ", tree->dado);
        preOrdem(tree->pai);
        preOrdem(tree->esq);
        preOrdem(tree->dir);
    }
}

void posOrdem (NO *tree) {
    if (tree != NULL) {
        printf("%d ", tree->dado);
        preOrdem(tree->esq);
        preOrdem(tree->dir);
        preOrdem(tree->pai);
    }
}

void emOrdem (NO *tree) {
    if (tree != NULL) {
        printf("%d ", tree->dado);
        preOrdem(tree->esq);
        preOrdem(tree->pai);
        preOrdem(tree->dir);
    }
}