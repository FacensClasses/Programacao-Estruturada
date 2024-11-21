#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct agenda{
	int reg;
	char nome[80];
	float nota;
}agenda;

void aloca(agenda **p,int *tam);
void reg(agenda **p,int *tam);
void mostra(agenda *p,int tam);

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	int tamanho=0;
	char opcao;
	agenda *p_agenda=NULL;
	
	printf("Bem-vindo ao programa de registro de estruturas em alocação dinâmica!\n");
	
	do
	{
		aloca(&p_agenda,&tamanho);
		reg(&p_agenda,&tamanho);
		printf("\nUsuário, você deseja continuar?(S/N)\nSua resposta: ");
		scanf(" %c",&opcao);
		fflush(stdin);
		if(opcao=='N'||opcao=='n')
		{
			printf("\nUsuário, você escolheu sair!\n\n");
			system("pause");
			system("cls");
			mostra(p_agenda,tamanho);
		}
	}while(opcao!='N'&&opcao!='n');
	
	return 0;
}

void aloca(agenda **p,int *tam)
{
	(*tam)++;
	if((*p=(agenda*)realloc(*p,*tam*sizeof(agenda)))==NULL)
	{
		printf("\nErro de alocação!\n");
		exit(1);
	}
}
void reg(agenda **p,int *tam)
{
	printf("\nDigite o %d registro: ",*tam);
	scanf("%d",&(*p+*tam-1)->reg);
	fflush(stdin);
	printf("Digite o %d nome: ",*tam);
	gets((*p+*tam-1)->nome);
	fflush(stdin);
	printf("Digite a %d nota: ",*tam);
	scanf("%f",&(*p+*tam-1)->nota);
	fflush(stdin);
}
void mostra(agenda *p,int tam)
{
	int x;
	printf("Resultado dos registros:\n");
	for(x=0;x<tam;x++)
	{
		printf("O %d registro é: %d.\n",x+1,(p+x)->reg);
		printf("O %d nome é: %s.\n",x+1,(p+x)->nome);
		printf("A %d nota é: %.2f.\n\n",x+1,(p+x)->nota);	
	}
}