#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>
#include<time.h>
#include "ex1.h"

int main(){
    TpPilha pilha1, pilha2, aux;

    inicializa(pilha1);
    inicializa(pilha2);
    inicializa(aux);


    insere(pilha1, 34);
    insere(pilha1, 87);
    insere(pilha1, 32);
    insere(pilha1, 45);

    insere(pilha2, 28);
    insere(pilha2, 74);
    insere(pilha2, 56);
    insere(pilha2, 41);
    insere(pilha2, 23);

    while(!vazia(pilha2.topo))
        insere(aux, retira(pilha2));

    while(!vazia(aux.topo))
        insere(pilha1, retira(aux));


    exibe(pilha1);

    return 1;
}
