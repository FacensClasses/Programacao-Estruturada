#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void mostra_invertido(char text[]);

int main() 
{
	setlocale(LC_ALL, "Portuguese_Brazil");

	char texto[999];

	printf("Digite alguma coisa: ");
	fgets(texto, 999, stdin);

	mostra_invertido(texto);

	return 0;
}

void mostra_invertido(char text[]) 
{
	int j;
	for(j=strlen(text)-1;j>=0;j--)
		printf("%c",text[j]);
}