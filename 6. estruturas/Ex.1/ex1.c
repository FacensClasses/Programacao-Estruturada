#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct cliente{
	char nome[30];
	int conta;
	float saldo;
}cliente;
typedef struct grupo{
	cliente clientes[10];
}grupo;

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	int x,j,opcao=0,verif,conta_existe;
	float aux;
	grupo pessoas={0};
	
	printf("Bem-vindo ao sistema bancário!\n\n");
	
	do
	{
		printf("Usuário escolha uma das três opções:\n1.Cadastro 2.Depósito 3.Retirada 4.sair\nSua escolha: ");
		scanf("%d",&opcao);
		fflush(stdin);
		switch(opcao)
		{
			case 1: 
					verif=0;
					for(x=0;x<10;x++)
					{
						if(pessoas.clientes[x].conta==0)
						{
							verif=1;
							break;
						}
					}
					if(verif==1)
					{
						conta_existe=0;
						int nova_conta;
						printf("\nUsuário, digite o seu nome: ");
						gets(pessoas.clientes[x].nome);
						fflush(stdin);
						do
						{
							printf("\nUsuário, digite o número de sua conta: ");
							scanf("%d",&nova_conta);
							fflush(stdin);
							conta_existe=0;
							for(j=0;j<10;j++)
							{
								if(pessoas.clientes[j].conta==nova_conta)
								{
									conta_existe=1;
									printf("Esse número de conta já existe! Tente novamente...\n");
									break;
								}
							}
						}while(conta_existe);
						pessoas.clientes[x].conta=nova_conta;
						printf("\nUsuário, digite seu saldo: ");
						scanf("%f",&pessoas.clientes[x].saldo);
						fflush(stdin);
						printf("\nConta registrada com sucesso!\n");
						system("pause");
						system("cls");
					}
					else
					{
						printf("\nNão há mais espaço para novos cadastros.\n");
						system("pause");
						system("cls");
					}
			break;
			case 2:
					verif=0;
					printf("\nUsuário, digite o número de sua conta corrente: ");
					scanf("%d",&verif);
					fflush(stdin);
					for(x=0;x<10;x++)
						if(verif==pessoas.clientes[x].conta)
						{
							verif=1;
							break;
						}
					if(verif==1)
					{
						printf("\nConta corrente encontrada!\n");	
						printf("\nSeja bem-vindo novamente %s!\nSeu saldo é atualmente: %.2f.\n",pessoas.clientes[x].nome,pessoas.clientes[x].saldo);
						printf("\n%s digite o valor que você gostaria de depositar: ",pessoas.clientes[x].nome);
						scanf("%f",&aux);
						fflush(stdin);
						pessoas.clientes[x].saldo+=aux;
						printf("\n%s seu saldo foi atualizado para: %.2f.\n",pessoas.clientes[x].nome,pessoas.clientes[x].saldo);
						system("pause");
						system("cls");
					}
					else
					{
						printf("\nConta corrente NÃO encontrada!\n");
						system("pause");
						system("cls");
					}
			break;
			case 3:
					verif=0;
					printf("\nUsuário, digite o número de sua conta corrente: ");
					scanf("%d",&verif);
					fflush(stdin);
					for(x=0;x<10;x++)
					if(verif==pessoas.clientes[x].conta)
					{
						verif=1;
						break;
					}
					if(verif==1)
					{
						printf("\nConta corrente encontrada!\n");	
						printf("\nSeja bem-vindo novamente %s!\nSeu saldo é atualmente: %.2f.\n",pessoas.clientes[x].nome,pessoas.clientes[x].saldo);
						printf("\n%s digite o valor que você gostaria de retirar: ",pessoas.clientes[x].nome);
						scanf("%f",&aux);
						fflush(stdin);
						pessoas.clientes[x].saldo-=aux;
						printf("\n%s seu saldo foi atualizado para: %.2f.\n",pessoas.clientes[x].nome,pessoas.clientes[x].saldo);
						system("pause");
						system("cls");
					}
					else
					{
						printf("\nConta corrente NÃO encontrada!\n");
						system("pause");
						system("cls");
					}
			break;
			case 4:
					printf("\nObrigado por usar e escolher nosso serviço! - Volte sempre!\n");
			break;
			default:
					printf("\nUsuário, essa opção não existe. Tente novamente...\n");
					system("pause");
					system("cls");
			break;
		}		
	}while(opcao!=4);

	return 0;
}