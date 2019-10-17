#include <stdio.h>
#define numCad 5
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
    for (int i = 0; i < numCad; i++) {

        printf("Escreva o nome(máximo 40 caracteres) : ");
        gets(cadastro[i].nome);

        printf("Escreva a rua(máximo 30 caracteres) : ");
        gets(cadastro[i].endereco.rua);
       
        printf("Escreva o bairro(máximo 30 caracteres): ");
        gets(cadastro[i].endereco.bairro);

        printf("Escreva a cidade(máximo 20 caracteres): ");
        gets(cadastro[i].endereco.cidade);

        do
        {
            printf("Escreva a sigla do estado(máximo 2 caracteres): ");
            gets(cadastro[i].endereco.estado);
            if(cadastro[i].endereco.estado != "AC" || cadastro[i].endereco.estado != "AL" || cadastro[i].endereco.estado != "AP" || cadastro[i].endereco.estado != "AM" || cadastro[i].endereco.estado != "BA" || cadastro[i].endereco.estado != "CE" || cadastro[i].endereco.estado != "DF" || cadastro[i].endereco.estado != "ES" || cadastro[i].endereco.estado != "GO" || cadastro[i].endereco.estado != "MA" || cadastro[i].endereco.estado != "MT" || cadastro[i].endereco.estado != "MS" || cadastro[i].endereco.estado != "MG" || cadastro[i].endereco.estado != "PA" || cadastro[i].endereco.estado != "PB" || cadastro[i].endereco.estado != "PR" || cadastro[i].endereco.estado != "PE" || cadastro[i].endereco.estado != "PI" || cadastro[i].endereco.estado != "RJ" || cadastro[i].endereco.estado != "RN" || cadastro[i].endereco.estado != "RS" || cadastro[i].endereco.estado != "RO" || cadastro[i].endereco.estado != "RR" || cadastro[i].endereco.estado != "SC" || cadastro[i].endereco.estado != "SP" || cadastro[i].endereco.estado != "SE"|| cadastro[i].endereco.estado != "TO")
                printf("Sigla inválida, por favor digite a sigla com apenas dois caracteres maiúsculos");    
        }
        while(cadastro[i].endereco.estado != "AC" || cadastro[i].endereco.estado != "AL" || cadastro[i].endereco.estado != "AP" || cadastro[i].endereco.estado != "AM" || cadastro[i].endereco.estado != "BA" || cadastro[i].endereco.estado != "CE" || cadastro[i].endereco.estado != "DF" || cadastro[i].endereco.estado != "ES" || cadastro[i].endereco.estado != "GO" || cadastro[i].endereco.estado != "MA" || cadastro[i].endereco.estado != "MT" || cadastro[i].endereco.estado != "MS" || cadastro[i].endereco.estado != "MG" || cadastro[i].endereco.estado != "PA" || cadastro[i].endereco.estado != "PB" || cadastro[i].endereco.estado != "PR" || cadastro[i].endereco.estado != "PE" || cadastro[i].endereco.estado != "PI" || cadastro[i].endereco.estado != "RJ" || cadastro[i].endereco.estado != "RN" || cadastro[i].endereco.estado != "RS" || cadastro[i].endereco.estado != "RO" || cadastro[i].endereco.estado != "RR" || cadastro[i].endereco.estado != "SC" || cadastro[i].endereco.estado != "SP" || cadastro[i].endereco.estado != "SE"|| cadastro[i].endereco.estado != "TO");
        
        do
        {
            printf("Escreva o CEP : ");
            gets(cadastro[i].endereco.cep);
            int verificacao = 0; //verificar o CEP
            for(int j; j < 8; j++)
            {
                if(cadastro[i].endereco.cep[j] < '0' || cadastro[i].endereco.cep[j] > '9')
                    verificacao += 1;
            }
            if(verificacao != 8 || strlen(cadastro[i].endereco.cep) < 8)
                printf("CEP invalido, digite apenas números e no mínimo 8 numeros");
        }
        while (verificacao != 8 || strlen(cadastro[i].endereco.cep) < 8);

        printf("Escreva o salário : ");
        scanf("%f", &cadastro[i].salario);
        getchar();

        do
        {
            printf("Escreva a identidade : ");
            gets(cadastro[i].identidade);
            int verificacao = 0; //verificar a identidade
            for(int j = 0; j < 9; j++)
            {
                if(cadastro[i].identidade[j] < '0' || cadastro[i].identidade[j] > '9')
                    verificacao += 1;
            }
             if(verificacao != 9 || strlen(cadastro[i].identidade) < 9)
                printf("CEP invalido, digite apenas números e no mínimo 9 numeros");
        }while (verificacao != 9 || strlen(cadastro[i].identidade) < 9);

        printf("Escreva o CPF : ");
        gets(cadastro[i].CPF);        
        
         do
        {
            printf("Escreva o estado civil\n 1- solteiro(a)\n 2- casado(a)\n 3- viúvo(a)\n 4- divorciado(a)\n  : ");
            scanf("%c",&cadastro[i].estadoCivil);
            getchar();
        }
        while(cadastro[i].estadoCivil < '1' || cadastro[i].estadoCivil > '4');


        printf("Escreva o telefone : ");
        gets(cadastro[i].telefone);

        printf("Escreva a idade : ");
        scanf("%d", &cadastro[i].idade);

        printf("Escreva o sexo\n 1- masculino\n 2- feminino\n 3- indefinido\n ");
        
        do
        {
            scanf("%c",&cadastro[i].sexo);
        }
        while(cadastro[i].sexo < '1' || cadastro[i].sexo > '3');
    }
}

void achaHomem(CADASTRO cadastro[]){
    for(int i = 0; i < numCad; ++i)
        if(cadastro[i].sexo == '1')
            printf("Indice: %d\nNome: %s\n\n",i,cadastro[i].nome);
}

void achaHomem(CADASTRO cadastro[]){
    for(int i = 0; i < numCad; ++i)
        if(cadastro[i].salario > 1000)
            printf("Indice: %d\nNome: %s\n\n",i,cadastro[i].nome);
}

int main(void){
    CADASTRO cadastro[numCad];
    preencheVetor(cadastro);
}
