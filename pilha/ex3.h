#define MAXPILA 10

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

void exibe(TpPilha p){
   while( !vazia(p.topo) )
        printf("\n%d",retira(p));
}

int retornaResultadoOperacao(char equacao[20]){
    TpPilha pilha;

    inicializa(pilha);

    int i, num, valor1, valor2, resultado;

    for(i = 0; i<strlen(equacao); i++){
        num = (int) (equacao[i] > 47 && equacao[i] < 58) ? equacao[i] - 48 : equacao[i];

        //empilha na pilha rs
        if(num > -1 && num <= 9){
            insere(pilha, num);
        }
        else{
            if(num == 42){ // *
                if(!vazia(pilha.topo)){
                    valor1 = retira(pilha);
                    valor2 = retira(pilha);
                    resultado = valor1*valor2;
                    insere(pilha, resultado);
                }
            }
            if(num == 43){// +
                if(!vazia(pilha.topo)){
                    valor1 = retira(pilha);
                    valor2 = retira(pilha);
                    resultado = valor1 + valor2;
                    insere(pilha, resultado);

                }
            }
            else if(num == 45){// -
                if(!vazia(pilha.topo)){
                    valor1 = retira(pilha);
                    valor2 = retira(pilha);
                    resultado = valor1-valor2;
                    insere(pilha, resultado);
                }
            }
            else if(num == 47){// /
                if(!vazia(pilha.topo)){
                    valor1 = retira(pilha);
                    valor2 = retira(pilha);
                    resultado = valor1/valor2;
                    insere(pilha, resultado);
                }
            }
        }
    }

    return elementoTopo(pilha);
}
