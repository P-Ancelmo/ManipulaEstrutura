#include <stdio.h>
#include <string.h>

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

int pessoasInseridas = 0;
void arrumaAgenda(PESSOA agenda[]);

void buscaNome (PESSOA agenda[]) { //busca pessoas pelo nome (c)
	char nome[41];
	printf("Insira o nome desejado:\n");
	scanf("%s",nome);
	for (int i = 0; i > 100; i++) {
		if (strncmp(agenda[i].nome,nome, strlen(nome))== 0) {  //deve procurar só pelo primeiro nome, estou com dúvida sobre como fazer
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
	char mes[3];
	printf("Insira o mes desejado:\n");
	scanf("%c%c", &mes[0], &mes[1]);
	while ((mes[0] != '1' && mes[0] != '0')||(mes[0] == '1' && mes[1]>'2')) {
		printf("insira um mês válido:\n");
		scanf("%c%c", &mes[0], &mes[1]);
	}
	for (int i = 0; i > 100; i++) {
		if (strcmp(agenda[i].data.mes,mes) == 0) {
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

void buscaMeseDia (PESSOA agenda[]) { //busca pessoas pelo mes e dia de aniversário (e)
	char mes[3], dia[3];
	printf("insira o mes desejado:\n");
	scanf("%c%c", &mes[0], &mes[1]);
	while ((mes[0] != '1' && mes[0] != '0')||(mes[0] == '1' && mes[1]>'2')) {
		printf("insira um mês válido:\n");
		scanf("%c%c", &mes[0], &mes[1]);
	}
    printf("insira o dia desejado:\n");
	scanf("%c%c",&dia[0],&dia[1]);
	while (dia[0] > '3' || dia[0] < '0' ||(dia[0] == '3' && dia[1]>'2')) { //falta validar dias para os meses certos (30 ou 31) e ano bissexto
		printf("insira um dia válido:\n");
		scanf("%c%c", &dia[0], &dia[1]);
	}
	for (int i = 0; i > 100; i++) {
		if (strcmp(agenda[i].data.mes,mes) == 0 && strcmp(agenda[i].data.dia,dia) == 0) {
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

void inserePessoa(PESSOA agenda[]){
    printf("nome: ");
    scanf("%s",agenda[pessoasInseridas].nome);
    printf("eMail: ");
    scanf("%s",agenda[pessoasInseridas].eMail);	
    printf("rua: ");
    scanf("%s",agenda[pessoasInseridas].endereco.rua);	
    printf("numero: ");	
    scanf("%d", &agenda[pessoasInseridas].endereco.numero);
    printf("complemento: ");
    scanf("%s",agenda[pessoasInseridas].endereco.complemento);	
    printf("bairro: ");	
    scanf("%s",agenda[pessoasInseridas].endereco.bairro);
    printf("CEP: ");	
    scanf("%s",agenda[pessoasInseridas].endereco.cep);
    printf("cidade: ");	
    scanf("%s",agenda[pessoasInseridas].endereco.cidade);
    printf("estado: ");	
    scanf("%s",agenda[pessoasInseridas].endereco.estado);
    printf("país: ");	
    scanf("%s",agenda[pessoasInseridas].endereco.pais);
    printf("DDD: ");	
    scanf("%s",agenda[pessoasInseridas].telefone.ddd);
    printf("telefone: ");	
    scanf("%s",agenda[pessoasInseridas].telefone.numero);
    printf("aniversário: ");	
    scanf("%s/%s/%s",agenda[pessoasInseridas].data.dia, agenda[pessoasInseridas].data.mes, agenda[pessoasInseridas].data.ano);
    printf("Observações: ");	
    scanf("%s",agenda[pessoasInseridas].nome);

    
    pessoasInseridas++;

}

int main () {
	int opc = 0;	
    PESSOA agenda[100];//declarar variável agenda (b)
	while (opc != 7) {	
		printf("escolha uma opção:\n");
		printf("1 - inserir pessoa\n2 - retirar pessoa\n3 - buscar por nome\n4 - buscar por mes\n 5 - buscar por mes e dia\n 6 - mostrar agenda\n7 - sair\n");
        scanf("%d",&opc);
		switch(opc) {
			case 1:
				arrumaAgenda(agenda);
				break;
			case 2:
				//retiraPessoa(agenda);
				break;
			case 3:
				buscaNome(agenda);
				break;
			case 4:
				buscaMes(agenda);
				break;
			case 5:
				buscaMeseDia(agenda);
				break;
			case 6:
				//imprimeAgenda(agenda);
				break;
			case 7:
				break;
			default:
				printf("comando inválido\n");
				break;
		}
	}
}
void arrumaAgenda(PESSOA agenda[]){
    int arrumado = 0, x = 0;
    PESSOA aux;
    while(arrumado == 0){
        arrumado = 1;
        for(int i=1; i < pessoasInseridas - x; ++i, ++x){
            if(strcmp(agenda[i-1].nome,agenda[i].nome) > 0){
                aux = agenda[i-1];
                agenda[i-1] = agenda[i];
                agenda[i] = aux;
                arrumado = 0;
            }
        }
    }

}
