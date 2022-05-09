#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#include "countingSort.h"

int createFile(char *nameFile, int size){
    int i, num;
    //Criar e abrir arquivo
    FILE *arq = fopen(nameFile, "w+");

    if(arq == NULL){
        return 1;
    }
    else{
        srand(time(NULL));
        for(i = 0; i < size; i++){
            
            num = rand() % 30000;
			if(fprintf(arq, "%d\n", num) == -1){//Erro ao tentar escrever no arquivo
                fclose(arq);
                return 1;
            }
        }
    }
    fclose(arq);
    return 0;
}

//Ler os dados do arquivo e retornar um vetor
int* readFile (char *nameFile, int size){
    int i;

    FILE *arq = fopen(nameFile, "r"); //Abre e lê o que estiver no arquivo
    if(arq == NULL){
        return NULL;
    }
    else{
        int *arr = (int*) malloc(size * sizeof(int)); //Alocar memória para vetor de inteiros
        if(arr == NULL){
            return NULL;
        }
        else{
            for(i = 0; i < size; i++){
                if(fscanf(arq, "%d", &arr[i]) == 0){ //Verificar se a leitura foi realizada corretamente
                    return NULL;
                }
            }
            fclose(arq);
            return arr;
        }

    }

}

//
void writeFile (char *nameFile, int sortType, int arrayType,  float midCopy, float midTime, float midComp, int tam)
{
	FILE *arq = fopen(nameFile, "a+");
    if(arq == NULL){
        exit(1);
    }
    else{
        if(sortType == 0){
            if(arrayType == 0){
                fprintf(arq, "-------------\n");
                fprintf(arq, "COUNTING SORT\n");
                fprintf(arq, "N = %d - Aleatórios\n", tam);
                fprintf(arq, "Numero medio de copias = %.f\n", midCopy);
                fprintf(arq, "Numero medio de comparacoes = %.f\n", midComp);
                fprintf(arq, "Numero medio do tempo = %lf\n", midTime);
                fprintf(arq, "-------------\n\n");
            }
            else{
                if(arrayType == 1){
                    fprintf(arq, "-------------\n");
                    fprintf(arq, "COUNTING SORT\n");
                    fprintf(arq, "N = %d - Ordenados\n", tam);
                    fprintf(arq, "Numero medio de copias = %.f\n", midCopy);
                    fprintf(arq, "Numero medio de comparacoes = %.f\n", midComp);
                    fprintf(arq, "Numero medio do tempo = %lf\n", midTime);
                    fprintf(arq, "-------------\n\n");
                }
                else{
                    fprintf(arq, "-------------\n");
                    fprintf(arq, "COUNTING SORT\n");
                    fprintf(arq, "N = %d - Decrescente\n", tam);
                    fprintf(arq, "Numero medio de copias = %.f\n", midCopy);
                    fprintf(arq, "Numero medio de comparacoes = %.f\n", midComp);
                    fprintf(arq, "Numero medio do tempo = %lf\n", midTime);
                    fprintf(arq, "-------------\n\n");
                }
            }
            
        }
        else{
            if(arrayType == 0){
                fprintf(arq, "-------------\n");
                fprintf(arq, "ECOUNTING SORT\n");
                fprintf(arq, "N = %d - Aleatórios\n", tam);
                fprintf(arq, "Numero medio de copias = %.f\n", midCopy);
                fprintf(arq, "Numero medio de comparacoes = %.f\n", midComp);
                fprintf(arq, "Numero medio do tempo = %lf\n", midTime);
                fprintf(arq, "-------------\n\n");
            }
            else{
                if(arrayType == 1){
                    fprintf(arq, "-------------\n");
                    fprintf(arq, "ECOUNTING SORT\n");
                    fprintf(arq, "N = %d - Ordenados\n", tam);
                    fprintf(arq, "Numero medio de copias = %.f\n", midCopy);
                    fprintf(arq, "Numero medio de comparacoes = %.f\n", midComp);
                    fprintf(arq, "Numero medio do tempo = %lf\n", midTime);
                    fprintf(arq, "-------------\n\n");
                }
                else{
                    fprintf(arq, "-------------\n");
                    fprintf(arq, "ECOUNTING SORT\n");
                    fprintf(arq, "N = %d - Decrescente\n", tam);
                    fprintf(arq, "Numero medio de copias = %.f\n", midCopy);
                    fprintf(arq, "Numero medio de comparacoes = %.f\n", midComp);
                    fprintf(arq, "Numero medio do tempo = %lf\n", midTime);
                    fprintf(arq, "-------------\n\n");
                }
            }
        }
        fclose(arq);
    }
}


//Escreve os valores de forma decrescente no arquivo
void reverseArray(int *arr, char *nameFile, int tam){
	int i;

	FILE *arq = fopen(nameFile, "w+");
    if(arq == NULL){
        exit(1);
    }
    else{
        for(i = 0; i < tam; i++){
		    if(fprintf(arq, "%d\n", arr[tam - i - 1]) == - 1){//Erro ao tentar escrever no arquivo
                fclose(arq);
            }
	    }   
    }
    fclose(arq);
}
    


void countingSort(int *arrA, int *arrB, int max, int tam, data *comp){
	int i;
    int* count = calloc(max + 1, sizeof(int));
    
    for (i = 0; i < tam; i++)
	{
    	count[arrA[i]]++;
        comp->copy++;
    }

    //Guardar o acumulativo das valores menores que um elemento i do vetor original (A)
    for (i = 1; i <= max; i++)
	{
        count[i] += count[i - 1];
        comp->copy++;
    }

    // Percorrer o vetor original com início no último elemento, subtituindo os índices nos elementos do vetor count e decrescendo a cada atribuição
    for (i = tam - 1; i >= 0; i--)
	{
        arrB[count[arrA[i]] - 1] = arrA[i];
        count[arrA[i]]--;
        comp->copy++;
    }
}

void eCountingSort(int *arrA, int *arrB, int max, int tam, data *d){
	int i, j = 0;
    int* count = calloc(max + 1, sizeof(int));

    // Count guarda a frequência
    for (i = 0; i < tam; i++){
        count[arrA[i]]++;
        d->copy++;
    }

    // Aproveitar a frequência dos elementos e o índice do vetor count para preencher o vetor B ordenado
    for (i = 0; i <= max; i++){
        while(count[i] > 0){
            arrB[j] = i;
            j++;
            count[i]--;
            d->copy++;
            d->comp++;
        }
    }
}

int findMax (int *arr, int tam) {
	int max, i;

	max = arr[0];

	for (i = 1; i < tam; i++) 
		if (arr[i] > max)
	    	max = arr[i];

	return max;
}

void cleanRegister(data *d1, data *d2, data *d3){
    d1->comp = d1->copy = d1->time = 0;
    d2->comp = d2->copy = d2->time = 0;
    d3->comp = d3->copy = d3->time = 0;
}

void freeArray(int* a, int* b, int *c, int *d)
{
    if(a != NULL && b !=  NULL && c!= NULL && d!= NULL){
    	free(a);
    	free(b);
    	free(c);
        free(d);
	}
}

//escreve os dados no arquivo REGISTER
void registerData (char *nameFile, int sortType, int tam, data *desord, data *ord, data *reverse)
{
	int arrayType;
	float midComp = 0, midCopy = 0, midTime = 0;
    
    strcpy(nameFile, "data/register.txt");
    //Calcular as médias para ordenação de vetor com elementos aleatórios
    midComp = (desord->comp / 10);
	midTime = (desord->time / 10);
    midCopy = (desord->copy / 10);
    arrayType = 0;
    writeFile(nameFile, sortType, arrayType, midCopy, midTime, midComp, tam);
    //Calcular as médias para ordenação de vetor com elementos ordenados
    midComp = (ord->comp / 10);
	midTime = (ord->time / 10);
    midCopy = (ord->copy / 10);
    arrayType = 1;
    writeFile(nameFile, sortType, arrayType, midCopy, midTime, midComp, tam);
    //Calcular as médias para ordenação de vetor com elementos descrescentes
    midComp = (reverse->comp / 10);
	midTime = (reverse->time / 10);
    midCopy = (reverse->copy / 10);
    arrayType = 2;
    writeFile(nameFile, sortType, arrayType, midCopy, midTime, midComp, tam);

}

void showStatus(int tam, int loopSequence, int sortType){
    if(sortType == 0){
        printf("\nCountSort para N = %d com semente %d", tam, loopSequence+1);
    }
    else{
        printf("\nCountSort Eficiente para N = %d com semente %d", tam, loopSequence+1);
    }
}