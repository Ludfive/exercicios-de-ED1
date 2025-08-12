#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

void geraNomeArquivo(char nomeArq[100]){
	printf("Indique o nome do arquivo: ");
	fflush(stdin);
	gets(nomeArq);
}

void geraFolhaAposta(char nomeArq[100]){
	FILE *ptr = fopen(nomeArq, "w");
	int i;
	
	for(i=1; i<21; i++)
		fprintf(ptr,"%d %d/%d/%d %d %d %d %d %d %d %d\n", i, rand()%30+1, rand()%12+1, 2020, rand()%60+1, rand()%60+1, rand()%60+1, rand()%60+1, rand()%60+1, rand()%60+1, rand()%60+1);
	
	printf("\n=====================================================\nApostas feita com sucesso!\n");
	
	fclose(ptr);
}

void exibeFolhaApostas(char nomeArq[100]){
	FILE *ptr = fopen(nomeArq, "r");
	int num, d, m, ano, a1, a2, a3, a4, a5, a6, a7;
	
	fscanf(ptr, "%d %d/%d/%d %d %d %d %d %d %d %d", &num, &d, &m, &ano, &a1, &a2, &a3, &a4, &a5, &a6, &a7);
	while(!feof(ptr)){
		printf("%d %d/%d/%d %d %d %d %d %d %d %d\n", num, d, m, ano, a1, a2, a3, a4, a5, a6, a7);
		fscanf(ptr, "%d %d/%d/%d %d %d %d %d %d %d %d", &num, &d, &m, &ano, &a1, &a2, &a3, &a4, &a5, &a6, &a7);
	}
	printf("%d %d/%d/%d %d %d %d %d %d %d %d\n", num, d, m, ano, a1, a2, a3, a4, a5, a6, a7);
	
	fclose(ptr);
}

int main(){
	srand(time(NULL));
	char nomeArq[100];
	
	geraNomeArquivo(nomeArq);
	geraFolhaAposta(nomeArq);
	exibeFolhaApostas(nomeArq);
	
	return 0;
}
