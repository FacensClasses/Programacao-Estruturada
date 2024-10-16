#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void verifica(char pass[6], char pass2[6]);

int main()
{
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	char senha[6], senha2[6];
	
	printf("Cadastramento de Senhas\n");
	
	printf("\nDigite sua senha: ");
	fgets(senha, 6, stdin);
	fflush(stdin);
	
	printf("\nConfirme sua senha: ");
	fgets(senha2, 6, stdin);
	fflush(stdin);
	
	verifica(senha, senha2);
	
	return 0;
}

void verifica(char pass[6], char pass2[6])
{
	if (strcmp(pass, pass2)==0)
		printf("\nSenha Válida\n");
	else
		printf("\nSenha inválida\n");
}