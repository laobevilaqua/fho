#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void inicializaListaArvore(Arvore **tree){
	*tree = NULL;	
}

int listaArvoreVazia(Arvore *tree){
	if(tree == NULL)
		return 1;
		
	return 0;
} 

void imprimePreOrdem(Arvore *tree){
	if(!listaArvoreVazia(tree)){
		printf("%s ", tree->uf);
		printf("%.2f \n", tree->dado);
		imprimePreOrdem(tree->esq);
		imprimePreOrdem(tree->dir);
	}
}

void imprimePosOrdem(Arvore *tree){
	if(!listaArvoreVazia(tree)){
		imprimePosOrdem(tree->esq);
		imprimePosOrdem(tree->dir);
		printf("%s ", tree->uf);
		printf("%.2f \n", tree->dado);
	}
}

void imprimeEmOrdem(Arvore *tree){
	if(!listaArvoreVazia(tree)){
		imprimeEmOrdem(tree->esq);
		printf("%s ", tree->uf);
		printf("%.2f \n", tree->dado);
		imprimeEmOrdem(tree->dir);
	}
}

Arvore* pesquisarValor(Arvore *tree, float valor){
	
	Arvore *aux = tree;
	
	while(aux != NULL){ // sai do loop sem encontrar o arvore pesquisado
	
		if(aux->dado == valor) // sai do loop quando encontrar o arvore pesquisado 
			break;
		
		else if(valor < aux->dado)
			aux = aux->esq;
			
		else
			aux = aux->dir;
	}
	
	return aux;  // aux vai ter o endereço da arvore encontrado
	             // ou aux vai ter NULO se a arvore não existir na árvore
}

void inserirValor(Arvore **tree, char uf[3], float valor){
	Arvore *aux, *papai;
	
	/* alocação de memória para a nova arvore */
	Arvore *novo = (Arvore*) malloc(sizeof(Arvore));
	strcpy(novo->uf, uf); // Não se pode atribuir uma string com '='
	novo->dado = valor; 
	novo->esq  = NULL;
	novo->dir  = NULL;
	novo->pai  = NULL;
	
	/* testa se a árvore está vazia */
	if(listaArvoreVazia(*tree)){
		*tree = novo;
		return;		
	}
	
	/* loop para encontrar a posição de inclusão */
	aux = *tree;
	while(aux != NULL){  // permite achar a posição da nova arvore
		
		papai = aux;
		
		if(valor < aux->dado)
			aux = aux->esq;
			
		else if(valor > aux->dado)
			aux = aux->dir;
			
		else{ // se chave (ID) é repetida
			printf("Nao eh possivel incluir a chave %f\n", valor);
			return;	
		}	
	}
	
	if(valor < papai->dado)
		papai->esq = novo;
	else
		papai->dir = novo;
	
	novo->pai = papai;
} // encerra rotina de inserção

Arvore* pesquisarMaior(Arvore *tree){
	
	Arvore *atual = tree;
	
	if (!listaArvoreVazia(tree)){
		while(atual->dir != NULL)
			atual = atual->dir;
	}
	
	return atual;
}

Arvore* pesquisaMenor(Arvore *tree){
	
	Arvore *atual = tree;
	
	if (!listaArvoreVazia(tree)){
		while(atual->esq != NULL)
			atual = atual->esq;
	}
	
	return atual;
}

int removerDado(Arvore **tree, float dado){
	Arvore *atual;
	Arvore *maior;
	float valor;
	
	if (listaArvoreVazia(*tree)){
		printf("Arvore vazia!!!\n");
		return 0;
	}

	atual = pesquisarValor(*tree, dado);
	
	if(atual == NULL){  // arvore não encontrado
		printf("arvore %f nao encontrado\n", dado);
		return 0;
	}
	
	/* *********************************** */
	/* *** caso 1 - arvore folha          *** */
	/* *********************************** */
	if((atual->esq == NULL) && (atual->dir == NULL)){
		
		/* tratar se eh no raiz */
		if(atual->pai == NULL){
			inicializaLista(tree);
			free(atual);
			return 1;
		}
				
		if(dado < atual->pai->dado)
			atual->pai->esq = NULL;
		else
			atual->pai->dir = NULL;
			
		free(atual);
		return 1;
	}

	/* *********************************** */
	/* *** caso 2 - arvore com 1 filho    *** */
	/* *********************************** */
	if(
		((atual->esq != NULL) && (atual->dir == NULL)) ||
	   ((atual->dir != NULL) && (atual->esq == NULL))) {
	
		// estou num arvore raiz?
		if(atual->pai == NULL){
			if(atual->esq != NULL)
				*tree = atual->esq;
				
			else
			    *tree = atual->dir;	
		}
		// e se não for a raiz?
		else{
			// processando a subarvore esquerda do pai
			if(atual == atual->pai->esq){
				
				//se o neto está na subarvore esquerda do pai que é o cara a ser removido
				if(atual->esq != NULL){
					atual->pai->esq = atual->esq;
					atual->esq->pai = atual->pai;	
				}
				
				//se o neto está na subarvore direira do pai que é o cara a ser removido
				else{
					atual->pai->esq = atual->dir;
					atual->dir->pai = atual->pai;	
				}
				
			} // fecha subarvore esquerda
			// processando a subarvore direita do pai
			else if(atual == atual->pai->dir) {

			//se o neto está na subarvore esquerda do pai que é o cara a ser removido
				if(atual->esq != NULL){
					atual->pai->dir = atual->esq;
					atual->esq->pai = atual->pai;	
				}
				
				//se o neto está na subarvore direira do pai que é o cara a ser removido
				else{
					atual->pai->dir = atual->dir;
					atual->dir->pai = atual->pai;	
				}	
			} // fecha a subarvore direita
				
		} // fecha o else do nao raiz
	
		free(atual);
		return 1;  
	} // encerra remocao do caso 2	


	/* ************************************ */
	/* *** caso 3 - arvore com dois filhos *** */
	/* ************************************ */
	if((atual->esq != NULL) && (atual->dir != NULL)){
		
		// encontrar a maior chave (id) da subarvore esquerda
		maior = pesquisarMaior(atual->esq);
		
		// guardar os dados desse maior encontrado
		valor = maior->dado;
		
		//remover o espaço do maior valor
		removerDado(tree, maior->dado);
		
		// substituir os dados daquele arvore que queriamos remover
		atual->dado = valor;
		
	} // fecha o caso 3
}

void esvaziaListaArvore(Arvore **lista) {
	/*enquanto a lista não estiver vazia, remover um nó */
	while (!listaArvoreVazia(*lista)){
		removerDado(lista, lista[0]->dado);
	}
}