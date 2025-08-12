#include <stdio.h>

#define MAXFILAFP 10000

struct TpElemento
{
	int Prioridade;
	int Info;
};

struct TpFilaPrioridade
{
	int Inicio, Fim, Cont;
	TpElemento Fila[MAXFILAFP];
};

void InicializarFP(TpFilaPrioridade &F)
{
	F.Cont = 0;
	F.Fim = -1;
	F.Inicio = 0;
}

TpElemento ElemInicioFP(TpFilaPrioridade F)
{
	return F.Fila[F.Inicio];
}

TpElemento ElemFimFP(TpFilaPrioridade F)
{
	return F.Fila[F.Fim];
}

TpElemento RetirarFP(TpFilaPrioridade &F)
{
	TpElemento Aux = F.Fila[F.Inicio++];

	if(F.Inicio == MAXFILAFP)
		F.Inicio = 0;

	F.Cont--;

	return Aux;
}

char CheiaFP(int Qtde)
{
	return Qtde == MAXFILAFP;
}

char VaziaFP(int Qtde)
{
	return Qtde == 0;
}

void AdcFP(TpFilaPrioridade &F, TpElemento Ele)
{
	if(F.Fim == MAXFILAFP - 1)
		F.Fim = -1;

	F.Cont++;

	F.Fila[++F.Fim] = Ele;
}

void InserirFP(TpFilaPrioridade &FP, TpElemento Ele)
{
	TpFilaPrioridade Aux;
	InicializarFP(Aux);

	while(!VaziaFP(FP.Cont) && ElemInicioFP(FP).Prioridade <= Ele.Prioridade)
		AdcFP(Aux, RetirarFP(FP));

	AdcFP(Aux, Ele);

	while(!VaziaFP(Aux.Cont))
		AdcFP(FP, RetirarFP(Aux));
}

void ExibeFP(TpFilaPrioridade F)
{
	TpElemento Aux;

	while(!VaziaFP(F.Cont))
	{
		Aux = RetirarFP(F);

		printf("%d (%d)\n", Aux.Info, Aux.Prioridade);
	}
}
