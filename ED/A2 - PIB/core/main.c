#include <stdio.h>
#include "shared/menu/main.c"
#include "shared/quick_sort/main.c"
#include "shared/binary_search/main.c"
#include "shared/file_control/main.c"
#include "header.h"

Tabble vetor[VET_LENGTH];

void selectedOptionMenu(int optionId) {
    switch(optionId){
        case 1:
            moisesByYear(vetor, 0, VET_LENGTH);
            printVetor(VET_LENGTH);
            break;
        case 2:
            searchPIBByYear();
            break;
        case 3:
            orderUpwardPIB();
            break;
        case 4:
            orderDecreasingPIB();
            break;
        case 5:
            getDataAndOrder();
            break;
        case 6:
            moises(vetor, 0, VET_LENGTH);
            generateReport();
            break;
        case 0:
            break;
        default:
            printf("invalid input");
            break;
    }
}

void getDataAndOrder() {
    getDataFile("assets/economy.txt", buildTable);
    moisesByYear(vetor, 0, VET_LENGTH);
}

void printVetor(int count) {
    for (int i = 0; i <= count; i++)
    {
       printf("Ano: %d  PIB: %.2f\n", vetor[i].ano, vetor[i].indice);
    }
}

void buildTable(FILE *file, int lines) {
    Tabble tab;	
   
    fscanf(file, "%d %f", &tab.ano, &tab.indice);
    vetor[lines] = tab;
}

void searchPIBByYear() {
    printf("Qual ano você deseja ver a taxa de crescimento per capita ?\n");
    scanf("%d", &searchYear);

    index = binarySearchUpward(vetor, 0, VET_LENGTH, searchYear);

    if(index >= 0) {
        printf("O indice do ano %d foi de: %.2f", searchYear, vetor[index].indice);
    } else {
        printf("Não foi encontrado o ano digitado.");
    }
}

void orderUpwardPIB() {
    moises(vetor, 0, VET_LENGTH);

    printf("Os 10 anos com maior PIB foram:\n");

    for (int i = VET_LENGTH; i >= (VET_LENGTH - 10 ); i--)
    {
       printf("Ano: %d PIB: %.2f\n", vetor[i].ano, vetor[i].indice);
    }
}

void orderDecreasingPIB() {
    moises(vetor, 0, VET_LENGTH);

    printf("Os 10 anos com menor PIB foram:\n");

    printVetor(9);
}

void generateReport() {
    FILE * arqSai;
	arqSai = fopen("assets/report.txt", "w");
 

    fprintf(arqSai, "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2PIB do Brasil nos ultimos 50 anos.\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    fprintf(arqSai, "+===================================|\n");
    fprintf(arqSai, "|\t  TOP 10 ANOS COM MAIOR PIB\t\t|\n");
    fprintf(arqSai, "|\t\tANO \t\tINDICE\t\t\t|\n");
    fprintf(arqSai, "+===================================|\n");

    for (int i = VET_LENGTH; i >= (VET_LENGTH - 10 ); i--)
    {
    	fprintf(arqSai, "|\t\t%d\t\t%.2f \t\t\t|\n", vetor[i].ano, vetor[i].indice);
    }

    fprintf(arqSai, "+-----------------------------------+\n");
    fprintf(arqSai, "\n+===================================|\n");
    fprintf(arqSai, "|\t  OS 10 ANOS COM MENOR PIB\t\t|\n");
    fprintf(arqSai, "|\t\tANO \t\tINDICE\t\t\t|\n");
    fprintf(arqSai, "+===================================|\n");

    for (int i = 0; i < 10; i++)
    {
    	fprintf(arqSai, "|\t\t%d\t\t%.2f \t\t\t|\n", vetor[i].ano, vetor[i].indice);
    }
    fprintf(arqSai, "+-----------------------------------+\n");

	fclose (arqSai);

    printf("\nArquivo Criado em %s.", "assets/report.txt");
}
