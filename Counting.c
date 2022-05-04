//FUNCIONAL

#include <stdio.h>
#include <stdlib.h>

void countingSort(int *arrA, int *arrB, int tam){
    int i;
    // Encontrar o maior elemento do vetor
    int max = arrA[0];
    for (int i = 1; i < tam; i++) {
        if (arrA[i] > max)
        max = arrA[i];
    }

    //Alocar um vetor para armazenar a frequência
    int* count = calloc(max, sizeof(int));

    // Inicializar o vetor com 0 ou calloc ou memset 0
    /*for (int i = 0; i < max; ++i) {
        count[i] = 0;
    }
    ou memset(count, 0, sizeof(count));*/

    // Guardar a frequências dos elementos no auxiliar Count
    for (i = 0; i < tam; i++) {
        count[arrA[i]-1]++;
    }

    // Particularidade do CountingSort Original
    // Guardar o acumulativo das valores menores que um elemento i do vetor original (A)
    for (i = 1; i < max; i++) {
        count[i] += count[i - 1];
    }

    // Percorrer o vetor original com início no último elemento, subtituindo os índices nos elementos do vetor count e decrescendo a cada atribuição
    for (i = tam - 1; i >= 0; i--) {
        arrB[count[arrA[i] - 1] - 1] = arrA[i];
        count[arrA[i]-1]--;
    }
}


void imprimeArr(int* array, int size){
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}


//Função para verificar o sucesso da ordenação
void isOrdered(int *arr, int tam){
  int i, flag = 0, aux = arr[0];

  for(i=1;i<tam;i++){
    if(arr[i] < aux){
      flag = 1;
    }
  }
  if(flag == 0){printf("\nVetor Ordenado\n");}
  else{printf("\nVetor Desordenado\n");}
}

int main() {
  int arrA[] = {4,8,7,9,8,5,2,1,2,8,7,4,1,2,5,4,8,9,3,1,4,7,2,1,4,2,3,23,56,98,784,54,21,654,77,124,785,354,147};
  int n = sizeof(arrA) / sizeof(arrA[0]);
  int *arrB = (int*) malloc(n * sizeof(int));
  countingSort(arrA, arrB, n);
  isOrdered(arrB, n);
  imprimeArr(arrB, n);
  isOrdered(arrA, n);
  imprimeArr(arrA, n);
}
