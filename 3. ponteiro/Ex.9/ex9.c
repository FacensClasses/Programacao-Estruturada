#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

unsigned long long fatorial(int n);

int main()
{
    setlocale(LC_ALL,"Portuguese_Brazil");

    int vet[15],vet2[15],*p_vet=vet,*p_vet2=vet2,x;

    for(x=0;x<15;x++)
    {
        printf("Digite o %d elemento: ",x+1);
        scanf("%d",p_vet++);
        printf("\n");
    }
    p_vet=vet;
    
    printf("\n");
    
    for(x=0;x<15;x++)
    {
        if(*p_vet<0) 
        {
			printf("O fatorial de %d não é definido.\n",*p_vet);
        	*p_vet2=0;
        } 
		else 
		{
        	*p_vet2=fatorial(*p_vet);
            printf("O fatorial de %d é: %llu.\n",*p_vet,*p_vet2);
        }
        p_vet++;
        p_vet2++;
    }

    return 0;
}

unsigned long long fatorial(int n)
{
    if(n==0||n==1)
    	return 1;
    return(n*fatorial(n-1));
}
