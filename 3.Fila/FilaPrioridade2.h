#define MAXFILA 10

struct TpElemento{
    char Elemento;
    int Prioridade;
};
struct TpFilaPrioridade{
    int INICIO, FIM, CONT;
    TpElemento FILA[MAXFILA];
};

//Obrigatório SEMPRE
void FPInicializar(TpFilaPrioridade &FP){
    FP.INICIO = 0;
    FP.FIM = -1;
    FP.CONT = 0;
}

void FPInserir(TpFilaPrioridade &FP, TpElemento Elemento){
    TpElemento aux;
    int i;
    FP.FILA[++FP.FIM] = Elemento;
    i = FP.FIM;
    while(i > FP.INICIO && FP.FILA[i].Prioridade < FP.FILA[i-1].Prioridade ){   //enquanto o i(elemento final do vetor) for maior que a posicao inicial (ou seja, vai percorrer todo o vetor) e a prioridade da ultima for maior que a antipenultima, irá acontecer o remanejamento
        aux = FP.FILA[i];
        FP.FILA[i] = FP.FILA[i-1];
        FP.FILA[i-1] = aux;
        i--;
    }
    FP.CONT ++;
}

//Retirar, OBRIGATORIAMENTE o elemento que se encontra no INÍCIO da FILA, independente da Prioridade. E, por fim, deve ser retornado o Elemento, neste caso um TpElemento.
TpElemento FPRetirar(TpFilaPrioridade &FP){
    FP.CONT--;
    return FP.FILA[FP.INICIO++];
}

// Retornar o elemento do INÍCIO
TpElemento FPElementoInicio(TpFilaPrioridade FP){
    return FP.FILA[FP.INICIO];
}
//Retornar o elemento do FIM
TpElemento FPElementoFim(TpFilaPrioridade FP){
    return FP.FILA[FP.FIM];
}
// Verificar se a FILA está Cheia
char FPCheia(int cont){
    return (cont == MAXFILA);
}
//Verificar se a FILA está Vazia
char FPVazia(int cont){
    return cont == 0;
}

// Exibir a FILA com PRIORIDADES
void FPExibir(TpFilaPrioridade FP){
    TpElemento Aux;
    while (!FPVazia(FP.CONT)){
        Aux = FPRetirar(FP);
        printf("Elemento: %c - Prioridade: %d\n", Aux.Elemento, Aux.Prioridade);
    }
}
