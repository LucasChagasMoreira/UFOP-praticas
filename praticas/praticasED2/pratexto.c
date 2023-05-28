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
void pegaalunobin(FILE *arq){
    aluno aux;
    arq = fopen("alunos.bin","rb");
    FILE *arq2 = fopen("conceito.txt","w");
    while(fread(&aux,sizeof(aluno),1,arq) == 1){
        fprintf(arq2,"%-4d \n",aux.matricula);
        fprintf(arq2,"%-30s \n",aux.nome);
        if(((aux.nota1 + aux.nota2 + aux.nota3)/3 + aux.faltas) > 18){
            fprintf(arq2,"%c\n",'F');    
        }
        else if(((aux.nota1 + aux.nota2 + aux.nota3)/3 + aux.faltas) <= 18 && (aux.nota1 + aux.nota2 + aux.nota3)/3 < 6){
            fprintf(arq2,"%c\n",'R');
        }
        else if(((aux.nota1 + aux.nota2 + aux.nota3)/3 + aux.faltas) <= 18 && (aux.nota1 + aux.nota2 + aux.nota3)/3 > 6 && (aux.nota1 + aux.nota2 + aux.nota3)/3 < 7){
            fprintf(arq2,"%c\n",'C');
        }
        else if(((aux.nota1 + aux.nota2 + aux.nota3)/3 + aux.faltas) <= 18 && (aux.nota1 + aux.nota2 + aux.nota3)/3 > 7.5 && (aux.nota1 + aux.nota2 + aux.nota3)/3 < 9){
            fprintf(arq2,"%c\n",'B');
        }
        else{
            fprintf(arq2,"%c\n",'A');
        }
    }
    fclose(arq);
    fclose(arq2);
}
int main(){
    FILE *arq;

    pegaalunobin(arq);
    return 0;
}