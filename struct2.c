#include <stdio.h>

typedef struct {
    char rua[31];
    int numero;
    char complemento[31];
    char bairro[31];
    char cep[9];
    char cidade[21];
    char estado[3];
    char pais[31];
} ENDERECO;

typedef struct 
{
	char ddd[3];
	char numero[10];
	
}TELEFONE;

typedef struct 
{
	char dia[3];
	char mes[3];
	char ano[5];
}ANIVERSARIO;

typedef struct 
{
	char nome[41];
	char eMail[21];
	ENDERECO endereco;
	TELEFONE telefone;
	ANIVERSARIO data;
	char observacao[101];
}PESSOA;

typedef struct {
