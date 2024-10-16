#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define PI 3.14

float calcula(float r);

int main()
{
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	float r;
	
	printf("Digite o valor do raio: ");
	scanf("%f", &r);
	
	printf("\nA área da esfera é: %.2f.\n", calcula(r));
	
	return 0;
}

float calcula(float r)
{
	return(4*PI*(r*r));
}