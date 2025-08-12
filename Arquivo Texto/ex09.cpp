#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>

void recebeNomeArquivo(char nomeArq[100]){
    printf("Indique o nome do arquivo: ");
    fflush(stdin);
    gets(nomeArq);
}


int contadorDeVogaisIniciais(char nomeArq[100]){
    int cont=0, flag=0;
    char lido;
    FILE *ptr = fopen(nomeArq, "r");

    lido = fgetc(ptr);
    while(!feof(ptr)){
        if(lido == 'U' && flag == 1)
			cont++;
        else if(lido == 'O' && flag == 1)
			cont++;
        else if(lido == 'I' && flag == 1)
			cont++;
        else if(lido == 'E' && flag == 1)
			cont++;
        else if(lido == 'A' && flag == 1)
			cont++;


		if(lido == ' ')
			flag = 1;
		else
			flag = 0;

        lido = fgetc(ptr);
        lido = toupper(lido);
    }
    printf("\nArquivo lido com sucesso!\n");
    fclose(ptr);

    return cont;
}

int main(){
    char nomeArq[100];
    int vogais;

    recebeNomeArquivo(nomeArq);
    vogais = contadorDeVogaisIniciais(nomeArq);
    printf("Quantidade de palavras que sao iniciadas por vogais: %d \n", vogais);
    return 0;
}
