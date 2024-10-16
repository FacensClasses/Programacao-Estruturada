#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void inverte(char text[], char aux[]);

int main()
{
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	char texto[999], aux[999];
	
	printf("Digite alguma coisa: ");
	fgets(texto, 999, stdin);
	
	inverte(texto,aux);
	
	return 0;
}

void inverte(char text[], char aux[])
{
	int i,j;
	j=strlen(text)-1;
	for(i=0;j>=0;i++,j--)
		aux[i]=text[j];
	aux[i]='\0';
	puts(aux);
}