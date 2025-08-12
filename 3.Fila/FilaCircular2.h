#define MAXFILA 10

struct TpFilaCirc{
    int inicio, fim, cont;
    char fila[MAXFILA];
};

void FCInicializar(TpFilaCirc &F){
    F.inicio = 0;
    F.fim = -1;
    F.cont = 0;
}

void FCInserir(TpFilaCirc &F, char Elem){
    if(F.fim == MAXFILA -1)   // se o fim for a ultima posição do vetor, ele recebe -1 para assim ser inserido na posição 0 (o inicio)
        F.fim = -1;

    F.fila[++F.fim] = Elem;

    F.cont ++;
}

char FCRetirar ( TpFilaCirc &F){
    int aux;

    aux = F.fila[F.inicio++];      // a variável aux recebe o elemento do início da fila, o que vai ser retirado

    if(F.inicio == MAXFILA)     // se o inicio for == MAXFILA ele recebe 0, ele "reseta", volta pro início
        F.inicio = 0;

    F.cont --;  //decrementa o contador, ja que foi retirado um elemento

    return aux;
}

char FCElementoInicio(TpFilaCirc F){
    return F.fila[F.inicio];
}

char FCElementoFIM(TpFilaCirc F ){
    return F.fila[F.fim];
}

char FCVazia( int cont ){
    return cont == 0;
}

char FCCheia(int cont){
    return cont == MAXFILA;
}

void FCExibir(TpFilaCirc F){
    while(!FCVazia(F.cont))
        printf("\t%c", FCRetirar(F));
}
