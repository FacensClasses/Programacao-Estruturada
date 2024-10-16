#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float media(float x, float y);

int main()
{
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	float x,y;
	
	printf("Digite o valor da 1 nota: ");
	scanf("%f", &x);
	
	printf("\nDigite o valor da 2 nota: ");
	scanf("%f", &y);
	
	printf("\nO valor da média entre ás notas é: %.2f.\n",media(x,y));
	
	return 0;
}

float media(float x, float y)
{
	return((x+y)/2);	
}