#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct quarto{
int num; // número do quarto
char categoria; // [S]olteiro / [F]amiliar
char status; // [L]ivre / [O]cupado
}quarto;

typedef struct hospede{
	int quarto; // número do quarto
	char nome[80]; //nome do hospede
	int acompanhante; // quantidade de acompanhantes
	char categoria; // [S]olteiro / [F]amiliar
	int dias; // tempo de permanência – em dias
}hospede;

void aloca_quarto(quarto **q,int qq);
void aloca_hospede(hospede **h,int qh);
void cadastro_quarto(quarto *q,int qq);
void cadastro_hospede(hospede *h,quarto *q,int qq);
int  busca_quarto(quarto *q,int qq,char cat);
int  busca_hospede(hospede *h,int qh,int n_quarto);
void check_out(hospede *h,int qh,quarto *q);
void mostra_quarto(quarto *q,int qq);
void mostra_hospede(hospede *h,int qh);

int main()
{
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	quarto *pq=NULL;
	hospede *ph=NULL;
	int op,cont=0,pos;
	
	printf("Bem-vindo ao programa de gerenciamento de hotel!\n\n");
	
	aloca_quarto(&pq,15);
	cadastro_quarto(pq,15);
	do
	{
		printf("Usuário, escolha uma das opções:\n1.Check-in 2.Check-out 3.Mostra Quarto 4.Mostra Hospede 5.Fim\nSua escolha: ");
		scanf("%d",&op);
		fflush(stdin);
		switch(op)
		{
			case 1:
					printf("\nUsuário, você escolheu fazer Check-in!\n");
					system("pause");
					system("cls");
					pos=busca_hospede(ph,cont,-1);
					if(pos==-1)
					{
						aloca_hospede(&ph,cont+1);
						pos=cont;
						cont++;
					}
					cadastro_hospede(ph+pos,pq,15);
					system("pause");
					system("cls");
			break;
			case 2:
					printf("\nUsuário, você escolheu fazer Check-out!\n");
					system("pause");
					system("cls");
					check_out(ph,cont,pq);
					system("pause");
					system("cls");
			break;
			case 3:
					printf("\nUsuário, você escolheu a opção Mostrar Quartos!\n");
					system("pause");
					system("cls");
					mostra_quarto(pq,15);
					system("pause");
					system("cls");
			break;
			case 4:
					printf("\nUsuário, você escolheu a opção Mostrar Hospedes!\n");
					system("pause");
					system("cls");
					mostra_hospede(ph,cont);
					system("pause");
					system("cls");
			break;	
			case 5:
					printf("\nUsuário, você escolheu sair! - Obrigado e volte sempre!\n");
			break;
			default:
					printf("\nUsuário, você escolheu uma opção que não existe! - Tente novamente...\n");
					system("pause");
					system("cls");
			break;
		}
	}while(op!=5);	
	
	return 0;
}

void aloca_quarto(quarto **q,int qq)
{
	if((*q=(quarto*)realloc(*q,qq*sizeof(quarto)))==NULL)
	{
		printf("\nErro de alocação!\n");
		exit(1);
	}
}
void aloca_hospede(hospede **h,int qh)
{
	if((*h=(hospede*)realloc(*h,qh*sizeof(hospede)))==NULL)
	{
		printf("\nErro de alocação!\n");
		exit(1);
	}
}
void cadastro_quarto(quarto *q,int qq)
{
	int x;
	for(x=0;x<qq;x++,q++)
	{
		q->num=x+1;
		q->status='L';
		if(x<5)
			q->categoria='S';
		else
			q->categoria='F';
	}
}
void cadastro_hospede(hospede *h,quarto *q,int qq)
{
	printf("Digite o seu nome: ");
	gets(h->nome);
	fflush(stdin);
	do
	{
		printf("\nQtde de acompanhantes - max.3: ");
		scanf("%d",&h->acompanhante);
		fflush(stdin);
	}while(h->acompanhante<0||h->acompanhante>3);
	if(h->acompanhante==0)
		h->categoria='S';
	else
		h->categoria='F';
	h->quarto=busca_quarto(q,qq,h->categoria); 
	if(h->quarto==-1)
		printf("\nNao ha quartos com a categoria desejada\n\n");
	else
	{
		printf("\nDigite a quantidade de dias de permanência: ");
		scanf("%d",&h->dias);
		fflush(stdin);
		printf("\nCadastro com sucesso - quarto = %d\n",h->quarto);
	}
}
int busca_quarto(quarto *q,int qq,char cat)
{
	int x;
	for(x=0;x<qq;x++,q++)
		if(q->categoria==cat&&q->status=='L')
		{
			q->status='O';
			return q->num;
		}
	return -1;
}
int busca_hospede(hospede *h,int qh,int n_quarto)
{
	int x;
	for(x=0;x<qh;x++,h++)
		if(h->quarto==n_quarto)
			return x;
	return -1;
}
void check_out(hospede *h,int qh,quarto *q)
{
	int n_quarto,check;
	float valor;
	printf("Quarto a ser finalizado: ");
	scanf("%d",&n_quarto);
	fflush(stdin);
	check=busca_hospede(h,qh,n_quarto);
	if(check==-1)
		printf("\nQuarto Invalido!\n\n");
	else
	{
		if((h+check)->categoria=='S')
			valor=(h+check)->dias*85;
		else
			valor=(h+check)->dias*(((h+check)->acompanhante)+1)*65;
		printf("\nNome: %s\nAcompanhantes: %d\nCategoria: %c\nDias: %d\nValor a ser pago: %.2f\n\n",(h+check)->nome,(h+check)->acompanhante,(h+check)->categoria,(h+check)->dias,valor);
		(h+check)->quarto=-1;
	}
	(q+n_quarto-1)->status='L';
}
void mostra_quarto(quarto *q,int qq)
{
	int x;
	for(x=0;x<qq;x++,q++)
		printf("Quarto: %d\nCategoria: %c\nStatus: %c\n\n",q->num,q->categoria,q->status);
}
void mostra_hospede(hospede *h,int qh)
{
	int x;
	for(x=0;x<qh;x++,h++)
		printf("Quarto: %d\nNome: %s\nAcompanhantes: %d\nCategoria: %c\nDias: %d\n\n",h->quarto,h->nome,h->acompanhante,h->categoria,h->dias);
}