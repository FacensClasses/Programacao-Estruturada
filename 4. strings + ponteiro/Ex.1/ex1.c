#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	int x;
	char frase[101],*p_frase;
	
	printf("Digite uma frase: ");
	fgets(frase,101,stdin);
	
	p_frase=frase+strlen(frase)-1;
	
	for(x=strlen(frase);x>0;x--)
	{
		printf("%c",*p_frase);
		p_frase--;
	}
	
	return 0;
}