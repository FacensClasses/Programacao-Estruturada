#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void aloca(char ***names,int *tam);
void recebe(char ***names,int *tam); 
void verifica(char ***names,int *tam);

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	int tamanho=0;
	char **nomes=NULL;
	
	aloca(&nomes,&tamanho);
	recebe(&nomes,&tamanho);
	verifica(&nomes,&tamanho);
	
	return 0;
}

void aloca(char ***names,int *tam)
{
	printf("Função aloca nomes quantas vezes o usuário desejar!\n");
	(*tam)++;
	*names=realloc(*names,*tam*sizeof(char*));
	if(*names==NULL)
	{
		printf("\nErro ao tentar alocar o espaço em memória!\n");
		exit(1);
	}
	(*names)[*tam-1]=malloc(100*sizeof(char));
	if((*names)[*tam-1]==NULL)
	{
		printf("\nErro ao alocar espaço para o nome!\n");
		exit(1);
	}
	printf("\nEspaço em memória alocado com sucesso: %u.\n",*names);
}
void recebe(char ***names,int *tam)
{
	printf("\nFunção recebe nomes quantas vezes o usuário desejar!\n");
	char opcao;
	int x;
	do
	{	
		printf("Endereço %u - %d Nome: ",*names+*tam-1,*tam);
		scanf("%s",*(*names+*tam-1));
		printf("Deseja continuar inserindo nomes?(S/N) - Resposta: ");
		scanf(" %c",&opcao);
		if(opcao=='S'||opcao=='s')
			aloca(names,tam);
	}while(opcao=='S'||opcao=='s');
	printf("\nNomes digitados pelo Usuário:\n");
	for(x=0;x<*tam;x++)
		printf("Endereço %u - %d Nome= %s\n",*names+x,x+1,*(*names+x));
}
void verifica(char ***names,int *tam)
{
	printf("\nFunção verifica - Mostra a quantidade de nomes e quantos começam com 'A'!\n");
	int x, countA=0;
	for(x=0;x<*tam;x++)
		if(*(*names+x)[0]=='A'||*(*names+x)[0]=='a')
			countA++;
	printf("A quantidade total de nomes inciados com 'A' são: %d.\n",countA);
	printf("A quantidade total de nomes alocados são: %d.\n",*tam);
}