#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float media(float x, float y);

int main()
{
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	float dis, vol;
	
	printf("Digite a distância(km): ");
	scanf("%f", &dis);
	
	printf("\nDigite o volume(L): ");
	scanf("%f", &vol);
	
	printf("\nO consumo médio é: %.2f.\n", media(dis,vol));
	
	return 0;
}

float media(float x, float y)
{
	return(x/y);
}