#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct aluno{
	char nome[80];
	char RA[7];
	float nota[2];
	float media;
}aluno;

void aloca(aluno **p,int *tam);
void cadastro(aluno **p,int *tam);
void controle(aluno **p,int *tam);

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	aluno *p_aluno=NULL;
	int tamanho=0,opcao;
	
	printf("Bem-vindo usuário ao diário elêtronico!\n\n");
	
	do
	{
		printf("Usuário, escolha uma das opções:\n1.Cadastro 2.Controle de notas 3.Sair\nSua escolha: ");
		scanf("%d",&opcao);
		fflush(stdin);
		switch(opcao)
		{
			case 1:
					printf("\nUsuário, você escolheu cadastrar!\n");
					system("pause");
					system("cls");
					aloca(&p_aluno,&tamanho);
					cadastro(&p_aluno,&tamanho);
					printf("\nCadastro realizado com sucesso!\n");
					system("pause");
					system("cls");
			break;
			case 2:
					printf("\nUsuário, você escolheu controle de notas!\n");
					system("pause");
					system("cls");
					controle(&p_aluno,&tamanho);
			break;
			case 3:
					printf("\nUsuário, você escolheu sair! - Obrigado e volte sempre!\n");
			break;
			default:
					printf("\nUsuário, você escolheu uma opção que não existe! Tente novamente...\n");
					system("pause");
					system("cls");
			break;
		}
	}while(opcao!=3);
	
	return 0;
}

void aloca(aluno **p,int *tam)
{
	(*tam)++;
	if((*p=(aluno*)realloc(*p,*tam*sizeof(aluno)))==NULL)
	{
		printf("\nErro de alocação!\n");
		exit(1);
	}
}
void cadastro(aluno **p,int *tam)
{
	int check,x;
	char aux[7];
	printf("Digite o nome do %d aluno: ",*tam);
	gets((*p+*tam-1)->nome);
	fflush(stdin);
	do
	{
		check=0;
		printf("Digite o RA do %d aluno: ",*tam);
		gets(aux);
		fflush(stdin);
		for(x=0;x<*tam;x++)
			if(strcmp((*p+x)->RA,aux)==0)
			{
				check=1;
				printf("\nO RA escolhido já foi cadastrado! Tente novamente...\n");
				system("pause");
				printf("\n");
				break;
			}
	}while(check==1);
	strcpy((*p+*tam-1)->RA,aux);
	printf("Digite o valor da 1 nota do %d aluno: ",*tam);
	scanf("%f",&(*p+*tam-1)->nota[0]);
	fflush(stdin);
	printf("Digite o valor da 2 nota do %d aluno: ",*tam);
	scanf("%f",&(*p+*tam-1)->nota[1]);
	fflush(stdin);
	(*p+*tam-1)->media=(((*p+*tam-1)->nota[0]+(*p+*tam-1)->nota[1])/2);
	printf("\nCalculando a média...\n");
	system("pause");
	printf("\nO resultado da média entre as duas notas é: %.2f\n",(*p+*tam-1)->media);
}
void controle(aluno **p,int *tam)
{
	int x,check=0;
	char aux[7];
	printf("Digite o RA de sua conta: ");
	gets(aux);
	fflush(stdin);
	for(x=0;x<*tam;x++)
		if(strcmp((*p+x)->RA,aux)==0)
		{
			check=1;
			printf("\nO RA foi encontrado com sucesso!\n");
			system("pause");
			break;
		}
	if(check==1)
	{
		printf("\nBem-vindo de volta %s!\nStatus da conta: 1 nota: %.2f | 2 nota: %.2f | média: %.2f\n",(*p+x)->nome,(*p+x)->nota[0],(*p+x)->nota[1],(*p+x)->media);
		printf("\n%s, digite o valor da 1 nota: ",(*p+x)->nome);
		scanf("%f",&(*p+x)->nota[0]);
		fflush(stdin);
		printf("\n%s, digite o valor da 2 nota: ",(*p+x)->nome);
		scanf("%f",&(*p+x)->nota[1]);
		fflush(stdin);
		(*p+x)->media=(((*p+x)->nota[0]+(*p+x)->nota[1])/2);
		printf("\nCalculando a média...\n");
		system("pause");
		printf("\nO resultado da média entre as duas notas é: %.2f\n",(*p+x)->media);
		printf("\nAlteração de notas realizada com sucesso!\n");
		system("pause");
		system("cls");
	}
	else
	{
		printf("\nO RA digitado não foi encontrado!\n");
		system("pause");
	}
	system("cls");
}