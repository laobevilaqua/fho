#include "menu/main.c"
#include "file_control/main.c"
#include "bst/main.c"
#include "header.h"

// BST
Arvore *arvore; 

void selectedOptionMenu(int optionId) {
    switch(optionId){
        case 1:
            imprimeEmOrdem(arvore);
            break;
        case 2:
            imprimePosOrdem(arvore);
            break;
        case 3:
            imprimePreOrdem(arvore);
            break;
        case 4:
            pesquisarValorDoEstado();
            break;
        case 5:
            getDataAndOrder();
            break;
        case 0:
            break;
        default:
            printf("invalid input");
            break;
    }
}

void getDataAndOrder() {
    inicializaLista(&arvore);
    getDataFile("assets/ods-brasil.txt", buildBST);
}

void buildBST(FILE *file, int lines) {
    float dado1, dado2, dado3, dado4, dado5;
    char uf[3];

    fscanf(file, "%s %f %f %f %f %f", &uf, &dado1, &dado2, &dado3, &dado4, &dado5);
    
    inserirValor(&arvore, uf, dado1, dado2, dado3, dado4, dado5);
}

void pesquisarValorDoEstado() {
    char valor[3];

    printf("Digite o valor que será buscado (utilize ','):\n");
    scanf("%c", &valor);
    Arvore *arvoreEncontrada = pesquisarValor(arvore, valor);
    
    printf("Valor encontrado na arvore! Segue os dados linkados a esse valor\n");
    imprimeDado(arvore);
}
