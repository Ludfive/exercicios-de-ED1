#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>

void nomeDoArquivo(char nomeArq[100]){
    printf("Indique o nome do arquivo [com extensão]: ");
    fflush(stdin);
    gets(nomeArq);
}

void vasculhaArquivo(char nomeArq[100]){
    int letras = 0, espacos = 0, linhas = 1;
    char lido;
    FILE *ptr = fopen(nomeArq, "r");

    lido = fgetc(ptr);
    while(!feof(ptr)){
        if(lido != ' ' && lido != ',' && lido != '.')
            letras++;
        if(lido == ' ')
            espacos++;
        if(lido == '\n')
            linhas++;
        lido = fgetc(ptr);
    }
    printf("Arquivo vasculhado...\nGerando resultados...\n");
    Sleep(2000);
    printf("\nLETRAS: %d\nESPACOS: %d\nLINHAS: %d\n", letras, espacos, linhas);

    fclose(ptr);
}

int main(){
    char nomeArq[100];

    nomeDoArquivo(nomeArq);
    vasculhaArquivo(nomeArq);

    return 1;
}
