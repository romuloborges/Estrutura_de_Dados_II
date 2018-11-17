#include <stdio.h>
#include <stdlib.h>

void preencher(int *vetor, int tam){
    for(int i = 0; i < tam; i++){
        scanf("%d", &vetor[i]);
    }
}

void bolha(int *vetor, int tam){
    int j;
    int aux;
    for(int i = tam - 1; i > 0; i--){
        for(j = 0; j < i; j++){
            if(vetor[j] > vetor[j + 1]){
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void bolhaMelhorada(int *vetor, int tam){
    int j, aux;
    int trocou;
    for(int i = tam - 1; i > 0; i--){
        trocou = 0;
        for(j = 0; j < i; j++){
            if(vetor[j] > vetor[j + 1]){
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
                trocou = 1;
            }
        }
        if(!trocou){
            break;
        }
    }
}

void imprimeVetor(int *vetor, int tam){
    for(int i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main(int argc, char** argv){

    int tam;

    scanf("%d", &tam);

    int vetor[tam];

    preencher(vetor, tam);

    imprimeVetor(vetor, tam);

    //bolha(vetor, tam);
    
    bolhaMelhorada(vetor, tam);

    imprimeVetor(vetor, tam);

    return 0;
}
