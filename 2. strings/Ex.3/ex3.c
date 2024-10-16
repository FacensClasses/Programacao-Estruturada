#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void inverte(char text[], char aux[]);
void MaisMenus(char aux[]);

int main()
{
	setlocale(LC_ALL, "Portuguese_Brazil");	
	
	char texto[100], aux[100];
	
	printf("Digite alguma coisa: ");
	fgets(texto, 100, stdin);
	
	inverte(texto, aux);
	MaisMenus(aux);
	
	return 0;
}

void inverte(char text[], char aux[])
{
	int i, j;
	j=strlen(text)-1;
	for(i=0;j>=0;i++,j--)
		aux[i]=text[j];
	puts(aux);
}

void MaisMenus(char aux[])
{
	int i;
	for(i=0;i<strlen(aux);i++)
		aux[i]=toupper(aux[i]);
	puts(aux);
	for(i=0;i<strlen(aux);i++)
		aux[i]=tolower(aux[i]);
	puts(aux);
}