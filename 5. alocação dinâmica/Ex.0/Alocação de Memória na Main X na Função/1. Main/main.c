#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void recebe(int *p,int tam);
void imprime(int *p,int tam);

int main()
{
	setlocale(LC_ALL, "Portuguese_Brazil");	
	
	int *numeros=NULL;
	
	if(numeros=(int*)calloc(numeros,sizeof(int)*10)==NULL)
	{
		printf("Erro na alocação");
		exit(1);
	}
	
	recebe(numeros,10);
	imprime(numeros,10);
	system("pause");
}

void recebe(int *p,int tam)
{
	int x;
	printf("Função recebe - Digite os valores\n");
	for(x=0;x<tam;x++)
	{
		printf("\nEndereço %u - Valor = ",p+x);
		scanf("%d",p+x);
	}
}
void imprime(int *p,int tam)
{
	int x;
	printf("\nFunção imprime - Mostra valores\n");
	for(x=0;x<tam;x++)
		printf("\nConteúdo do Endereço %u: %d.",p+x,*(p+x));
}