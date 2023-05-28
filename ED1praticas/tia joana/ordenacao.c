#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Manter como especificado
void ordena(Aluno *alunos, int n) {
	// PREENCHER AQUI
    int h,j;
    char aux[21];
    for(h = 1;h<n;){
        h = 3*h+1;
    }
    do
    {
        h = (h-1)/3;   
        for(int i = h;i<n;i++){
            strcpy(aux, alunos[i].nome);
            j = i; 
            
            while(compare(alunos[j-h].nome,aux)==1){
                strcpy(alunos[j].nome, alunos[j-h].nome);
                j = j-h;
                if(j<h){
                    break;
                }
            }
            strcpy(alunos[j].nome,aux);
        }
    } while (h>1);
    
}

// Manter como especificado
int compare(const char* aluno1, const char* aluno2) {
    int aux = strcmp(aluno1, aluno2);
    if(aux == 0)
    {
        return 0;
    }else if (aux < 0)
    {
        return -1;
    }else
    {
        return 1;
    }
}


/* Manter como especificado */
void imprimeResposta(Aluno* alunos, int n, int k) {
    // PREENCHER AQUI
    printf("%s\n",alunos[n-k].nome);
}

/* Manter como especificado */
Aluno* alocaAlunos(int n) {
    // PREENCHER AQUI
    Aluno *vetor = malloc(sizeof(Aluno)*n);
    return vetor; 
}

/* Manter como especificado */
void liberaAlunos(Aluno** alunos) {
    // PREENCHER AQUI
    free(*alunos);
}

/* Manter como especificado */
void leAlunos(Aluno* alunos, int n) {
    // PREENCHER AQUI
    for(int i = 0;i<n;i++){
        scanf("%s",alunos[i].nome);
    }
}

/* Manter como especificado */
void leQuantidades(int* n, int* k) {
    // PREENCHER AQUI
    scanf("%d %d",n,k);
}

