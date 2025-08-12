#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>

void indicaNomeArquivo(char nomeArq[100]){
    printf("Indica o nome do arquivo: ");
    fflush(stdin);
    gets(nomeArq);
}

void descriptografaArquivo(char nomeArq[100]){
    FILE *ptr = fopen(nomeArq, "r");
    FILE *ptrNv = fopen("ArquivoDescriptografado.txt", "w");
    char lido;

    lido = fgetc(ptr);
    while(!feof(ptr)){
        fputc(lido-3, ptrNv);
        lido = fgetc(ptr);
    }
    printf("\nArquivo Descriptografado com sucesso!\n");
    fclose(ptr);
    fclose(ptrNv);
}


int main(){
    char nomeArq[100];

    indicaNomeArquivo(nomeArq);
    descriptografaArquivo(nomeArq);

    return 1;
}
