#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio2.h>
#include <string.h>
#include <windows.h>
#include "FilaCircular2.h"


int main(){
    TpFilaCirc F;

    FCInicializar(F);

    FCInserir(F, 'A');
    FCInserir(F, 'B');
    FCInserir(F, 'C');
    FCInserir(F, 'D');
    FCInserir(F, 'E');
    FCInserir(F, 'F');
    FCInserir(F, 'G');
    FCInserir(F, 'H');
    FCInserir(F, 'I');
    FCInserir(F, 'J');

    FCRetirar(F);

    FCInserir(F, 'K');

    FCExibir(F);
}
