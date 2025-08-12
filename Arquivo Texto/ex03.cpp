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

int verificaIgualdade(char arq1[100], char arq2[100]){
    char carac1, carac2;
    int cont=0;

    FILE *ptr1 = fopen(arq1, "r");
    FILE *ptr2 = fopen(arq2, "r");

    carac1 = fgetc(ptr1);
    carac2 = fgetc(ptr2);
    while(!feof(ptr1)){
        if(carac1 != carac2)
            cont++;
        carac1 = fgetc(ptr1);
        carac2 = fgetc(ptr2);
    }

    fclose(ptr1);
    fclose(ptr2);

    if(cont == 0)
        return 1;
    else
        return 0;
}


int main(){
    char arquivo1[100], arquivo2[100];
    int x;

    nomeDoArquivo(arquivo1);
    nomeDoArquivo(arquivo2);

    x = verificaIgualdade(arquivo1, arquivo2);
    if(x==1)
        printf("\nOs arquivos sao identicos\n");
    else
        printf("\nOs arquivos nao sao identicos\n");

    return 1;
}
