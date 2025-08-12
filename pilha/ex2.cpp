#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>
#include<time.h>
#include "ex2.h"

int main(){
    TpPilha pilha1, pilha2, aux;

    int elemento, pos;

    inicializa(pilha1);

    insere(pilha1, 34);
    insere(pilha1, 87);
    insere(pilha1, 32);
    insere(pilha1, 45);
    insere(pilha1, 28);
    insere(pilha1, 74);
    insere(pilha1, 56);
    insere(pilha1, 41);
    insere(pilha1, 23);

    printf("Elemento => ");
    scanf("%d", &elemento);

    pos = buscaElemento(pilha1, elemento);

    if(pos != -1)
        excluiElemento(pilha1, pos);
    else
        printf("Elemento não encontrado!\n");

    exibe(pilha1);

    return 1;
}
