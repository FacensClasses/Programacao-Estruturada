#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void aloca(float **num,int *tam);
void recebe(float **num,int *tam);
void mostra_invertido(float *num,int tam);

int main() 
{
    setlocale(LC_ALL,"Portuguese_Brazil");

    int tamanho;
    float *numeros = NULL;

    printf("Digite a quantidade de números: ");
    scanf("%d",&tamanho);

    aloca(&numeros,&tamanho);
    recebe(&numeros,&tamanho);
    mostra_invertido(numeros,tamanho);

    free(numeros);

    return 0;
}

void aloca(float **num,int *tam) 
{
    printf("\nAloca o espaço em memória!");
    *num=(float*)realloc(*num,(*tam)*sizeof(float));
    if(*num==NULL) 
	{
        printf("\nErro ao alocar o espaço em memória!\n");
        exit(1);
    }
    printf("\nO endereço da memória alocada é: %u\n",*num);
}
void recebe(float **num,int *tam) 
{
    printf("\nRecebe valores nos espaços da memória!\n");
    int x;
    char opcao;
    for(x=0;x<*tam;x++) 
	{
        printf("Endereço %u - %d Valor = ",*num+x,x+1);
        scanf("%f",*num+x);
    }
    do 
	{
        printf("Usuário, você deseja continuar?(S/N) - Resposta: ");
        scanf(" %c", &opcao);
        if (opcao=='S'||opcao=='s') 
		{
            (*tam)++;
            aloca(num, tam);
            printf("Endereço %u - %d Valor = ",*num+*tam-1,*tam);
            scanf("%f",*num +*tam-1);
        }
    }while(opcao=='S'||opcao=='s');
    printf("\nOrdem padrão:\n");
    for (x=0;x<*tam;x++) 
    	printf("Endereço %u - %d Valor: %.2f.\n",*num+x,x+1,*(*num+x));
}
void mostra_invertido(float *num,int tam) 
{
    int x;
    printf("\nMostra invertido\n");
    for(x=tam-1;x>=0;x--)
        printf("Endereço %u - %d Valor: %.2f.\n",num+x,x+1,*num+x);
}