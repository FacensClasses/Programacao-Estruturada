#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	int x;
	float vet[10],*p_vet,med=0;
	p_vet=vet;
	
	for(x=0;x<10;x++)
	{
		printf("Digite o %d elemento: ",x+1);
		scanf("%f",p_vet++);
		printf("\n");
	}
	p_vet=vet;
	
	for(x=0;x<10;x++)
		med+=*p_vet++;
	med/=10;
	
	printf("\nO valor da média é: %.2f.\n",med);
	
	return 0;
}