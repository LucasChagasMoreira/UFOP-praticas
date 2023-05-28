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

void pegaaluno(FILE *arq){
    aluno aux;
    arq = fopen("alunos.txt","r");
    FILE *arq2 = fopen("conceito.txt","w");
    while(fscanf(arq,"%d %s %f %f %f %d",&aux.matricula,  aux.nome,  &aux.nota1,  &aux.nota2,  &aux.nota3,  &aux.faltas) != EOF){
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
}
int main(){
    FILE *arq;

    pegaaluno(arq);
    return 0;
}