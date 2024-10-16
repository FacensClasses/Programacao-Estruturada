#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	int x,y;
	float vet[10],*p_vet,*p_aux,aux;
	p_vet=vet;
	
	for(x = 0; x < 10; x++)
	{
		printf("Digite o %d elemento: ", x + 1);
		scanf("%f", p_vet++);
	}	
	p_vet=vet;
	
	for(x=0;x<10-1;x++)
	{
		for(y=0;y<10-1-x;y++)
		{
			p_aux=vet+y;
			if(*p_aux>*(p_aux+1))
			{
				aux=*p_aux;
				*p_aux=*(p_aux + 1);
				*(p_aux+1)=aux;
			}
		}
	}
	p_vet=vet;
	
	printf("\nVetor em ordem crescente:\n");
	for(x=0;x<10;x++)
	{
		printf("%.2f ",*p_vet++);
	}
	
	return 0;
}