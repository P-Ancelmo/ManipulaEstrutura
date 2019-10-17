#include <stdio.h>
typedef struct {
    char rua[31];
    char bairro[31];
    char cidade[21];
    char estado[3];
    char cep[9];
} ENDERECO;

typedef struct {
    char nome[41];
    ENDERECO endereco;
    float salario;
    char identidade[10];
    char CPF[12];
    char estadoCivil;
    char telefone[12];
    int idade;
    char sexo;
} CADASTRO;

void preencheVetor (CADASTRO cadastro[]) {
    for (int i = 0; i < 5; i++) {

        printf("Escreva o nome(máximo 40 caracteres) : ");
        gets(cadastro[i].nome);

        printf("Escreva a rua(máximo 30 caracteres) : ");
        gets(cadastro[i].endereco.rua);
       
        printf("Escreva o bairro(máximo 30 caracteres): ");
        gets(cadastro[i].endereco.bairro);

        printf("Escreva a cidade(máximo 20 caracteres): ");
        gets(cadastro[i].endereco.cidade);

        printf("Escreva a sigla do estado(máximo 2 caracteres): ");
        gets(cadastro[i].endereco.estado);

        printf("Escreva o cep : ");
        gets(cadastro[i].endereco.cep);

        printf("Escreva o salário : ");
        scanf("%f", &cadastro[i].salario);

        printf("Escreva a identidade : ");
        gets(cadastro[i].identidade);

        printf("Escreva o CPF : ");
        gets(cadastro[i].CPF);

        printf("Escreva o estado civil\n1- solteiro(a)\n2- casado(a)\n3- viúvo(a)\n4- divorciado(a)\n  : ");
        getchar(cadastro[i].estadoCivil);

        printf("Escreva o telefone : ");
        gets(cadastro[i].telefone);

        printf("Escreva a idade : ");
        scanf("%d", &cadastro[i].idade);

        printf("Escreva o sexo\n1- masculino\n2- feminino\n3- indefinido\n ");
        getchar(cadastro[i].sexo);
    }
}

int main(void){
    CADASTRO cadastro[5];
    preencheVetor(cadastro);
}
