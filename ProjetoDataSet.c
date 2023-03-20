#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CSVSIZE 18000

typedef struct ProjetoDataSet
{
    int productID;
    char *marcaName;
    char *title;
    float precoAtual;
    float precoAnter;
    char *cor;
    char *moeda;
    int rrp;
    int produtoCode;
    char *produtoType;
}t_comerce;


int main() 
{

    t_comerce *eletronico;
    FILE *fp;
    char str[900]; // para ler uma linha do arquivo
    int i = 0; //ontador que é usado para controlar o número de registros lidos

    eletronico = (t_comerce*) malloc(CSVSIZE * sizeof(t_comerce));

    if (eletronico == NULL)
    {
        printf("ERRO! Falha ao alocar memoria!\n");
        exit(1);
    }
    

    fp = fopen("Asosmenfashion.csv", "r");

    if(fp == NULL)
    {
        printf("ERRO! Arquivo nao pode ser aberto.\n");
        exit(1);
    }

    // pegando o cabeçalho
    char *ok; // se ok for NULL teve problema na leitura
    ok = fgets(str, 900, fp); // pega a string do arquivo
    if (ok == NULL)
    {
        printf("Erro lendo o cabeçalho do CSV!!!", str);
        exit(1);
    }
    
    i = 0;
    char sep[] = ",";

    while (!feof(fp) && i < CSVSIZE) // enquanto nâo chegar no final do arquivo ou no tamanho do array
    {
        ok = fgets(str, 900, fp); // pega uma string do arquivo
        if (ok) // se ok != NULL (NULL é Falso, diferente de NULL verdadeiro)
        {
            char *campo;
            campo = strtok(str, sep); // pega o primeiro campo
            eletronico[i].productID = atoi(campo); // converte para inteiro e atribui ao campo productID
            campo = strtok(NULL, sep); // pega o próximo campo
            eletronico[i].marcaName = strdup(campo); // copia a string para o campo marcaName
            campo = strtok(NULL, sep); // pega o próximo campo
            eletronico[i].title = strdup(campo); // copia a string para o campo title
            campo = strtok(NULL, sep); // pega o próximo campo
            eletronico[i].precoAtual = atof(campo); // converte para float e atribui ao campo precoAtual
            campo = strtok(NULL, sep); // pega o próximo campo
            eletronico[i].precoAnter = atof(campo); // converte para float e atribui ao campo precoAnter
            campo = strtok(NULL, sep); // pega o próximo campo
            eletronico[i].cor = strdup(campo); // copia a string para o campo cor
            campo = strtok(NULL, sep); // pega o próximo campo
            eletronico[i].moeda = strdup(campo); // copia a string para o campo moeda
            campo = strtok(NULL, sep); // pega o próximo campo
            eletronico[i].rrp = atoi(campo); // converte para inteiro e atribui ao campo rrp
            campo = strtok(NULL, sep); // pega o próximo campo
            eletronico[i].produtoCode = atoi(campo); // converte para inteiro e atribui ao campo produtoCode
            campo = strtok(NULL, sep); // pega o próximo campo
            eletronico[i].produtoType = strdup(campo); // copia a string para o campo produtoType
            i++;
        }
    }

        fclose(fp);

        //exibindo os dados lidos
        for (int j = 0; j < i; j++)
        {
            printf("ID: %d\n", eletronico[j].productID);
            printf("Marca: %s\n", eletronico[j].marcaName);
            printf("Titulo: %s\n", eletronico[j].title);
            printf("Preco Atual: %.2f\n", eletronico[j].precoAtual);
            printf("Preco Anterior: %.2f\n", eletronico[j].precoAnter);
            printf("Cor: %s\n", eletronico[j].cor);
            printf("Moeda: %s\n", eletronico[j].moeda);
            printf("RRP: %d\n", eletronico[j].rrp);
            printf("Codigo do Produto: %d\n", eletronico[j].produtoCode);
            printf("Tipo do Produto: %s\n\n", eletronico[j].produtoType);
        }

        //liberandi a memoria alocada
        for (int j = 0; j < i; j++)
        {
            free(eletronico[j].marcaName);
            free(eletronico[j].title);
            free(eletronico[j].cor);
            free(eletronico[j].moeda);
            free(eletronico[j].produtoType);
        }

        free(eletronico);
        
    return 0;
}