struct TpFilme{
    char titulo[70], classif[10];
    int producao, duracao;
    float gasto, renda, taxaEspec;
};

int validaArquivo(char nomeArq[100]){
    if(nomeArq == NULL)
        return 0;
    else
        return 1;
}

void filmeMaiorLucro(char nomeArq[100]){
    FILE *ptr = fopen(nomeArq, "r");
    TpFilme filme;
    float maiorLucro = 0, renda;
    char nomeFilme[70];
    int ano;

    fscanf(ptr,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&filme.titulo, &filme.producao, &filme.classif, &filme.gasto, &filme.renda, &filme.duracao, &filme.taxaEspec);
    while(!feof(ptr)){
        renda = filme.renda - filme.gasto;
        if(renda > maiorLucro){
            maiorLucro = renda;
            strcpy(nomeFilme, filme.titulo);
            ano = filme.producao;
        }

        fscanf(ptr,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&filme.titulo, &filme.producao, &filme.classif, &filme.gasto, &filme.renda, &filme.duracao, &filme.taxaEspec);
      }

 printf("Filme com maior lucro: %s - %d, lucro: %.2f\n", nomeFilme, ano, maiorLucro);

 fclose(ptr);
}

void maiorTaxa(char nomeArq[100]){
	FILE *ptr = fopen(nomeArq, "r");
   TpFilme filme;
   float maiortaxa=0;
   char nomefilme[60];
   int ano;
   
   fscanf(ptr,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&filme.titulo, &filme.producao, &filme.classif, &filme.gasto, &filme.renda, &filme.duracao, &filme.taxaEspec);
	while(!feof(ptr)){
		
		if(filme.taxaEspec > maiortaxa){
			maiortaxa = filme.taxaEspec;
			strcpy(nomefilme,filme.titulo);
			ano = filme.producao;
		}
		
	  fscanf(ptr,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&filme.titulo, &filme.producao, &filme.classif, &filme.gasto, &filme.renda, &filme.duracao, &filme.taxaEspec);
	}
	printf("Filme com maior taxa de expectadores: %s - %d e com taxa de %.1f expectadores\n",nomefilme,ano,maiortaxa);
	
	fclose(ptr);
}

void duracaoMedia(char nomeArq[100]){
	FILE *ptr = fopen(nomeArq, "r");
   TpFilme filme;
   float media=0;
   int qtdeFilmes=0;
   
   fscanf(ptr,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&filme.titulo, &filme.producao, &filme.classif, &filme.gasto, &filme.renda, &filme.duracao, &filme.taxaEspec);
	while(!feof(ptr)){
		
	  media += filme.duracao;
	  //media = media + filme.duracao;
     qtdeFilmes++;
	  fscanf(ptr,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&filme.titulo, &filme.producao, &filme.classif, &filme.gasto, &filme.renda, &filme.duracao, &filme.taxaEspec);
	}
	
	media += filme.duracao;
	qtdeFilmes++;
	
	media = media/qtdeFilmes;
	printf("Duracao media dos %d filmes:  %.2f\n",qtdeFilmes,media);
	
	fclose(ptr);
}

void ordenaAnoProd(char nomeArq[100],int vet[36]){
	FILE *ptr = fopen(nomeArq,"r");
	int i,j,aux;
	for(i=0;i<36;i++)
		for(j=i+1;j<36;j++){
			if(vet[i] > vet[j])
			{
				aux=vet[i];
				vet[i]=vet[j];
				vet[j]=aux;
			}
		}
	fclose(ptr);
}

void anoFilmes(char nomeArq[100]){
	FILE *ptr = fopen(nomeArq,"r");
	TpFilme filme;
	int i=0,vet[36],maiorAno,maior=1,cont=0;
	
	fscanf(ptr,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&filme.titulo, &filme.producao, &filme.classif, &filme.gasto, &filme.renda, &filme.duracao, &filme.taxaEspec);
	while(!feof(ptr))
	{
		vet[i++] = filme.producao;
		fscanf(ptr,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&filme.titulo, &filme.producao, &filme.classif, &filme.gasto, &filme.renda, &filme.duracao, &filme.taxaEspec);
	}
	vet[i++] = filme.producao;
	ordenaAnoProd(nomeArq,vet);
	
	for(i=1;i<36;i++)
	{
		cont = 1;
		while(vet[i] == vet[i-1])
		{
			cont++;
			i++;
		}
		if(cont > maior){
			maior = cont;
			maiorAno = vet[i-1];
		}
	}
	   printf("O ano em que houve a maior quantidade de producoes foi %d, totalizando %d filmes\n", maiorAno, maior);
		
		fclose(ptr);
}
//gera relatório com filmes eparados por classificação
void geraRelatorioSeparadoPorClassif(char nomeArq[100]){
    FILE *ptr = fopen(nomeArq, "r");



    fclose(ptr);
}


void ordenaBubleSortArqBinario(char nomeArq2[100]){
    FILE *ptr = fopen(nomeArq2, "rb+");
    TpFilme ra, rb;
    int i, b, j;

    fseek(ptr, 0, 2);
    i = ftell(ptr) / sizeof(TpFilme);
    i--;

    while(i>0){
        for(j=0; j<i; j++){
            b = j +1;

            fseek(ptr, j*sizeof(TpFilme), 0);
            fread(&ra, sizeof(TpFilme), 1, ptr);
            fseek(ptr, b*sizeof(TpFilme), 0);
            fread(&rb, sizeof(TpFilme), 1, ptr);
            if(ra.producao > ra.producao){
                fseek(ptr, j*sizeof(TpFilme), 0);
                fwrite(&rb, sizeof(TpFilme), 1, ptr);
                fseek(ptr, b*sizeof(TpFilme), 0);
                fwrite(&ra, sizeof(TpFilme), 1, ptr);
            }
        }
        i--;
    }

    fclose(ptr);
}

void printaArqBinario(){
    FILE *ptr = fopen("FilmesOrdenadosPorAno.dat", "rb");
    TpFilme reg;

    fseek(ptr, 0, 0);

    fread(&reg, sizeof(TpFilme), 1, ptr);
    while(!feof(ptr))
	{
        printf("%s %d %s %.2f %.2f %d %.2f \n",reg.titulo, reg.producao, reg.classif, reg.gasto, reg.renda, reg.duracao, reg.taxaEspec);

        fread(&reg, sizeof(TpFilme), 1, ptr);
    }

    fclose(ptr);
}

void geraArqBinOrdenadosPorAno(char nomeArq[100]){
    char nomeArq2[100];
    strcpy(nomeArq2, "FilmesOrdenadosPorAno.dat");
    FILE *ptr1 = fopen(nomeArq, "r");
    FILE *ptr2 = fopen(nomeArq2, "wb");
    TpFilme filme;

    rewind(ptr2);

    fscanf(ptr1,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&filme.titulo, &filme.producao, &filme.classif, &filme.gasto, &filme.renda, &filme.duracao, &filme.taxaEspec);
    while(!feof(ptr1)){

        fwrite(&filme, sizeof(TpFilme), 1, ptr2);

        fscanf(ptr1,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&filme.titulo, &filme.producao, &filme.classif, &filme.gasto, &filme.renda, &filme.duracao, &filme.taxaEspec);
    }

	fclose(ptr1);
	fclose(ptr2);

    ordenaBubleSortArqBinario(nomeArq2);

    printaArqBinario();

}


void indicaValorMedianoAnoProducao(char nomeArq[100]){
    FILE *ptr = fopen(nomeArq, "r");
    TpFilme filme;
    int i=0, vet[36], anoMed;
    float mediana;

    fscanf(ptr,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&filme.titulo, &filme.producao, &filme.classif, &filme.gasto, &filme.renda, &filme.duracao, &filme.taxaEspec);
    while(!feof(ptr)){

        vet[i++] = filme.producao;

        fscanf(ptr,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&filme.titulo, &filme.producao, &filme.classif, &filme.gasto, &filme.renda, &filme.duracao, &filme.taxaEspec);
    }
    vet[i++] = filme.producao;

    ordenaAnoProd(nomeArq, vet);

    mediana = (float) (vet[18] + vet[17])/2;

    printf("\n\nValor mediano entre o ano de producao dos filmes foi %f\n", mediana);

    fclose(ptr);
}
	
