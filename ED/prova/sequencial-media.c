#include <stdio.h>

#define PESO_PROVA 3
#define PESO_TRABALHO 1
 
typedef struct {
    int ra;
    float prova;
    float traba;
    char nome[30];
} turmaMAT;

float BuscaSequencial(turmaMAT *alunos, int raPesquisa, int qde) {
    turmaMAT aluno;

    for(int i=0; i < qde ;i++) {
        if (alunos[i].ra == raPesquisa) {
            aluno = alunos[i];
            
            return (aluno.prova * PESO_PROVA + aluno.traba * PESO_TRABALHO)/4;
        }
    }

    return -1;
}

// int main()
// {
//     int i, RABusca;
//     turmaMAT vetalu[3];
//     for(i=0; i<3; i++){
//         scanf("%d %f %f %s", &vetalu[i].ra, &vetalu[i].prova,&vetalu[i].traba, &vetalu[i].nome);
//     }
//     printf("Informe RA para pesquisar: ");
//     scanf("%d", &RABusca);

//     float media = BuscaSequencial(vetalu, RABusca, 3);

//     printf("%.2f", media);
//     return 0;
// }
