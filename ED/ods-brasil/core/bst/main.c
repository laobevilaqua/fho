#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void inicializaLista(Arvore **tree){
	*tree = NULL;	
}

int listaVazia(Arvore *tree){
	if(tree == NULL)
		return 1;
		
	return 0;
} 

void imprimeDado(Arvore *tree) {
	printf("\n\n+------+------+------+------+------+------+\n");
	printf("|  UF  | 2015 | 2016 | 2017 | 2018 | 2019 |\n");
	printf("|  %s  | %.2f | %.2f | %.2f | %.2f | %.2f |\n", tree->uf, tree->a2015, tree->a2016, tree->a2017, tree->a2018, tree->a2019);
	printf("+------+------+------+------+------+------+\n");
}

void imprimePreOrdem(Arvore *tree){
	if(!listaVazia(tree)){
		imprimeDado(tree);
		imprimePreOrdem(tree->esq);
		imprimePreOrdem(tree->dir);
	}
}

void imprimePosOrdem(Arvore *tree){
	if(!listaVazia(tree)){
		imprimePosOrdem(tree->esq);
		imprimePosOrdem(tree->dir);
		imprimeDado(tree);
	}
}

void imprimeEmOrdem(Arvore *tree){
	if(!listaVazia(tree)){
		imprimeEmOrdem(tree->esq);
		imprimeDado(tree);
		imprimeEmOrdem(tree->dir);
	}
}

Arvore* pesquisarValor(Arvore *tree, float valor){
	
	Arvore *aux = tree;
	
	while(aux != NULL){ // sai do loop sem encontrar o arvore pesquisado
	
		if(
			aux->a2015 == valor ||
			aux->a2016 == valor ||
			aux->a2017 == valor ||
			aux->a2018 == valor ||
			aux->a2019 == valor
		) // sai do loop quando encontrar o arvore pesquisado 
			break;

		
		else if(valor < aux->a2015)
			aux = aux->esq;
			
		else if(valor > aux->a2019)
			aux = aux->dir;
	}
	
	return aux;  // aux vai ter o endereço da arvore encontrado
	             // ou aux vai ter NULO se a arvore não existir na árvore
}

void inserirValor(Arvore **tree, char uf[3], float a2015, float a2016, float a2017, float a2018, float a2019){
	Arvore *aux, *papai;
	
	/* alocação de memória para a nova arvore */
	Arvore *novo = (Arvore*) malloc(sizeof(Arvore));
	strcpy(novo->uf, uf); // não pode-se atribuir com '=' então usamos essa função
	novo->a2015 = a2015; 
	novo->a2016 = a2016; 
	novo->a2017 = a2017; 
	novo->a2018 = a2018; 
	novo->a2019 = a2019; 
	novo->esq  = NULL;
	novo->dir  = NULL;
	novo->pai  = NULL;
	
	/* testa se a árvore está vazia */
	if(listaVazia(*tree)){
		*tree = novo;
		return;		
	}
	
	/* loop para encontrar a posição de inclusão */
	aux = *tree;
	while(aux != NULL){  // permite achar a posição da nova arvore
		
		papai = aux;
		
		if(a2019 < aux->a2015)
			aux = aux->esq;
			
		else if(a2019 > aux->a2019)
			aux = aux->dir;
			
		else{ // se chave (ID) é repetida
			printf("Nao eh possivel incluir a chave %f\n", a2019);
			return;	
		}	
	}
	
	if(a2019 < papai->a2015)
		papai->esq = novo;
	else
		papai->dir = novo;
	
	novo->pai = papai;
} // encerra rotina de inserção
