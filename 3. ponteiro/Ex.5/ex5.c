#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	int x;
	float vet[10],*p_vet,maior;
	p_vet=vet;
	
	for(x=0;x<10;x++)
	{
		printf("Digite o %d elemento: ",x+1);
		scanf("%f",p_vet++);
		printf("\n");
	}
	p_vet=vet;
	
	maior=*p_vet;
	
	for(x=0;x<10;x++)
	{
		if(*p_vet>maior)
			maior=*p_vet;
		p_vet++;
	}
	
	printf("\nO maior valor digitado é: %.2f.\n",maior);
	
	return 0;
}