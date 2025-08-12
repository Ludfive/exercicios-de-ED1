#define MAXPILA 10

struct tpPilha{
	int topo;
	char PILHA[MAXPILA];
};

void inicializa(tpPilha &p){
	p.topo = -1;
}
void insere(tpPilha &p,char elemento){
	p.PILHA[++p.topo] = elemento;
}
char retira(tpPilha &p){
	return p.PILHA[p.topo--];
}
char elementoTopo(tpPilha p){
	return p.PILHA[p.topo];
}
char cheia(int topo){
	return topo == MAXPILA - 1;
}
char vazia(int topo){
	return topo == -1;
}
int exibe(tpPilha p){
	while(!vazia(p.topo))
		printf("\n%c",retira(p));
}
