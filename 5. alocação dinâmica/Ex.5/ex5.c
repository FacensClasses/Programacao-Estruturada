#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void aloca(int **temp,int *dias);
void recebe(int **temp,int *dias);
void maior_temp(int *temp,int dias);

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	int dias=0, *temperatura=NULL;
	
	printf("Digite a quantidade de dias: ");
	scanf("%d",&dias);
	
	aloca(&temperatura,&dias);
	recebe(&temperatura,&dias);
	maior_temp(temperatura,dias);
	
	free(temperatura);
	
	return 0;
}

void aloca(int **temp,int *dias)
{
	printf("\nFunção aloca espaço em memória referente a quantidade de dias!\n");
	*temp=(int*)calloc(*dias,sizeof(int));
	if(*temp==NULL)
	{
		printf("\nErro ao alocar o espaço em mémoria!");
		exit(1);
	}
	printf("\nEspaço em memória reservado com sucesso: %u\n",*temp);
}
void recebe(int **temp,int *dias)
{
	printf("\nFunção recebe os valores no espaço em memória reservados!\n");
	int x;
	for(x=0;x<*dias;x++)
	{
		printf("Endereço %u - Digite o valor do %d dia temperatura: ",*temp+x,x+1);
		scanf("%d",*temp+x);
	}
	printf("\nTemperatura registrada de cada dia do mês:\n");
	for(x=0;x<*dias;x++)
		printf("Endereço %u - Dia %d Temperatura: %d\n",*temp+x,x+1,*(*temp+x));
}
void maior_temp(int *temp,int dias)
{
	printf("\nFunção mostra a maior temperatura ocorrida no mês!\n");
	int x,maior=*temp;
	for(x=1;x<dias;x++)
		if(*(temp+x)>maior)
			maior=*(temp+x);
	printf("\nA maior temperatura ocorrida no mês é: %d.\n",maior);
}