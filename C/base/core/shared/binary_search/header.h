#ifndef Binary_Search_H

typedef struct _row{
    int ano;
    float indice;
}row;

#define Binary_Search_H
/* declaracoes das funcoes de lista */
int binarySearchUpward(row *vet, int ini,int fim, int RAbusca);
int binarySearchDecreasing(row *vet, int ini,int fim, int RAbusca);

#endif
