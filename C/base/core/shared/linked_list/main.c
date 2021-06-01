#include <stdio.h>
#include <stdlib.h>
#include "header.h"

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
		printf("%d ", atual->dado);
		atual = atual->proximo;
		
	}
	
	printf("]\n");
	
}

void insereInicio(No **lista, int dado) {
    No *novo;
        
    /* cria o novo noh a ser inserido na lista */
    novo = (No*) malloc (sizeof(No));
    novo->dado = dado;

    /* se a lista estiver vazia, novo noh aponta para NULL */
    if (listaVazia(*lista))
        novo->proximo = NULL;

    /* caso contrario, novo noh aponta para o inicio da lista */
    else
        novo->proximo = *lista;

    /* novo noh passa a ser o inicio da lista */
    *lista = novo;

}

void insereFinal(No**lista, int dado) {
 	No *novo;
        
    /* cria o novo noh a ser inserido na lista */
    novo = (No*) malloc (sizeof(No));
    novo->dado = dado;
	novo->proximo = NULL;

	No* atual = *lista; //começar no primeiro
    while (atual->proximo != NULL){ //navegar até ao fim
        atual = atual->proximo;
    }

    atual->proximo = novo; //colocar o novo nó no fim
}

void inserePosicao(No **lista, int posicao, int dado){
	No *novo;
	No *atual = *lista;
	No *posAnterior = *lista;
	
	int pos = 0;
	
	printf("----> insere %d na posicao %d\n", dado, posicao);
	
	/* criar o novo noh a ser inserido na lista */
	novo = (No*) malloc(sizeof(No));
	novo->dado = dado;
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

void insereOrdenado(No **lista, int dado){
	No *novo;
	No *atual = *lista;
	No *posAnterior = *lista;
	
	/* criar o novo noh a ser inserido na lista */
	novo = (No*) malloc(sizeof(No));
	novo->dado = dado;
	novo->proximo = NULL;
	
	/* se a lista esta vazia, o novo noh passa a ser o inicio da lista */
	if(listaVazia(*lista)){
		*lista = novo;
		return;
	}

	/* caso contrario, caminhar at� achar o local correto na lista */
	/* insere ap�s o final da lista */
	while((atual != NULL) && (atual->dado < dado)){
		posAnterior = atual;
		atual = atual->proximo;
	}
	
	/* sed a posicao for antes do inicio da lista */
	/* entao, a inclusao ser� no inicio da lista */
	if(atual == *lista){
		insereInicio(lista, dado);
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
    if((*lista)->dado == idBusca){ // verifica se posição == 0
        (*lista) = (*lista)->proximo; // coloca a lista no próximo item
        free(aux); // limpa a memória

        return 1; // finaliza com verdadeiro
    }

    No *prev;
    while(aux){ // verifica se aux não chegou ao fim e percorre a posição
        prev = aux; // prev guarda valor da remoção
        aux = aux->proximo;
        if(aux && aux->dado == idBusca){ // verifica o id do avião
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

	while(( aux != NULL) && (aux->dado !=idBusca)){
		aux = aux->proximo;
	}
	// em aux, pode haver 2 situações , aux = id NULO ou aux = endereço do nó pesquisado
	return aux;
}

void esvaziaLista(No **lista){
	/*enquanto a lista não estiver vazia, remover um nó */
	while (!listaVazia(*lista)){
		removeFinal(lista);
	}
}	
