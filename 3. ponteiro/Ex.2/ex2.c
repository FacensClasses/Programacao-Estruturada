#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	int tam,x=0;
	
	printf("Digite a quantidade de números: ");
	scanf("%d", &tam);
	
	float vetor[tam], *p_vetor;
	p_vetor=vetor;
	char resp;
	
	do
	{
		printf("\nDigite o %d elemento: ",x+1);
		scanf("%f",p_vetor++);
		x++;
		printf("\nVocê deseja continuar? (S/N): ");
		scanf(" %c",&resp);
	}while(resp=='S'||resp=='s'&&x<tam);
	printf("\n");
	p_vetor=vetor;
	for(x=0;x<tam;x++)
	{
		printf("\nO %d elemento é: %.2f.",x+1,*(p_vetor++));
	}
	
	return 0;
}