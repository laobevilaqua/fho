#include <stdio.h>
#include <stdlib.h>
// 22246271		1162	Train Swapping	Accepted	C++17	0.110	4/9/21, 3:32:28 PM
int bubbleSort(int vetor[], int n);

int main(int argc)
{
    int n = 0, l = 0, i = 0, y = 0, troca = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &l);
        int num[l];
        for (y = 0; y < l; y++)
        {
            scanf("%d", &num[y]);
        }
        troca = bubbleSort(num, l);
        printf("Optimal train swapping takes %d swaps.\n", troca);
    }
    return 0;
}

int bubbleSort(int vetor[], int n)
{
    int k, j, aux, troca = 0;

    for (k = 0; k < n - 1; k++)
    {
        for (j = 0; j < n - k - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
                troca++;
            }
        }
    }
    return troca;
}