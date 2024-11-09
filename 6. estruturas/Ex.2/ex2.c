#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct aluno{
	char nome[80];
	char RA[7];
	float nota[2];
	float media;
}aluno;
typedef struct grupo{
	aluno aluno[10];
}grupo;

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	int x,j,opcao,opcao2,verif=0;
	char verif_RA[7];
	grupo alunos={0};
	
	printf("Bem-vindo ao Diário eletronico\n\n");
	
	do
	{
		printf("Usuário, escolha uma das opções:\n1.Cadastro 2.Controle de Notas 3.Sair\nSua escolha: ");
		scanf("%d",&opcao);
		fflush(stdin);
		switch(opcao)
		{
			case 1:
					verif=0;
					for(x=0;x<10;x++)
					{
						if(strlen(alunos.aluno[x].RA)==0)
						{
							verif=1;
							break;
						}
					}
					if(verif==1)
					{
						printf("\nUsuário, digite o seu nome: ");
						fgets(alunos.aluno[x].nome,80,stdin);
						alunos.aluno[x].nome[strcspn(alunos.aluno[x].nome,"\n")]=0;
						fflush(stdin);
						do
						{	
							printf("\nUsuário, digite o seu RA: ");
							fgets(verif_RA,7,stdin);
							fflush(stdin);
							verif=0;
							for(j=0;j<10;j++)
							{
								if(strcmp(alunos.aluno[j].RA,verif_RA)==0)
								{
									verif=1;
									printf("\nO RA digitado já existe! Tente novamente...\n");
									break;	
								}
							}	
						}while(verif==1);
						strcpy(alunos.aluno[x].RA,verif_RA);
						printf("\nUsuário, digite a sua 1 nota: ");
						scanf("%f",&alunos.aluno[x].nota[0]);
						fflush(stdin);
						printf("\nUsuário, digite a sua 2 nota: ");
						scanf("%f",&alunos.aluno[x].nota[1]);
						fflush(stdin);
						alunos.aluno[x].media=(alunos.aluno[x].nota[0]+alunos.aluno[x].nota[1])/2; 
						printf("\nA média entre as duas notas é: %.2f.\n",alunos.aluno[x].media);
						printf("\nCadastro realizado com sucesso!\n");
						system("pause");
						system("cls");
					}
					else
					{
						printf("\nNão há mais espaço para novos cadastros.\n");
						system("pause");
						system("cls");
					}
			break;
			case 2:
					printf("\nUsuário, digite o seu RA: ");
					fgets(verif_RA,7,stdin);
					verif_RA[strcspn(verif_RA,"\n")]=0;
					fflush(stdin);
					verif=0;
					for(x=0;x<10;x++)
					{
						if(strcmp(alunos.aluno[x].RA,verif_RA)==0)
						{
							verif=1;
							break;
						}
					}		
					if(verif==1)
					{
						do
						{
							printf("RA encontrado com sucesso!\n");
							printf("\nBem-vindo de volta %s!\nSeus dados: 1 nota = %.2f, 2 nota = %.2f, média = %.2f.\n\n",alunos.aluno[x].nome,alunos.aluno[x].nota[0],alunos.aluno[x].nota[1],alunos.aluno[x].media);
							system("pause");
							system("cls");	
							printf("Gostaria de realizar alteração?\n1.Sim 2.Voltar ao Menu Inicial\nSua escolha: ");
							scanf("%d",&opcao2);
							switch(opcao2)
							{
								case 1:
										printf("\n%s digite sua 1 nota: ",alunos.aluno[x].nome);
										scanf("%f",&alunos.aluno[x].nota[0]);
										fflush(stdin);
										printf("\n%s digite sua 2 nota: ",alunos.aluno[x].nome);
										scanf("%f",&alunos.aluno[x].nota[1]);
										fflush(stdin);
										printf("\nDados alterados com sucesso!\n");
										alunos.aluno[x].media=(alunos.aluno[x].nota[0]+alunos.aluno[x].nota[1])/2;
										printf("\nSeus dados atualizados: 1 nota = %.2f, 2 nota = %.2f, média = %.2f.\n",alunos.aluno[x].nota[0],alunos.aluno[x].nota[1],alunos.aluno[x].media);
										system("pause");
										system("cls");
								break;
								case 2:
										printf("\nUsuário, você escolheu voltar ao menu inicial!\n");
										system("pause");
										system("cls");		
								break;
								default:
										printf("\nUsuário, está opção não existe! - Tente novamente!\n");
								break;
							}
						}while(opcao2!=2);	
					}		
					else
					{
						printf("\nO RA digitado não foi encontrado! Tente novamente...\n");
						system("pause");
						system("cls");
					}
			break;
			case 3:
					printf("\nUsuário, você escolheu sair do programa! - Volte sempre!\n");
			break;		
			default:
					printf("\nUsuário, está opção não existe! - Tente novamente!\n");
					system("pause");
					system("cls");
			break;
		}		
	}while(opcao!=3);

	return 0;
}