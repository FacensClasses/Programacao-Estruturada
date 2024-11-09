#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void aloca_nome(char **nome_din,char *nome,int tam);
void mostra(char **nome_din);
void mostra_alterado(char **nome_din,int tam);

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	char nome[100], *nome_dinamico=NULL;
	
	printf("Digite o seu nome: ");
	scanf("%s",nome);
	
	int tamanho=strlen(nome);
	
	aloca_nome(&nome_dinamico,nome,tamanho+1);
	mostra(&nome_dinamico);
	mostra_alterado(&nome_dinamico,tamanho);
	
	free(nome_dinamico);
	
	return 0;
}

void aloca_nome(char **nome_din,char *nome,int tam)
{
	printf("\nFunção aloca espaço em memória para o nome!\n");
	*nome_din=(char*)calloc(tam,sizeof(char));
     if(*nome_din==NULL)
     {
     	printf("\nErro ao alocar o espaço em memória!\n");
     	exit(1);
	 }
	 printf("Espaço em memória reservado com sucesso: %u\n",*nome_din);
	 strcpy(*nome_din,nome);
}
void mostra(char **nome_din)
{
	printf("\nFunção mostra o conteúdo do espaço em memória alocado!\n");
	printf("Endereço %u - Nome: ",*nome_din);
	puts(*nome_din);
}
void mostra_alterado(char **nome_din,int tam)
{
	printf("\nFunção faz alterações e mostra!\n");
	int x,y;
	char aux;
	for(x=0,y=tam-1;x<y;x++,y--)
	{
        aux=*(*nome_din+x);
        *(*nome_din+x)=*(*nome_din+y);
        *(*nome_din+y)=aux;
	}
	printf("\nEndereço %u - Nome alterado: ",*nome_din);
	puts(*nome_din);
}