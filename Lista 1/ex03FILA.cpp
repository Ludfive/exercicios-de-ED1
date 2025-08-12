#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>
#include<windows.h>
#include "FILA03.h"


int main(){
    /*
    [1] - Impressao -> 3ut
    [2] - Gravaçao em disp. interno -> 5ut
    [3] - Leitura -> 4ut
    [4] - Gravaçao em disp. externo -> 8ut
    */
    TpFila F;

    Inicializar(F);

    int ut = 0, elemento;

    while(!kbhit() && (!FilaCheia(F.inicio, F.fim))){
        if(ut % 2 == 0)
            Inserir(F, (rand()%4)+1);

        MostrarFila(F);

        elemento = ElementoInicio(F);
        if(elemento == 1 && (ut % 3 == 0))
            Retirar(F);
        else if(elemento == 2 && (ut % 5 == 0))
            Retirar(F);
        else if(elemento == 3 && (ut % 4 == 0))
            Retirar(F);
        else if(elemento == 4 && (ut % 8 == 0))
            Retirar(F);

        Sleep(1000);
        printf("\nUT = %d\n", ut);

        ut++;
    }
    system("pause");
}
