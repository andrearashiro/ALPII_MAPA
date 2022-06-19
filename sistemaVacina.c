#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Criando a estrutura para receber os cadastro de vacina
struct vacina
{

    int codigo;
    char nome[100];
    char CPF[15];
    char vacina[30];
    char data[10];
    int lote;
    
};

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
    int option, nCadastro, i, j, acha, buscado;
    char busca[15];
    struct vacina cadastro[nCadastro];
    
    option = 0;
    nCadastro = 0;
        
    printf("<#>--- Bem vindo ao sistema de cadastro de vacina ---<#> \n");
   			
        while (option != 4){

            printf("\n\n Escolha uma opção abaixo: \n [1] ==> Cadastro de Vacina. \n [2] ==> Listagem de Vacinados. \n [3] ==> Consulta de Vacinados por CPF. \n [4] ==> Sair do Sistema. \n Opção: ");
			scanf("%d", &option);
			
            if(option == 1){
                system("cls");
               
                printf("Digite os dados abaixo para cadastrar o vacinado: \n\n");
                printf("Código da Carteira de Vacinação (somente números): \n");
                scanf("%d", &cadastro[nCadastro].codigo);
                fflush(stdin);
                printf("\n### Nome completo:\n");
                scanf("%100[^\n]s", &cadastro[nCadastro].nome);
                fflush(stdin);
                printf("\n### CPF no formato 000.000.000-00:\n");
                scanf("%15[^\n]s", &cadastro[nCadastro].CPF);
                fflush(stdin);
                printf("\n### Digite o fabricante da vacina - Ex: Pfizer, Astrazeneca, Coronavac, etc: \n");
                scanf("%30[^\n]s", &cadastro[nCadastro].vacina);
                fflush(stdin);
                printf("\n### Digite a data no formato DD/MM/AAAA: \n");
                scanf("%10[^\n]s", &cadastro[nCadastro].data);
                fflush(stdin);
                printf("\n### Digite o lote (somente números): \n");
                scanf("%d", &cadastro[nCadastro].lote);
                fflush(stdin);
                printf("\n### Cadastro concluído ###\n");
                                
                nCadastro++;             
                
            }else{
            	
            	if(option == 2){
            		
            	system("cls");
            	printf("Listagem de pessoas vacinadas: \n");
            	
            	for (i = 0; i<nCadastro; i++){
            		printf("\n <<<<<<<< VACINADO Nº 00%d >>>>>>>> \n\n", i+1);
            		printf("1) Carteira Vacinação: %d \n", cadastro[i].codigo);
            		printf("2) Nome: %s \n", cadastro[i].nome);
            		printf("3) CPF: %s \n", cadastro[i].CPF);
            		printf("4) Fabricante vacina: %s \n", cadastro[i].vacina);
            		printf("5) Data Vacinação: %s \n", cadastro[i].data);
            		printf("6) Lote: %d \n", cadastro[i].lote);
            		
            	
			}
        }else{
        	if(option == 3){
        		system("cls");
        		printf("Digite o CPF para realizar o registro da vacina: \n CPF: ");
        		scanf("%s", busca);
        		fflush(stdin);
        		acha == 0;
        		
        		printf("%s \n", busca);
        		printf("%s \n", cadastro[0].CPF);
        		printf("%s \n", cadastro[1].CPF);
        		
        		acha = atoi(cadastro[0].CPF);
        		buscado = atoi(busca);
        		printf("%d", acha);
        		printf("%d", buscado);
        		
        		
        		if(buscado == acha){
        			printf("Achei!");
				}else{
					printf("Não Achei");
				}
        		
					
			}else{
				if(option == 4){
					printf("Saindo do Sistema");
				}
			}
		}
	} 
}

return 0;
}