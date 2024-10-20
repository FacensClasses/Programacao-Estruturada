#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");

	int x,verif;
	char frase[101],*p_frase,a,*p_a;
	p_frase=frase,p_a=&a;
	
	printf("Digite uma frase: ");
	fgets(frase,101,stdin);
	
	printf("\nDigite uma letra para buscar sua ocorrência na frase: ");
	scanf("%c",p_a);
	
	for(x=0;x<strlen(frase)-1;x++)
	{
		if(*p_frase==*p_a)
			verif=0;		
		p_frase++;
	}
	
	if(verif==0)
		printf("\nO caracter escolhido foi encontrado na frase!\n");
	else
		printf("\nO caracter escolhido NÃO foi encontrado na frase!\n");
		
	return 0;
}