#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>
#include<time.h>
#include "nPilhas.h"

//pilha 0 sendo minha auxiliar
void Concatenar(tpPilha &p){
	while(!vazia(p,2))
		inserir(p,retirar(p,2),0);
	
	while(!vazia(p,0))
		inserir(p,retirar(p,0),1);
		
	exibe(p,1);
}

int main(){
	tpPilha pilha;
	inicializar(pilha,3);
	
	//pilha 1
	inserir(pilha,34,1);
	inserir(pilha,87,1);
	inserir(pilha,32,1);
	inserir(pilha,45,1);
	
	//pilha 2
	inserir(pilha,28,2);
	inserir(pilha,74,2);
	inserir(pilha,56,2);
	inserir(pilha,41,2);
	inserir(pilha,23,2);
	
	Concatenar(pilha);
	return 1;
}


