#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* processar(char* padrao){
    int m = strlen(padrao);
    int* temp = (int*) malloc(sizeof(int) * m);
    int i = 1;
    int j = -1;
    temp[0] = j;
    for(i; i < m; i++){
        while(j > -1 && padrao[j+1] != padrao[i])
            j = temp[j];
        if(padrao[i] == padrao[j+1])
            j++;
        temp[i] = j;
    }
    return temp;
}

int busca(char* padrao, char* texto){
    int *aux = processar(padrao);
    int k = -1;
    int m = strlen(padrao);
    for(int i = 0; i < strlen(texto); i++){
        while(k > -1 && padrao[k + 1] != texto[i]){
            k = aux[k];
        }
        if(texto[i] == padrao[k + 1])
            k++;
        if(k == m - 1){
            free(aux);
            aux = NULL;
            return i-k;
        }
    }
    return -1;
}

int main(int argc, char** argv){

    char padrao[7] = "abacab\0";

    char texto[12] = "abacacbacab\0";

    int ind = busca(padrao, texto);

    printf("%d\n", ind);

    return 0;
}
