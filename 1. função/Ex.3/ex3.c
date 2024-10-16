#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void calcula_dias_meses(int x, float vet[2]);

int main()
{
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	int idade;
	float vetor[2];
	
	printf("Usuário, digite sua idade: ");
	scanf("%d", &idade);
	
	calcula_dias_meses(idade,vetor);
	
	printf("\nA quantidade aproximada dias de vida é: %.2f.\n", vetor[0]);
	printf("\nA quantidade aproximada de meses de vida é: %.2f.\n", vetor[1]);	
	
	return 0;
}

void calcula_dias_meses(int x, float vet[2])
{
	vet[0]=x*365;
	vet[1]=x*12;
}