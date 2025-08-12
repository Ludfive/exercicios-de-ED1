#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>

void nomeDoArquivo(char nomeArq[100]){
	printf("Indique o nome do arquivo: ");
	fflush(stdin);
	gets(nomeArq);
}

void formataNovoArquivo(char nomeArq[100]){
	char carac;
	int flag=0;
	
	FILE *ptr1 = fopen(nomeArq, "r");
	FILE *ptr2 = fopen("primeiraLetraMaiusc.txt", "w");
	
	carac = fgetc(ptr1);
	while(!feof(ptr1)){
		if(flag == 0)
			fputc(carac, ptr2);
		else
			fputc(toupper(carac), ptr2);
		
		if(carac == ' ')
			flag = 1;
		else 
			flag = 0;
		carac = fgetc(ptr1);
	}
	
	fclose(ptr1);
	fclose(ptr2);
}

void exibeArquivo(){
	char carac;
	FILE *ptr = fopen("primeiraLetraMaiusc.txt", "r");
	
	if(ptr == NULL)
		printf("Arquivo não encontrado!\n");
	else{
		carac = fgetc(ptr);
		printf("%c", carac);
		while(!feof(ptr)){
			//printf("%c", fgetc(ptr));
			printf("%c", carac);
			carac = fgetc(ptr);	
		}
		printf("\n=== FIM DO ARQUIVO! ===\n");
		getch();
	}
	
	fclose(ptr);
}

int main(){
	char nomeArq[100];
	
	nomeDoArquivo(nomeArq);
	formataNovoArquivo(nomeArq);
	exibeArquivo();
	
	return 1;
}
