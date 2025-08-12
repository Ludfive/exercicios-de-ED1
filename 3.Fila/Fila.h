#define MAXFILA 10

struct TpFila{
    int inicio, fim;
    char fila[MAXFILA];
};

void Inicializar(TpFila& F){
    F.inicio = 0;
    F.fim = -1;
}

void Inserir(TpFila &F, char  elemento){
    F.fila[++F.fila] = elemento;
}
char Retirar(TpFila &F){
    return F.fila[F.inicio++];
}

char ElementoInicio(TpFila F){
    return F.fila[F.inicio];
}
char ElementoFinal(TpFila F){
    return F.fila[F.fim];
}

char FilaVazia(int inicio, int fim){
    return inicio > fim;
}
char FilaCheia(int inicio, int fim){
    return (inicio == 0 && fim == MAXFILA-1);
}

void MostrarFila(TpFila F)
    while(!FilaVazia(F.inicio, F.fim))
        printf("\t%c", Retirar(F));
}
