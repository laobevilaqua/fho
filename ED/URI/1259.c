#include <stdio.h>
#include <stdlib.h>
// 22337422		1259	Even and Odd	Accepted	C++	0.035	4/14/21, 3:47:26 PM
void printArray(int A[], int size);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

int main() {
 
    int i, N, v[100000];
 
    scanf("%d", &N);

    for (i = 0; i<N; i++){
        scanf("%d", &v[i]);
    }
    mergeSort(v,0,N-1);

    printArray(v,N);

    return 0;
}

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++){
        if (A[i] %2 == 0){
            printf("%d\n", A[i]);   
        }
    }

    for (int i = size-1; i >= 0; i--){
        if (A[i] %2 != 0){
            printf("%d\n", A[i]);   
        }
    }
}
 

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}