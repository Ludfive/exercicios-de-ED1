#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

struct TpPont{
   char Elem;
   TpPont *ant, *prox;
};
struct TpDescritor{
   TpPont *Inicio, *Final;
   int Qtde;
};

TpPont *NovaCaixa(char Elemento){
    TpPont *pCaixa = new TpPont;
    pCaixa->Elem = Elemento;
    pCaixa->ant = NULL;
    pCaixa->prox = NULL;
    return pCaixa;
}

void InicializarDescritor(TpDescritor &Desc){
    Desc.Inicio = Desc.Final = NULL;
    Desc.Qtde = 0;
}

void InserirOrdenado(TpDescritor &Desc, char Elemento){
    TpPont *p, *NC = NovaCaixa(Elemento);

    Desc.Qtde++;
    if (Desc.Inicio == NULL)   //Lista Vazia!
        Desc.Inicio = Desc.Final = NC;
    else{
        if (Elemento <= Desc.Inicio->Elem){
            NC->prox = Desc.Inicio;
            Desc.Inicio->ant = NC;
            Desc.Inicio = NC;
        }
        else{
            if (Elemento >= Desc.Final->Elem){
                NC->ant = Desc.Final;
                Desc.Final->prox = NC;
                Desc.Final = NC;
            }
            else{
                p = Desc.Inicio->prox;
                while (Elemento > p->Elem)
                        p = p->prox;

                NC->prox = p;
                NC->ant = p->ant;
                p->ant = NC;
                NC->ant->prox = NC;
            }
        }
    }
}

void Exclusao(TpDescritor &desc, char elemento){
    TpPont *p;

    if(desc.Inicio == NULL)
        printf("\nLista Vazia!\n");
    else if(elemento == desc.Inicio->Elem){ // elemento ta no inicio
        desc.Qtde--;
        desc.Inicio = desc.Inicio->prox;
        delete(desc.Inicio->ant);
    }
    else if(elemento == desc.Final->Elem){ // elemento ta no fim
        desc.Qtde--;
        desc.Final->ant->prox = NULL;
        delete(desc.Final);
    }
    else{  // elemento ta no meio
        p = desc.Inicio->prox;
        while(elemento != p->Elem && p->prox != NULL)
            p = p->prox;

        if(p->Elem == elemento){
            desc.Qtde--;
            p->ant->prox = p->prox;
            p->prox = p->ant;
            delete(p);
        }
        else{
            printf("\nElemento nao encontrado!\n");
        }
    }
}

void Exibir(TpDescritor Desc){
	printf("\n\n======= Elementos contidos na Lista =======\n");
	while (Desc.Inicio!=NULL)
	{
	   printf("%c ",Desc.Inicio->Elem);
	   Desc.Inicio = Desc.Inicio->prox;
    }
    printf("\n===========================================\n");
	getch();
}


int main(void){
    TpDescritor Descritor;

    InicializarDescritor(Descritor);
    InserirOrdenado(Descritor,'M');
    Exibir(Descritor);
    InserirOrdenado(Descritor,'G');
    Exibir(Descritor);
    InserirOrdenado(Descritor,'Z');
    Exibir(Descritor);
    InserirOrdenado(Descritor,'F');
    Exibir(Descritor);

    Exclusao(Descritor, 'Z');
    Exibir(Descritor);

    return 1;
}
