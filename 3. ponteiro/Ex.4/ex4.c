#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	int x;
	float nota,nota2,*p_nota,*p_nota2,vet[100],*p_vet;
	p_nota=&nota,p_nota2=&nota2,p_vet=vet;
	
	for(x=0;x<100;x++)
	{
		do
		{
			printf("%d aluno, digite a 1 nota: ",x+1);
			scanf("%f",p_nota);
			printf("%d aluno, digite a 2 nota: ",x+1);
			scanf("%f",p_nota2);
			if(*p_nota<0||*p_nota>10||*p_nota2<0||*p_nota2>10)
				printf("\nTente novamente! As notas devem ser entre 0 - 10.\n\n");
		}while(*p_nota<0||*p_nota>10||*p_nota2<0||*p_nota2>10);
		
		*p_vet=(*p_nota+*p_nota2)/2;
		
		printf("\nA média do %d aluno é: %.2f.\n",x+1,*p_vet);
		
		if(*p_vet>=7)
			printf("\nStatus do %d aluno: APROVADO!\n\n",x+1);
		else if(*p_vet>=4&&*p_vet<7)
			printf("\nStatus do %d aluno: EXAME!\n\n",x+1);
		else
			printf("\nStatus do %d aluno: REPROVADO!\n\n",x+1);
			
		p_vet++;
	}
	
	return 0;
}