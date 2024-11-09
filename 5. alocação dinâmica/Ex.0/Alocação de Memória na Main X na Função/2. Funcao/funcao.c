#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void aloca(int **num,int tam);
void recebe(int *num,int tam);
void mostra(int *num,int tam);

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	int *numeros;
	
	aloca(&numeros,10);
	recebe(numeros,10);
	mostra(numeros,10);
	
	return 0;
}

void aloca(int **num,int tam)
{
	*num=(int*)calloc(tam,sizeof(int));
	if(*num==NULL)
	{
		printf("Erro ao alocar a memória!\n");
		exit(1);
	}
	
	printf("O endereço de aloca é: %u.\n",*num);
}

void recebe(int *num,int tam)
{
	int x;
	for(x=0;x<tam;x++)
	{
		printf("\nDigite o %d número no endereço %u: ",x+1,num+x);
		scanf("%d",num+x);
	}
}

void mostra(int *num,int tam)
{
	int x;
	printf("\nOs 10 números armazenados são:\n");
	for(x=0;x<tam;x++)
		printf("\nEndereço %u - Valor = %d.\n",num+x,*num+x);
}