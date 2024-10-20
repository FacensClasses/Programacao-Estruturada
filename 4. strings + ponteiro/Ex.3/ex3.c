#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");	
	
	int x;
	char frase[101],*p_frase,frase2[101],*p_frase2;
	p_frase2=frase2;
	
	printf("Digite uma frase: ");
	fgets(frase,101,stdin);
	
	if(frase[strlen(frase)-1]=='\n')
    	frase[strlen(frase)-1]='\0';
	
	p_frase=frase+strlen(frase)-1;
	
	for(x=strlen(frase);x>0;x--)
	{
		if(isupper(*p_frase))
			*p_frase2=tolower(*p_frase);
		else if(islower(*p_frase))
			*p_frase2=toupper(*p_frase);
		else
			*p_frase2=*p_frase;
		p_frase2++;
		p_frase--;
	}
	*p_frase2='\0';
	p_frase2=frase2;
	
	printf("\nFrase invertida + alteração dos caracteres: %s\n",p_frase2);
	
	return 0;
}