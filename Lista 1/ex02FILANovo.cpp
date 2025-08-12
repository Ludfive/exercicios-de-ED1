#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
#include<locale.h>
#include<time.h>
#include "FILA02Novo.h"

/* -> PADRAO DO ARQUIVO:
/PLACA/COR/FABRICANTE/QTDE_EIXOS/CATEGORIA/TEMPO_QUE_DEMORA_PARA_PASSAR_NO_SEMAFORO/
*/

char menu(){
    system("cls");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t====================================\n");
    printf("\t\t\t\t\t        SIMULACAO FILA SEMAFORO        \n");
    printf("\t\t\t\t\t====================================\n");
    printf("\t\t\t\t\t   [ ENTER ]  -  Iniciar\n");
    printf("\t\t\t\t\t   [ Qualquer tecla ]  - Sair\n");
    printf("\t\t\t\t\t====================================\n");

    return toupper(getch());
}


int main(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    TpFilaCirc fila;
    TpElemento veiculo, processo;

    int ut, tempoPassando;
    char op;

    op = menu();
    while(op == 13){

        system("cls");
        FILE *ptr = fopen("Veiculos.txt", "r");

        ut = 1;

        FCInicializar(fila);

        while(!feof(ptr) || !FCVazia(fila.cont)){

            textcolor(2);
            gotoxy(99, 1);
            printf("UT = %d\n", ut);
            textcolor(15);

            if(ut % 7 == 0){
                fscanf(ptr,"%[^;];%[^;];%[^;];%d;%[^;];%d\n", &veiculo.placa, &veiculo.cor, &veiculo.fabricante, & veiculo.qtdeEixos, &veiculo.categoria, &veiculo.tempoParaPassar);

                FCInserir(fila, veiculo);

            }

            if(ut % 60 == 0){  // o semaforo abre de 60 em 60 ut

                tempoPassando = 0;

                while(ut % 90 != 0){  // o semaforo fecha em 30 ut

                    textcolor(2);
                    gotoxy(99, 1);
                    printf("UT = %d\n", ut);
                    textcolor(15);

                    if(!FCVazia(fila.cont) && tempoPassando == 0){

                        processo = FCRetirar(fila);
                        tempoPassando = processo.tempoParaPassar;
                        printf("Carro que esta passando: %s - Tempo: %d\n", processo.placa, processo.tempoParaPassar);

                    }

                    if(tempoPassando > 0){

                        tempoPassando--;
                        if(tempoPassando == 0){
                            printf("O carro %s passou!\n", processo.placa);
                        }

                    }

                    Sleep(900);
                    ut++;
                }

                getch();
            }


            ut++;
            Sleep(900);
        }

















        fclose(ptr);
        op = menu();
    }



    return 0;
}
