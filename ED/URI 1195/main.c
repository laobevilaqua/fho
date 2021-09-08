#include <stdio.h>
#include<stdlib.h>

typedef struct _no{
	
	int dado; //id
	struct _no *pai;
	struct _no *esq;
	struct _no *dir;
	
} No;


/*----------------------------------*/
void inicializar(No **tree){ //tree aponta para onde *arvore está apontando
	*tree = NULL;
}


/*----------------------------------*/
int estaVazia(No *tree){
	if(tree == NULL){
		return 1;  //Se estiver vazia = retorna 1
	}	
	else{
		return 0;  //Se não estiver vazia = retorna 0
	}
}


/*----------------------------------*/
void preOrdem(No *tree){
	if(!estaVazia(tree)){
		printf(" %d", tree->dado);
		preOrdem(tree->esq);
		preOrdem(tree->dir);
	}
}

void posOrdem(No *tree){
	if(!estaVazia(tree)){
		posOrdem(tree->esq);
		posOrdem(tree->dir);
		printf(" %d", tree->dado);
	}
}

void emOrdem(No *tree){
	if(!estaVazia(tree)){
		emOrdem(tree->esq);
		printf(" %d", tree->dado);
		emOrdem(tree->dir);
	}
}


/*----------------------------------*/
/*	Rotinas de Insercao de um No	*/
/*----------------------------------*/
void inserir(No **tree, int valor){
	No *aux, *papai;
	
	/*Alocação de memória para o novo nó*/
	No *novo = (No*) malloc(sizeof(No));
	//*novo = (No*) malloc(sizeof(No) <- casting
	//x = (int) 5/2; <- casting
	
	//novo = espaço de memoria
	
	novo->dado = valor;
	novo->esq = NULL;
	novo->dir = NULL;
	novo->pai = NULL;
	
	
	/*Se a arvore está vazia*/
	if(estaVazia(*tree)){ 
		*tree = novo; 		
		return;
	}
	
	/*Se a arvore NAO está vazia*/
	/*Loop para encontrar a posição de inclusão*/
	aux = *tree;
	
	while(aux != NULL){ //permite achar a posição do novo nó
		
		papai = aux;
		
		if(valor < aux->dado){ //Se o valor for menor que aux->dado
			aux = aux->esq;	//aux aponta para a esquerda
		}		
		else if(valor > aux->dado){ //Se o valor for maior que aux->dado
			aux = aux->dir;
		}
		else{ //Se o valor é igual ao de uma chave (numero repetido)
			return;
		}
	}//fim do while
	
	if(valor < papai->dado){ //Se menor, vai para a esquerda
		papai->esq = novo;
	}
	else{
		papai->dir = novo; //Se maior, vai para a direita
	}
	novo->pai = papai;
}// encerra a rotina de inserçao



int main(){
		
	No *arvore; //aponta para a raiz da arvore
	No *aux; //aux para a função 'busca'
	int C, N, i, j, Noh;
	
	inicializar(&arvore); //nesse instante, o ponteiro arvore recebe nulo
	
	scanf("%d", &C);
	
	for(j=1; j<=C; j++){
		
		arvore = NULL; //Zerando para não ocorrer problema nas proximas laçadas do for
		
		scanf("%d", &N);
		
		for(i=0; i<N; i++){
			scanf("%d", &Noh);
			inserir(&arvore, Noh);  /* Inserção do Noh */
		}
		
		/* Impressao */
		printf("Case %d:", j);
		printf("\nPre.:");
		preOrdem(arvore);
		
		printf("\nIn..:");
		emOrdem(arvore);
		
		printf("\nPost:");
		posOrdem(arvore);	
		
		printf("\n\n");
	}//fim for
		
	return 0;
}
