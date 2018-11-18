#include <stdio.h>
#include <stdlib.h>

#define N 10

int buscaBinaria(int *v, int chave){
	int esq = 0, dir = N - 1, meio;

	while(esq <= dir){
		meio = (esq + dir) / 2;
		if(v[meio] == chave)
			return chave;
		else if(v[meio] < chave)
			esq = meio + 1;
		else
			dir = meio - 1;
	}
	return -1;
}

int buscaBinariaMelhorada(int *v, int chave){
	int esq = 0, dir = N - 1, meio;
	while(esq < dir){
		meio = (esq + dir) / 2;
		if(chave > v[meio])
			esq = meio + 1;
		else
			dir = meio;
	}
	if(v[dir] == chave)
		return chave;
	else
		return -1;
}

int recBinaria(int *v, int chave, int esq, int dir){
	if(esq <= dir){
		int meio = (esq + dir)/2;
		if(v[meio] == chave){
			return chave;
		}else if(v[meio] < chave){
			return recBinaria(v, chave, meio + 1, dir);
		}else{
			return recBinaria(v, chave, esq, meio -1);
		}
	}else{
		return -1;
	}
}

int main(int argc, char** argv){

	int v[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	printf("Buscando o 2: %d\n", buscaBinaria(v, 2));

	printf("Buscando o 2: %d\n", recBinaria(v, 2, 0, N - 1));

	printf("Buscando o 2: %d\n", buscaBinariaMelhorada(v, 2));

	return 0;
}
