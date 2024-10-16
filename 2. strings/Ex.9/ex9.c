#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void nomeJEDI(char name[], char subname[], char returnname[]);
void subJEDI(char mother[], char city[], char returnsub[]);
void composto(char jediname[], char subjedi[], char returncompos[]);

int main()
{
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	char nome[50], sobrenome[50], mae[50], cidade[50], nameJEDI[50], subnameJEDI[50], composJEDI[50];
	
	printf("Digite o seu nome: ");
	fgets(nome,50,stdin);
	
	printf("\nDigite o seu sobrenome: ");
	fgets(sobrenome,50,stdin);
	
	printf("\nDigite o nome de sua mãe: ");
	fgets(mae,50,stdin);
	
	printf("\nDigite o nome de sua cidade em que nasceu: ");
	fgets(cidade,50,stdin);
	
	nomeJEDI(nome,sobrenome,nameJEDI);
	subJEDI(mae,cidade,subnameJEDI);
	composto(nameJEDI,subnameJEDI,composJEDI);
	
	printf("\nSeu nome JEDI completo: %s %s.\n",nameJEDI,subnameJEDI);
	printf("\nSeu nome JEDI composto: %s.\n",composJEDI);
	return 0;
}

void nomeJEDI(char name[], char subname[], char returnname[])
{
	int i,j=0;
	for(i=0;i<3;i++)
		returnname[i]=name[i];
	for(i=3;i<5;i++)
	{
		returnname[i]=subname[j];
		j++;
	}
	returnname[5]='\0';
}

void subJEDI(char mother[], char city[], char returnsub[])
{
	int i,j=0;
	for(i=0;i<2;i++)
		returnsub[i]=mother[i];
	for(i=2;i<5;i++)
	{
		returnsub[i]=city[j];
		j++;
	}
	returnsub[5]='\0';
}

void composto(char jediname[], char subjedi[], char returncompos[])
{
	int i,j=strlen(subjedi)-3;
	for(i=0;i<3;i++)
		returncompos[i]=jediname[i];
	for(i=3;i<6;i++)
	{
		returncompos[i]=subjedi[j];
		j++;
	}
	returncompos[6]='\0';
}