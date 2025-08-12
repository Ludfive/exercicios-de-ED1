#define MAXPILA 100

struct TpPilha{
    int topo;
    int pilha[MAXPILA];
};

void inicializa(TpPilha &p){ //pra prova transformar a expressao em polonesa
    p.topo = -1; //valor da string - 48(na expressao polonesa) for(i=0;i<strlen(expressao);i++)
   																					 //num = expresssao[i] - 48;
   																					 //48=='0'
   																					 //49=='1'
   																					 //operador - 2 pops
   																					 //operando - push
   																					 //ex 9 - pilha de string(matriz de caracteres)
}

void insere(TpPilha &p, int elemento){
    p.pilha[++p.topo] = elemento;
}
int retira(TpPilha &p){
    return p.pilha[p.topo--];
}

int elementoTopo(TpPilha p){
    return p.pilha[p.topo];
}

int cheia(int topo){
    return topo == MAXPILA-1;
}
int vazia(int topo){
    return topo == -1;
}

int exibe(TpPilha p){
   while( !vazia(p.topo) )
        printf("\n%d",retira(p));
}

int buscaElemento(TpPilha pilha, int elemento){
    int numRetirado = -1, pos = 0;

    while(!vazia(pilha.topo) && elemento != numRetirado){
        numRetirado = retira(pilha);
        pos++;
    }

    if(elemento == numRetirado) //ver o que esta acontecendo nesse caso da exclusao
        return pos;
    else
        return -1;
}

void excluiElemento(TpPilha &pilha1, int pos){
    TpPilha aux;
    int cont = 1;

    inicializa(aux); 

    while(!vazia(pilha1.topo)){
        if(cont == pos)
            retira(pilha1);
        else
            insere(aux, retira(pilha1));
        cont++;
    }

    while(!vazia(aux.topo))
        insere(pilha1, retira(aux));

}
