#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

void aloca(char **word,int tam);
void recebe(char **word,int tam);
void altera(char **word,int tam); 

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");	
	
	char *letras;
	
	aloca(&letras,11);
	recebe(&letras,11);
	altera(&letras,11);
	
	free(letras);
	
	return 0;
}
void aloca(char **word,int tam)
{
	printf("Função aloca letras em um espaço em memória!\n");
	*word=(char*)calloc(tam,sizeof(char));
	if(*word==NULL)
	{
		printf("\nErro ao alocar espaço em memória!\n");
		exit(1);
	}
	printf("Espaço em memória reservado com sucesso: %u\n",*word);
}
void recebe(char **word,int tam)
{
	printf("\nFunção recebe 10 letras\n");
	int x;
	for(x=0;x<tam-1;x++)
	{
		printf("Endereço %u - Letra = ",*word+x);
		scanf(" %c",*word+x);
	}
	*(*word+x)='\0';
	printf("\nAs 10 letras digitadas pelo usuário são: ");
	puts(*word);
}
void altera(char **word,int tam)
{
	printf("\nFunção altera as letras maiusculas e minusculas\n");
	int x;
	for(x=0;x<tam-1;x++)
	{
		if(isupper(*(*word+x)))
			*(*word+x)=tolower(*(*word+x));
		else if(islower(*(*word+x)))
			*(*word+x)=toupper(*(*word+x));
	}
	for(x=0;x<tam-1;x++)
		printf("Endereço %u - Letra alterada: %c\n",(*word+x),*(*word+x));
	printf("\nAs 10 letras alteradas pelo programa são: ");
	puts(*word);
}