#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include "exfilmes.h"

void nomeArquivo(char arq[100]){
	printf("nome do arquivo: ");
	fflush(stdin);
	gets(arq);
}

int main(){
	char arquivo[100];
	nomeArquivo(arquivo);
	filmeMaiorLucro(arquivo);
	maiorTaxa(arquivo);
	duracaoMedia(arquivo);
	anoFilmes(arquivo);
	geraArqBinOrdenadosPorAno(arquivo);
	indicaValorMedianoAnoProducao(arquivo);
}
