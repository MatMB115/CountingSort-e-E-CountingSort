//Funcional

#include <stdio.h>
#include <stdlib.h>

void eCountingSort(int *arrA, int *arrB, int tam){
    int i, j = 0;
    // Encontrar o maior elemento do vetor
    int max = arrA[0];
    for (int i = 1; i < tam; i++) {
        if (arrA[i] > max)
        max = arrA[i];
    }

    // Alocar um vetor para armazenar a frequência com tamanho do maior elemento encontrado
    int count[max];

    // Inicializar os elementos do vetor com 0
    for (i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    // Guardar a frequências dos elementos no auxiliar Count
    for (i = 0; i < tam; i++) {
        count[arrA[i]]++;
    }

    //E-Counting particularidade
    for(i = 0; i <= max; i++){
        while(count[i] > 0){
            arrB[j] = i;
            j++;
            count[i]--;
        }
    }
}


void imprimeArr(int* array, int size){
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}


int main() {
  int arrA[] = {4,8,7,9,8,5,2,1,2,8,7,4,1,2,5,4,8,9,3,1,4,7,2,1,4,2,3,23,56,98,784,54,21,654,77,124,785,354,147};
  int n = sizeof(arrA) / sizeof(arrA[0]);
  int *arrB = (int*) malloc(n * sizeof(int));
  eCountingSort(arrA, arrB, n);
  imprimeArr(arrB, n);
  imprimeArr(arrA, n);
}
