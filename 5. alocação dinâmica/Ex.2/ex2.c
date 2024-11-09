#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void aloca(float **num,int tam);
void recebe(float *num,int tam);
void mostra_invertido(float *num,int tam);

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	float *numeros=NULL;
	int tam;
	
	printf("Digite a quantidade de números: ");
	scanf("%d",&tam);
	
	aloca(&numeros,tam);
	recebe(numeros,tam);
	mostra_invertido(numeros,tam);
	
	free(numeros);
	
	return 0;
}

void aloca(float **num,int tam)
{
	printf("\nAloca espaço em Memória!");
	*num=(float*)calloc(tam,sizeof(float));
	if(*num==NULL)
	{
		printf("\nErro ao tentar alocar o espaço em memória!\n");
		exit(1);
	}
	printf("\nO endereço atribuido é: %u.\n",*num);
}
void recebe(float *num,int tam)
{
	printf("\nRecebe os valores:\n");
	int x;
	for(x=0;x<tam;x++)
	{
		printf("Digite o %d número em seu endereço %u: ",x+1,num+x);
		scanf("%f",num+x);
	}
	printf("\n");
}
void mostra_invertido(float *num,int tam)
{
	printf("\nMostra invertido!\n");
	int x;
	for(x=tam-1;x>=0;x--)
		printf("Endereço %u - Valor: %.2f\n",num+x,*(num+x));
}