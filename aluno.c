#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "aluno.h"

struct aluno
{
    char nome[50];
    int matricula;
    char documento[20];
};

void comb_sort(char *vetor[], int n)
{
    int gap = n;
    int busca = 1;

    char *aux;

    while (gap > 1 || busca == 1)
    {
        if (gap > 1)
        {
            gap /= 1.3;
        }
        int i = 0;
        busca = 0;
        while (i + gap < n)
        {
            if (strcmp(vetor[i], vetor[i + gap]) > 0)
            {
                aux = vetor[i];
                vetor[i] = vetor[i + gap];
                vetor[i + gap] = aux;
                busca = 1;
            }
        }
    }
}

Aluno *cria_Aluno(Aluno *aluno)
{
    aluno = (Aluno *)malloc(sizeof(Aluno));
    if (aluno == NULL)
    {
        printf("ERRO!\n");
        exit(1);
    }
    printf("Informe o nome do aluno: \n");
    scanf(" %[^\n]s", aluno->nome);
    printf("Informe a matricula do aluno: \n");
    scanf("%d", &aluno->matricula);
    printf("Informe o documento do aluno: \n");
    scanf(" %[^\n]s", aluno->documento);

    FILE *aluno_txt;

    if (access("Alunos.txt", F_OK) == 0)
    {

        aluno_txt = fopen("Alunos.txt", "at");

        fprintf(aluno_txt, "Nome: %s\tMatricula: %d\tDocumento: %s\n", aluno->nome, aluno->matricula, aluno->documento);

        fclose(aluno_txt);

        printf("Aluno criado com sucesso! \n");
    }

    else
    {

        aluno_txt = fopen("Alunos.txt", "wt");

        fprintf(aluno_txt, "Nome: %s\tMatricula: %d\tDocumento: %s\n", aluno->nome, aluno->matricula, aluno->documento);

        fclose(aluno_txt);

        printf("Aluno criado com sucesso! \n");
    }

    return (aluno);
}



char *recebe_nomes()
{
    char linha[100];
    int i = 0;
    FILE *aluno_txt;
    char *nomes[50][3];

    aluno_txt = fopen("Alunos.txt", "rt");

    if (aluno_txt == NULL)
    {
        printf("\nERRO!");
        exit(1);
    }

    while (fgets(linha, 100, aluno_txt) != NULL)
    {
        sscanf(linha, " %[^\n]s", &nomes[50][i]);
        i++;
    }

    fclose(aluno_txt);

    return(nomes[50][3]);
}