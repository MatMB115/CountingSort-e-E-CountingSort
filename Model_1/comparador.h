// APENAS UM RASCUNHO
// APENAS UM RASCUNHO
// APENAS UM RASCUNHO
// APENAS UM RASCUNHO

#ifndef COMPARADOR_H
#define COMPARADOR_H

//declara o tipo de dados conjuntoElementos
typedef struct conjuntoElementos conjuntoElementos;

//Essa função aloca memória para uma variável do tipo conjuntoElementos
conjuntoElementos* alocaConjunto();

// Essa função cria dois arquivos e armazena 1 milhão de valores aleatórios em ambos
void geraValores();

//Essa função retorna o vetor contido na estrutura conjuntoElementos;
int *getVetor(conjuntoElementos *vetor);

//Essa função retorna o tamanho vetor contido na estrutura conjuntoElementos;
int getTamanho(conjuntoElementos *vetor);

//Essa função retorna o valor da variável error contido na estrutura conjuntoElementos;
int getErro(conjuntoElementos *vetor);

//Essa função trata os erros relativos à função conjuntoElementos
//erro 1: abertura do arquivo
//erro 2: leitura do arquivo
//erro 3: alocação de memória
void trataErro(int erro);

//Essa função lê um arquivo com números inteiros (um número por linha) e preenche um vetor
//A função retorna o tipo conjuntoElementos formado por um ponteiro para inteiros, um inteiro que
//guarda o tamanho do vetor, um inteiro que codifica erros e métricas
conjuntoElementos* ordenador(char nomeArquivo[], int tamanho, int escolha, int y);

//Essa função abre um arquivo com valores gerados aleatoriamente e substitui
//os valores, colocando-os de modo ordenado (de maneira crescente)
void escritor(int *vetor, char nomeArquivo[], int tamanho);

//Essa função imprime os dados de um vetor (um número por linha)
void imprimeVet(int *vetor, int tamanho);

//Essa função ordena os valores do vetor usando o algoritmo Counting Sort
void countingSort(int *vetor, int size, int tamanho);

#endif //COMPARADOR_H