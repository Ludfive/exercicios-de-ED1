#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio2.h>
#include <string.h>
#include <windows.h>
#include "FilaCircularPrioridade.h"

int main(){
    TpFilaCircPri FCP;
    TpElemento elem;

    FCPInicializar(FCP);

    elem.Elemento = 'A';
    elem.Prioridade = 3;
    FCPInserir(FCP, elem);

    elem.Elemento = 'B';
    elem.Prioridade = 2;
    FCPInserir(FCP, elem);

    elem.Elemento = 'C';
    elem.Prioridade = 1;
    FCPInserir(FCP, elem);

    elem.Elemento = 'D';
    elem.Prioridade = 3;
    FCPInserir(FCP, elem);

    elem.Elemento = 'E';
    elem.Prioridade = 3;
    FCPInserir(FCP, elem);

    elem.Elemento = 'F';
    elem.Prioridade = 2;
    FCPInserir(FCP, elem);

    //FCPRetirar(FCP);

    elem.Elemento = 'G';
    elem.Prioridade = 1;
    FCPInserir(FCP, elem);

    //FCPRetirar(FCP);

    FCPExibir(FCP);

    getch();

    return 0;
}
