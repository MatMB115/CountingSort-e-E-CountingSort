#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "countingSort.h"

int main(){
	int *arrRandCS, *arrOrdCS, *outputCS, *arrReverseCS;
    int *arrRandECS, *arrOrdECS, *outputECS, *arrReverseECS;
	
	//tam é o tamanho do vetor
	//max é o valor mais alto do vetor
	int max, tam, i, j;
    clock_t inicio, fim;
    
	char nameFile[30];
	
    //Estruturas que guardam as métricas de cada semente para o count e e-count
    data CountRand, CountAscend, CountDescend;
    data ECountRand, ECountAscend, ECountDescend;

	//Loop para testar todos os cenários
	for (j = 0; j < 4; j++){

		if (j == 0) {
			//Execução tam = 10000
			strcpy(nameFile, "data/data10K.txt");
			tam = 10000;
			
		} else if (j == 1){
			//Execução tam = 100000
			strcpy(nameFile, "data/data100K.txt");
			tam = 100000;
			
		} else if (j == 2) {
			//Execução tam = 500000
			strcpy(nameFile, "data/data500K.txt");
			tam = 500000;
			
		} else {
			//Execução tam = 1000000
			strcpy(nameFile, "data/data1KK.txt");
			tam = 1000000;
			
		}

		// Execução dos algoritmos de ordenação
		arrOrdCS = (int*) calloc(tam, sizeof(int));
	    outputCS = (int*) calloc(tam, sizeof(int));
        arrOrdECS = (int*) calloc(tam, sizeof(int));
	    outputECS = (int*) calloc(tam, sizeof(int));
		
	    //Zerar os valores dos campos da estrutura
	    cleanRegister(&CountRand, &CountAscend, &CountDescend);
        cleanRegister(&ECountRand, &ECountAscend, &ECountDescend);
	    
		for (i = 0; i < 10; i++){
			//Criar um arquivo com "tam" números
	        createFile(nameFile, tam);
	    
			//Ler os números para o vetor de elementos aleatórios
			arrRandCS = readFile(nameFile, tam);
	        arrRandECS = readFile(nameFile, tam);
			
			//Encontra o max, chama o counting sort para o vetor desordenado
			max = findMax(arrRandCS, tam);
			
	        //Contagem, ao final da execução o tempo é incrementado no registro
	        inicio = clock();
			countingSort(arrRandCS, arrOrdCS, max, tam, &CountRand);
	        fim = clock();
	        CountRand.time += (double)(fim - inicio) / CLOCKS_PER_SEC;
            
	        //Reaproveita o vetor ordenado no countingSort anterior
	        inicio = clock();
			countingSort(arrOrdCS, outputCS, max, tam, &CountAscend);
	        fim = clock();
	        CountAscend.time += (double)(fim - inicio) / CLOCKS_PER_SEC;			

	        //Insere elementos de forma decrescente no arquivo e lê novamente para o vetor
	        reverseArray(arrOrdCS, nameFile, tam);
	        arrReverseCS = readFile(nameFile, tam);
			
	        //Contagem
	        inicio = clock();
	        countingSort(arrReverseCS, arrOrdCS, max, tam, &CountDescend);
	        fim = clock();
	        CountDescend.time += (double)(fim - inicio) / CLOCKS_PER_SEC;
			showStatus(tam, i, 0);

            //Couting Eficiente
            //Contagem, ao final da execução o tempo é incrementado no registro
	        inicio = clock();
			eCountingSort(arrRandECS, arrOrdECS, max, tam, &ECountRand);
	        fim = clock();
	        ECountRand.time += (double)(fim - inicio) / CLOCKS_PER_SEC;

	        //Reaproveita o vetor ordenado no eCountingSort anterior
	        inicio = clock();
			eCountingSort(arrOrdECS, outputECS, max, tam, &ECountAscend);
	        fim = clock();
	        ECountAscend.time += (double)(fim - inicio) / CLOCKS_PER_SEC;			

	        //Insere elementos de forma decrescente no arquivo e lê novamente para o vetor
	        reverseArray(arrOrdECS, nameFile, tam);
	        arrReverseECS = readFile(nameFile, tam);
			
	        //Contagem
	        inicio = clock();
	        eCountingSort(arrReverseECS, arrOrdECS, max, tam, &ECountDescend);
	        fim = clock();
	        ECountDescend.time += (double)(fim - inicio) / CLOCKS_PER_SEC;
			showStatus(tam, i, 1);
	    }
		
	    registerData(nameFile, 0, tam, &CountRand, &CountAscend, &CountDescend);
        registerData(nameFile, 1, tam, &ECountRand, &ECountAscend, &ECountDescend);
        freeArray(arrOrdCS, arrRandCS, arrReverseCS, outputCS);
        freeArray(arrOrdECS, arrRandECS, arrReverseECS, outputECS);
	}

	return 0;
}