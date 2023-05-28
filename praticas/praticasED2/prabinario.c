#include <stdio.h>
#include <string.h>

typedef struct
{
    int matricula;
    char nome[30];
    float nota1;
    float nota2;
    float nota3;
    int faltas;

}aluno;

void txttobin(FILE *arq){
    aluno aux;
    arq = fopen("alunos.txt","r");
    FILE *arq2 = fopen("alunos.bin","wb");
    while(fscanf(arq,"%d %s %f %f %f %d",&aux.matricula,  aux.nome,  &aux.nota1,  &aux.nota2,  &aux.nota3,  &aux.faltas) != EOF){

        fwrite(&aux, sizeof(aluno), 1, arq2);
    }
    fclose(arq);
    fclose(arq2);
}

void lebinario(FILE *arq){
    aluno aux;
    arq = fopen("alunos.bin","rb");
    while(fread(&aux,sizeof(aluno),1,arq) ==1){
        printf("%d\n",aux.matricula);
        printf("%s\n",aux.nome);
        printf("%f\n",aux.nota1);
        printf("%f\n",aux.nota2);
        printf("%f\n",aux.nota3);
        printf("%d\n",aux.faltas);
    }
    fclose(arq);
}
int main(){
    FILE *arq;
    txttobin(arq);
    lebinario(arq);
    return 0;
}