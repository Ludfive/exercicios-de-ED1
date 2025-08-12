#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>
#include<time.h>
#include<string.h>
#include "ex3.h"

int main(){

    int resp;
    char expressao[20];

    printf("Expressao -> ");
    fflush(stdin);
    gets(expressao);

    resp = retornaResultadoOperacao(expressao);

    printf("\nResultado da expressao = %d\n", resp);
}
