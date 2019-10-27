#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char rua[31];
    int numero;
    char complemento[31];
    char bairro[31];
    char cep[9];
    char cidade[21];
    char estado[3];
    char pais[31];
} ENDERECO;

typedef struct{
    char ddd[3];
    char numero[10];
} TELEFONE;

typedef struct{
    char dia[3];
    char mes[3];
    char ano[5];
} ANIVERSARIO;

typedef struct{
    char nome[41];
    char eMail[21];
    ENDERECO endereco;
    TELEFONE telefone;
    ANIVERSARIO data;
    char observacao[101];
} PESSOA;

int pessoasInseridas = 0;
void arrumaAgenda (PESSOA agenda[]);

void inserePessoa (PESSOA agenda[]){ //insere pessoas por ordem alfabética de nome (a.2)
    printf("Nome: ");
    scanf("%s",agenda[pessoasInseridas].nome);
    printf("E-mail: ");
    scanf("%s",agenda[pessoasInseridas].eMail);
    printf("Rua: ");
    scanf("%s",agenda[pessoasInseridas].endereco.rua);
    printf("Número: ");
    scanf("%d", &agenda[pessoasInseridas].endereco.numero);
    printf("Complemento: ");
    scanf("%s",agenda[pessoasInseridas].endereco.complemento);
    printf("Bairro: ");
    scanf("%s",agenda[pessoasInseridas].endereco.bairro);
    printf("CEP: ");
    scanf("%s",agenda[pessoasInseridas].endereco.cep);
    printf("Cidade: ");
    scanf("%s",agenda[pessoasInseridas].endereco.cidade);
    printf("Estado: ");
    scanf("%s",agenda[pessoasInseridas].endereco.estado);
    printf("País: ");
    scanf("%s",agenda[pessoasInseridas].endereco.pais);
    printf("DDD: ");
    scanf("%s",agenda[pessoasInseridas].telefone.ddd);
    printf("Telefone: ");
    scanf("%s",agenda[pessoasInseridas].telefone.numero);
    printf("Aniversário: ");
    scanf("%s/%s/%s", agenda[pessoasInseridas].data.dia, agenda[pessoasInseridas].data.mes, agenda[pessoasInseridas].data.ano);
    printf("Observações: ");
    scanf("%s", agenda[pessoasInseridas].observacao);
    
    pessoasInseridas++;
}

void retiraPessoa (PESSOA agenda[]){ //retira pessoa: retira todos os dados dessa pessoa e desloca todos os elementos seguintes do vetor para a posição anterior (b.2)
    char nome[41];
    printf("Qual pessoa gostaria de retirar de sua agenda? (Atenção: ao digitar o nome dessa pessoa você estará retirando todos os dados da mesma)\n");
    printf("Nome da pessoa a ser retirada: ");
    scanf("%s", nome);
    for (int i = 0; i < pessoasInseridas; i++){
        if (strncmp(agenda[i].nome, nome, strlen(nome)) == 0){
            for (int j = i; j < pessoasInseridas - 1; j++){
                agenda[j] = agenda[j+1];
            }
            pessoasInseridas--;
        }
    }
}

void buscaNome (PESSOA agenda[]){ //busca pessoas pelo nome (c)
    char nome[41];
    printf("Insira o nome desejado:\n");
    scanf("%s", nome);
    for (int i = 0; i < 100; i++){
        if (strncmp(agenda[i].nome, nome, strlen(nome)) == 0){
            printf("Nome: %s\n", agenda[i].nome);
            printf("E-mail: %s\n", agenda[i].eMail);
            printf("Rua: %s\n", agenda[i].endereco.rua);
            printf("Número: %d\n", agenda[i].endereco.numero);
            printf("Complemento: %s\n", agenda[i].endereco.complemento);
            printf("Bairro: %s\n", agenda[i].endereco.bairro);
            printf("CEP: %s\n", agenda[i].endereco.cep);
            printf("Cidade: %s\n", agenda[i].endereco.cidade);
            printf("Estado: %s\n", agenda[i].endereco.estado);
            printf("País: %s\n", agenda[i].endereco.pais);
            printf("Telefone: %s%s\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);
            printf("Aniversário: %s/%s/%s\n", agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano);
            printf("Observações: %s\n", agenda[i].observacao);
        }
    }
}

void buscaMes (PESSOA agenda[]){ //busca pessoas pelo mês de aniversário (d)
    char mes[3];
    printf("Insira o mês desejado:\n");
    scanf("%c%c", &mes[0], &mes[1]);
    while ((mes[0] != '1' && mes[0] != '0') || (mes[0] == '1' && mes[1] > '2')){
        printf("Insira um mês válido:\n");
        scanf("%c%c", &mes[0], &mes[1]);
    }
    for (int i = 0; i < 100; i++){
        if (strcmp(agenda[i].data.mes,mes) == 0){
            printf("Nome: %s\n", agenda[i].nome);
            printf("E-mail: %s\n", agenda[i].eMail);
            printf("Rua: %s\n", agenda[i].endereco.rua);
            printf("Número: %d\n", agenda[i].endereco.numero);
            printf("Complemento: %s\n", agenda[i].endereco.complemento);
            printf("Bairro: %s\n", agenda[i].endereco.bairro);
            printf("CEP: %s\n", agenda[i].endereco.cep);
            printf("Cidade: %s\n", agenda[i].endereco.cidade);
            printf("Estado: %s\n", agenda[i].endereco.estado);
            printf("País: %s\n", agenda[i].endereco.pais);
            printf("Telefone: %s%s\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);
            printf("Aniversário: %s/%s/%s\n", agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano);
            printf("Observações: %s\n", agenda[i].observacao);
        }
    }
}

void buscaMeseDia (PESSOA agenda[]){ //busca pessoas pelo mês e dia de aniversário (e)
    char mes[3], dia[3];
    printf("Insira o mês desejado:\n");
    scanf("%c%c", &mes[0], &mes[1]);
    while ((mes[0] != '1' && mes[0] != '0') || (mes[0] == '1' && mes[1] > '2')){
        printf("Insira um mês válido:\n");
        scanf("%c%c", &mes[0], &mes[1]);
    }
    printf("Insira o dia desejado:\n");
    scanf("%c%c", &dia[0], &dia[1]);
    while (dia[0] > '3' || dia[0] < '0' || (dia[0] == '3' && dia[1] > '2')){ //falta validar dias para os meses certos (30 ou 31) e ano bissexto
        printf("Insira um dia válido:\n");
        scanf("%c%c", &dia[0], &dia[1]);
    }
    for (int i = 0; i < 100; i++){
        if (strcmp(agenda[i].data.mes, mes) == 0 && strcmp(agenda[i].data.dia, dia) == 0){
            printf("Nome: %s\n", agenda[i].nome);
            printf("E-mail: %s\n", agenda[i].eMail);
            printf("Rua: %s\n", agenda[i].endereco.rua);
            printf("Número: %d\n", agenda[i].endereco.numero);
            printf("Complemento: %s\n", agenda[i].endereco.complemento);
            printf("Bairro: %s\n", agenda[i].endereco.bairro);
            printf("CEP: %s\n", agenda[i].endereco.cep);
            printf("Cidade: %s\n", agenda[i].endereco.cidade);
            printf("Estado: %s\n", agenda[i].endereco.estado);
            printf("País: %s\n", agenda[i].endereco.pais);
            printf("Telefone: %s%s\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);
            printf("Aniversário: %s/%s/%s\n", agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano);
            printf("Observações: %s\n", agenda[i].observacao);
        }
    }
}

void imprimeAgenda (PESSOA agenda[]){ //imprime a agenda de dois modos: nome, telefone e email ou todos os dados (c.2)
    int modo;
    printf("Quais dados de cada pessoa de sua agenda você gostaria de ver?\nOpções:\n1 - Nome, E-mail e Telefone\n2 - Todos (Nome, Telefone, E-mail, Endereço, Telefone, Aniversário etc)\n");
    printf("Escolho a opção: ");
    scanf("%d", &modo);
    while (modo != 1 || modo != 2){
        printf("Digite um número de opção válida:\n");
        printf("Quais dados de cada pessoa de sua agenda você gostaria de ver?\nOpções:\n1 - Nome, E-mail e Telefone\n2 - Todos (Nome, Telefone, E-mail, Endereço, Telefone, Aniversário etc)\n");
        printf("Escolho a opção: ");
        scanf("%d", &modo);
    }
    if (modo == 1){
        for (int i = 0; i < 100; i++){
            printf("Nome: %s\n", agenda[i].nome);
            printf("E-mail: %s\n", agenda[i].eMail);
            printf("Telefone: %s%s\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);
        }
    }
    if (modo == 2){
        for (int i = 0; i < 100; i++){
            printf("Nome: %s\n", agenda[i].nome);
            printf("E-mail: %s\n", agenda[i].eMail);
            printf("Rua: %s\n", agenda[i].endereco.rua);
            printf("Número: %d\n", agenda[i].endereco.numero);
            printf("Complemento: %s\n", agenda[i].endereco.complemento);
            printf("Bairro: %s\n", agenda[i].endereco.bairro);
            printf("CEP: %s\n", agenda[i].endereco.cep);
            printf("Cidade: %s\n", agenda[i].endereco.cidade);
            printf("Estado: %s\n", agenda[i].endereco.estado);
            printf("País: %s\n", agenda[i].endereco.pais);
            printf("Telefone: %s%s\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);
            printf("Aniversário: %s/%s/%s\n", agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano);
            printf("Observações: %s\n", agenda[i].observacao);
        }
    }
}

int main (){
    int opc = 0;
    PESSOA agenda[100]; //declarar variável agenda (b)
    while (opc != 7){ //menu principal oferecendo as diversas opções distintas existentes nesse programa (a.3)
        printf("\n-------------------- Seja bem-vindx à sua Agenda Digital! --------------------\n");
        printf("\nEscolha uma opção:\n");
        printf("1 - Inserir pessoa\n2 - Retirar pessoa\n3 - Buscar por nome\n4 - Buscar por mês\n5 - Buscar por mês e dia\n6 - Mostrar agenda\n7 - Sair\n");
        printf("\nEscolho a opção: ");
        scanf("%d\n", &opc);
        switch (opc){
            case 1:
                arrumaAgenda(agenda);
                break;
            case 2:
                retiraPessoa(agenda);
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
                imprimeAgenda(agenda);
                break;
            case 7:
                break;
            default:
                printf("Comando inválido!\n");
                break;
        }
    }
}
void arrumaAgenda (PESSOA agenda[]){
    int arrumado = 0, x = 0;
    PESSOA aux;
    while (arrumado == 0){
        arrumado = 1;
        for (int i = 1; i < pessoasInseridas - x; ++i, ++x){
            if (strcmp(agenda[i-1].nome, agenda[i].nome) > 0){
                aux = agenda[i-1];
                agenda[i-1] = agenda[i];
                agenda[i] = aux;
                arrumado = 0;
            }
        }
    }
    
}
