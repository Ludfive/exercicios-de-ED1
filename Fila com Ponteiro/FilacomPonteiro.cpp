//LISTA SIMPLESMENTE ENCADEADA
#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>

struct tpPont{
	char info; //camo pra guardar o elemento
	tpPont *prox; //campo do tipo endereço pra apontar pro proximo(isso guarda o endereço)
};
// a variavel que a gnt declara é estatica (*caixa) ,entao nao posso deletar a caixa,mas posso deletar o tpPont que está no heap
//a medida que eu preciso,eu realoco espaço ,nao preciso alocar no começo do programa,igual um vetor[10]


//retorna um endereço -> endereço onde realocou a caixinha no heap //vai povoando o heap
tpPont *novaCaixa(char elemento){
	tpPont *caixa; //ponteiro pra uma caixinha / guarda o endereço pra um lugar/ aqui caixa estava apontando pra lixo
	
	caixa = new tpPont; //agora a caixa está apontando pra uma parte dinamica do heap,que tem um espaço pra info e prox
	caixa->info = elemento;
	caixa->prox = NULL;
	
	return caixa //retornar o endereço onde foi realocado esse espaço e é o conteudo,por isso nao é *caixa
	
}

tpPont *insereInicio(tpPont *Lista){ //passagem de parametro de ponteiro por valor
	tpPont *NC; //a lista só esta me dizendo quem é o primeiro da lista agora(vai atualizando)
	char elemento;
	printf("\n## Inserir no inicio da lista ##");
	printf("\n Elemento :");
	elemento = getche();
	while(elemento!=27)
	{
		NC = novaCaixa(elemento);
		if(lista == NULL)
			lista = NC;
		else
		{
			NC->prox= lista; //NC que agora esta apontando pra incio da fila,aponta agora pro novo elemento do inicio e o prox que estava apontando pra null
			lista=NC; //pra onde a lista esta apontando(que era o inicio) e agora a lista aponta para o novo inicio
		}
		printf("\n Elemento :");
		elemento = getche();
	}
	return lista;
	
}

void exibirLista(tpPont *lista){ //é void pq so está percorrendo a lista
	if(lista == NULL)
		printf("\nlista vazia!");
	else
	{
		while(lista->prox!=NULL)
		lista = lista->prox;
		printf("\nConteudo da lista:",lista->info);
	}	
	getch();
}

int main(){
	tpPont *L = NULL;
	L = insereInicio();
	exibirLista(L);
	return 0;
}

//lista precisa apontar pra onde o NC está apontando

