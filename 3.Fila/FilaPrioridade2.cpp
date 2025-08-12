#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio2.h>
#include <string.h>
#include <windows.h>
#include "FilaPrioridade2.h"

int main(){
    TpFilaPrioridade FP;
    TpElemento elem;

    FPInicializar(FP);

    elem.Elemento = 'A';
    elem.Prioridade = 3;
    FPInserir(FP, elem);

    elem.Elemento = 'B';
    elem.Prioridade = 2;
    FPInserir(FP, elem);

    elem.Elemento = 'C';
    elem.Prioridade = 3;
    FPInserir(FP, elem);

    //FPRetirar(FP);

    FPExibir(FP);

    getch();

    return 0;
}
