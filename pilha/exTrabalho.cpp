#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define TF 52

struct tpcarta
{
int num;//1=A, 5=5, J=12...
int naipe; //3=copas, 6=espadas, 4=ouros, 5=paus
int cor; //2=preto, 1=vermelo
};



void criabaralho(tpcarta baralho[TF])
{
int i,j=0,k=0,l=0;
for(i=0;i<=12;i++)
{
baralho[i].num=i+1;
baralho[i].naipe=3;
baralho[i].cor=1;
}
for(i=13;i<=25;i++,j++)
{
baralho[i].num=j+1;
baralho[i].naipe=6;
baralho[i].cor=2;
}
for(i=26;i<=38;i++,k++)
{
baralho[i].num=k+1;
baralho[i].naipe=4;
baralho[i].cor=1;
}
for(i=39;i<=51;i++,l++)
{
baralho[i].num=l+1;
baralho[i].naipe=5;
baralho[i].cor=2;
}


getch();
}
void embaralha(tpcarta baralho[TF])
{
tpcarta aux;
int p,j,i;
for(i=0;i<=100;i++)
{
p=rand()%52;
j=rand()%52;
aux=baralho[p];
baralho[p]=baralho[j];
baralho[j]=aux;
}
printf("%d%c",baralho[0].num,baralho[0].naipe);
getch();
}


void formarvetor(tpcarta baralho[TF], int &TL)
{
int um[13]={0},
dois[13]={1,2},
tres[13]={3,4,5},
quatro[13]={6,7,8,9},
cinco[13]={10,11,12,13,14},
seis[13]={15,16,17,18,19,20},
sete[13]={21,22,23,24,25,26,27},
oito[24]={28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51},
nove[24],
dez[13],
onze[13],
doze[13],
treze[13];

int
TL1=1,
TL2=2,
TL3=3,
TL4=4,
TL5=5,
TL6=6,
TL7=7,
TL8=24,
TL9=0,
TL10=0,
TL11=0,
TL12=0,
TL13=0;

}


void darcartas(tpcarta baralho[TF], int &TL)
{
int c,l,i,op;
for(i=0,c=3,l=10;i<7;i++)
{
gotoxy(c,l);

if(baralho[i].cor==1)
{
if(baralho[i].num==1)
{
textcolor(RED);
printf("A%c",baralho[i].naipe);
}
else
if(baralho[i].num==11)
{
textcolor(RED);
printf("Q%c",baralho[i].naipe);
}

else
if(baralho[i].num==12)
{
textcolor(RED);
printf("J%c",baralho[i].naipe);
}
else
if(baralho[i].num==13)
{
textcolor(RED);
printf("K%c",baralho[i].naipe);
}

else
{
textcolor(RED);
printf("%d%c",baralho[i].num,baralho[i].naipe);}

}

if(baralho[i].cor==2)
{
if(baralho[i].num==1)
{
textcolor(BLACK);
printf("A%c",baralho[i].naipe);
}
else
if(baralho[i].num==11)
{
textcolor(BLACK);
printf("Q%c",baralho[i].naipe);
}

else
if(baralho[i].num==12)
{
textcolor(BLACK);
printf("J%c",baralho[i].naipe);
}
else
if(baralho[i].num==13)
{
textcolor(BLACK);
printf("K%c",baralho[i].naipe);
}

else
{
textcolor(BLACK);
printf("%d%c",baralho[i].num,baralho[i].naipe);
}

}
c=c+8;
}
for(i=0,c=3,l=12;i<7;i++)
{
textcolor(WHITE);
gotoxy(c,l);
printf("(%d)",i+1);
c=c+8;
}

for(i=0,c=7,l=12;i<7;i++)
{
textcolor(BLUE);
gotoxy(c,l);
printf("(%d)",i+1);
c=c+8;
}

for(i=0,c=3,l=2,op=35;i<3;i++)
{ textcolor(WHITE);
gotoxy(c,l);
printf("%c",op);
c=c+1;
}
for(i=0,c=3,l=4,op=43;i<2;i++)
{
gotoxy(c,l);
printf("(%c)",op);
c=c+8;
op--;
}
for(i=0,c=27,l=4,op=97;i<4;i++)
{
gotoxy(c,l);
printf("(%c)",op);
c=c+8;
op++;
}
getch();
}
void esqueleto()
{
int i,c,l,t;
textbackground(GREEN);
clrscr();
for(i=0,c=2,l=2,t=179;i<20;i++)
{
gotoxy(c,l);
printf("%c",t);
c=c+4;
if(i>=3)
{
l=4; c=2;
do{
gotoxy(c,l);
printf("%c",t);
c=c+4;
i++;
}while(i<=6);
}
if(i>=7)
{
c=26; l=2;
do{
gotoxy(c,l);
printf("%c",t);
c=c+4;
i++;
}while(i<=14);
if(i>=15)
{
l=4; c=26;
do{
gotoxy(c,l);
printf("%c",t);
c=c+4;
i++;
}while(i<=22);
}
}
if(i>=22)
{
l=10; c=2;
do{
gotoxy(c,l);
printf("%c",t);
c=c+4;
i++;
}while(i<=36);
}
if(i>=36)
{
l=12; c=2;
do{
gotoxy(c,l);
printf("%c",t);
c=c+4;
i++;
}while(i<=50);
}
}

}

/*char menu(void)
{
return getch();


}

int logica(tpcarta baralho[TF], int TL)
{
int i=0;
char opcao;

do
{
opcao=menu();
switch (opcao)
{
case '+':formarvetor(baralho,TL);break;
case '*':break;
case '1':break;
case '2':break;
case '3':break;
case '4':break;
case '5':break;
case '6':break;
case '7':break;
case 'a':break;
case 'b':break;
case 'c':break;
case 'd':break;
}
} while(i!=0);

}

*/
int main (void)
{
srand(time(NULL));
int vet[TF],TL=0;
tpcarta baralho[TF];

esqueleto();
criabaralho(baralho);
embaralha(baralho);
darcartas(baralho,TL);
formarvetor(baralho,TL);


}
