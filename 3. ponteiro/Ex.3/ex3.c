#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	int tam,x;
	
	do
	{
		printf("Digite a quantidade de números(<=100): ");
		scanf("%d",&tam);
		if(tam>100)
			printf("\nTente novamente! O valor deve ser menor ou igual a 100.\n\n");
	}while(tam>100);
	
	float vet[tam],vet2[tam],vet3[tam],*p_vet,*p_vet2,*p_vet3;
	p_vet=vet,p_vet2=vet2,p_vet3=vet3;
	
	for(x=0;x<tam;x++)
	{
		printf("\nDigite o %d elemento do 1 vetor: ",x+1);	
		scanf("%f",p_vet++);
	}
	printf("\n");
	for(x=0;x<tam;x++)
	{
		printf("\nDigite o %d elemento do 2 vetor: ",x+1);
		scanf("%f",p_vet2++);
	}
	
	p_vet=vet,p_vet2=vet2;
	
	for(x=0;x<tam;x++)
		*p_vet3++=*p_vet++ + *p_vet2++;
	p_vet3=vet3;
	for(x=0;x<tam;x++)
		printf("\nO %d elemento do 3 vetor é: %.2f.",x+1,*p_vet3++);
	
	return 0;
}