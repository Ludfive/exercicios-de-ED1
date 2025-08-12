#define MAXPILA 100
struct TpFrase{
    char palavra[30];
};
struct TpPilha{
    int topo;
    TpFrase pilha[MAXPILA];
};

void inicializa(TpPilha &p){
    p.topo = -1;
}

void insere(TpPilha &p, TpFrase elemento){
    p.pilha[++p.topo] = elemento;
}
TpFrase retira(TpPilha &p){
    return p.pilha[p.topo--];
}

TpFrase elementoTopo(TpPilha p){
    return p.pilha[p.topo];
}

int cheia(int topo){
    return topo == MAXPILA-1;
}
int vazia(int topo){
    return topo == -1;
}

int exibe(TpPilha p){
    TpFrase aux;
    while( !vazia(p.topo) ){
        aux = retira(p);
        printf(" %s", aux.palavra);
   }
}


void PalavrasOrdemReversa(char frase[60]){
    TpPilha pilha;
    TpFrase f;
    
    char palavra[30];
    int i,j=0;
    inicializa(pilha);
    
    
    for(i=0;i<=strlen(frase);i++)
    {
    	if(frase[i] != ' ' && frase[i] != '\0'){
    		palavra[j] = frase[i];
    		j++;
		 }
		
		else
		{
			palavra[j] = '\0';
			strcpy(f.palavra,palavra);
			j=0;
			insere(pilha,f);
		}
	 }
	 exibe(pilha);
    
}
