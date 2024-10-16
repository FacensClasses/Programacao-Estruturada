#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int soma(int a, int b);

int main()
{
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	int x,y,z;
	
	printf("Digite o primeiro valor: ");
	scanf("%d", &x);
	printf("\nDigite o segundo valor: ");
	scanf("%d", &y);
	
	z=soma(x,y);
	
	printf("\nO resultado da soma entre %d e %d é: %d.\n", x,y,z);
	
	return 0;
}

int soma(int a, int b)
{
	int resul;
	resul=a+b;
	return resul;
}