#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void aloca(float **num,int tam);
void recebe_mostra(float *num,int tam);
void altera_mostra(float *num,int tam);

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	float *numeros=NULL;
	
	aloca(&numeros,10);
	recebe_mostra(numeros,10);
	altera_mostra(numeros,10);
	
	free(numeros);
	
	return 0;
}

void aloca(float **num,int tam)
{
	printf("Aloca espaço na mémoria!\n");
	*num=(float*)calloc(tam,sizeof(float));
	if(*num==NULL)
	{
		printf("Erro ao alocar na memória!\n");
		exit(1);
	}
	printf("Endereço alocado: %u.\n",*num);
}
void recebe_mostra(float *num,int tam)
{
	printf("\nRecebe e mostra os valores da memória!\n");
	int x;
	for(x=0;x<tam;x++)
	{
		printf("Endereço %u - Valor = ",num+x);
		scanf("%f",num+x);
	}
	printf("\nValores de cada posição:");
	for(x=0;x<tam;x++)
		printf("\nEndereço %u - Valor: %.2f.",num+x,*num+x);
	printf("\n");
}
void altera_mostra(float *num,int tam)
{
	int x;
	for(x=0;x<tam;x++)
		*(num+x)+=30;
	printf("\nValores alterados:");
	for(x=0;x<tam;x++)
		printf("\nEndereço %u - Valor: %.2f.",num+x,*num+x);
}