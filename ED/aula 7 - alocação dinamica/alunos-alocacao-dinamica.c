#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int ra;
    char nome[20];
    int idade;
    char sexo;
    float media;
} Aluno;

int main()
{
    int qtdAlunos = 5;
    Aluno aluno;
    Aluno *alunos;

    alunos = (Aluno *)malloc(qtdAlunos * sizeof(Aluno));

    for (int i = 0; i < qtdAlunos; i++)
    {
        printf("Aluno %d\n", i + 1);

        printf("RA: ");
        scanf("%d", &aluno.ra);

        fflush(stdin);

        printf("Nome: ");
        gets(&aluno.nome);

        printf("Idade: ");
        scanf("%d", &aluno.idade);

        fflush(stdin);

        printf("Sexo: ");
        scanf("%c", &aluno.sexo);

        printf("Media: ");
        scanf("%f", &aluno.media);

        alunos[i] = aluno; 
    }

    printf("Dado, endereço de memória, qtde bytes: \n\n");

    for (int i = 0; i < qtdAlunos; i++)
    {
        printf("RA: %d, endereço: %p, bytes: %d\n", alunos[i].ra, &alunos[i].ra, sizeof(alunos[i].ra));
    }

    return 0;
}