#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct cliente{
	char nome[30];
	int conta;
	float saldo;
}cliente;

void aloca(cliente **p,int *tam);
void cadastro(cliente **p,int *tam);
void deposito(cliente **p,int *tam);
void retirada(cliente **p,int *tam);

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	cliente *p_cliente=NULL;
	int tamanho=0,opcao;
	
	printf("Bem-vindo ao sistema de contas bancárias\n\n");
	
	do
	{
		printf("Usuário, escolha uma das opções:\n1.Cadastro 2.Depósito 3.Retirada 4.Sair\nSua escolha: ");
		scanf("%d",&opcao);
		fflush(stdin);
		switch(opcao)
		{
			case 1:
					printf("\nUsuário, você escolheu cadastrar!\n");
					system("pause");
					system("cls");
					aloca(&p_cliente,&tamanho);
					cadastro(&p_cliente,&tamanho);
					printf("\nCadastro realizado com sucesso!\n");
					system("pause");
					system("cls");
			break;
			case 2:
					printf("\nUsuário, você escolheu depositar!\n");
					system("pause");
					system("cls");
					deposito(&p_cliente,&tamanho);
			break;
			case 3:
					printf("\nUsuário, você escolheu retirar!\n");
					system("pause");
					system("cls");
					retirada(&p_cliente,&tamanho);
			break;
			case 4:
					printf("\nUsuário, você escolheu sair! - Obrigado e volte sempre!\n");
			break;
			default:
					printf("\nUsuário, você escolheu uma opção que não existe! Tente novamente...\n");
					system("pause");
					system("cls");
			break;
		}
	}while(opcao!=4);
	
	return 0;
}

void aloca(cliente **p,int *tam)
{
	(*tam)++;
	if((*p=(cliente*)realloc(*p,*tam*sizeof(cliente)))==NULL)
	{
		printf("\nErro de alocação!\n");
		exit(1);
	}
}
void cadastro(cliente **p,int *tam)
{
	int x,check,aux;
	printf("Digite o nome do %d cliente: ",*tam);
	gets((*p+*tam-1)->nome);
	fflush(stdin);
	do
	{
		check=0;
		printf("Digite o número da conta do %d cliente: ",*tam);
		scanf("%d",&aux);
		fflush(stdin);
		for(x=0;x<*tam;x++)
			if((*p+x)->conta==aux)
			{
				check=1;
				printf("\nEste número de conta já está cadastrado! Por favor tente novamente...\n");
				system("pause");
				printf("\n");
				break;
			}
	}while(check==1);
	(*p+*tam-1)->conta=aux;
	printf("Digite o saldo do %d cliente: ",*tam);
	scanf("%f",&(*p+*tam-1)->saldo);
	fflush(stdin);
}
void deposito(cliente **p,int *tam)
{
	int x,aux,check=0;
	float soma;
	printf("Digite o número de sua conta: ");
	scanf("%d",&aux);
	fflush(stdin);
	for(x=0;x<*tam;x++)
		if((*p+x)->conta==aux)
		{
			check=1;
			printf("\nO número de conta digitado foi encontrado com sucesso!\n");
			system("pause");
			break;
		}
	if(check==1)
	{
		printf("\nBem vindo de volta %s!\nSeu saldo atual: %.2f\n",(*p+x)->nome,(*p+x)->saldo);
		printf("\n%s, digite a quantidade que você gostaria de depositar: ",(*p+x)->nome);
		scanf("%f",&soma);
		fflush(stdin);
		(*p+x)->saldo+=soma;
		printf("\nDepósito realizado com sucesso!\n\nConta: %s\nSeu saldo atual: %.2f\n\n",(*p+x)->nome,(*p+x)->saldo);
		system("pause");
	}
	else
	{
		printf("\nO número de conta digitado não foi encontrado!\n");
		system("pause");
	}
	system("cls");
}
void retirada(cliente **p,int *tam)
{
	int x,aux,check=0;
	float sub;
	printf("Digite o número de sua conta: ");
	scanf("%d",&aux);
	fflush(stdin);
	for(x=0;x<*tam;x++)
		if((*p+x)->conta==aux)
		{
			check=1;
			printf("\nO número de conta digitado foi encontrado com sucesso!\n");
			system("pause");
			break;
		}
	if(check==1)
	{
		printf("\nBem vindo de volta %s!\nSeu saldo atual: %.2f\n",(*p+x)->nome,(*p+x)->saldo);
		printf("\n%s, digite a quantidade que você gostaria de retirar: ",(*p+x)->nome);
		scanf("%f",&sub);
		fflush(stdin);
		(*p+x)->saldo-=sub;
		printf("\nRetirada realizada com sucesso!\n\nConta: %s\nSeu saldo atual: %.2f\n\n",(*p+x)->nome,(*p+x)->saldo);
		system("pause");
	}
	else
	{
		printf("\nO número de conta digitado não foi encontrado!\n");
		system("pause");
	}
	system("cls");
}