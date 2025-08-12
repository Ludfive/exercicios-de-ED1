#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>

void solicitaNomeArquivo(char nomeArq[100]){
    printf("Indique o nome do arquivo: ");
    fflush(stdin);
    gets(nomeArq);
}

void criptografia(char nomeArq[100]){
    FILE *ptr = fopen(nomeArq, "r");
    FILE *ptrNv = fopen("ArquivoCriptografado.txt", "w");
    char lido;

    lido = fgetc(ptr);
    while(!feof(ptr)){
        fputc(lido+3, ptrNv);
        lido = fgetc(ptr);
    }
    printf("\nArquivo Criptografado com sucesso!\n");

    fclose(ptr);
    fclose(ptrNv);
}

int main(){
    char nomeArq[100];

    solicitaNomeArquivo(nomeArq);
    criptografia(nomeArq);
    return 0;
}
