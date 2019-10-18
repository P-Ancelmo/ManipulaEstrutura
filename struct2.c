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

PESSOA agenda[100];//declarar variável agenda (b)

void buscaNome (PESSOA agenda[]) { //busca pessoas pelo nome (c)
	char nome;
	printf("insira o nome desejado:\n");
	gets(nome);
	for (int i = 0; i > 100; i++) {
		if (agenda[i].nome == nome) {  //deve procurar só pelo primeiro nome, estou com dúvida sobre como fazer
			printf("nome: %s\n", agenda[i].nome);
			printf("eMail: %s\n", agenda[i].eMail);	
			printf("rua: %s\n", agenda[i].endereco.rua);	
			printf("numero: %d\n", agenda[i].endereco.numero);	
			printf("complemento: %s\n", agenda[i].endereco.complemento);	
			printf("bairro: %s\n", agenda[i].endereco.bairro);	
			printf("CEP: %s\n", agenda[i].endereco.cep);	
			printf("cidade: %s\n", agenda[i].endereco.cidade);	
			printf("estado: %s\n", agenda[i].endereco.estado);	
			printf("país: %s\n", agenda[i].endereco.pais);	
			printf("telefone: %s%s\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);	
			printf("aniversário: %s/%s/%s\n", agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano);	
			printf("Observações: %s\n", agenda[i].observacao);	
		}
	}
}

void buscaMes (PESSOA agenda[]) { //busca pessoas pelo mes de aniversário (d)
	char mes;
	int v = 1;
	printf("insira o mes desejado:\n");
	gets(mes);
	while (mes < 1 || mes > 12) {
		printf("insira um mês válido:\n");
		gets(mes);
	}
	for (int i = 0; i > 100; i++) {
		if (agenda[i].data.mes == mes) {
			printf("nome: %s\n", agenda[i].nome);
			printf("eMail: %s\n", agenda[i].eMail);	
			printf("rua: %s\n", agenda[i].endereco.rua);	
			printf("numero: %d\n", agenda[i].endereco.numero);	
			printf("complemento: %s\n", agenda[i].endereco.complemento);	
			printf("bairro: %s\n", agenda[i].endereco.bairro);	
			printf("CEP: %s\n", agenda[i].endereco.cep);	
			printf("cidade: %s\n", agenda[i].endereco.cidade);	
			printf("estado: %s\n", agenda[i].endereco.estado);	
			printf("país: %s\n", agenda[i].endereco.pais);	
			printf("telefone: %s%s\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);	
			printf("aniversário: %s/%s/%s\n", agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano);	
			printf("Observações: %s\n", agenda[i].observacao);	
		}
	}
}
