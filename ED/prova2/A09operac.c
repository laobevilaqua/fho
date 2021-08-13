#include <stdio.h>
#include <stdlib.h>
#include "A09header.h"

void inicializaLista(No **lista) {
    *lista = NULL;
}

int listaVazia(No *lista) {
    if (lista == NULL)
        return 1;

    return 0;
}

void imprimeLista(No *lista){
	
	No *atual = lista;
	
	if(listaVazia(lista)){
		printf("A lista esta vazia!!!\n");
		return;
	}
	
	
	printf("Lista: [ ");
	while(atual != NULL){
		printf("%d ", atual->codigo);
		atual = atual->proximo;
		
	}
	
	printf("]\n");
	
}

void insereCompetidor(No **lista, int codigo, int pontos) {
    No *novo;
        
    /* cria o novo noh a ser inserido na lista */
    novo = (No*) malloc (sizeof(No));
    novo->codigo = codigo;
    novo->pontos = pontos;

    /* se a lista estiver vazia, novo noh aponta para NULL */
    if (listaVazia(*lista))
        novo->proximo = NULL;

    /* caso contrario, novo noh aponta para o inicio da lista */
    else
        novo->proximo = *lista;

    /* novo noh passa a ser o inicio da lista */
    *lista = novo;

}

void insereInicio(No **lista, int codigo) {
    No *novo;
        
    /* cria o novo noh a ser inserido na lista */
    novo = (No*) malloc (sizeof(No));
    novo->codigo = codigo;

    /* se a lista estiver vazia, novo noh aponta para NULL */
    if (listaVazia(*lista))
        novo->proximo = NULL;

    /* caso contrario, novo noh aponta para o inicio da lista */
    else
        novo->proximo = *lista;

    /* novo noh passa a ser o inicio da lista */
    *lista = novo;

}

void insereFinal(No**lista, int codigo) {
 	No *novo;
        
    /* cria o novo noh a ser inserido na lista */
    novo = (No*) malloc (sizeof(No));
    novo->codigo = codigo;
	novo->proximo = NULL;

	No* atual = *lista; //começar no primeiro
    while (atual->proximo != NULL){ //navegar até ao fim
        atual = atual->proximo;
    }

    atual->proximo = novo; //colocar o novo nó no fim
}

void inserePosicao(No **lista, int posicao, int codigo){
	No *novo;
	No *atual = *lista;
	No *posAnterior = *lista;
	
	int pos = 0;
	
	printf("----> insere %d na posicao %d\n", codigo, posicao);
	
	/* criar o novo noh a ser inserido na lista */
	novo = (No*) malloc(sizeof(No));
	novo->codigo = codigo;
	novo->proximo = NULL;
	
	/* se a lista esta vazia, o novo noh passa a ser o inicio */
	if(listaVazia(*lista)){
		*lista = novo;
		return;
	}
	
	if(posicao == 0){
	   novo->proximo = 	atual;
	   *lista = novo;
	   return;
	}
	
	/* achar a posicao de inclusao no meio ou final da lista */
	while((pos<posicao) && (atual != NULL)){
		posAnterior = atual;
		atual = atual->proximo;
		pos++;
		
	}
	
	/* insere o novo noh na posicao encontrada */
	/* ou depois do �ltimo noh */
	posAnterior->proximo = novo;
	novo->proximo = atual;
}

void insereOrdenado(No **lista, int codigo){
	No *novo;
	No *atual = *lista;
	No *posAnterior = *lista;
	
	/* criar o novo noh a ser inserido na lista */
	novo = (No*) malloc(sizeof(No));
	novo->codigo = codigo;
	novo->proximo = NULL;
	
	/* se a lista esta vazia, o novo noh passa a ser o inicio da lista */
	if(listaVazia(*lista)){
		*lista = novo;
		return;
	}

	/* caso contrario, caminhar at� achar o local correto na lista */
	/* insere ap�s o final da lista */
	while((atual != NULL) && (atual->codigo < codigo)){
		posAnterior = atual;
		atual = atual->proximo;
	}
	
	/* sed a posicao for antes do inicio da lista */
	/* entao, a inclusao ser� no inicio da lista */
	if(atual == *lista){
		insereInicio(lista, codigo);
		return;
	}
	
	
	/* caso contr�rio, insere no meio ou ap�s o final da lista */
	posAnterior->proximo = novo;
	novo->proximo = atual;
}


void removeInicio(No**lista) {
	No *atual = *lista;
	No *proximos = *lista;

	if(listaVazia(*lista))
		return;

	proximos = atual->proximo;

	*lista = proximos;
	atual->proximo = NULL;
	free(atual);
}

void removeFinal(No **lista){
	
	No *atual = *lista;
	No *posAnterior = *lista;
	
	if(listaVazia(*lista))
		return;
	
	/* caminhar at� o final */
	while(atual->proximo != NULL){
		posAnterior = atual;
		atual = atual->proximo;	
	}
	
	/* se tiver apenas um elemento na lista */
	if(atual == *lista)
	  *lista = NULL;
	  
	else // caso contr�rio, o penultimo n� deve ter proximo = NULL
	   posAnterior->proximo = NULL;
	   
	/* liberar mem�ria do n� a ser removido */   
	free(atual);
	
}

void removeEspecifico(No **lista, int idBusca){
	if(listaVazia(*lista))
        return;

	No *aux = (*lista);
    if((*lista)->codigo == idBusca){ // verifica se posição == 0
        (*lista) = (*lista)->proximo; // coloca a lista no próximo item
        free(aux); // limpa a memória

        return 1; // finaliza com verdadeiro
    }

    No *prev;
    while(aux){ // verifica se aux não chegou ao fim e percorre a posição
        prev = aux; // prev guarda valor da remoção
        aux = aux->proximo;
        if(aux && aux->codigo == idBusca){ // verifica o id do avião
            prev->proximo = aux->proximo;
            free(aux);
            return 1;
        }
    }
}

No* pesquisaElemento(No *lista, int idBusca){

	No *aux = lista;

	printf("\n ---> Busca por %d\n", idBusca);

	//caminhar na lista até encontrar idBusca ou até chegar no fim e não acha-lo

	while(( aux != NULL) && (aux->codigo !=idBusca)){
		aux = aux->proximo;
	}
	// em aux, pode haver 2 situações , aux = id NULO ou aux = endereço do nó pesquisado
	return aux;
}

// Meu
No* dadosCompetidor(No *ponteiro, int cod){

	No *aux = ponteiro;

	if(ponteiro == NULL) {
		return -1;
	}


	while(( aux != NULL) && (aux->codigo !=cod)){
		aux = aux->proximo;
	}


	if(( aux != NULL) && aux->codigo == cod) {
		printf("Codigo: %d\nPontos: %d\nCompetidor: %s", aux->codigo, aux->pontos, aux->competidor);
		return 1;
	}

	return 0;
}


// Nicolas
No* dadosCompetidor(No *ponteiro, int cod){

	No *aux = ponteiro;

	if(ponteiro == NULL) {
		return -1;
	}


	while(( aux != NULL) && (aux->codigo !=cod)){
		aux = aux->proximo;
	}


	if(aux == NULL) {
		return 0;
	}
	
	printf("Codigo: %d\nPontos: %d\nCompetidor: %s", aux->codigo, aux->pontos, aux->competidor);
	return 1;
}

// Daniel
No* dadosCompetidor(No *ponteiro, int cod){

	No *aux = ponteiro;

	if(ponteiro == NULL) {
		return -1;
	}


	while(( aux != NULL) && (aux->codigo !=cod)){
		aux = aux->proximo;
	}

	if(aux == NULL) {
		return 0;
	}


	printf("\nCodigo: %d", aux->codigo);
	printf("\nPontos: %d", aux->pontos);
	printf("\nCompetidor: %s", aux->competidor);

	return 1;
}

void esvaziaLista(No **lista){
	/*enquanto a lista não estiver vazia, remover um nó */
	while (!listaVazia(*lista)){
		removeFinal(lista);
	}
}	
