#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include "ex05.h"

void coletaNomeArquivo(char nomeArq[100]){
    printf("Digite o nome do arquivo:  ");
    fflush(stdin);
    gets(nomeArq);
}

void coletaPremiada(int premiadas[5]){
    int i;

    for(i=0; i<5; i++){
        printf("%d numero premiado:  ", i+1);
        scanf("%d", &premiadas[i]);
    }
}

int main(){
    char nomeArq[100];
    int premiadas[5];

    coletaNomeArquivo(nomeArq);
	geraArquivo(nomeArq); //ex05
	mostraArquivo(nomeArq);

    coletaPremiada(premiadas);
	geraPremiadas(nomeArq, premiadas); //ex06

	return 1;
}
