//implementacao
#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
float ordenashell(void) {
    FILE *arquivo;
    int *vetor, n, i = 0, j, h, aux;
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
    h = 1;
    inicio = clock();
    while (h < n) {
        h = h * 3 + 1;
    }
    while (h != 1) {
        h = (h - 1) / 3;
        for (i = h; i < n; i++) {
            aux = vetor[i];
            j = i;
            while (vetor[j - h] > aux) {
                vetor[j] = vetor[j - h];
                j = j - h;
                if (j < h) {
                    break;
                }
            }
            vetor[j] = aux;
        }
    }
    fim = clock();
    if ((arquivo = fopen("shell.txt", "w")) == NULL) {
        printf("Nao e possivel criar o arquivo\n");
    } else {
        for (i = 0; i < n; i++) {
            fprintf(arquivo, "%d\t", vetor[i]);
        }
    }
    fclose(arquivo);
    total = ((float) (fim - inicio) / CLOCKS_PER_SEC);
    printf("Vetor ordenado com sucesso!");
    return total;
}

float ordenaMerge() {
    FILE *arquivo;
    int *vetor, n, i = 0;
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
		  inicio=clock();
		  mergeSort(vetor, 0, n-1);
		  fim = clock();
					total = ((float) (fim - inicio) / CLOCKS_PER_SEC);
					printf("Vetor ordenado com sucesso!");
    return total;
}

void mergeSort(int *vetor, int comeco, int fim)
{
	int meio;
		if(comeco==fim)
		{
				//printf("Nada encontrado no vetor\n");
		return;
		}
			else{
				if(comeco<fim)
				{
					meio = floor(comeco+fim)/2;
					mergeSort(vetor, comeco, meio);
					mergeSort(vetor,meio+1,fim);
					mergeorganiza(vetor, comeco, meio, fim);
				}	
			}
	return;		
}

void mergeorganiza(int *vetor, int comeco, int meio, int fim)
{
	FILE *arquivo;
	int i, j, k, *tmp, partinicio=0,partmeio=0,quantidade, cont1=0, cont2=0;
		quantidade=fim-comeco+1;
			partinicio=comeco;
			partmeio=meio+1;
			tmp=(int *) malloc(sizeof(int) * quantidade);
				for(i=0;i<quantidade;i++)
				{
						if(cont1==0 && cont2==0 )
						{
								if(vetor[partinicio] < vetor[partmeio])
								{
								tmp[i]=vetor[partinicio++];
								}
									else{
									tmp[i]=vetor[partmeio++];	
									}
										if(partinicio>meio)
										{
										cont1=1;	
										}
											if(partmeio>fim)
											{
											cont2=1;	
											}
						}					
												else{
														if(cont1==0)
														{
														tmp[i]=vetor[partinicio++];
														}
															else{
																tmp[i]=vetor[partmeio++];
															}
												}
						}
						j=0;
						k=comeco;
				while(j<quantidade)
				{
						vetor[k]=tmp[j];	
					j++;
					k++;
				}
	free(tmp);
		if ((arquivo = fopen("merge.txt", "w")) == NULL) {
					printf("Nao e possivel criar o arquivo\n");
					}
					else {
						for (i = 0; i < quantidade; i++) {
						fprintf(arquivo, "%d\t", vetor[i]);
						}
						}
						fclose(arquivo);	
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
    printf("Mostrar ordem de\n[1]SHELL\t[2]MERGE\t[3]QUICK\n");
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
            if ((arquivo = fopen("merge.txt", "r")) == NULL) {
                printf("Vetor não ordenado para esse tipo\n");
            } else {
                printf("---MERGE SORT---\n");
                while (cont != a) {
                    fscanf(arquivo, "%d", &aux);
                    printf("%d\t", aux);
                    cont++;
                }
            }
            fclose(arquivo);
            break;
        case 3:
            if ((arquivo = fopen("quick.txt", "r")) == NULL) {
                printf("Vetor não ordenado para esse tipo\n");
            } else {
                printf("---QUICK SORT---\n");
                while (cont != a) {
                    fscanf(arquivo, "%d", &aux);
                    printf("%d\t", aux);
                    cont++;
                }
            }
            fclose(arquivo);
    }
}

