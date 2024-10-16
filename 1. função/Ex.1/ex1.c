#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int produto(int a, int b);

int main()
{
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	int x,y;
	
	printf("Digite o primeiro valor: ");
	scanf("%d", &x);
	printf("\nDigite o segundo valor: ");
	scanf("%d", &y);
	
	printf("\nO produto entre %d e %d é: %d.\n", x,y,produto(x,y));
	
	return 0;
}

int produto(int a, int b)
{
	return(a*b);
}