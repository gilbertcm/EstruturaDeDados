#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILMES 10000
#define MAX_LINHA 900

typedef struct {
    int rank;
    char titulo[30];
    char descricao[100];
    char lancamento[15];
    float medVotos;
    int contVotos;
    char idioma[10];
    int popularidade;
} Filme;

int main() {
    Filme filmes[MAX_FILMES];
    FILE *fp;
    char linha[MAX_LINHA];

    fp = fopen("filmes.csv", "r");

    if (fp == NULL) {
        printf("ERRO! Arquivo nao pode ser aberto.\n");
        exit(1);
    }

    // Lendo e descartando o cabeçalho
    fgets(linha, MAX_LINHA, fp);

    int num_filmes = 0;

    while (fgets(linha, MAX_LINHA, fp) != NULL && num_filmes < MAX_FILMES) {
        char *campo;
        campo = strtok(linha, ",");
        filmes[num_filmes].rank = atoi(campo);
        campo = strtok(NULL, ",");
        strcpy(filmes[num_filmes].titulo, campo);
        campo = strtok(NULL, ",");
        strcpy(filmes[num_filmes].descricao, campo);
        campo = strtok(NULL, ",");
        strcpy(filmes[num_filmes].lancamento, campo);
        campo = strtok(NULL, ",");
        filmes[num_filmes].medVotos = atof(campo);
        campo = strtok(NULL, ",");
        filmes[num_filmes].contVotos = atoi(campo);
        campo = strtok(NULL, ",");
        strcpy(filmes[num_filmes].idioma, campo);
        campo = strtok(NULL, ",");
        filmes[num_filmes].popularidade = atoi(campo);

        num_filmes++;
    }

    fclose(fp);

    // Exibindo os dados lidos
    for (int i = 0; i < num_filmes; i++) {
        printf("Rank: %d\n", filmes[i].rank);
        printf("Titulo: %s", filmes[i].titulo);
        printf("Descricao: %s\n", filmes[i].descricao);
        printf("Lancamento: %s\n", filmes[i].lancamento);
        printf("Media de votos: %.2f\n", filmes[i].medVotos);
        printf("Quantidade de votos: %d\n", filmes[i].contVotos);
        printf("Idioma: %s\n", filmes[i].idioma);
        printf("Popularidade: %d\n", filmes[i].popularidade);
    }

        //liberandi a memoria alocada
        for (int j = 0; j < num_filmes; j++)
        {
            free(filmes[j].titulo);
            free(filmes[j].descricao);
            free(filmes[j].lancamento);
            free(filmes[j].idioma);
        }

        free(filmes);
        
    return 0;
}