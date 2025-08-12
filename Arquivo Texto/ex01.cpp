#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>

void nomeArquivo(char nomeArq[100]){
	printf("Indique o arquivo: ");
	fflush(stdin);
	gets(nomeArq);
}
void maiuscTexto(char nomeArq[100], char novoArq[100]){
	char lido;
	FILE *ptrArq, *ptrNovoArq;
	
	ptrArq = fopen(nomeArq, "r");
	ptrNovoArq = fopen(novoArq, "w");
	
	lido = fgetc(ptrArq);
	
	while(!feof(ptrArq)){
		fputc(toupper(lido), ptrNovoArq); //grava o caractere maiusculo no novo arquivo
		
		lido = fgetc(ptrArq); //le o proximo
	}
	printf("Arquivo em maiúsculo!\n");
	
	fclose(ptrArq);
	fclose(ptrNovoArq);
	getch();
}

void exibeTxt(char nomeArq[100]){
	char lido;
	FILE *ptrArq = fopen(nomeArq, "r");
	system("cls");
	printf("CONTEÚDO DO ARQUIVO: %s \n", nomeArq);
	if(ptrArq == NULL)
		printf("Arquivo não encontrado!\n");
	else{
		lido = fgetc(ptrArq);
		printf("%c", lido);
		while(!feof(ptrArq))
			printf("%c", fgetc(ptrArq));
	}
	printf("\n=== FIM DO ARQUIVO ===\n");
	getch();
	fclose(ptrArq);
}

int main(){
	char arqTexto[100], novoTexto[100];
	
	nomeArquivo(arqTexto);
	nomeArquivo(novoTexto);
	maiuscTexto(arqTexto, novoTexto);
	exibeTxt(novoTexto);
	
	return 1;
}
