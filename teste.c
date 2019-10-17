#include <stdio.h>
#include <string.h>
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
    for (int i = 0; i < 1; i++) {

        printf("Escreva o nome da %d° pessoa(máximo 40 caracteres): ", i+1);
        gets(cadastro[i].nome);

        printf("Escreva a rua da %d° pessoa(máximo 30 caracteres): ", i+1);
        gets(cadastro[i].endereco.rua);

        printf("Escreva o bairro da %d° pessoa(máximo 30 caracteres): ", i+1);
        gets(cadastro[i].endereco.bairro);

        printf("Escreva a cidade da %d° pessoa(máximo 20 caracteres): ", i+1);
        gets(cadastro[i].endereco.cidade);
        
        do
        {
            printf("Escreva a sigla do estado da %d° pessoa(2 letras): ", i+1);
            gets(cadastro[i].endereco.estado);
            
            if(    strcmp(cadastro[i].endereco.estado, "AC") != 0 && strcmp(cadastro[i].endereco.estado, "AL") != 0 && strcmp(cadastro[i].endereco.estado, "AP") != 0 && strcmp(cadastro[i].endereco.estado, "AM") != 0 && strcmp(cadastro[i].endereco.estado, "BA") != 0 && strcmp(cadastro[i].endereco.estado, "CE") != 0 
                && strcmp(cadastro[i].endereco.estado, "DF") != 0 && strcmp(cadastro[i].endereco.estado, "ES") != 0 && strcmp(cadastro[i].endereco.estado, "GO") != 0 && strcmp(cadastro[i].endereco.estado, "MA") != 0 && strcmp(cadastro[i].endereco.estado, "MT") != 0 && strcmp(cadastro[i].endereco.estado, "MS") != 0
                && strcmp(cadastro[i].endereco.estado, "MG") != 0 && strcmp(cadastro[i].endereco.estado, "PA") != 0 && strcmp(cadastro[i].endereco.estado, "PB") != 0 && strcmp(cadastro[i].endereco.estado, "PR") != 0 && strcmp(cadastro[i].endereco.estado, "PE") != 0 && strcmp(cadastro[i].endereco.estado, "PI") != 0 
                && strcmp(cadastro[i].endereco.estado, "RJ") != 0 && strcmp(cadastro[i].endereco.estado, "RN") != 0 && strcmp(cadastro[i].endereco.estado, "RS") != 0 && strcmp(cadastro[i].endereco.estado, "RO") != 0 && strcmp(cadastro[i].endereco.estado, "RR") != 0 && strcmp(cadastro[i].endereco.estado, "SC") != 0 
                && strcmp(cadastro[i].endereco.estado, "SP") != 0 && strcmp(cadastro[i].endereco.estado, "SE") != 0 && strcmp(cadastro[i].endereco.estado, "TO") != 0){
                    printf("--Sigla inválida, por favor digite a sigla com apenas duas letras maiúsculas--\n");
                    
            }
        }
        while(     strcmp(cadastro[i].endereco.estado, "AC") != 0 && strcmp(cadastro[i].endereco.estado, "AL") != 0 && strcmp(cadastro[i].endereco.estado, "AP") != 0 && strcmp(cadastro[i].endereco.estado, "AM") != 0 && strcmp(cadastro[i].endereco.estado, "BA") != 0 && strcmp(cadastro[i].endereco.estado, "CE") != 0 
                && strcmp(cadastro[i].endereco.estado, "DF") != 0 && strcmp(cadastro[i].endereco.estado, "ES") != 0 && strcmp(cadastro[i].endereco.estado, "GO") != 0 && strcmp(cadastro[i].endereco.estado, "MA") != 0 && strcmp(cadastro[i].endereco.estado, "MT") != 0 && strcmp(cadastro[i].endereco.estado, "MS") != 0
                && strcmp(cadastro[i].endereco.estado, "MG") != 0 && strcmp(cadastro[i].endereco.estado, "PA") != 0 && strcmp(cadastro[i].endereco.estado, "PB") != 0 && strcmp(cadastro[i].endereco.estado, "PR") != 0 && strcmp(cadastro[i].endereco.estado, "PE") != 0 && strcmp(cadastro[i].endereco.estado, "PI") != 0 
                && strcmp(cadastro[i].endereco.estado, "RJ") != 0 && strcmp(cadastro[i].endereco.estado, "RN") != 0 && strcmp(cadastro[i].endereco.estado, "RS") != 0 && strcmp(cadastro[i].endereco.estado, "RO") != 0 && strcmp(cadastro[i].endereco.estado, "RR") != 0 && strcmp(cadastro[i].endereco.estado, "SC") != 0 
                && strcmp(cadastro[i].endereco.estado, "SP") != 0 && strcmp(cadastro[i].endereco.estado, "SE") != 0 && strcmp(cadastro[i].endereco.estado, "TO") != 0);

        int verificacao = 0; //verificar o CEP
        do
        {
            printf("Escreva o CEP da %d° pessoa: ", i+1);
            gets(cadastro[i].endereco.cep);
            verificacao = 0; //verificar o CEP
            for(int j = 0; j < 8; j++)
            {
                if(cadastro[i].endereco.cep[j] >= '0' && cadastro[i].endereco.cep[j] <= '9')
                    verificacao += 1;
            }
            if(verificacao != 8 || strlen(cadastro[i].endereco.cep) != 8){
                printf("--CEP invalido, digite apenas 8 numeros--\n");
            }
        }
        while (verificacao < 8 || strlen(cadastro[i].endereco.cep) < 8);

        printf("Escreva o salário da %d° pessoa: ", i+1);
        scanf("%f", &cadastro[i].salario);
        getchar();

        int verificacao2 = 0; //verificar a identidade
        do
        {
            printf("Escreva a identidade da %d° pessoa: ", i+1);
            gets(cadastro[i].identidade);
            verificacao2 = 0; //verificar a identidade
            for(int j = 0; j < 9; j++)
            {
                if(cadastro[i].identidade[j] >= '0' && cadastro[i].identidade[j] <= '9')
                    verificacao2 += 1;
            }
             if(verificacao2 != 9 || strlen(cadastro[i].identidade) < 9)
                printf("--Identidade invalido, digite apenas 9 números--\n");
        }while (verificacao2 != 9 || strlen(cadastro[i].identidade) < 9);

        do
        {
            printf("Escreva o CPF da %d° pessoa : ", i+1);
            gets(cadastro[i].CPF);
            verificacao2 = 0;
            for(int j = 0; j < 11; j++)
            {
                if(cadastro[i].CPF[j] >= '0' && cadastro[i].CPF[j] <= '9')
                    verificacao2 += 1;
            }
             if(verificacao2 != 11 || strlen(cadastro[i].CPF) < 11)
                printf("--Identidade invalido, digite exatamente 11 números--\n");

        }while(verificacao2 != 11 || strlen(cadastro[i].CPF) < 11);

         do
        {
            printf("Escreva o estado civil da %d° pessoa\n 1- solteiro(a)\n 2- casado(a)\n 3- viúvo(a)\n 4- divorciado(a)\n Reposta: ", i+1);
            scanf("%c",&cadastro[i].estadoCivil);
            getchar();
            if(cadastro[i].estadoCivil < '1' || cadastro[i].estadoCivil > '4')
                printf("--Opção inválida, por favor digite confor o mostrado--\n");
        }
        while(cadastro[i].estadoCivil < '1' || cadastro[i].estadoCivil > '4');

        do
        {
            printf("Escreva o telefone da %d° pessoa: ", i+1);
            gets(cadastro[i].telefone);
            verificacao2 = 0;
            for(int j = 0; j < 11; j++)
            {
                if(cadastro[i].telefone[j] >= '0' && cadastro[i].telefone[j] <= '9')
                    verificacao2 += 1;                
            }
            if(verificacao2 != 11 || strlen(cadastro[i].telefone) < 11)
                    printf("--Número invalido, digite exatamente 11 números, incluindo o DDD--\n");
        }while(verificacao2 != 11 || strlen(cadastro[i].telefone) < 11);


        printf("Escreva a idade da %d° pessoa: ", i+1);
        scanf("%d", &cadastro[i].idade);
        getchar();        

        do
        {
            printf("Escreva o sexo da %d° pessoa\n 1- masculino\n 2- feminino\n 3- indefinido\nResposta: ", i+1);
            scanf("%c",&cadastro[i].sexo);
            getchar();
            if(cadastro[i].sexo < '1'|| cadastro[i].sexo > '3')
                printf("--Opção inválida, por favor digite confor o mostrado--\n");
        }
        while(cadastro[i].sexo < '1' || cadastro[i].sexo > '3');
    }
}

void achaHomem(CADASTRO cadastro[]){
    for(int i = 0; i < numCad; ++i)
        if(cadastro[i].sexo == '1')
            printf("Indice: %d\nNome: %s\n\n",i,cadastro[i].nome);
}

void achaSalario(CADASTRO cadastro[]){
    for(int i = 0; i < numCad; ++i)
        if(cadastro[i].salario > 1000)
            printf("Indice: %d\nNome: %s\n\n",i,cadastro[i].nome);
}



int achaRG(CADASTRO cadastro[]){
    char rg[10], continuar;
    do{
        int verificador;
        do
        {   
            verificador = 0;
            printf("Digite uma identidade para visualização: ");
            scanf("%s",rg);
            getchar();        
            for(int i = 0; i < numCad; ++i){
                if(strcmp(cadastro[i].identidade,rg) == 0){
                    printf("=>Nome: %s\n",cadastro[i].nome);
                    printf("=>Rua: %s\n",cadastro[i].endereco.rua);
                    printf("=>Bairro: %s\n",cadastro[i].endereco.bairro);
                    printf("=>Cidade: %s\n",cadastro[i].endereco.cidade);
                    printf("=>Estado: %s\n",cadastro[i].endereco.estado);
                    printf("=>CEP: %s\n",cadastro[i].endereco.cep);
                    printf("=>Salario: %.2f\n",cadastro[i].salario);
                    printf("=>RG: %s\n",cadastro[i].identidade);
                    printf("=>CPF: %s\n",cadastro[i].CPF);
                    switch(cadastro[i].estadoCivil){
                        case '1':
                            printf("=>Estado civil: solteiro(a)\n");
                            break;
                        case '2':
                            printf("=>Estado civil: casado(a)\n");
                            break;
                        case '3':
                            printf("=>Estado civil: divorciado(a)\n");
                            break;
                        case '4':
                            printf("=>Estado civil: viuvo(a)\n");
                    }            
                    printf("=>Telefone: %s\n",cadastro[i].telefone);
                    printf("=>Idade: %d\n",cadastro[i].idade);
                    switch(cadastro[i].sexo){
                        case '1':
                            printf("=>Sexo: masculino\n");
                            break;
                        case '2':
                            printf("=>Sexo: feminino\n");
                            break;
                        case '3':
                            printf("=>Sexo: indefinido\n");
                            break;
                    }            
                    verificador++; //identidade válida
                }        
            }            
            if(verificador == 0)
                printf("--Identidade inválida--\n");
        }while(verificador == 0);
        printf("Deseja continuar? S - Sim N - Nao: ");
        scanf("%c",&continuar);
        getchar();
    }while(continuar == 'S');
}

int main(void){
    CADASTRO cadastro[numCad];
    preencheVetor(cadastro);    
    achaRG(cadastro);
    return 0;
}
