#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

int ForcaBruta(char t[], char p[]){
    int i, j, n = strlen(t), m = strlen(p);

    for(i = 0; i <= n - m; i++){
        j = 0;
        while((j<m) && t[i+j] == p[j]){
            j++;
            if(j == m)
                return i;
        }
    }
    return -1;
}

int ForcaBruta2(char t[], char p[]){
    int i, j, n = strlen(t), m = strlen(p);

    for(i = 0; i <= n - m; i++){
        j = 0;
        while((j<m) && t[i+j] == p[j]){
            j++;
        }
        if(j == m)
            return i;
    }
    return -1;
}

int forcaBruta(char *texto, char *padrao, int tT, int tP){
    int atual = 0;
    for(int i = 0; i <= tT - tP; i++){
        if(texto[i] == padrao[atual]){
            atual++;
            for(int j = i + 1; j < tT; j++){
                if(texto[j] == padrao[atual]){
                    atual++;
                }else{
                    break;
                }
            }
            if(atual == tP)
                return i;
        }
        atual = 0;
    }
    return -1;
}

int* forcaBrutaTO(char *texto, char *padrao, int tT, int tP){
    int atual = 0;
    int *vetor = (int*) malloc(sizeof(int) * (tT / tP) + 1);
    vetor[0] = 0;
    int pV = 1;
    for(int i = 0; i <= tT - tP; i++){
        atual = 0;
        while(texto[ i + atual ] == padrao[ atual ]){
            atual++;
        }
        if(atual == tP){
            vetor[0] += 1;
            vetor[pV] = i;
            pV++;
        }
    }
    return vetor;
}

int main(){

    char texto[N]; //= "abcdefghi";

    scanf("%[^\n]", texto);

    setbuf(stdin, NULL);
    char padrao[N];

    scanf("%[^\n]", padrao);

    int *pos = forcaBrutaTO(texto, padrao, strlen(texto), strlen(padrao));

    if(pos[0] != 0){
        for(int i = 1;i <= pos[0]; i++){
            printf("%d\n", pos[i]);
        }
    }
    else
        printf("Não é uma substring!\n");

    return 0;
}
