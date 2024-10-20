#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	int x;
	char nome[51],sobrenome[51],mae[51],cidade[51],*p_nome,*p_sobrenome,*p_mae,*p_cidade,nomeJEDI[50],sobrenomeJEDI[50],nomecomposJEDI[50],*p_nomeJEDI,*p_sobrenomeJEDI,*p_nomecomposJEDI;
	p_nome=nome,p_sobrenome=sobrenome,p_mae=mae,p_cidade=cidade,p_nomeJEDI=nomeJEDI,p_sobrenomeJEDI=sobrenomeJEDI,p_nomecomposJEDI=nomecomposJEDI;
	
	printf("Digite o seu nome: ");
	fgets(nome,51,stdin);

	printf("\nDigite o seu sobrenome: ");
	fgets(sobrenome,51,stdin);
	
	printf("\nDigite o nome de sua mae: ");
	fgets(mae,51,stdin);

	printf("\nDigite o nome de sua cidade: ");
	fgets(cidade,51,stdin);
	
	for(x=0;x<3;x++)
	{
		*p_nomeJEDI=*p_nome;
		p_nomeJEDI++,p_nome++;
	}
	for(x=0;x<2;x++)
	{
		*p_nomeJEDI=*p_sobrenome;
		p_nomeJEDI++,p_sobrenome++;
	}
	p_nomeJEDI=nomeJEDI;
	
	for(x=0;x<2;x++)
	{
		*p_sobrenomeJEDI=*p_mae;
		p_sobrenomeJEDI++,p_mae++;
	}
	for(x=0;x<3;x++)
	{
		*p_sobrenomeJEDI=*p_cidade;
		p_sobrenomeJEDI++,p_cidade++;
	}
	p_sobrenomeJEDI=sobrenomeJEDI;
	
	for(x=0;x<3;x++)
	{
		*p_nomecomposJEDI=*p_nomeJEDI;
		p_nomecomposJEDI++,p_nomeJEDI++;
	}
	p_sobrenomeJEDI+=strlen(sobrenomeJEDI)-3;
	for(x=0;x<3;x++)
	{
		*p_nomecomposJEDI=*p_sobrenomeJEDI;
		p_nomecomposJEDI++,p_sobrenomeJEDI++;
	}
	*p_nomecomposJEDI='\0';
	p_nomecomposJEDI=nomecomposJEDI,p_nomeJEDI=nomeJEDI,p_sobrenomeJEDI=sobrenomeJEDI;
	
	printf("\nSeu nome e sobrenome JEDI é: %s %s.\n",p_nomeJEDI,p_sobrenomeJEDI);
	printf("Seu nome composto JEDI é: %s.\n",p_nomecomposJEDI);
	
	return 0;
}