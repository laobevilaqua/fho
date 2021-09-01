#ifndef BST_H

#define BST_H
/* estrutura do noh da lista */
typedef struct _arvore{
	char uf[3];
	float dado;
	struct _arvore *pai;
	struct _arvore *esq;
	struct _arvore *dir;
} Arvore;


/* declaracoes das funcoes de lista */
void inicializaListaArvore(Arvore**);
int listaArvoreVazia(Arvore*);

void imprimePreOrdem(Arvore*);
void imprimePosOrdem(Arvore*);
void imprimeEmOrdem(Arvore*);

Arvore* pesquisarValor(Arvore*, float);
void inserirValor(Arvore**, char[3], float);

Arvore* pesquisarMaior(Arvore*);
Arvore* pesquisaMenor(Arvore*);

int removerDado(Arvore**, float);
void esvaziaListaArvore(Arvore**);

#endif
