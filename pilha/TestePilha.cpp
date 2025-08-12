#include<stdio.h>
#include<conio2.h>
#include<stdlib.h>
#include "TestePilha.h"

char menu(){
	clrscr();
	printf("**** MENU ****");
	printf("\n1 - Inicializa");
	printf("\n2 - Insere(PUSH)");
	printf("\n3 - Retira(POP)");
	printf("\n4 - Elemento do topo");
	printf("\n5 - Exibe pilha");
	printf("\n[ESC] para sair\n");
	printf("\nEscolha uma opcao");
	return getche();
}

int main(){
	tpPilha pilha;
	char op,elemento;
	
	do
	{
		op = menu();
		switch(op)
		{
			case '1':
				inicializa(pilha);
				printf("\nPilha inicializada!");
				getch();
				break;
			case '2':
				if(!cheia(pilha.topo))
				{
					printf("\nElemento:");
					fflush(stdin);
					scanf("%c",&elemento);
					insere(pilha,elemento);
					printf("\nElemento inserido!\n");
				}
				else
					printf("\nPilha cheia!\n");
					getch();
					break;
			case '3':
				if(!vazia(pilha.topo))
				{
					//retira(pilha);
					printf("\nelemento [%c] retirado da pilha!\n",retira(pilha));
				}
				else
					printf("\nPilha vazia!\n");
					getch();
					break;
			case '4':
				if(!vazia(pilha.topo))
					printf("\nElemento do topo: [%c]\n",elementoTopo(pilha));
				else
					printf("\nPilha vazia!\n");
					getch();
					break;
			case '5':
				if(!vazia(pilha.topo))
					exibe(pilha);
				else
					printf("\nPilha vazia!\n");
					getch();
					break;
		}
		
	}while(op!=27);
	
}
