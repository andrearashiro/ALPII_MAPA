#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Criando uma struct com os dados para o tipo vacina
struct vacina{
  int codeNumber, lote;
  char name[100];
  char CPF[15];
  char model[40];
  char date[12];     
};

//Procedimento (subrotina) para efetuar o cadastro
void cadastrar(struct vacina * cadastro, int * nCadastro){

  printf("|==|==|==|==|==| Opção cadastrar vacina selecionado |==|==|==|==|==|\n\n");
  printf("o nCadastro é: %d \n", * nCadastro);
  //Início da entrada de dados
  printf("Digite o número da Carteira de Vacinação: ");  
    scanf("%d", &cadastro[* nCadastro].codeNumber);
    __fpurge(stdin);
  printf("\nDigite o nome completo do vacinado: ");
    scanf("%s", * &cadastro[* nCadastro].name);
    __fpurge(stdin);
  printf("\nDigite o CPF do vacinado no formato 000.000.000-00: ");
    scanf("%s", * &cadastro[* nCadastro].CPF);
    __fpurge(stdin);
  printf("\nDigite a fabricante da vacina (ex. Pfizer, Modena, Astrazeneca): ");
    scanf("%s", * &cadastro[* nCadastro].model);
    __fpurge(stdin);
  printf("\nDigite a data de hoje, no formato DD/MM/AA: ");
    scanf("%s", * &cadastro[* nCadastro].date);
    __fpurge(stdin);
  printf("\nDigite o lote da vacina (somente números): ");
    scanf("%d", &cadastro[* nCadastro].lote); 
  //Fim da entrada de dados  
  printf("Cadastro realizado com sucesso \n\n");
     
 };

//Procedimento para listar os vacinados cadastrados;
void listarVacinados(struct vacina * cadastro, int * nCadastro){
  
system("clear");
  printf("|==|==|==|==|==| Cadastro de pessoas vacinadas |==|==|==|==|==| \n\n");
  int count;
  for (count = 0; count < * nCadastro; count++){
    
  printf("*******************************");
  printf("\nNº Carteira Vacina: (%d)\nNome: %s\nCPF: %s\nFabricante: %s\nData: %s\nLote: %d \n",  cadastro[count].codeNumber, cadastro[count].name, cadastro[count].CPF, cadastro[count].model, cadastro[count].date, cadastro[count].lote);
     
  };
  printf("\n|==|==|==|==|==| Fim da listagem |==|==|==|==|==|\n\n"); 
};

//Procedimento para fazer busca
void buscaCPF(struct vacina * cadastro, int * nCadastro){
  
system("clear");
  char cpfBuscado[30];
  int count = 0;  
  int achar = 0;

  printf("Digite o número do CPF que deseja buscar: ");
  scanf("%s", cpfBuscado);
  
  printf("\nO CPF buscado é: %s \n", cpfBuscado);

  /*for (count = 0; count < *nCadastro; count++)
    printf("%d \n", strcmp(cadastro[count].CPF, cpfBuscado));*/

     while((count <= *nCadastro) && (achar == 0)){
    if (strcmp(cpfBuscado,cadastro[count].CPF) == 0){
      achar = 1;
    }else{
      count++;
    };
  }
  if (achar == 1){
    printf("Encontrado, os dados buscados são: \n");
    printf("\nNº Carteira Vacina: (%d)\nNome: %s\nCPF: %s\nFabricante: %s\nData: %s\nLote: %d \n",  cadastro[count].codeNumber, cadastro[count].name, cadastro[count].CPF, cadastro[count].model, cadastro[count].date, cadastro[count].lote);
    
  }else{
    printf("Não achei! \n");
  } 
}
 
int main(void) {
  //Criação do menu utilizando switch

  setlocale(LC_ALL, "Portuguese");
  int option = 0, nCadastro = 0;
       
  struct vacina cadastro;     

  printf(" #======# Bem vindo ao sistema de Vacinas! (v 1.0.) #======# \n\n");  
  
  while(option != 4){
    printf("Escolha uma das opções abaixo: \n");
    printf(" 1) ===> Cadastro de vacinados \n 2) ===> Listagem dos vacinados \n 3) ===> Buscar vacinado pelo CPF \n 4) ===> Sair do Sistema \n Digite a opção:  ");
    scanf("%d", &option);

  switch(option){
    case 1: system("clear");
            cadastrar(&cadastro, &nCadastro);
            nCadastro++;
    break;
    case 2: listarVacinados(&cadastro, &nCadastro);
    break;
    case 3: buscaCPF(&cadastro, &nCadastro);
    break;
    case 4: printf("Obrigado por usar o sistema!");
    break;
    default: printf("Opção inválida! \n\n");
      return main();
      
    }
  }     
  return 0;
}
