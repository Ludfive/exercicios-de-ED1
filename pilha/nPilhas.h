#define MAXPILA 50

struct tpPilha{
	int topos[MAXPILA],bases[MAXPILA];
	char pilhas	[MAXPILA];
};

void inicializar(tpPilha &p,int qtd){
	int i,qtdElem = MAXPILA/qtd;
	for(i=0;i<=qtdElem;i++)
	{
		p.bases[i] = qtdElem * i;
		p.topos[i] = p.bases[i] - 1;
	 } 
}

void inserir(tpPilha &p,char elem,int nPilha){
	p.pilhas[++p.topos[nPilha]] = elem;
}

int retirar(tpPilha &p,int nPilha){
	return p.pilhas[p.topos[nPilha]--];
}

int elementoTopo(tpPilha p,int nPilha){
	return p.pilhas[p.topos[nPilha]];
}

int cheia(tpPilha p,int nPilha){
	return p.topos[nPilha]+1 == p.bases[nPilha+1];
}

int vazia(tpPilha p,int nPilha){
	return p.topos[nPilha] < p.bases[nPilha];
}

void exibe(tpPilha p,int nPilha){
	while(!vazia(p,nPilha))
		printf("\n %d",retirar(p,nPilha));
}
