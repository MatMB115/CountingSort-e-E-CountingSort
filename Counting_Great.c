#include <stdio.h>
#include <stdlib.h>

//Funciona conforme o vídeo https://www.youtube.com/watch?v=3bm7NgKJpj4
 
void countingSort(int arr[], int n) {
  int arr1[10];

  int x = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > x)
      x = arr[i];
  }

  
  int *count_arr = (int*) calloc(10, sizeof(int)); //Calloc já aloca as posições com 0

  /*for (int i = 0; i <= x; ++i) { //loop para zerar os elementos do vetor
    count_arr[i] = 0;
  }*/

  for (int i = 0; i < n; i++) {
    count_arr[arr[i]]++;
  }

  for (int i = 1; i <= x; i++) {
    count_arr[i] += count_arr[i - 1];
  }

 
  for (int i = n - 1; i >= 0; i--) {
    arr1[count_arr[arr[i]] - 1] = arr[i];
    count_arr[arr[i]]--;
  }

  for (int i = 0; i < n; i++) {
    arr[i] = arr1[i];
  }
}

void display(int arr[], int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d  ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {4, 2, 2, 8, 3, 3, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  countingSort(arr, n);
  display(arr, n);
}