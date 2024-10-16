#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	int tam,*p_vet,x,maior,dia_maior=1;
	float med=0;
	
	printf("Digite a quantidade de dias em seu mês atual: ");
	scanf("%d",&tam);
	
	int vet[tam];
	p_vet=vet;
	
	for(x=0;x<tam;x++)
	{
		printf("\nDigite a temperatura do %d dia: ",x+1);
		scanf("%d",p_vet++);
	}
	printf("\n");
	p_vet=vet;
	
	maior=*p_vet;
	for(x=0;x<tam;x++)
	{
		if(*p_vet>maior)
		{
			maior=*p_vet;
			dia_maior=x+1;
		}
		p_vet++;
	}
	p_vet=vet;
	printf("\nA maior temperatura é %d e ocorreu no dia %d.\n",maior,dia_maior);
	
	for(x=0;x<tam;x++)
		med+=*p_vet++;
	med/=tam;	
	p_vet=vet;
	printf("\nA temperatura média mensal é: %.2f.\n",med);
	
	printf("\nTemperaturas inferiores à média:");
	for(x=0;x<tam;x++)
	{
		if(*p_vet<med)
			printf("\nA temperatura do dia %d foi: %d.\n",x+1,*p_vet);
		p_vet++;
	}
	
	return 0;
}