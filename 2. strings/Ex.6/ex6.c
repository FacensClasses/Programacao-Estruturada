#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void verifica(char text[], char letra);

int main()
{
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	char texto[100];
	char letra;
	
	printf("Digite alguma coisa: ");
	fgets(texto, 100, stdin);
	fflush(stdin);
	
	printf("\nEscolha uma letra a procurar: ");
	scanf("%c", &letra);
	fflush(stdin);
	
	verifica(texto, letra);
	
	return 0;
}

void verifica(char text[], char letra)
{
	int i, count=0;
	for(i=0;i<strlen(text)-1;i++)
		if(text[i]==letra)
			count++;
	printf("\nA letra %c ocorre %d vez(es).\n",letra,count);
}