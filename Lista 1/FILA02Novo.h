#define MAXFILA 10

struct TpElemento{
    char placa[8], cor[25], fabricante[25], categoria[25];
    int qtdeEixos, tempoParaPassar;
};

struct TpFilaCirc{
    int inicio, fim, cont;
    TpElemento fila[MAXFILA];
};

void FCInicializar(TpFilaCirc &F){
    F.inicio = 0;
    F.fim = -1;
    F.cont = 0;
}

void FCInserir(TpFilaCirc &F, TpElemento veiculo){
    if(F.fim == MAXFILA -1)   // se o fim for a ultima posição do vetor, ele recebe -1 para assim ser inserido na posição 0 (o inicio)
        F.fim = -1;

    F.fila[++F.fim] = veiculo;

    F.cont ++;
}

TpElemento FCRetirar (TpFilaCirc &F){
    TpElemento aux;

    aux = F.fila[F.inicio++];      // a variável aux recebe o elemento do início da fila, o que vai ser retirado

    if(F.inicio == MAXFILA)     // se o inicio for == MAXFILA ele recebe 0, ele "reseta", volta pro início
        F.inicio = 0;

    F.cont --;  //decrementa o contador, ja que foi retirado um elemento

    return aux;
}

TpElemento FCElementoInicio(TpFilaCirc F){
    return F.fila[F.inicio];
}

TpElemento FCElementoFIM(TpFilaCirc F){
    return F.fila[F.fim];
}

char FCVazia( int cont ){
    return cont == 0;
}

char FCCheia(int cont){
    return cont == MAXFILA;
}

void FCExibir(TpFilaCirc F){
    TpElemento aux;
    while(!FCVazia(F.cont)){
        aux = FCRetirar(F);
        printf("Placa: %s\tCor: %s \tFabr.: %s \tEixos%d \tCat.: %s \t Tempo: %d\n", aux.placa, aux.cor, aux.fabricante, aux.qtdeEixos, aux.categoria, aux.tempoParaPassar);
    }
}
