//implementacao
#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>
#include <time.h>

float ordenashell(void)
{
	 FILE *arquivo;
    int *vetor, n, i=0, j, h, aux;
    clock_t inicio, fim;
    float total;
    if ((arquivo = fopen("entrada.txt", "r")) == NULL) {
        printf("Impossivel realizar a leitura do arquivo. Tente novamente\n");
    }
    //descobrir o número de valores
    fscanf(arquivo, "%d", &n); //faz a leitura do primeiro elemento do meu arquivo que por padrão é a quantidade de elementos do meu vetor
    //lendo os valores de entrada
    
    vetor = malloc(sizeof (int)* n);
    
    while (!feof(arquivo)) {
        fscanf(arquivo, "%d", &vetor[i]);
        i++;
    }
    fclose(arquivo);
    h=1;
    inicio = clock();
		while(h<n)
		{
				h=h*3+1;
		}
				while(h!=1)
				{
						h=(h-1)/3;
							for(i=h;i<n;i++)
							{
									aux=vetor[i];
									j=i;
										while(vetor[j-h] > aux)
										{
										vetor[j]=vetor[j-h];
										j=j-h;
												if(j<h)
												{
													break;
												}
										}
										vetor[j]=aux;
							}
				}
	fim = clock();
					if ((arquivo = fopen("shell.txt", "w")) == NULL) {
						printf("Nao e possivel criar o arquivo\n");
						} 
						else {
								for (i = 0; i < n; i++) {
									fprintf(arquivo, "%d\t", vetor[i]);
									}
							 }
		fclose(arquivo);
		 total = ((float) (fim - inicio) / CLOCKS_PER_SEC);
		printf("Vetor ordenado com sucesso!");
    return total;
}		 

void mostraentrada() {
    FILE *arquivo;
    int a, aux, cont = 0;
    if ((arquivo = fopen("entrada.txt", "r")) == NULL) {
        printf("Impossivel realizar a leitura do arquivo. Tente novamente\n");
    }
    //descobrir o número de valores
    fscanf(arquivo, "%d", &a);
    printf("Quantidade de números no total=%d\n", a);
    //lendo os valores de entrada
    while (cont != a) {
        fscanf(arquivo, "%d", &aux);
        printf("%d\t", aux);
        cont++;
    }
    fclose(arquivo);
}

void mostraordenado() {
    FILE *arquivo;
    int opcao, aux, a, cont;
    //sub=menu
    printf("Mostrar ordem de\n[1]SHELL\t[2]SELECTION\t[3]INSERTION\n");
    scanf("%d", &opcao);
    if ((arquivo = fopen("entrada.txt", "r")) == NULL) {
        printf("Impossivel realizar a leitura do arquivo. Tente novamente\n");
    }
    //descobrir o número de valores
    fscanf(arquivo, "%d", &a);
    fclose(arquivo);
    cont = 0; //zerando meu vetor auxiliar para o while
    switch (opcao) {
        case 1:
            if ((arquivo = fopen("shell.txt", "r")) == NULL) {
                printf("Vetor não ordenado para esse tipo\n");
            } else {
                printf("---SHELL SORT---\n");
                while (cont != a) {
                    fscanf(arquivo, "%d", &aux);
                    printf("%d\t", aux);
                    cont++;
                }
            }
            fclose(arquivo);
            break;
        case 2:
            if ((arquivo = fopen("selection.txt", "r")) == NULL) {
                printf("Vetor não ordenado para esse tipo\n");
            } else {
                printf("---SELECTION SORT---\n");
                while (cont != a) {
                    fscanf(arquivo, "%d", &aux);
                    printf("%d\t", aux);
                    cont++;
                }
            }
            fclose(arquivo);
            break;
        case 3:
            if ((arquivo = fopen("insertion.txt", "r")) == NULL) {
                printf("Vetor não ordenado para esse tipo\n");
            } else {
                printf("---INSERTION SORT---\n");
                while (cont != a) {
                    fscanf(arquivo, "%d", &aux);
                    printf("%d\t", aux);
                    cont++;
                }
            }
            fclose(arquivo);
    }
}

