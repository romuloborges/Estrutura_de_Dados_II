#include <stdio.h>
#include <stdlib.h>

#define N 5

void busca(int* vetor, int chave){
    int i, j;
    for(i = 0; i < N; i++){
        if(vetor[i] == chave){
            for(j = i; j > 0; j--){
                vetor[j] = vetor[j - 1];
            }
            vetor[0] = chave;
            break;
        }
    }
}

int main(int argc, char** argv){

    int vetor[N];

    int i = 0;

    for(i = 0; i < N; i++){
        printf("Insira o %dº elemento: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    printf("Vetor\n");
    for(i = 0 ; i < N; i++){
        printf("%d\n", vetor[i]);
    }

    busca(vetor, 2);

    printf("Vetor depois da busca\n");
    for(i = 0 ; i < N; i++){
        printf("%d\n", vetor[i]);
    }

    return 0;
}
