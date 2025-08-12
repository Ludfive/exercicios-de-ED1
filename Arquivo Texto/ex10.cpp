#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>

void indicaArquivo(char nomeArq[100]){
    printf("Indique o nome do arquivo: ");
    fflush(stdin);
    gets(nomeArq);
}

void contagem1ate1000(char nomeArq[100]){
    FILE *ptr = fopen(nomeArq, "w");
    int i;

    for(i=1; i<1001; i++){
        fprintf(ptr, "%d", i);
        fputc('\n', ptr);
    }
    fputs("--> Vitor Guilhermo <--", ptr);

    printf("\nNumeros gravados com sucesso!\n");
    fclose(ptr);
}

void exibeArquivo(char nomeArq[100]){
    FILE *ptr = fopen(nomeArq, "r");
    char lido;

    lido = fgetc(ptr);
    while(!feof(ptr)){
        printf("%c", lido);
        Sleep(5);
        lido = fgetc(ptr);
    }

    fclose(ptr);
}

int main(){
    char nomeArq[100];

    indicaArquivo(nomeArq);
    contagem1ate1000(nomeArq);
    exibeArquivo(nomeArq);

    return 0;
}
