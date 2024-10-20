#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	int x;
	char frase[101],temp,*p_frase,*p_fim;
	p_frase=frase;
	
	printf("Digite uma frase: ");
	fgets(frase,101,stdin);
	
	size_t len = strlen(frase);
    if(frase[len-1]=='\n') 
	{
        frase[len-1]='\0';
        len--;
    }
	
	p_fim=frase+len-1;
	
	for(;p_frase<p_fim;p_frase++,p_fim--)
	{
		temp=*p_frase;
		*p_frase=*p_fim;
		*p_fim=temp;
	}
	p_frase=frase;
	
	puts(p_frase);
	
	return 0;
}