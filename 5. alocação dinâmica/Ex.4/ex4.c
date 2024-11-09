#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void aloca(float **num,int *tam);
void recebe(float **num,int *tam);

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	float *numeros=NULL;
	int tamanho=0;
	
	aloca(&numeros,&tamanho);
	recebe(&numeros,&tamanho);
	
	free(numeros);
	
	return 0;
}

void aloca(float **num,int *tam)
{
	(*tam)++;
	printf("Função aloca, aloca dinamicamente os valores!");
	*num=(float*)realloc(*num,(*tam)*sizeof(float));
	if(*num==NULL)
	{
		printf("\nErro ao alocar o espaço em memória!\n");
		exit(1);
	}
	printf("\nO Endereço alocado é: %u\n",*num);
}
void recebe(float **num,int *tam)
{
	printf("\nRecebe os valores até o quando o usuário quiser!");

	char opcao;

	do
	{
		printf("\nEndereço %u - %d número = ",*num+*tam-1,*tam);
		scanf("%f",*num +*tam-1);
		
		printf("Deseja continuar?(S/N) - Resposta: ");
		scanf(" %c",&opcao);
		if(opcao=='S'||opcao=='s')
		{
			aloca(num,tam);
		}
	}while(opcao=='S'||opcao=='s');
	printf("\nOrdem padrão:\n");
	int x;
	for(x=0;x<*tam;x++)
		printf("Endereço %u = %d Valor: %.2f.\n",*num+x,x+1,*(*num+x));
}