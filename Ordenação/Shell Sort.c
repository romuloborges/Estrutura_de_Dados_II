#include <stdio.h>
#include <stdlib.h>

#define N 10

void shellSort(int *vetor){
    int h = 1;
    int i;
    int aux;
    int j;

    while(h < N)
        h = 3 * h + 1;

    while(h > 1){
        h /= 3;
        for(i = h; i < N; i++){
            aux = vetor[i];
            j = i - h;
            while(j >= 0 && aux < vetor[j]){
                vetor[j + h] = vetor[j];
                j -= h;
            }
            vetor[j + h] = aux;
        }
    }
}

int main(){

    int vetor[N];
    int i;
    
    for(i = 0; i < N; i++){
        scanf("%d", &vetor[i]);
    }

    shellSort(vetor);
    
    for(i = 0; i < N; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
