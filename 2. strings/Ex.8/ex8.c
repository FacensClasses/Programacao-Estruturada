#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void procura(char text[], char word[]);

int main()
{
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	char texto[100], palavra[] = "put";
	
	printf("Digite alguma coisa: ");
	fgets(texto,100,stdin);
	
	procura(texto, palavra);
	
	return 0;
}

void procura(char text[], char word[])
{
	if(strstr(text,word)!=NULL)
		printf("\nO string %s foi encontrado!\n",word);
	else
		printf("\nO string %s não foi encontrado!\n",word);	
}