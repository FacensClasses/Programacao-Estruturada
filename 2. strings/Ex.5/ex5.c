#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void procura(char text[]);

int main()
{
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	char texto[100];
	
	printf("Digite alguma coisa: ");
	fgets(texto, 100, stdin);
	
	procura(texto);
	
	return 0;
}

void procura(char text[])
{
	int i, verif=0;
	for(i=0;i<strlen(text)-1;i++)
		if(text[i]=='x'||text[i]=='X')
			verif++;		
	if(verif==0)
		printf("\nO caracter x não foi encontrado!\n");
	else
		printf("\nO caracter x foi encontrado!\n");
}