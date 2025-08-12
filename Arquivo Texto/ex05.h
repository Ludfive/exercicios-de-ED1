struct TpAposta{
	int nrAposta, vetAp[7];
	char data[11];
};

void geraArquivo(char nomeArq[100]){
	int i, j, qtd;
	FILE *fp = fopen(nomeArq, "w");
	TpAposta aposta;

    printf("Quantidade de apostas: ");
	scanf("%d", &qtd); // quantidade de apostas a serem feitas
	for(i=0; i<qtd; i++){
		aposta.nrAposta = i+1;
		strcpy(aposta.data, "01/03/2020");    // adiciona a data na variavel da struct
		fprintf(fp, "%d\t%s", aposta.nrAposta, aposta.data);
		for(j=0; j<7; j++){
			aposta.vetAp[j] = rand()%60+1;
			fprintf(fp, "\t%d", aposta.vetAp[j]);  // printa os 7 números
		}
		fprintf(fp, "\n");
	}
	fclose(fp);

}

void mostraArquivo(char nomeArq[100]){
    TpAposta aposta;
    FILE *ptr = fopen(nomeArq, "r");

    fscanf(ptr, "%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d", &aposta.nrAposta, &aposta.data, &aposta.vetAp[0], &aposta.vetAp[1], &aposta.vetAp[2], &aposta.vetAp[3], &aposta.vetAp[4], &aposta.vetAp[5], &aposta.vetAp[6]);
    while(!feof(ptr)){
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", aposta.nrAposta, aposta.data, aposta.vetAp[0], aposta.vetAp[1], aposta.vetAp[2], aposta.vetAp[3], aposta.vetAp[4], aposta.vetAp[5], aposta.vetAp[6]);

        fscanf(ptr, "%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d", &aposta.nrAposta, &aposta.data, &aposta.vetAp[0], &aposta.vetAp[1], &aposta.vetAp[2], &aposta.vetAp[3], &aposta.vetAp[4], &aposta.vetAp[5], &aposta.vetAp[6]);
    }

    fclose(ptr);
}

void geraPremiadas(char nomeArq[100], int premiadas[5]){
    TpAposta aposta;
    FILE *ptr = fopen(nomeArq, "r");
    int i, j, cont=0;

    fscanf(ptr, "%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d", &aposta.nrAposta, &aposta.data, &aposta.vetAp[0], &aposta.vetAp[1], &aposta.vetAp[2], &aposta.vetAp[3], &aposta.vetAp[4], &aposta.vetAp[5], &aposta.vetAp[6]);
    while(!feof(ptr)){

        cont = 0;

        for(i=0; i<5; i++)
            for(j=0; j<7; j++)
                    if(premiadas[i] == aposta.vetAp[j])
                        cont++;

        if(cont == 5)
            printf("Numero da Aposta Premiada com a QUINA: %d\n", aposta.nrAposta);
        else if(cont == 4)
            printf("Numero da Aposta Premiada com a QUADRA: %d\n", aposta.nrAposta);
        else if(cont == 3)
            printf("Numero da Aposta Premiada com o TERNO: %d\n", aposta.nrAposta);

        fscanf(ptr, "%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d", &aposta.nrAposta, &aposta.data, &aposta.vetAp[0], &aposta.vetAp[1], &aposta.vetAp[2], &aposta.vetAp[3], &aposta.vetAp[4], &aposta.vetAp[5], &aposta.vetAp[6]);
    }


    fclose(ptr);
}
