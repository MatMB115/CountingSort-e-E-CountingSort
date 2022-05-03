//EM DESENVOLVIMENTO!!!

#include <stdio.h>
#include <stdlib.h>

void countingSort(int arrA[], int *arrB, int tam){

    // Encontrar o maior elemento do vetor
    int max = arrA[0];
    for (int i = 1; i < tam; i++) {
        if (arrA[i] > max)
        max = arrA[i];
    }

    //Alocar um vetor para armazenar a frequência
    int* count = (int*) calloc(tam, sizeof(int));

    // Inicializar o vetor com 0 ou calloc ou memset 0
    /*for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }*/

    // Guardar a frequências dos elementos no
    for (int i = 0; i < tam; i++) {
        count[arrA[i]]++;
    }

    // Guardar o acumulativo das valores menores que um elemento i do vetor
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Percorrer o vetor original com início no último elemento, subtituindo os índices nos elementos do vetor count e decrescendo a cada atribuição
    for (int i = tam - 1; i >= 0; i--) {
        arrB[count[arrA[i]] - 1] = arrA[i];
        count[arrA[i]]--;
    }
}

// Function to print an array
void printArray(int* array, int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

// Driver code
int main() {
  int arrA[] = {4,8,7,9,8,5,2,1,2,8,7,4,1,2,5,4,8,9,3,1,4,7,2,1,4,2,3,23,56,98,784,54,21,654,77,124,785,354,147};
  int n = sizeof(arrA) / sizeof(arrA[0]);
  int *arrB = (int*) malloc(n * sizeof(int));
  countingSort(arrA, arrB, n);
  printArray(arrB, n);
}
