#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	int x;
	char frase[101],*p_frase,string[101],*p_string,result,*p_result;
	p_frase=frase,p_string=string,p_result=result;
	
	printf("Digite uma frase: ");
	fgets(frase,101,stdin);
	
	printf("Digite uma string a procurar: ");
	fgets(string,101,stdin);
	
	p_frase[strcspn(p_frase,"\n")]='\0';
    p_string[strcspn(p_string,"\n")]='\0';
	
	p_result=strstr(p_frase,p_string);
	
	if(p_result!=NULL)
		printf("\nA substring %s foi encontrada!\n",p_string);
	else
		printf("\nA substring %s não foi encontrada!\n",p_string);
		
	return 0;
}