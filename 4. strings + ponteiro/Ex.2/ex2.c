#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	int x;
	char frase[101],*p_frase,frase2[101],*p_frase2;
	p_frase2=frase2;
	
	printf("Digite uma frase: ");
	fgets(frase,101,stdin);
	
	p_frase=frase+strlen(frase)-1;
	
	for(x=strlen(frase);x>0;x--)
	{
		*p_frase2=*p_frase;
		p_frase2++;
		p_frase--;
	}
	*p_frase2='\0';
	p_frase2=frase2;
	
	printf("\nFrase invertida: %s\n",p_frase2);
	
	return 0;
}