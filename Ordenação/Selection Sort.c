#include <stdio.h>
#include <stdlib.h>

#define N 10

void selectionSort(int *vetor){
    int i, menor, j, aux;
    for(i = 0; i < N; i++){
        menor = i;
        for(j = i + 1; j < N; j++){
            if(vetor[j] < vetor[menor])
                menor = j;
        }
        if(i != menor){
            aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }
}

int main(){
    int i;
    int vetor[N];
    for(i = 0; i < N; i++){
        scanf("%d", &vetor[i]);
    }
    selectionSort(vetor);
    printf("VETOR:\n");
    for(i = 0; i < N; i++){
        printf("%d\n", vetor[i]);
    }
}
