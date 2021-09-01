#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int binarySearchUpward(row *vet, int ini,int fim, int idBusca){
    int i, meio;

    meio = (int) (ini+fim)/2;

    if(vet[meio].ano == idBusca)
        return meio;
    if (ini >= fim)
        return -1;
    if(idBusca < vet[meio].ano)
        binarySearchUpward(vet, ini, meio-1, idBusca);
    else
        binarySearchUpward(vet, meio+1, fim, idBusca);
}

int binarySearchDecreasing(row *vet, int ini,int fim, int idBusca){
    int i, meio;

    meio = (int) (ini+fim)/2;

    if(vet[meio].ano == idBusca)
        return meio;
    if (ini >= fim)
        return -1;
    if(idBusca > vet[meio].ano)
        binarySearchDecreasing(vet, ini, meio-1, idBusca);
    else
        binarySearchDecreasing(vet, meio+1, fim, idBusca);
}