#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int matricula;
    char nome[30];
    int faltas;

}aluno;

void lebinario(FILE *arq){
    aluno aux;
    arq = fopen("alunosrand.bin","rb");
    while(fread(&aux,sizeof(aluno),1,arq) ==1){
        printf("%d\n",aux.matricula);
        printf("%s\n",aux.nome);
        printf("%d\n",aux.faltas);
        printf("\n");
    }
    fclose(arq);
}
aluno busca(FILE *arq,aluno x){
    aluno aux;
    arq = fopen("alunosrand.bin","rb");
    while(fread(&aux,sizeof(aluno),1,arq) ==1){
        printf("%d\n",aux.matricula);
        printf("%s\n",aux.nome);
        printf("%d\n",aux.faltas);
        printf("\n");
    }
    fclose(arq);
}

int main(){
    srand(time(NULL));
    int n = 40;
    aluno pivot;
    FILE *arq = fopen("alunosrand.bin","wb");

    for(int i = 0;i<n;i++){
        // criando matricula aleatoria
        pivot.matricula = rand() % 10;
        
        // criando nome "aleatorio"
        char x[10];
        strcpy(x,"nome");

        char y[4];
        sprintf(y,"%d",i);
        
        strcat(x,y);

        strcpy(pivot.nome,x);


        // criando faltas aleatorias
        pivot.faltas = rand() % 5;

        // escrevendo no arquivo binario
        fwrite(&pivot, sizeof(aluno), 1, arq);
    }
    fclose(arq);
    lebinario(arq);
}