// Pesquisa e Classificação de Dados - Atividade Semi-Presencial 02 - 11 de abril de 2018
// Andrelise Nunes Lemos Pinheiro (andrelisenunes@hotmail.com) , Marina Silva da Silva (marina_silva98@hotmail.com).
#include <stdio.h>
#include <string.h>
#include "funcao.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int tamanho, *vetor, i = 0, opc, x=0;
    float m = 0, s = 0, q = 0;
    FILE *arquivo;

    printf("Digite a quantidade de numeros inteiros:");
    scanf("%d", &tamanho); //tamanho do vetor
    
    vetor = gerarNumeros(tamanho,x);
    x++;
    do {
        printf("\n==MENU==\n");
        printf("0)Sair\n1)Incrementos decrescentes (Shell Sort)\n2)Intercalação (Merge Sort)\n3)Ordenação rápida (Quick Sort)\n4)Mostrar valores de entrada\n5)Mostrar valores ordenados\n6)Tempo de execucao\n7)Gerar outra sequencia de numeros\n>>OPCAO:");
        scanf("%d", &opc);
        switch (opc) {
            case 1:
            { //shell
                s = ordenashell();
                break;
            }
            case 2:
            { //merge
                vetor = abrirArquivo();
                m = ordenaMerge(vetor, tamanho);
                break;
            }
            case 3:
            { //quick
                vetor = abrirArquivo();
                q = ordenaquick(vetor, 0, (tamanho));
                printf("Vetor ordenado com sucesso!");
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
                printf("-->Tempo de execucao<--\n[1] SHELL=%f\n[2]MERGE=%f\n[3]QUICK=%f\n", s, m, q);
                break;
            }
            case 7:
            {
                vetor = gerarNumeros(tamanho, x);
                break;
            }
        }
    } while (opc != 0);
    return 0;
}
