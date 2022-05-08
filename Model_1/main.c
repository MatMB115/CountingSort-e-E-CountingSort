#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "countingSort.h"


int main(){
	int *arrRand, *arrOrd, *output, *arrReverse;
	
	//tam é o tamnho do vetor
	//max é o valor mais alto do vetor
	int max, tam, i;
    clock_t inicio, fim;
    
	char nameFile[30];
    //Estruturas que guardam as métricas de cada semente para o count e e-count
    data CountRand, CountAscend, CountDescend;
    data ECountRand, ECountAscend, ECountDescend;

	strcpy(nameFile, "data/data10K.txt");
	tam = 10000;
	arrOrd = (int*) calloc(tam, sizeof(int));
    output = (int*) calloc(tam, sizeof(int));
    //Zerar os valores dos campos da estrutura
    cleanRegister(&CountRand, &CountAscend, &CountDescend);
    cleanRegister(&ECountRand, &ECountAscend, &ECountDescend);
    
	for (i = 0; i < 10; i++){
		//Criar um arquivo com 10000 números
        createFile(nameFile, tam);
    
		//Ler os números para o vetor de elementos aleatórios
		arrRand = readFile(nameFile, tam);
        
		//Encontra o max, chama o counting sort para o vetor desordenado
		max = findMax(arrRand, tam);
        //Contagem, ao final da execução o tempo é incrementado no registro
        inicio = clock();
		countingSort(arrRand, arrOrd, max, tam, &CountRand);
        fim = clock();
        CountRand.time += (double)(fim - inicio) / CLOCKS_PER_SEC;
        //Reaproveita o vetor ordenado no countingSort anterior
        inicio = clock();
		countingSort(arrOrd, output, max, tam, &CountAscend);
        fim = clock();
        CountAscend.time += (double)(fim - inicio) / CLOCKS_PER_SEC;
        //Insere elementos de forma decrescente no arquivo e lê novamente para o vetor
        reverseArray(arrOrd, nameFile, tam);
        arrReverse = readFile(nameFile, tam);
        //Contagem
        inicio = clock();
        countingSort(arrReverse, arrOrd, max, tam, &CountDescend);
        fim = clock();
        CountDescend.time += (double)(fim - inicio) / CLOCKS_PER_SEC;
        showStatus(tam, i, 0);
        
        //ORDENAR COM E-COUNTING
        //Reaproveitar o vetor aleatório
        inicio = clock();
        eCountingSort(arrRand, arrOrd, max, tam, &ECountRand);
        fim = clock();
        ECountRand.time += (double)(fim - inicio) / CLOCKS_PER_SEC;
        //Reaproveita o vetor ordenado no eCountingSort anterior
        inicio = clock();
		eCountingSort(arrOrd, output, max, tam, &ECountAscend);
        fim = clock();
        ECountAscend.time += (double)(fim - inicio) / CLOCKS_PER_SEC;
        //Reaproveitar o vetor decrescente
        inicio = clock();
        eCountingSort(arrReverse, arrOrd, max, tam, &ECountDescend);
        fim = clock();
        ECountAscend.time += (double)(fim - inicio) / CLOCKS_PER_SEC;
        showStatus(tam, i, 1);
    }
    registerData(nameFile, 0, tam, &CountRand, &CountAscend, &CountDescend);
    registerData(nameFile, 1, tam, &ECountRand, &ECountAscend, &ECountDescend);
    freeArray(arrOrd, arrRand, arrReverse, output);
    
    //Execução tam = 100000
    strcpy(nameFile, "data/data100K.txt");
	tam = 100000;
	arrOrd = (int*) calloc(tam, sizeof(int));
    output = (int*) calloc(tam, sizeof(int));
    //Zerar os valores dos campos da estrutura
    cleanRegister(&CountRand, &CountAscend, &CountDescend);
    cleanRegister(&ECountRand, &ECountAscend, &ECountDescend);

	for (i = 0; i < 10; i++){
        //Criar um arquivo com 10000 números
        createFile(nameFile, tam);
    
		//Ler os números para o vetor de elementos aleatórios
		arrRand = readFile(nameFile, tam);
        
		//Encontra o max, chama o counting sort para o vetor desordenado
		max = findMax(arrRand, tam);
        //Contagem, ao final da execução o tempo é incrementado no registro
        inicio = clock();
		countingSort(arrRand, arrOrd, max, tam, &CountRand);
        fim = clock();
        CountRand.time += (double)(fim - inicio) / CLOCKS_PER_SEC;
        //Reaproveita o vetor ordenado no countingSort anterior
        inicio = clock();
		countingSort(arrOrd, output, max, tam, &CountAscend);
        fim = clock();
        CountAscend.time += (double)(fim - inicio) / CLOCKS_PER_SEC;
        //Insere elementos de forma decrescente no arquivo e lê novamente para o vetor
        reverseArray(arrOrd, nameFile, tam);
        arrReverse = readFile(nameFile, tam);
        //Contagem
        inicio = clock();
        countingSort(arrReverse, arrOrd, max, tam, &CountDescend);
        fim = clock();
        CountDescend.time += (double)(fim - inicio) / CLOCKS_PER_SEC;
        showStatus(tam, i, 0);
        
        //ORDENAR COM E-COUNTING
        //Reaproveitar o vetor aleatório
        inicio = clock();
        eCountingSort(arrRand, arrOrd, max, tam, &ECountRand);
        fim = clock();
        ECountRand.time += (double)(fim - inicio) / CLOCKS_PER_SEC;
        //Reaproveita o vetor ordenado no eCountingSort anterior
        inicio = clock();
		eCountingSort(arrOrd, output, max, tam, &ECountAscend);
        fim = clock();
        ECountAscend.time += (double)(fim - inicio) / CLOCKS_PER_SEC;
        //Reaproveitar o vetor decrescente
        inicio = clock();
        eCountingSort(arrReverse, arrOrd, max, tam, &ECountDescend);
        fim = clock();
        ECountAscend.time += (double)(fim - inicio) / CLOCKS_PER_SEC;
        showStatus(tam, i, 1);
    }
	registerData(nameFile, 0, tam, &CountRand, &CountAscend, &CountDescend);
    registerData(nameFile, 1, tam, &ECountRand, &ECountAscend, &ECountDescend);
    freeArray(arrOrd, arrRand, arrReverse, output);

    //Execução tamanho 500000
    strcpy(nameFile, "data/data500K.txt");
	tam = 500000;
	arrOrd = (int*) calloc(tam, sizeof(int));
    output = (int*) calloc(tam, sizeof(int));
    //Zerar os valores dos campos da estrutura
    cleanRegister(&CountRand, &CountAscend, &CountDescend);
    cleanRegister(&ECountRand, &ECountAscend, &ECountDescend);
    
	for (i = 0; i < 10; i++){
        //Criar um arquivo com 10000 números
        createFile(nameFile, tam);
    
		//Ler os números para o vetor de elementos aleatórios
		arrRand = readFile(nameFile, tam);
        
		//Encontra o max, chama o counting sort para o vetor desordenado
		max = findMax(arrRand, tam);
        //Contagem, ao final da execução o tempo é incrementado no registro
        inicio = clock();
		countingSort(arrRand, arrOrd, max, tam, &CountRand);
        fim = clock();
        CountRand.time += (double)(fim - inicio) / CLOCKS_PER_SEC;
        //Reaproveita o vetor ordenado no countingSort anterior
        inicio = clock();
		countingSort(arrOrd, output, max, tam, &CountAscend);
        fim = clock();
        CountAscend.time += (double)(fim - inicio) / CLOCKS_PER_SEC;
        //Insere elementos de forma decrescente no arquivo e lê novamente para o vetor
        reverseArray(arrOrd, nameFile, tam);
        arrReverse = readFile(nameFile, tam);
        //Contagem
        inicio = clock();
        countingSort(arrReverse, arrOrd, max, tam, &CountDescend);
        fim = clock();
        CountDescend.time += (double)(fim - inicio) / CLOCKS_PER_SEC;
        showStatus(tam, i, 0);
        
        //ORDENAR COM E-COUNTING
        //Reaproveitar o vetor aleatório
        inicio = clock();
        eCountingSort(arrRand, arrOrd, max, tam, &ECountRand);
        fim = clock();
        ECountRand.time += (double)(fim - inicio) / CLOCKS_PER_SEC;
        //Reaproveita o vetor ordenado no eCountingSort anterior
        inicio = clock();
		eCountingSort(arrOrd, output, max, tam, &ECountAscend);
        fim = clock();
        ECountAscend.time += (double)(fim - inicio) / CLOCKS_PER_SEC;
        //Reaproveitar o vetor decrescente
        inicio = clock();
        eCountingSort(arrReverse, arrOrd, max, tam, &ECountDescend);
        fim = clock();
        ECountAscend.time += (double)(fim - inicio) / CLOCKS_PER_SEC;
        showStatus(tam, i, 1);
    }
    registerData(nameFile, 0, tam, &CountRand, &CountAscend, &CountDescend);
    registerData(nameFile, 1, tam, &ECountRand, &ECountAscend, &ECountDescend);
    freeArray(arrOrd, arrRand, arrReverse, output);
	
    //Execução tamanho 1000000
    strcpy(nameFile, "data/data1KK.txt");
	tam = 1000000;
	arrOrd = (int*) calloc(tam, sizeof(int));
    output = (int*) calloc(tam, sizeof(int));
    //Zerar os valores dos campos da estrutura
    cleanRegister(&CountRand, &CountAscend, &CountDescend);
    cleanRegister(&ECountRand, &ECountAscend, &ECountDescend);
	for (i = 0; i < 10; i++){
		//Criar um arquivo com 10000 números
        createFile(nameFile, tam);
    
		//Ler os números para o vetor de elementos aleatórios
		arrRand = readFile(nameFile, tam);
        
		//Encontra o max, chama o counting sort para o vetor desordenado
		max = findMax(arrRand, tam);
        //Contagem, ao final da execução o tempo é incrementado no registro
        inicio = clock();
		countingSort(arrRand, arrOrd, max, tam, &CountRand);
        fim = clock();
        CountRand.time += (double)(fim - inicio) / CLOCKS_PER_SEC;
        //Reaproveita o vetor ordenado no countingSort anterior
        inicio = clock();
		countingSort(arrOrd, output, max, tam, &CountAscend);
        fim = clock();
        CountAscend.time += (double)(fim - inicio) / CLOCKS_PER_SEC;
        //Insere elementos de forma decrescente no arquivo e lê novamente para o vetor
        reverseArray(arrOrd, nameFile, tam);
        arrReverse = readFile(nameFile, tam);
        //Contagem
        inicio = clock();
        countingSort(arrReverse, arrOrd, max, tam, &CountDescend);
        fim = clock();
        CountDescend.time += (double)(fim - inicio) / CLOCKS_PER_SEC;
        showStatus(tam, i, 0);
        
        //ORDENAR COM E-COUNTING
        //Reaproveitar o vetor aleatório
        inicio = clock();
        eCountingSort(arrRand, arrOrd, max, tam, &ECountRand);
        fim = clock();
        ECountRand.time += (double)(fim - inicio) / CLOCKS_PER_SEC;
        //Reaproveita o vetor ordenado no eCountingSort anterior
        inicio = clock();
		eCountingSort(arrOrd, output, max, tam, &ECountAscend);
        fim = clock();
        ECountAscend.time += (double)(fim - inicio) / CLOCKS_PER_SEC;
        //Reaproveitar o vetor decrescente
        inicio = clock();
        eCountingSort(arrReverse, arrOrd, max, tam, &ECountDescend);
        fim = clock();
        ECountAscend.time += (double)(fim - inicio) / CLOCKS_PER_SEC;
        showStatus(tam, i, 1);
	}
    registerData(nameFile, 0, tam, &CountRand, &CountAscend, &CountDescend);
    registerData(nameFile, 1, tam, &ECountRand, &ECountAscend, &ECountDescend);
    freeArray(arrOrd, arrRand, arrReverse, output);
	return 0;
}