#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int long fatorial(int long x);

int main()
{
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	int long x;
	
	printf("Digite um numero: ");
	scanf("%d", &x);
	
	printf("\nO fatorial de %d é: %d.\n",x,fatorial(x));
	
	return 0;
}

int long fatorial(int long x)
{
	if(x==0)
		return 1;
	return(x*fatorial(x-1));
}