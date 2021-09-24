#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "header.h"

// Menu para BST
void showMenu(void (*callback)(int *)) {
    int optionSelected;

    printf("------------------------------------------\n\n");

    do {
        system("cls");
        printf("Main Menu\n");
        printf("1. Exibir todos os dados capiturados em ordem (Considerando o ultimo ano como referencia).\n");
        printf("2. Exibir todos os dados capiturados em pos ordem (Considerando o ultimo ano como referencia).\n");
        printf("3. Exibir todos os dados capiturados em pre ordem (Considerando o ultimo ano como referencia).\n");
        printf("4. Pesquisar arvore com base no valor.\n");
        printf("5. Atualizar dados do arquivo.\n");
        printf("6. Remover estado da BST.\n");
        // printf("7. Limpar BST.\n");
        printf("7. Pesquisar media da ODS no brasil por ano.\n");
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
