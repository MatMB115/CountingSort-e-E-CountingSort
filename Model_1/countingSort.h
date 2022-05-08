#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H
//Estrutura para guardar o valores para médias
typedef struct data{
    int comp;
    int copy;
    double time;
} data;
//Criar um arquivo e gerar valores aleatórios
int createFile (char *nameFile, int size);

//Ler os dados do arquivo e retornar um vetor
int* readFile (char *nameFile, int size);

//Reescrever os valores do arquivo;
void writeFile (char *nameFile, int sortType, int arrayType, float midCopy, float midTime, float midComp, int tam);

//Algoritmo CountingSort
void countingSort(int *arrA, int *arrB, int max, int tam, data *d);

//Algoritmo EfficientCountingSort
void eCountingSort(int *arrA, int *arrB, int max, int tam, data *d);

//Escreve os valores de forma decrescente no arquivo
void reverseArray(int *arr, char *nameFile, int tam);

int findMax (int *arr, int tam);

void freeArray(int* a, int* b, int *c, int *d);

void cleanRegister(data *d1, data *d2, data *d3);

void registerData (char *nameFile, int sortType, int tam, data *desord, data *ord, data *reverse);

void showStatus(int tam, int loopSequence, int sortType);

#endif //COUNTINGSORT_H
