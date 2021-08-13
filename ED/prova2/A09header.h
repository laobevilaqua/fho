#ifndef LISTA_H

#define LISTA_H
/* estrutura do noh da lista */
typedef struct _no {
    int codigo;
    int pontos;
    char competidor[50];
    struct _no *proximo;
} No;


/* declaracoes das funcoes de lista */
void inicializaLista(No**);
int listaVazia(No*);

void imprimeLista(No*);

void insereCompetidor(No**, int, int);
void insereInicio(No**, int);
void insereFinal(No**, int);
void inserePosicao(No**, int, int);
void insereOrdenado(No**, int);

void removeInicio(No**);
void removeFinal(No**);
void removeEspecifico(No**, int);

No* dadosCompetidor(No*, int); // aula 10
No* pesquisaElemento(No*, int); // aula 10
void esvaziaLista(No**);  // aula 10


#endif
