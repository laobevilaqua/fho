#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// função para ler um arquivo.
// filePath: caminho para o arquivo.
// callback: função de retorno que recebe a linha do arquivo e a quantagem de linhas.
void getDataFile(char *filePath, void (*callback)(FILE *, int)) {
	FILE * arqEnt;
    int lines = 0, lastChar;
	
	arqEnt = fopen(filePath, "r");
	if (arqEnt == NULL){
		printf("Erro de abertura do arquivo \n");
	}

	while(!feof(arqEnt)) {

		callback(arqEnt, lines);

        lastChar = fgetc(arqEnt);
        if(lastChar == '\n')
        {
            lines++;
        }
    }
	
    fclose (arqEnt);
}

// função para criar um arquivo.
// filePath: caminho para o novo arquivo.
// callback: função de retorno que recebe o arquivo vazio para escreve-lo.
void generateFile(char *filePath, void (*callback)(FILE *)) {
    FILE * arqSai;
	arqSai = fopen(filePath, "w");
 
	callback(arqSai);

	fclose (arqSai);

    printf("\nArquivo Criado em %s.", filePath);
}
