#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	int x,count=0,*p_count;
	char frase[101],*p_frase,a,*p_a;
	p_frase=frase,p_a=&a,p_count=&count;
	
	printf("Digite uma frase: ");
	fgets(frase,101,stdin);
	
	printf("\nDigite uma letra para contar sua ocorrência na frase: ");
	scanf("%c",p_a);
	
	for(x=0;x<strlen(frase)-1;x++)
	{
		if(*p_frase==*p_a)
			(*p_count)++;
		p_frase++;
	}
	
	printf("\nA quantidade de vezes em que a letra %c ocorre é: %d.\n",*p_a,*p_count);
	
	return 0;
}