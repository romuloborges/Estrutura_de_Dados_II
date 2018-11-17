#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 256

int bmh(char *texto, char *padrao){
    int i, j, k;
    int n = strlen(texto);
    int m = strlen(padrao);
    int tabela[256];

    for(j = 0; j < 256; j++)
        tabela[j] = m;
    for(j = 1; j < m; j++)
        tabela[padrao[j - 1]] = m - j;

    i = m;

    while(i <= n){
        k = i;
        j = m;
        while(texto[k - 1] == padrao[j - 1] && j > 0){
            k--;
            j--;
        }
        if(j == 0)
            return k+1;
        i += tabela[texto[i - 1]];
    }
    return -1;
}

int main(){

    char texto[] = "aabcaccacacbac";
    char padrao[] = "cacbac";

    int pos = bmh(texto, padrao);

    printf("%d\n", pos);

    return 0;
}
