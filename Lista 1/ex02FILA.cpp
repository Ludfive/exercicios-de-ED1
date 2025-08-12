#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>
#include<windows.h>
#include "ex02FILA.h"

int main(){
    TpFila F;
    Inicializar(F);

    int ut = 1, ut_semaforo, veiculosQSairam=0;

    while(!kbhit() && (!FilaCheia(F.inicio, F.fim))){

        if(ut % 5 == 0)          // um carro chega na fila do semáforo a cada 5 ut
            Inserir(F, rand()%100);

        if(ut % 30 == 0){  // o semáforo abre a cada 30 ut

            ut_semaforo=0;
            while(ut_semaforo < 15){

                if(ut_semaforo % 3 == 0){ // A cada 3 unidades de tempo do semaforo um carro sai
                    Retirar(F);
                    veiculosQSairam++;
                }
                ut_semaforo++;
            }
        }
        ut++;
    }

    printf("Quantidade de veículos que passaram pelo semáforo : %d\n", veiculosQSairam);
    printf("Tempo gasto pelos veículos que ficaram parados:  %d ut\n", ut);
    getch();
}
