#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>
#include<time.h>
#include "FILA01.h"

int main(){
    srand(time(NULL));
    TpFila F;

    char tecla;
    int num, x;

    Inicializar(F);

    while(tecla != 27){
        num = rand()%100;

        if(num % 2 == 0 ){
            Inserir(F, num);
            MostrarFila(F);
        }
        else if(num % 2 != 0 && !FilaVazia(F.inicio, F.fim)){
            Retirar(F);
            MostrarFila(F);
        }

        tecla = getche();
    }
}
