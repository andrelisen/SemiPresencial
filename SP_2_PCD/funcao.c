//implementacao
float ordenashell(void)
{
	 FILE *arquivo;
    int a, i = 0, *vetor, x, y, z, aux=0;
    clock_t inicio, fim;
    float total;
    if ((arquivo = fopen("entrada.txt", "r")) == NULL) {
        printf("Impossivel realizar a leitura do arquivo. Tente novamente\n");
    }
    //descobrir o número de valores
    fscanf(arquivo, "%d", &a); //faz a leitura do primeiro elemento do meu arquivo que por padrão é a quantidade de elementos do meu vetor
    //lendo os valores de entrada
    
    vetor = malloc(sizeof (int)* a);
    
    while (!feof(arquivo)) {
        fscanf(arquivo, "%d", &vetor[i]);
        i++;
    }
    fclose(arquivo);
    inicio = clock();
		x=1;
			while(x<a)
			{
				x=3*x+1;	
			}
				while(x>1)
				{
				  x=x-1/3;
					for(y=x;y<a;y++)
					{
					  z=vetor[y];
					  aux=y-x;
						while(aux >= 0 && z<vetor[aux])
						{
							vetor[aux+x];
							aux=aux-x;	
						}
					vetor[aux+x]=z;	
					}
				}
				 fim = clock();
				 
}
