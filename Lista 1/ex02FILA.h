#define MAXFILA 100

struct TpFila {
    int inicio, fim;
    int Fila[MAXFILA];
};

void Inicializar(TpFila &F){
    F.inicio = 0;
    F.fim = -1;
}

void Inserir (TpFila &F, int elemento){
    F.Fila[++F.fim] = elemento;
}

int Retirar(TpFila &F){
    return F.Fila[F.inicio++];
}


int ElementoInicio(TpFila F){
    return F.Fila[F.inicio];
}

int ElementoFinal(TpFila F){
    return F.Fila[F.fim];
}

int FilaVazia(int inicio, int fim){
    return inicio > fim;
}

int FilaCheia(int inicio, int fim){
    return (inicio == 0 && fim == MAXFILA-1);
}

void MostrarFila(TpFila F){
    while(!FilaVazia(F.inicio, F.fim))
        printf("%d, ", Retirar(F));
}

