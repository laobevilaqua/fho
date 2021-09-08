#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLENGTH 50

// SUBMISSOES DO URI
// LUCAS A 24326484		1200	BST Operations I	Accepted	C99	0.000	9/4/21, 5:01:15 PM
// NICOLAS
// DANIEL
// GABRIEL B

typedef struct Arvore{
	char letra;
	struct Arvore *esquerda;
	struct Arvore *direita;
} Arvore;

void infixa(Arvore *);
void prefixa(Arvore *);
void posfixa(Arvore *);
void printInfixa(char *);
void printPrefixa(char *);
void printPosfixa(char *);
int busca(Arvore *, char );
Arvore* push(Arvore *, char );

char letrasInfixa[MAXLENGTH] = { 0 };
char letrasPosfixa[MAXLENGTH] = { 0 };
char letrasPrefixa[MAXLENGTH] = { 0 };

int indexInfixa = 0, indexPosfixa = 0, indexPrefixa = 0;

void main ()
{
	char opcao[20], letra;

	Arvore *no = NULL;
	while (scanf("%s%*c", &opcao) != EOF)
	{
		if (strcmp(opcao, "I") == 0)
		{
			scanf("%c", &letra);
			no = push(no, letra);
		} else if (!strcmp(opcao, "INFIXA")) {
			infixa(no), printInfixa(letrasInfixa);
        } else if (!strcmp(opcao, "PREFIXA")) {
			prefixa(no), printPrefixa(letrasPrefixa);
        } else if (!strcmp(opcao, "P")) {
			scanf("%c", &letra);
			if (busca(no, letra)) {
				printf("%c existe\n", letra);
            } else {
				printf("%c nao existe\n", letra);
            }
		} else {
			posfixa(no), printPosfixa(letrasPosfixa);
        }
	}
}

Arvore* push(Arvore *no, char letra)
{
	if (!no)
	{
		no = (Arvore *) malloc(sizeof(Arvore));
		no->letra = letra;
		no->direita = no->esquerda = NULL;
	}
	else if (no->letra > letra)
		no->esquerda = push(no->esquerda, letra);
	else
		no->direita = push(no->direita, letra);

	return no;
}

int busca(Arvore *no, char letra)
{
	int direita, esquerda;

	if (!no)
		return 0;

	if (no->letra == letra)
		return 1;

	if (no->letra > letra)
		esquerda = busca(no->esquerda, letra);
	else
		direita = busca(no->direita, letra);
}

void printInfixa(char *letras)
{
	for (int i = 0; i < indexInfixa; ++i)
		if (!i)
			printf("%c", letrasInfixa[i]);
		else
			printf(" %c", letrasInfixa[i]);

	indexInfixa = 0;
	printf("\n");
}

void printPrefixa(char *letras)
{
	for (int i = 0; i < indexPrefixa; ++i)
		if (!i)
			printf("%c", letrasPrefixa[i]);
		else
			printf(" %c", letrasPrefixa[i]);

	indexPrefixa = 0;
	printf("\n");
}

void printPosfixa(char *letras)
{
	for (int i = 0; i < indexPosfixa; ++i)
		if (!i)
			printf("%c", letrasPosfixa[i]);
		else
			printf(" %c", letrasPosfixa[i]);

	indexPosfixa = 0;
	printf("\n");
}

void infixa(Arvore *no)
{
	if (no)
	{
		infixa(no->esquerda);
		letrasInfixa[indexInfixa++] = no->letra;
		infixa(no->direita);
	}
}

void posfixa(Arvore *no)
{
	if (no)
	{
		posfixa(no->esquerda);
		posfixa(no->direita);
		letrasPosfixa[indexPosfixa++] = no->letra;
	}
}

void prefixa(Arvore *no)
{
	if (no)
	{
		letrasPrefixa[indexPrefixa++] = no->letra;
		prefixa(no->esquerda);
		prefixa(no->direita);

	}
}