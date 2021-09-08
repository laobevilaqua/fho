#include <stdio.h>
#include <stdlib.h>

// SUBMISSOES DO URI
//DANIEL HENRIQUE - 108878
//GABRIEL BRAGA - 
//LUCAS ARAUJO - 110601
//NICOLAS GOMES - 109181


typedef struct Arvore{
	unsigned numero;
	struct Arvore *dir;
	struct Arvore *esq;
} Arvore;

void busca(Arvore *);
Arvore* push(Arvore *, unsigned );

unsigned Nos;

void main ()
{

	unsigned cont, num, qtsNum;
	unsigned qtsCasos, caso;

	scanf("%u", &qtsCasos);

	caso = 0;
	while (qtsCasos--)
	{
		scanf("%u", &qtsNum);

		Nos = 0;
		Arvore *no = NULL;
		for (cont = 0; cont < qtsNum; ++cont)
		{

			scanf("%u", &num);
			no = push(no, num);
			++Nos;

		}
		printf("Case %u:\n", ++caso);
		busca(no);
		printf("\n\n");

	}

}

Arvore* push(Arvore *no, unsigned numero)
{

	if (!no)
	{

		no = (Arvore *) malloc(sizeof(Arvore));
		no->numero = numero;
		no->esq = no->dir = NULL;

	}
	else if (no->numero > numero){
		no->esq = push(no->esq, numero);
	}	
	else{
		no->dir = push(no->dir, numero);
	}	

	return no;

}

void busca(Arvore *no)
{

	Arvore *fila;
	unsigned cont, f;
	int flag = 0;

	fila = (Arvore *) malloc(Nos * sizeof(Arvore));
	fila[0] = *no;
	cont = 0; f = 1;

	while (f > cont)
	{

		*no = fila[cont++];
		if (!flag)
			printf("%u", no->numero), flag = 1;
		else
			printf(" %u", no->numero);

		if (no->esq)
			fila[f++] = *no->esq;
		if (no->dir)
			fila[f++] = *no->dir;

	}

	free(fila);
}