// APENAS UM RASCUNHO FEITO PELO MATHEUS LUZ
// APENAS UM RASCUNHO FEITO PELO MATHEUS LUZ
// APENAS UM RASCUNHO FEITO PELO MATHEUS LUZ
// APENAS UM RASCUNHO FEITO PELO MATHEUS LUZ

// Bibliotecas
#include "comparador.h"
#include <stdio.h>
#include <string.h>

// Função principal
int main() {

    // Declara o nomeArquivo
    char nomeArquivo[28];

    // Declarando um ponteiro
    conjuntoElementos *vetor;

    // Variável para auxiliar na ordenação
    int tamanho;

    // Alocando
    vetor = alocaConjunto();

    // Gera um arquivo "dadosCounting.txt"
    // e um arquivo "dadosAprimoradoCounting.txt"
    // e armazena 1 milhão de valores inteiros
    // gerados aleatoriamente em ambos os arquivos
    geraValores();

    // Loop para escolher o algoritmo ordenador:
    // 0 = CountingSort
    // 1 = eCountingSort
    for (int escolha = 0; escolha < 2; escolha++) {

        // Define o nome do arquivo que será
        // usado para buscar e armazenar os valores
        if (escolha == 0) {
            strcpy(nomeArquivo, "dadosCounting.txt");
				printf("\n\nORDENANDO COM COUNTING SORT\n\n");

        } else {
            strcpy(nomeArquivo, "dadosAprimoradoCounting.txt");
				printf("\n\nORDENANDO COM COUNTING SORT EFICIENTE\n\n");

        }

        // Loop para ordenar diferentes tamanhos de entradas
        // Y = 0, 1, 2 ou 3 = Algoritmo executado no vetor desordenado
        // Y = 4, 5, 6 ou 7 = Algoritmo executado no vetor ordenado
        // Y = 8, 9, 10 ou 11 = Algoritmo executado no vetor em ordem decrescente
        for (int y = 0; y < 12; y++) {

            // Dependendo do contador do loop, é ordenada
            // um tamanho diferente de entrada
            if ((y == 0) || (y == 4) || (y == 8)) {

                // Quantidade de elementos: 10.000
                tamanho = 10000;

            } else if ((y == 1) || (y == 5) || (y == 9)) {

                // Quantidade de elementos: 100.000
                tamanho = tamanho * 10;

            } else if ((y == 2) || (y == 6) || (y == 10)) {

                // Quantidade de elementos: 500.000
                tamanho = tamanho * 5;

                // y = 3 || y = 7 || y = 11
            } else {

                // Quantidade de elementos: 1.000.000
                tamanho = tamanho * 2;

            }

            switch(y){
                case 0:
                    printf("\nVETOR DESORDENADO 10");
                    break;
                case 1:
                    printf("\nVETOR DESORDENADO 100");
                    break;
                case 2:
                    printf("\nVETOR DESORDENADO 500");
                    break;
                case 3:
                    printf("\nVETOR DESORDENADO MILHÃO");
                    break;
                case 4:
                    printf("\nVETOR ORDENADO 10");
                    break;
                case 5:
                    printf("\nVETOR ORDENADO 100");
                    break;
                case 6:
                    printf("\nVETOR ORDENADO 500");
                    break;
                case 7:
                    printf("\nVETOR ORDENADO MILHÃO");
                    break;
                case 8:
                    printf("\nVETOR DECRESCENTE 10");
                    break;
                case 9:
                    printf("\nVETOR DECRESCENTE 100");
                    break;
                case 10:
                    printf("\nVETOR DECRESCENTE 500");
                    break;
                case 11:
                    printf("\nVETOR DECRESCENTE MILHÃO");
                    break;

                default:
                    break;

            }

            // Ordena o vetor de entrada
            vetor = ordenador(nomeArquivo, tamanho, escolha, y);

            // Pega a média que retorna do vetor e gera o relatório de desempenho
            //printf("\nMedia %d", y+1);


            // Dependendo do valor de y, altera ou não o arquivo
            // y == 3 : os dados do arquivo precisam ser substituídos pela versão
            // ordenada
            if (y == 3) {

                // Alterar a ordem dos valores no arquivo nomeArquivo,
                // que deve ser aberto e ter seus 1 milhão de valores
                // substituídos
                escritor(getVetor(vetor), nomeArquivo, tamanho);

            }

        }

    }

    // IMPRIME O VETOR
    //printf("\n\n\n");
    //imprimeVet(getVetor(vetor), tamanho);
	printf("\n\n\nTamanho %d", tamanho);

    return 0;

}