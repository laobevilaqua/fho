#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	printf("+------+------+------+------+------+------+\n");
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

void calculaMediaAnual(Arvore *tree, int ano) {
	if(!listaVazia(tree)){
		if (ano == 2015) {
			mediaAnual += tree->a2015;
		} else if (ano == 2016) {
			mediaAnual += tree->a2016;
		} else if (ano == 2017) {
			mediaAnual += tree->a2017;
		} else if (ano == 2018) {
			mediaAnual += tree->a2018;
		} else if (ano == 2019) {
			mediaAnual += tree->a2019;
		}
		calculaMediaAnual(tree->esq, ano);
		calculaMediaAnual(tree->dir, ano);
	}
}

Arvore* pesquisarValor(Arvore *tree, char uf[3]){
	Arvore *aux = tree;
	
	while(aux != NULL){ // sai do loop sem encontrar o arvore pesquisado
		if(!strcmp(aux->uf, uf)) // sai do loop quando encontrar o arvore pesquisado 
			break;

		
		else if(uf < aux->uf)
			aux = aux->esq;
			
		else if(uf > aux->uf)
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
		
		if(uf < aux->uf)
			aux = aux->esq;
			
		else if(uf > aux->uf)
			aux = aux->dir;
			
		else{ // se chave (ID) é repetida
			printf("Nao eh possivel incluir a chave %s\n", uf);
			return;	
		}	
	}
	
	if(uf < papai->uf)
		papai->esq = novo;
	else
		papai->dir = novo;
	
	novo->pai = papai;
} // encerra rotina de inserção


int removerDado(Arvore **tree, char dado[3]){
	Arvore *atual;
	Arvore *maior;
	char valor[3];
	
	if (listaVazia(*tree)){
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
				
		if(dado < atual->pai->uf)
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
		strcpy(maior->uf, valor);
		
		//remover o espaço do maior valor
		removerDado(tree, maior->uf);
		
		// substituir os dados daquele arvore que queriamos remover
		strcpy(atual->uf, valor);
		
	} // fecha o caso 3
}

Arvore* pesquisarMaior(Arvore *tree){
	Arvore *atual = tree;
	
	if (!listaVazia(tree)){
		while(atual->dir != NULL)
			atual = atual->dir;
	}
	
	return atual;
}

void liberaNo(Arvore *no) {
	if(no == NULL)
		return 0;

	liberaNo(no->esq);
	liberaNo(no->dir);
	free(no);
	no = NULL;
}

void libera_ArvBin(Arvore* raiz) {
    if(raiz == NULL)
        return;
    liberaNo(raiz);
    free(raiz);
}

void esvaziaListaArvore(Arvore **lista) {
	/*enquanto a lista não estiver vazia, remover um nó */
	while (!listaVazia(*lista)){
		removerDado(lista, lista[0]->uf);
		esvaziaListaArvore(lista);
	}
}