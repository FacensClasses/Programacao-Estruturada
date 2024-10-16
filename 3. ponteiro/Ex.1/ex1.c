#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	int tam,x;
	
	printf("Com quantos números iremos trabalhar: ");
	scanf("%d",&tam);
	
	float vetor[tam], *p_vetor;
	p_vetor=vetor;
	
	for(x=0;x<tam;x++)
	{
		printf("\nDigite o %d elemento: ",x+1);
		scanf("%f",p_vetor++);
	}
	printf("\n");
	p_vetor=vetor;
	for(x=0;x<tam;x++)
	{
		printf("\nO %d elemento é: %.2f.\n",x+1,*(p_vetor++));
	}
	
	return 0;
}
