#define MAXFILA 10

struct TpElemento{
    char Elemento;
    int Prioridade;
};
struct TpFilaCircPri{
    int inicio, fim, cont;
    TpElemento fila[MAXFILA];
};

void FCPInicializar(TpFilaCircPri &FCP){
    FCP.inicio = 0;
    FCP.fim = -1;
    FCP.cont = 0;
}

void FCPInserir(TpFilaCircPri &FCP, TpElemento Elemento){
    TpElemento aux;
    int i;

    if(FCP.fim == MAXFILA -1)   // se o fim for a ultima posição do vetor, ele recebe -1 para assim ser inserido na posição 0 (o inicio)
        FCP.fim = -1;

    FCP.fila[++FCP.fim] = Elemento;
    i = FCP.fim;

    while(i>FCP.inicio && FCP.fila[i].Prioridade < FCP.fila[i-1].Prioridade){
        aux = FCP.fila[i];
        FCP.fila[i] = FCP.fila[i-1];
        FCP.fila[i-1] = aux;
        i--;
    }

    FCP.cont ++;
}

TpElemento FCPRetirar (TpFilaCircPri &FCP){
    TpElemento aux;

    aux = FCP.fila[FCP.inicio++];      // a variável aux recebe o elemento do início da fila, o que vai ser retirado

    if(FCP.inicio == MAXFILA)     // se o inicio for == MAXFILA ele recebe 0, ele "reseta", volta pro início
        FCP.inicio = 0;

    FCP.cont --;  //decrementa o contador, ja que foi retirado um elemento

    return aux;
}

TpElemento FCPElementoInicio(TpFilaCircPri FCP){
    return FCP.fila[FCP.inicio];
}

TpElemento FCPElementoFIM(TpFilaCircPri FCP){
    return FCP.fila[FCP.fim];
}

char FCPVazia( int cont ){
    return cont == 0;
}

char FCPCheia(int cont){
    return cont == MAXFILA;
}

FCPExibir(TpFilaCircPri FCP){
    TpElemento aux;
    while(!FCPVazia(FCP.cont)){
        aux = FCPRetirar(FCP);
        printf("Elemento: %c - Prioridade: %d\n", aux.Elemento, aux.Prioridade);

    }
}
