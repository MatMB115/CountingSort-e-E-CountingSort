// APENAS UM RASCUNHO
// APENAS UM RASCUNHO
// APENAS UM RASCUNHO
// APENAS UM RASCUNHO



#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "comparador.h"



/* APRIMORAR */
// Estrutura
struct conjuntoElementos {
    int* valor;
    int tamanho;
    int erro;

    // Métricas
    int comparacoesChaves[10];
    int copiasRegistros[10];
    int tempoGasto[10];

};



/* APRIMORAR */
//Essa função aloca memória para uma variável do tipo conjuntoElementos
conjuntoElementos* alocaConjunto(){

    //Usar calloc para limpar a memória após alocar
    conjuntoElementos *vetor = (conjuntoElementos*) malloc(sizeof(conjuntoElementos));

    // Trata possíveis erros
    // Se vetor != NULL, "tamanho" e "erro"
    // Recebem os valores iniciais
    if (vetor == NULL){
        vetor->erro = 3;

    } else {
        vetor->tamanho = 0;
        vetor->erro = 0;

    }

    return vetor;

}



// Essa função cria dois arquivos e armazena 1 milhão de valores aleatórios em ambos
void geraValores(){

    // Variável auxiliar
    int aux;

    // Declara os ponteiros
    FILE *file;
    FILE *fileDois;

    // Abre os arquivos que guardarão
    // os valores inteiros aleatórios
    file = fopen("dadosCounting.txt", "w");
    fileDois = fopen("dadosAprimoradoCounting.txt", "w");

    // Verificar se os arquivos foram abertos corretamente - pensar em o que fazer caso ocorra
    if(file == NULL || file == NULL){
        return;
    }
    else{
        // Usa o tempo atual como semente
        // para gerar números aleatórios
        srand(time(NULL));

        // Loop para gerar valores aleatórios
        // e armazenar nos arquivos
        for (int i = 0; i < 1000000; i++){

            // Atribui um valor aleatório a aux
            aux = rand() % 30000;

            // Armazena o valor nos dois arquivos
            fprintf(file,"%d\n", aux);
            fprintf(fileDois,"%d\n", aux);

        }

        // Fecha os arquivos
        fclose(file);
        fclose(fileDois);
        return;
    }
    
}



//Essa função retorna o vetor contido na estrutura conjuntoElementos;
int *getVetor(conjuntoElementos *vetor){
    return vetor->valor;

}



//Essa função retorna o tamanhoanho vetor contido na estrutura conjuntoElementos;
int getTamanho(conjuntoElementos *vetor){
    return vetor->tamanho;

}



//Essa função retorna o valor da variável erro contido na estrutura conjuntoElementos;
int getErro(conjuntoElementos *vetor){
    return vetor->erro;

}



//Essa função trata os erros relativos à função conjuntoElementos
//erro 1: abertura do arquivo
//erro 2: leitura do arquivo
//erro 3: alocação de memória
void trataErro(int erro){

    // Estrutura condicional para tratar os erros
    switch(erro){
        case 1:
            printf("\nErro na abertura do arquivo");
            break;

        case 2:
            printf("\nErro na leitura do arquivo");
            break;

        case 3:
            printf("\nErro na alocação de memória");
            break;

        default:
            printf("\nErro não especificado");
            break;

    }
	
}



/* ORDENADOR */
/* ORDENADOR */
/* ORDENADOR */
conjuntoElementos* ordenador(char nomeArquivo[], int tamanho, int escolha, int y){

    // Define o arquivo (descrever melhor)
    FILE *arquivo;

    // Variável auxiliar
    int aux;

    // Alocação da estrutura
    conjuntoElementos *vetor = alocaConjunto();

	// Se possível, aprimorar este código para não precisar do
    // array "vetorAuxiliar"
    int vetorAuxiliar[tamanho];
	
    // Loop para tirar a media de 10 ordenações usando x elementos
    for (int i = 0; i < 10; i++){

        // Abre o arquivo com os dados
        arquivo = fopen(nomeArquivo, "r");

        // Define o tamanho do vetor
        vetor->tamanho = tamanho;

        // Aloca um vetor de inteiros com o tamanho "tamanho"
        //calloc
        vetor->valor = (int*) malloc(tamanho * sizeof(int));
		
        // Quando y for igual a 8, 9, 10 ou 11
        // O algoritmo precisa armazenar os dados do arquivo
        // começando pela posição "tamanho" e terminando em 0
        // ou seja, é necessário ler de trás para frente
        if ((y != 8) && (y != 9) && (y != 10) && (y != 11)){

			// Armazenando os valores em um vetor temporário
            for (int j = 0; j < tamanho; j++){
                fscanf(arquivo, "%d", &vetorAuxiliar[j]);
				vetor->valor[j] = vetorAuxiliar[j];
            }

        } else {

            // Armazenando os valores em um vetor temporário
            for (int j = 0; j < tamanho; j++){
                fscanf(arquivo, "%d", &vetorAuxiliar[j]);
            }

            // Transferindo os valores do vetor temporário para o
            // vetor dinamicamente alocado
            aux = tamanho-1;
            for (int j = 0; j < tamanho; j++){
                vetor->valor[j] = vetorAuxiliar[aux];
                aux--;

            }

        }

        // Fecha o arquivo
        fclose(arquivo);

        // Escolhe o algoritmo de ordenação
        // 0 = countingSort
        // 1 = eCountingSort
        if (escolha == 0){

            /* Algoritmo de ordenação Counting Sort */
			int a = sizeof(vetorAuxiliar) / sizeof(vetorAuxiliar[0]);
			countingSort(vetor->valor, a, tamanho);
			

        } else {
            /* Algoritmo de ordenação E-Counting Sort */
			int a = sizeof(vetorAuxiliar) / sizeof(vetorAuxiliar[0]);
			countingSort(vetor->valor, a, tamanho);

        }

        // Comparação necessária pois quando o tamanho do
        // vetor for 1 milhão de itens e a quantidade de
        // comparações for igual a 10, os elementos serão
        // alocados no arquivo para que os outros testes
        // sejam realizados sobre o algoritmo ordenador
        if ((tamanho != 1000000) && (i != 10)){

            // Desaloca o vetor de inteiros
            free(vetor->valor);

        }

    }

    // Retorna o vetor
    return vetor;

}



//Essa função abre um arquivo com valores gerados aleatoriamente e substitui
//os valores, colocando-os de modo ordenado (de maneira crescente)
void escritor(int *vetor, char nomeArquivo[], int tamanho){

    // Variável auxiliar
    //int aux;

    // Declara o ponteiro
    FILE *file;

    // Abre os arquivos que guardarão
    // os valores inteiros ordenados
    
    file = fopen(nomeArquivo, "w");

    // Loop para armazenar os valores ordenados
    // no arquivo 'nomeArquivo'
    for (int i = 0; i < tamanho; i++){

        // Armazena o valor no arquivo
        fprintf(file,"%d\n", vetor[i]);

    }

    // Fecha o arquivo
    fclose(file);

}



//Essa função imprime os dados de um vetor (um número por linha)
void imprimeVet(int *vetor, int tamanho){

    // Loop para imprimir os dados do vetor
    // Loop para imprimir os dados do vetor
    for (int i = 0; i < tamanho; i++) {
        printf("Pos[%d] = %d\n", i + 1, vetor[i]);

    }
	
}



// //Essa função ordena os valores do vetor usando o algoritmo Counting Sort
void countingSort(int *vetor, int size, int tamanho) {
printf("\nCountingSort");
  int output[tamanho];

  // Find the largest element of the array
  int max = vetor[0];
  for (int i = 1; i < size; i++) {
    if (vetor[i] > max)
      max = vetor[i];
  }

  // The size of count must be at least (max+1) but
  // we cannot declare it as int count(max+1) in C as
  // it does not support dynamic memory allocation.
  // So, its size is provided statically.
  int count[30000];

  // Initialize count array with all zeros.
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Store the count of each element
  for (int i = 0; i < size; i++) {
    count[vetor[i]]++;
  }

  // Store the cummulative count of each array
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (int i = size - 1; i >= 0; i--) {
    output[count[vetor[i]] - 1] = vetor[i];
    count[vetor[i]]--;
  }

  // Copy the sorted elements into original array
  for (int i = 0; i < size; i++) {
    vetor[i] = output[i];
	  
  }
}