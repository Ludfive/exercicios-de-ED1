#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>
#include<time.h>
#include<string.h>
#include "ex9.h"

int main(){
	char frase[60];
	
	printf("Frase:");
	fflush(stdin);
	gets(frase);
	
	PalavrasOrdemReversa(frase);
	return 1;
}
