#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "header.h"

// Menu para lista encadeada
void showMenuLinkedList(void (*callback)(int *)) {
    int optionSelected;

    printf("------------------------------------------\n\n");

    do {
        system("cls");
        printf("Main Menu\n");

        printf("1. Exibir todos os dados capiturados.\n");
        printf("2. Pesquisar o indice com base no ano.\n");
        printf("3. Exibir os 10 anos com melhores indices de PIB.\n");
        printf("4. Exibir os 10 anos com piores indices de PIB.\n");
        printf("5. Atualizar dados do arquivo.\n");
        printf("6. Gerar arquivo `report.txt` com todos os relatios do PIB.\n");
        printf("0. Encerrar programa.\n");
        
        printf("  Por favor digite a opção de desejo do 'Main Menu': \n");
        scanf("%d",&optionSelected);
        printf("\n");

        callback(optionSelected);
        
        if(optionSelected != 0) {
            printf("\nPressione qualquer tecla para processeguir.\nObs: a tela sera limpa");
            getch();
        }
    } while(optionSelected != 0);
}

// Menu para BST
void showMenuBST(void (*callback)(int *)) {
    int optionSelected;

    printf("------------------------------------------\n\n");

    do {
        system("cls");
        printf("Main Menu\n");

        printf("1. Exibir todos os dados capiturados em ordem.\n");
        printf("2. Exibir todos os dados capiturados em pós ordem.\n");
        printf("3. Exibir todos os dados capiturados em pré ordem.\n");
        printf("4. Pesquisar arvore com base no valor.\n");
        printf("5. Atualizar dados do arquivo.\n");
        printf("0. Encerrar programa.\n");
        
        printf("  Por favor digite a opção de desejo do 'Main Menu': \n");
        scanf("%d",&optionSelected);
        printf("\n");

        callback(optionSelected);
        
        if(optionSelected != 0) {
            printf("\nPressione qualquer tecla para processeguir.\nObs: a tela sera limpa");
            getch();
        }
    } while(optionSelected != 0);
}
