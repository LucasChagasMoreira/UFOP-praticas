#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

//Manter como especificado
int *alocaVetor(int *vetor, int n){
    vetor = malloc(n*sizeof(int));
    return vetor;
}

//Manter como especificado
int *desalocaVetor(int *vetor){
    free(vetor);
    return vetor;
}

void ordenacao(int *vetor, int n, int *movimentos){
    int aux;
    int troca = 0;
    for(int i = 0;i<n;i++){
        for(int j = 1;j<n-i;j++){
            if(vetor[j] < vetor[j-1]){
                aux = vetor[j];
                vetor[j]=vetor[j-1];
                vetor[j-1] = aux;
                troca = troca+1;
            }
        }
        if(troca == 0){
            return;
        }
    }
    *movimentos = troca-1;
    
}
