//FUNCIONAL

#include <stdio.h>
#include <stdlib.h>

void countingSort(int *arrA, int *arrB, int max, int tam){
    int i;
    //Alocar um vetor para armazenar a frequência
    int* count = calloc(max + 1, sizeof(int));

    // Inicializar o vetor com 0 ou calloc ou memset 0
    /*for (int i = 0; i < max; ++i) {
        count[i] = 0;
    }
    ou memset(count, 0, sizeof(count));*/

    // Guardar a frequências dos elementos no auxiliar Count
    for (i = 0; i < tam; i++) {
        count[arrA[i]]++;
    }

    // Particularidade do CountingSort Original
    // Guardar o acumulativo das valores menores que um elemento i do vetor original (A)
    for (i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Percorrer o vetor original com início no último elemento, subtituindo os índices nos elementos do vetor count e decrescendo a cada atribuição
    for (i = tam - 1; i >= 0; i--) {
        arrB[count[arrA[i]] - 1] = arrA[i];
        count[arrA[i]]--;
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
  int arrA[] = {4,8,7,9,8,5,2,1,2,8,7,4,1,2,5,4,24,785,354,147,74,21,654,77,124,78,785,354,147};

  //Calcular o tamanho do vetor
  //Encontrar maior elemento do vetor
  int tam = sizeof(arrA) / sizeof(arrA[0]);
  int max = arrA[0];
  for (int i = 1; i < tam; i++) {
      if (arrA[i] > max)
      max = arrA[i];
  }
  int *arrB = (int*) malloc(tam * sizeof(int));
  countingSort(arrA, arrB, max, tam);
  isOrdered(arrB, tam);
  imprimeArr(arrB, tam);
  isOrdered(arrA, tam);
  imprimeArr(arrA, tam);
}
