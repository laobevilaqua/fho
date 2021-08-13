#include <stdio.h>
#include <stdlib.h>
#include "header.h"

//função Moisés
void moises(Tabble *vetor, int inicio, int fim)
{
    int pivo;
    if (fim > inicio)
    {
        pivo = quickSort(vetor, inicio, fim);
        moises(vetor, inicio, pivo - 1);
        moises(vetor, pivo + 1, fim);
    }
}

// função quickSort por indice
int quickSort(Tabble *vetor, int inicio, int final)
{
    int esq, dir;
    Tabble aux, pivo;
    esq = inicio;
    dir = final;
    pivo = vetor[inicio];
    while (esq < dir)
    {
        while (vetor[esq].indice <= pivo.indice)
            esq++;
        while (vetor[dir].indice > pivo.indice)
            dir--;
        if (esq < dir)
        {
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
        }
    }
    vetor[inicio] = vetor[dir];
    vetor[dir] = pivo;

    return dir;
}

void moisesByYear(Tabble *vetor, int inicio, int fim)
{
    int pivo;
    if (fim > inicio)
    {
        pivo = quickSortByYear(vetor, inicio, fim);
        moisesByYear(vetor, inicio, pivo - 1);
        moisesByYear(vetor, pivo + 1, fim);
    }
}

int quickSortByYear(Tabble *vetor, int inicio, int final)
{
    int esq, dir;
    Tabble aux, pivo;
    esq = inicio;
    dir = final;
    pivo = vetor[inicio];
    while (esq < dir)
    {
        while (vetor[esq].ano <= pivo.ano)
            esq++;
        while (vetor[dir].ano > pivo.ano)
            dir--;
        if (esq < dir)
        {
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
        }
    }
    vetor[inicio] = vetor[dir];
    vetor[dir] = pivo;

    return dir;
}