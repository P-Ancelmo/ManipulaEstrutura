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
    char eMail[41];
    ENDERECO endereco;
    TELEFONE telefone;
    ANIVERSARIO data;
    char observacao[101];
} PESSOA;

int pessoasInseridas = 0;
int verificacao2;
void arrumaAgenda (PESSOA agenda[]);

void inserePessoa (PESSOA agenda[]){ //insere pessoas por ordem alfabética de nome (a.2)
    char c[20];
    printf("\nNome: ");
    gets(c);
    gets(agenda[pessoasInseridas].nome);
    printf("E-mail: ");
    gets(agenda[pessoasInseridas].eMail);
    printf("Rua: ");
    gets(agenda[pessoasInseridas].endereco.rua);
    printf("Número: ");
    scanf("%d", &agenda[pessoasInseridas].endereco.numero);
    printf("Complemento: ");
    gets(c);
    gets(agenda[pessoasInseridas].endereco.complemento);
    printf("Bairro: ");
    gets(agenda[pessoasInseridas].endereco.bairro);
    //printf("CEP: ");
   //gets(agenda[pessoasInseridas].endereco.cep);

    int verificacao = 0; //verificar o CEP
    do
    {
      printf("CEP: ");
      gets(agenda[pessoasInseridas].endereco.cep);
      verificacao = 0; //verificar o CEP
      for(int j = 0; j < 8; j++)
      {
        if(agenda[pessoasInseridas].endereco.cep[j] >= '0' && agenda[pessoasInseridas].endereco.cep[j] <= '9')
          verificacao += 1;
      }
        if(verificacao != 8 || strlen(agenda[pessoasInseridas].endereco.cep) != 8){
          printf("--CEP invalido, digite apenas 8 numeros--\n");
        }
    }while (verificacao < 8 || strlen(agenda[pessoasInseridas].endereco.cep) < 8);


    printf("Cidade: ");
    gets(agenda[pessoasInseridas].endereco.cidade);
    //printf("Estado(Sigla): ");
    //gets(agenda[pessoasInseridas].endereco.estado);
    do
    {
      printf("Estado(Sigla): ");
      gets(agenda[pessoasInseridas].endereco.estado);
      if(strlen(agenda[pessoasInseridas].endereco.estado) != 2)
        printf("Por favor insira a sigla(2 letras)\n");
    }while(strlen(agenda[pessoasInseridas].endereco.estado) != 2);

    printf("País: ");
    gets(agenda[pessoasInseridas].endereco.pais);
    //printf("DDD: ");
    //gets(agenda[pessoasInseridas].telefone.ddd);
    do
    {
      printf("DDD: ");
      gets(agenda[pessoasInseridas].telefone.ddd);
      verificacao2 = 0;
      for(int j = 0; j < 2; j++)
      {
          if(agenda[pessoasInseridas].telefone.ddd[j] >= '0' && agenda[pessoasInseridas].telefone.ddd[j] <= '9')
              verificacao2 += 1;
      }
      if(verificacao2 != 2 || strlen(agenda[pessoasInseridas].telefone.ddd) < 2)
              printf("--Número invalido, digite exatamente 2 números, incluindo o DDD--\n");
    }while(verificacao2 != 2 || strlen(agenda[pessoasInseridas].telefone.ddd) < 2);

    //printf("Telefone: ");
    //gets(agenda[pessoasInseridas].telefone.numero);
    do
        {
            printf("Telefone: ");
            gets(agenda[pessoasInseridas].telefone.numero);
            verificacao2 = 0;
            for(int j = 0; j < 9; j++)
            {
                if(agenda[pessoasInseridas].telefone.numero[j] >= '0' && agenda[pessoasInseridas].telefone.numero[j] <= '9')
                    verificacao2 += 1;
            }
            if(verificacao2 != 9 || strlen(agenda[pessoasInseridas].telefone.numero) < 9)
                    printf("--Número invalido, digite exatamente 9 números--\n");
        }while(verificacao2 != 9 || strlen(agenda[pessoasInseridas].telefone.numero) < 9);

    printf("Aniversário\n");
    printf("Dia: ");
    gets(agenda[pessoasInseridas].data.dia);
    printf("Mês: ");
    gets(agenda[pessoasInseridas].data.mes);
    printf("Ano: ");
    gets(agenda[pessoasInseridas].data.ano);
    printf("Observações: ");
    gets(agenda[pessoasInseridas].observacao);
    printf("\nPessoa Inserida com sucesso!\n\n");
    pessoasInseridas++;
}

void retiraPessoa (PESSOA agenda[]){ //retira pessoa: retira todos os dados dessa pessoa e desloca todos os elementos seguintes do vetor para a posição anterior (b.2)
    char nome[41];
    printf("\nQual pessoa gostaria de retirar de sua agenda? (Atenção: ao digitar o nome dessa pessoa você estará retirando todos os dados da mesma)\n");
    printf("Nome da pessoa a ser retirada: ");
    scanf("%s", nome);
    int i = 0;
    while (strncmp(agenda[i].nome, nome, strlen(nome)) != 0 && i < pessoasInseridas){
        i++;
    }
    if (i == pessoasInseridas){
        printf("\n--Nenhuma pessoa encontrada!\n\n");
        return;
    }
    for (; i < pessoasInseridas - 1; i++){
        agenda[i] = agenda[i+1];
    }
    printf("\nPessoa excluída com sucesso!\n\n");
    pessoasInseridas--;
}

void buscaNome (PESSOA agenda[]){ //busca pessoas pelo nome (c)
    char nome[41];
    int pessoas = 0;
    printf("\nInsira o nome desejado: ");
    char c[40];
    gets(c);
    gets(nome);
    for (int i = 0; i < pessoasInseridas; i++){
        if (strncmp(agenda[i].nome, nome, strlen(nome)) == 0){
            printf("\nNome: %s\n", agenda[i].nome);
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
            pessoas = 1;
        }
    }
    if(pessoas == 0)
      printf("\n--Nenhuma pessoa encontrada\n");
}

void buscaMes (PESSOA agenda[]){ //busca pessoas pelo mês de aniversário (d)
    char mes[3];
    int pessoas = 0;
    printf("\nInsira o mês desejado: ");
    scanf("%s", mes);
    while ((mes[0] != '0' && mes[0] != '1') || (mes[0] == '1' && mes[1] > '2')){
        printf("\nInsira um mês válido: ");
        scanf("%s", mes);
    }
    for (int i = 0; i < pessoasInseridas; i++){
        if (strcmp(agenda[i].data.mes, mes) == 0){
            printf("Nome: %s\n", agenda[i].nome);
            printf("E-mail: %s\n", agenda[i].eMail);
            printf("Rua: %s\n", agenda[i].endereco.rua);
            printf("Numero: %d\n", agenda[i].endereco.numero);
            printf("Complemento: %s\n", agenda[i].endereco.complemento);
            printf("Bairro: %s\n", agenda[i].endereco.bairro);
            printf("CEP: %s\n", agenda[i].endereco.cep);
            printf("Cidade: %s\n", agenda[i].endereco.cidade);
            printf("Estado: %s\n", agenda[i].endereco.estado);
            printf("Pais: %s\n", agenda[i].endereco.pais);
            printf("Telefone: %s%s\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);
            printf("Aniversario: %s/%s/%s\n", agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano);
            printf("Observacoes: %s\n", agenda[i].observacao);
            pessoas = 1;
        }
    }
    if(pessoas == 0)
      printf("\n--Nenhuma pessoa encontrada\n");
}

void buscaMeseDia (PESSOA agenda[]){ //busca pessoas pelo mês e dia de aniversário (e)
    char mes[3], dia[3];
    int pessoas = 0;
    printf("\nInsira o mês desejado: ");
    scanf("%s", mes);
    while ((mes[0] != '0' && mes[0] != '1') || (mes[0] == '1' && mes[1] > '2')){
        printf("\nInsira um mês válido: ");
        scanf("%s", mes);
    }
    printf("\nInsira o dia desejado: ");
    scanf("%s", dia);
    while (dia[0] > '3' || dia[0] < '0' || (dia[0] == '3' && dia[1] > '2')){ //falta validar dias para os meses certos (30 ou 31) e ano bissexto
        printf("\nInsira um dia válido: ");
        scanf("%s", dia);
    }
    for (int i = 0; i < 100; i++){
        if (strcmp(agenda[i].data.mes, mes) == 0 && strcmp(agenda[i].data.dia, dia) == 0){
            printf("\n\nNome: %s\n", agenda[i].nome);
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
            pessoas = 1;
        }

    }
    if(pessoas == 0)
      printf("\n--Nenhuma pessoa encontrada\n");
}

void imprimeAgenda (PESSOA agenda[]){ //imprime a agenda de dois modos: nome, telefone e email ou todos os dados (c.2)
    int modo;
    printf("\nQuais dados de cada pessoa de sua agenda você gostaria de ver?\nOpções:\n1 - Nome, E-mail e Telefone\n2 - Todos (Nome, Telefone, E-mail, Endereco, Telefone, Aniversário etc)");
    printf("\n\nEscolho a opção: ");
    scanf("%d", &modo);
    while (modo != 1 && modo != 2){
        printf("\nOpção inválida! Digite um número de opção válido:\n");
        printf("Quais dados de cada pessoa de sua agenda você gostaria de ver?\nOpções:\n1 - Nome, E-mail e Telefone\n2 - Todos (Nome, Telefone, E-mail, Endereco, Telefone, Aniversário etc)");
        printf("\n\nEscolho a opção: ");
        scanf("%d", &modo);
    }
    if (modo == 1){
        for (int i = 0; i < pessoasInseridas; i++){
            printf("\nNome: %s\n", agenda[i].nome);
            printf("E-mail: %s\n", agenda[i].eMail);
            printf("Telefone: (%s) %s\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);
        }
    }
    if (modo == 2){
        for (int i = 0; i < pessoasInseridas; i++){
            printf("\nNome: %s\n", agenda[i].nome);
            printf("E-mail: %s\n", agenda[i].eMail);
            printf("Rua: %s\n", agenda[i].endereco.rua);
            printf("Número: %d\n", agenda[i].endereco.numero);
            printf("Complemento: %s\n", agenda[i].endereco.complemento);
            printf("Bairro: %s\n", agenda[i].endereco.bairro);
            printf("CEP: %s\n", agenda[i].endereco.cep);
            printf("Cidade: %s\n", agenda[i].endereco.cidade);
            printf("Estado: %s\n", agenda[i].endereco.estado);
            printf("País: %s\n", agenda[i].endereco.pais);
            printf("Telefone: (%s) %s\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);
            printf("Aniversário: %s/%s/%s\n", agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano);
            printf("Observações: %s\n", agenda[i].observacao);
        }
    }
}

int main (){
    char opc = '0';
    PESSOA agenda[100]; //declarar variável agenda (b)
    //menu principal oferecendo as diversas opções distintas existentes nesse programa (a.3)
    printf("\n-------------------- Seja bem-vindo a sua Agenda Digital! --------------------");
    while (opc != '7'){
        printf("\n\nEscolha uma dentre as opções a seguir:\n");
        printf("1 - Inserir pessoa\n2 - Retirar pessoa\n3 - Buscar por nome\n4 - Buscar por mês do Aniversário\n5 - Buscar por mês e dia do Aniversário\n6 - Mostrar agenda\n7 - Sair\n");
        printf("\nEscolho a opção: ");
        scanf("%c", &opc);
        getchar();
        if(opc >= '1'  && opc <= '7' && opc != '1' && opc != '7' && pessoasInseridas==0){
              printf("Agenda Vazia\n");
        }else{
          switch (opc){
              case '1':
                  inserePessoa(agenda);
                  arrumaAgenda(agenda);
                  break;
              case '2':
                  retiraPessoa(agenda);
                  break;
              case '3':
                  buscaNome(agenda);
                  break;
              case '4':
                  buscaMes(agenda);
                  break;
              case '5':
                  buscaMeseDia(agenda);
                  break;
              case '6':
                  imprimeAgenda(agenda);
                  break;
              case '7':
                  return 0;
                  break;
              default:
                  printf("\nComando inválido!\n");
                  break;
          }
        }
        do{
            printf("\nDeseja continuar?\n1 - Sim\n2 - Não\n");
            printf("\nEscolho: ");
            scanf("%c", &opc);
            getchar();
            if (opc != '1' && opc != '2'){
                printf("Comando inválido!\n");
            }else if (opc == '2'){
                return 0;
            }
        }while (opc != '1' && opc != '2');
    }
    return 0;
}
void arrumaAgenda (PESSOA agenda[]){
    int arrumado = 0, x = 0;
    PESSOA aux;
    while (arrumado == 0){
        arrumado = 1;
        for (int i = 1; i < pessoasInseridas - x; ++i){
            if (strcmp(agenda[i-1].nome, agenda[i].nome) > 0){
                aux = agenda[i-1];
                agenda[i-1] = agenda[i];
                agenda[i] = aux;
                arrumado = 0;
            }
        }
        x++;
    }
}

void verificarPessoas(){

}
