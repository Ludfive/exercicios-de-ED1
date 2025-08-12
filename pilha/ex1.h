#define MAXPILA 100

struct TpPilha{
    int topo;
    int pilha[MAXPILA];
};

void inicializa(TpPilha &p){
    p.topo = -1;
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
