#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

typedef struct _tab {
	char estado[30];
	float indice; 
} Tabble;

//main
Tabble vetor[26];
void pegaDados ();
void moises(Tabble *vetor, int inicio, int fim);
int quickSort(Tabble *vetor, int inicio, int final);

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
	
    FILE * arqSai;
	arqSai = fopen("assets/resultado.txt", "w");
    
    pegaDados();
	moises(&vetor, 0, 25);

    system("cls");
    
    fprintf(arqSai, "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2Razão de mortalidade materna dos estados brasileiros em ordem crescente de acordo com o indice\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
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

// função pegaDados
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

// função quickSort
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