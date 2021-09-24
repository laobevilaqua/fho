#include <stdio.h>
#include <stdlib.h>

typedef struct _no
{
    int ID;
    struct no *pai;
    struct no *esq;
    struct no *dir;
} No;

int listaArvoreVazia(No *r){
	if(r == NULL)
		return 1;
		
	return 0;
} 

int pegaDado(No *r) {
    return r->ID;
}

void ehBST(No *r) {
    if(!listaArvoreVazia(r) && pegaDado(r->esq) < r->ID &&  r->ID < pegaDado(r->dir)){
        ehBST(r->dir);
        ehBST(r->esq);
        return 0;
	}

    return 1;
}