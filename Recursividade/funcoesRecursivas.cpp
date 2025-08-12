#include <stdio.h>

//fatorial sem recurs
int fatorial(int n) {
	int fat = 1;
	while(n > 1)
	{
		fat = fat * n;
		n--;
	}
	
	return fat;                         
}

//fat com recursividade(na recursividade ele nao declara ada dentro da funçao.Tem que passar o que eu querovpor parametro)
long long int fatRecu(int n) {
	if(n == 0)
		return 1;
	return n * fatRecu(n-1);
}


int simu(int n){
	if(n == 0)
		return 1;
	if(n == 1)
		return 4;
	else
		return 3*simu(n-1) + 3*simu(n-2);
}

//potencia x elevado a y

int potencia(int n,int e){
	if(e == 0)
		return 1;
	if(n == 0)
		return 0;
	if(e > 0)
		return n* potencia(n,e-1);
}

//int Vetor(int vet[10],int tl,int vet2){
//	if(tl == 0)
//		return 0;
//	if(tl > 0 )
//	{
//		vet2 = vet[tl];
//	}
//	return Vetor(vet,tl-1);
//
//}


//int fibonacci(int x){
//	if(x==0 || x==1)
//		return 1;
//	else
//		return fibonacci(x-1) + fibonacci(x-2);	
//}
//
//int recursivo(int n,int m){
//	if(n == m || n ==0)
//		return 1;
//	else
//		return recursivo(n-1,m) + recursivo(n-1,m+1);
//}
//
int MDC(int x,int y){
	if(x == y)
		return y;
	else if(x < y)
		return (y,y-x);
	else if(x > y)
		return (x-y,y);
}


int main(void) {
	int n=0, m=0,e=0;
	printf("Digite n: ");
	scanf("%d", &n);
	//printf("Digite m: ");
	//scanf("%d", &m);
//	printf("Digite o exponencial: ");
//	scanf("%d", &e);
	//printf("Fatorial de %d: %llu", num, fatRecu(num));
	//printf("Recursivo de (%d,%d) = %d", n, m, recursivo(n, m) );
//	int vetor[10] = {456,123,543,997,890,547,854};
//	int vetor2[7];
//	int tl = 7;
   printf(" valor da simulacao : %d",simu(n));
   int x,y;
//	printf("Digite x: ");
//	scanf("%d", &x);
//	printf("Digite y: ");
//	scanf("%d", &y);
//	printf("O maior MDC de (%d,%d) : %d",x,y,MDC(x,y));
	 
}
