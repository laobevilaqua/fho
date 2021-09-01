#ifndef Quick_Sort_H

#define Quick_Sort_H
/* estrutura dos dados */
typedef struct _tab {
 	int ano;
 	float indice; 
} Tabble;


/* declaracoes das funcoes do quick sort */
void moises(Tabble *, int, int);
int quickSort(Tabble *, int, int);
void moisesByYear(Tabble *, int, int);
int quickSortByYear(Tabble *, int, int);

#endif
