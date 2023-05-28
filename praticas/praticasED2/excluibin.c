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


void excluialunobin(FILE *arq,int matricula){
    aluno alunoexcluido;
    arq = fopen("alunos.bin","rb");
    FILE *arq2 = fopen("temp.bin","wb");
    while(fread(&alunoexcluido,sizeof(aluno),1,arq) == 1){
        if(alunoexcluido.matricula != matricula){
            fwrite(&alunoexcluido, sizeof(aluno), 1, arq2);
        }
    }
    fclose(arq);
    fclose(arq2);

    arq = fopen("alunos.bin","wb");
    arq2 = fopen("temp.bin","rb");
    while(fread(&alunoexcluido,sizeof(aluno),1,arq2) == 1){
        fwrite(&alunoexcluido, sizeof(aluno), 1, arq);
        printf("%d\n",alunoexcluido.matricula);
        printf("%s\n",alunoexcluido.nome);
        printf("%f\n",alunoexcluido.nota1);
        printf("%f\n",alunoexcluido.nota2);
        printf("%f\n",alunoexcluido.nota3);
        printf("%d\n",alunoexcluido.faltas);
    }
    fclose(arq);
    fclose(arq2);

}
int main(){
    FILE *arq;

    excluialunobin(arq,12);
    return 0;
}