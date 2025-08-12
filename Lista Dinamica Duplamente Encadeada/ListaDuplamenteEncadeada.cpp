#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

struct TpPont{
    char elem;
    TpPont *ant, *prox;
};

char LeValor(void){
   printf("\nElemento: ");
   return toupper(getche());
}

TpPont *NovaCaixa(char elemento){
    TpPont *caixa;

    caixa = new TpPont; //instanciei
    caixa->elem = elemento;
    caixa->prox = NULL;
    caixa->ant = NULL;

    return caixa;
}

TpPont *InsereInicioLista(TpPont *head){
    TpPont *nc;
    char elemento;

    elemento = LeValor();
    while(elemento != 27){

        nc = NovaCaixa(elemento);
        if(head != NULL){
            nc->prox = head;
            head->ant = nc;
        }
        head = nc;

        elemento = LeValor();
    }

    return head;
}
TpPont *InsereFinalLista(TpPont *head){
    TpPont *nc, *aux;
    char elemento;

    elemento = LeValor();
    while(elemento != 27){

        nc = NovaCaixa(elemento);
        if(head == NULL)
            head = nc;
        else{
            aux = head;
            while(aux->prox != NULL)
                aux = aux->prox;
            nc->ant = aux;
            aux->prox = nc;

        }

        elemento = LeValor();
    }

    return head;
}
TpPont *InsereEntreDoisElementos(TpPont *head){
    TpPont *nc, *aux;
    char elemento, elem1, elem2;

    elemento = LeValor();
    fflush(stdin);
    printf("\nElemento 1 conhecido: ");
    fflush(stdin);
    elem1 = toupper(getche());
    printf("\nElemento 2 conhecido: ");
    fflush(stdin);
    elem2 = toupper(getche());

    aux = head;
    while(aux != NULL && aux->elem != elem1 && aux->prox->elem != elem2)
        aux = aux->prox;

    if(aux->elem == elem1 && aux->prox->elem == elem2){
        nc = NovaCaixa(elemento);

        nc->prox = aux->prox;
        nc->ant = aux;
        aux->prox = nc;
        aux->prox->ant = nc;

    }
    else
        printf("\nElementos conhecidos digitados nao foram encontrados ou nao estao em ordem!\n");

    return head;
}
TpPont *RetornaPosicao(TpPont *head, char elemento){
    TpPont *aux;

    aux = head;
    while(aux != NULL && elemento > aux->elem){
        printf("\nteste\n");
        aux = aux->prox;
    }

    return head;
}

void Exibe(TpPont *head){
    printf("\n\n======= Elementos contidos na Lista =======\n");
	while (head != NULL){
	   printf("%c ",head->elem);
	   head = head->prox;
    }
    printf("\n===========================================\n");
	getch();
}

TpPont *InserirOrdenado(TpPont *head){
    TpPont *nc, *aux, *guarda;
    char elemento;

    elemento = LeValor();
    while(elemento != 27){

        nc = NovaCaixa(elemento);

        if(head == NULL)
            head = nc;
        else{
            aux = head;
            while(aux->prox != NULL && elemento > aux->elem)
                aux = aux->prox;

            if(aux->ant == NULL && elemento < aux->elem){ // caso 1 - insere inicio
                nc->prox = head;
                head->ant = nc;
                head = nc;
            }
            else if(aux->prox == NULL && elemento> aux->elem){ // caso 2 - insere fim
                nc->ant = aux;
                aux->prox = nc;
            }
            else{  // caso 3 - insere entre duas posicoes
                nc->prox = aux;
                nc->ant = aux->ant;
                aux->ant = nc;
                nc->ant->prox = nc;
            }

        }

        elemento = LeValor();
    }
    return head;
}
TpPont *InsereOrdenado(TpPont *head, char elemento){
    TpPont *nc, *p;

    nc = NovaCaixa(elemento);

    if(head == NULL) //lista vazia
        head = nc;
    else if(elemento <= head->elem){
        nc->prox = head;
        head->ant = nc;
        head = nc;
    }
    else{
        p = head;
        while(p->prox != NULL && elemento > p->elem)
            p = p->prox;

        if(p->prox == NULL && elemento > p->elem){
            nc->ant = p;
            p->prox = nc;
        }
        else{
            nc->prox = p;
            nc->ant = p->ant;
            p->ant=nc;
            nc->ant->prox=nc;
        }
    }

    return head;
}
TpPont *ExcluiElemento(TpPont *head, char elemento){
    TpPont *p;

    if(head == NULL)
        printf("\nLista Vazia!\n");
    else if(head->elem == elemento){ // elemento ta na primeira posiçao
        p = head;
        head = head->prox;
        delete(p);
    }
    else{
        p = head;
        while(p->prox != NULL && p->elem != elemento)
            p = p->prox;

        if(p->elem == elemento){
            p->ant->prox = p->prox;
            p->prox->ant = p->ant;
            delete(p);
        }
        else
            printf("\nElemento nao encontrado!\n");
    }

    return head;
}

void ExibePrimeiroElemento(TpPont *head){
    printf("\nElemento do inicio = %c\n", head->elem);
}
void ExibeUltimoElemento(TpPont *head){
    TpPont *p = head;
    while(p->prox != NULL)
        p = p->prox;
    printf("\nElemento do fim = %c\n", p->elem);
}
void BuscaElemento(TpPont* head, char elemento){
    TpPont *p = head;
    while(p->prox != NULL && elemento != p->elem)
        p = p->prox;

    if(p->elem == elemento)
        printf("\nElemento %c encontrado!\n", elemento);
    else
        printf("\nElemento %c não encontrado!\n");
}
int BuscaElementoRecursivamente(TpPont *head, char elemento){
    if(head->elem == elemento)
        return 1;
    if(head->prox == NULL)
        return 0;
    else{
        BuscaElementoRecursivamente(head->prox, elemento);
    }
}


TpPont *ExcluiTodosElementos(TpPont* head){
    return head = NULL;
}

TpPont *ExcluiTodosElementoRecursivamente(TpPont *head){
    TpPont *aux;

    aux = head;
    head = head->prox;
    delete(aux);

    if(head == NULL)
        return head;
    else
        return ExcluiTodosElementoRecursivamente(head);
}

char menu(){
    system("cls");
    printf("\n\n\n\n\n\n\n\t\t\t================================ MENU ================================\n");
    printf("\t\t\t[ A ] - Exibir primeiro elemento da lista\n");
    printf("\t\t\t[ B ] - Exibir ultimo elemento da lista\n");
    printf("\t\t\t[ C ] - Inserir no inicio\n");
    printf("\t\t\t[ D ] - Inserir no fim\n");
    printf("\t\t\t[ E ] - Inserir entre dois elementos previamente conhecidos\n");
    printf("\t\t\t[ F ] - Inserir ordenado\n");
    printf("\t\t\t[ G ] - Consultar um elemento\n");
    printf("\t\t\t[ H ] - Exibir a lista\n");
    printf("\t\t\t[ I ] - Excluir um elemento\n");
    printf("\t\t\t[ J ] - Excluir todos os elementos\n");
    printf("\t\t\t[ K ] - Inserir ordenado 2.0\n");
    printf("\t\t\t[ L ] - Excluir todos os elementos recursivamente\n");
    printf("\t\t\t[ M ] - Busca elemento recursivamente\n");
    printf("\t\t\t[ ESC ] - Sair\n");
    printf("\t\t\t----------> ");
    return toupper(getche());
}

int main(){
    TpPont *head = NULL;
    char op, letra;

    do{
        op = menu();

        system("cls");
        switch(op){
            case 'A':
                ExibePrimeiroElemento(head);
                break;
            case 'B':
                ExibeUltimoElemento(head);
                break;
            case 'C':
                head = InsereInicioLista(head);
                Exibe(head);
                break;
            case 'D':
                head = InsereFinalLista(head);
                Exibe(head);
                break;
            case 'E':
                head = InsereEntreDoisElementos(head);
                Exibe(head);
                break;
            case 'F':
                letra = LeValor();
                while(letra != 27){
                    head = InsereOrdenado(head, letra);
                    Exibe(head);
                    letra = LeValor();
                }
                break;
            case 'G':
                BuscaElemento(head, LeValor());
                break;
            case 'H':
                Exibe(head);
                break;
            case 'I':
                head = ExcluiElemento(head, LeValor());
                Exibe(head);
                break;
            case 'J':
                head = ExcluiTodosElementos(head);
                break;
            case 'K':
                head = InserirOrdenado(head);
                Exibe(head);
                break;
            case 'L':
                head = ExcluiTodosElementoRecursivamente(head);
                break;
            case 'M':
                if(BuscaElementoRecursivamente( head, LeValor()) == 1)
                    printf("Achou!\n");
                else
                    printf("Nao achou!\n");
                break;
        }

        Exibe(head);

    }while(op != 27);


    return 1;
}
