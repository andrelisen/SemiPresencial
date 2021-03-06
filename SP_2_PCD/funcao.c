//implementacao
// Pesquisa e Classificação de Dados - Atividade Semi-Presencial 02 - 11 de abril de 2018
// Andrelise Nunes Lemos Pinheiro (andrelisenunes@hotmail.com) , Marina Silva da Silva (marina_silva98@hotmail.com).
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

float ordenaMerge(int *vetor, int n) {
    FILE *arquivo;
    int i = 0;
    clock_t inicio, fim;
    float total;

    inicio = clock();
    mergeSort(vetor, 0, n - 1);
    fim = clock();
    total = ((float) (fim - inicio) / CLOCKS_PER_SEC);
    printf("Vetor ordenado com sucesso!");
    if ((arquivo = fopen("merge.txt", "w")) == NULL) {
        printf("Nao e possivel criar o arquivo\n");
    } else {
        for (i = 0; i < n; i++) {
            fprintf(arquivo, "%d\t", vetor[i]);
        }
    }
    fclose(arquivo);
    
    return total;
}

void mergeSort(int *vetor, int comeco, int fim) {
    int meio;
    if (comeco == fim) {
        //printf("Nada encontrado no vetor\n");
        return;
    } else {
        if (comeco < fim) {
            meio = floor(comeco + fim) / 2;
            mergeSort(vetor, comeco, meio);
            mergeSort(vetor, meio + 1, fim);
            mergeorganiza(vetor, comeco, meio, fim);
        }
    }
    return;
}

void mergeorganiza(int *vetor, int comeco, int meio, int fim) {
    int i, j, k, *tmp, partinicio = 0, partmeio = 0, quantidade, cont1 = 0, cont2 = 0;
    quantidade = fim - comeco + 1;
    partinicio = comeco;
    partmeio = meio + 1;
    tmp = (int *) malloc(sizeof (int) * quantidade);
    for (i = 0; i < quantidade; i++) {
        if (cont1 == 0 && cont2 == 0) {
            if (vetor[partinicio] < vetor[partmeio]) {
                tmp[i] = vetor[partinicio++];
            } else {
                tmp[i] = vetor[partmeio++];
            }
            if (partinicio > meio) {
                cont1 = 1;
            }
            if (partmeio > fim) {
                cont2 = 1;
            }
        } else {
            if (cont1 == 0) {
                tmp[i] = vetor[partinicio++];
            } else {
                tmp[i] = vetor[partmeio++];
            }
        }
    }
    j = 0;
    k = comeco;
    while (j < quantidade) {
        vetor[k] = tmp[j];
        j++;
        k++;
    }
    free(tmp);
}

void mostraentrada() {
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

int* gerarNumeros(int n, int x) {
    FILE *arquivo;
    int i, *vetor;
    
    if(x!=0){
        printf("Digite a quantidade de numeros inteiros:");
        scanf("%d", &n);
    }
    
    //cria vetor com valores aleatórios
    vetor = malloc(sizeof (int)* n);
    srand(time(NULL));
    //abrindo arquivo que guardará os números gerados
    if ((arquivo = fopen("entrada.txt", "w")) == NULL) {
        printf("Nao e possivel criar um arquivo de texto. Tente novamente\n");
    }
    fprintf(arquivo, "%d\n", n); //primeiro elemento é o tamanho do meu vetor de números para a ordenação
    for (i = 0; i < n; i++) {
        vetor[i] = rand() % (n * 2);
        //printf("%d\n", vetor[i]);
        fprintf(arquivo, "%d\t", vetor[i]);
    }
    fclose(arquivo);
    x++;
    printf("-->NUMEROS GERADOS E SALVOS COM SUCESSO<--\n");
}

float ordenaquick(int* vetor, int inicio, int fim) {
    FILE *arquivo;
    int i, j, pivo, temp, n;
    clock_t tempo_i, tempo_f;
    float total;

    //ordenacao
    tempo_i = clock();
    quickSort(vetor, inicio, fim);
    tempo_f = clock();
    total = ((float) (tempo_f - tempo_i) / CLOCKS_PER_SEC);
    
     if ((arquivo = fopen("quick.txt", "w")) == NULL) {
        printf("Nao e possivel criar o arquivo\n");
    } else {
        for (i = 0; i < (fim+1); i++) {
            fprintf(arquivo, "%d\t", vetor[i]);
        }
    }
    fclose(arquivo);
    

    return total;
}

void quickSort(int* vetor, int inicio, int fim){
    int i, j, pivo, temp;
    if (inicio < fim) {
        pivo = inicio;
        i = inicio;
        j = fim;

        while (i < j) {
            while (vetor[i] <= vetor[pivo] && i < fim)
                i++;
            while (vetor[j] > vetor[pivo])
                j--;
            if (i < j) {
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
        temp = vetor[pivo];
        vetor[pivo] = vetor[j];
        vetor[j] = temp;
        ordenaquick(vetor, inicio, j - 1);
        ordenaquick(vetor, j + 1, fim);
    }
}

int* abrirArquivo() {
    FILE *arquivo;
    int *vetor, n, i = 0;
    if ((arquivo = fopen("entrada.txt", "r")) == NULL) {
        printf("Impossivel realizar a leitura do arquivo. Tente novamente\n");
    }
    //descobrir o número de valores
    //faz a leitura do primeiro elemento do meu arquivo que por padrão é a quantidade de elementos do meu vetor
    //lendo os valores de entrada
    fscanf(arquivo, "%d", &n);

    vetor = malloc(sizeof (int)* n);

    while (!feof(arquivo)) {
        fscanf(arquivo, "%d", &vetor[i]);
        i++;
    }
    fclose(arquivo);

    return vetor;
}

