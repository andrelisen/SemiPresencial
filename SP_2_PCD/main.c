// Pesquisa e Classificação de Dados - Atividade Semi-Presencial 02 - 11 de abril de 2018
// Andrelise Nunes Lemos Pinheiro (andrelisenunes@hotmail.com) , Marina Silva da Silva (marina_silva98@hotmail.com).
#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>
#include <time.h>

int main() {
    int x, *vetor, i = 0, opc;
    float b = 0, s = 0, ins = 0;
    FILE *arquivo;
    printf("Digite a quantidade de numeros inteiros:");
    scanf("%d", &x);
    //cria vetor com valores aleatórios
    vetor = malloc(sizeof (int)* x);
    srand(time(NULL));
    //abrindo arquivo que guardará os números gerados
    if ((arquivo = fopen("entrada.txt", "w")) == NULL) {
        printf("Nao e possivel criar um arquivo de texto. Tente novamente\n");
    }
    fprintf(arquivo, "%d\n", x); //primeiro elemento é o tamanho do meu vetor de números para a ordenação
    for (i = 0; i < x; i++) {
        vetor[i] = rand() % (x * 2);
        //printf("%d\n", vetor[i]);
        fprintf(arquivo, "%d\t", vetor[i]);
    }
    fclose(arquivo);
    printf("-->NUMEROS GERADOS E SALVOS COM SUCESSO<--\n");
    //menu
    do {
        printf("\n==MENU==\n");
        printf("0)Sair\n1)Incrementos decrescentes (Shell Sort)\n2) Intercalação (Merge Sort)\n3) Ordenação rápida (Quick Sort)4)Mostrar valores de entrada\n5)Mostrar valores ordenados\n6)Tempo de execucao\n>>OPCAO:");
        scanf("%d", &opc);
        switch (opc) {
            case 1:
            { //shell
                b = ordenashell();
                break;
            }
            case 2:
            { //merge
                s = ordenamerge();
                break;
            }
            case 3:
            { //quick
                ins = ordenaquick();
                break;
            }
            case 4:
            { //MOSTRAR VALORES DE ENTRADA 	
                mostraentrada();
                break;
            }
            case 5:
            { //MOSTRAR VALORES ORDENADOS
                mostraordenado();
                break;
            }
            case 6:
            { //TEMPO DE EXECUÇÃO DE CADA PROCESSO
                printf("-->Tempo de execucao<--\n[1] SHELL=%f\n[2]MERGE=%f\n[3]QUICK=%f\n", b, s, ins);
                break;
            }
        }
    } while (opc != 0);
    return 0;
}
