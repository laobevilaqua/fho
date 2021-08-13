#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

typedef struct _tab {
	char estado[30];
	float indice; 
} Tabble;

Tabble vetor[26];
void pegaDados ();
void shellSort(Tabble *vetor, int N);

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
	
    FILE * arqSai;
	arqSai = fopen("assets/resultado.txt", "w");
    
    pegaDados();
    shellSort(&vetor, 26);
    system("cls");
    
    fprintf(arqSai, "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2RazÃ£o de mortalidade materna dos estados brasileiros em ordem crescente de acordo com o indice\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    fprintf(arqSai, "+-------------------------------|\n");
    fprintf(arqSai, "|\t\tESTADO (INDICE)\t\t\t|\n");
    fprintf(arqSai, "+-------------------------------|\n");
    
    for (int i = 0; i < 26; i++)
    {
    	fprintf(arqSai, "\t%s (%.2f)\t\t\n", vetor[i].estado, vetor[i].indice);
    }

	fclose (arqSai);
 
    return 0;
}

// funÃ§Ã£o pegaDados
void pegaDados () {
	Tabble tab;	
	FILE * arqEnt;
	
	arqEnt = fopen("assets/Dados.txt", "r");
	if (arqEnt == NULL){
		printf("Erro de abertura do arquivo de retang.txt \n");
	}
	
	if (arqEnt == NULL){
		printf("Erro de abertura do arquivo de resultado.txt \n");
	}
	
    float ind2009, ind2015;
    for (int i = 0; i < 26; i++)
    {
        fscanf(arqEnt, "%s %f %f", &tab.estado, &ind2009, &ind2015);
        tab.indice = (ind2015 - ind2009);
        vetor[i] = tab;
    }

    fclose (arqEnt);
}

// função shellSort
void shellSort(Tabble *vetor, int N)
{
    int i = (N - 1) / 2;
    int chave, k;
    Tabble aux;

    while(i != 0)
    {
        do
        {
            chave = 1;
            for(k = 0; k < N - i; ++k){
                if(vetor[k].indice > vetor[k + i].indice)
                {
                    aux = vetor[k];
                    vetor[k] = vetor[k + i];
                    vetor[k + i] = aux;
                    chave = 0;
                }
            }
        } while(chave == 0);
        i = i / 2;
    }
}

