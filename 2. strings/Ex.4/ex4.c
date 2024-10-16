#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void inverte(char text[]);

int main()
{
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	char texto[100];
	
	printf("Digite alguma coisa: ");
	fgets(texto, 100, stdin);
	
	inverte(texto);
	
	return 0;
}

void inverte(char text[])
{
	int i,j;
	char temp;
	j=strlen(text)-1;
	for(i=0;i<=j;i++,j--)
	{
		temp=text[i];
		text[i]=text[j];
		text[j]=temp;
	}
	puts(text);
}