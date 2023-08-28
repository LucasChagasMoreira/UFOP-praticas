#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
typedef struct{
	double p1;
	double p2;
	double p3;
	double tp;
	double notaFinal;
}Aluno;
void setAprovado(Aluno *aluno, double nota){
	double recuperacao;
	if(nota >= 6){
		printf("o aluno ja foi aprovado");
	}else{
		scanf("%lf",&recuperacao);
		if(recuperacao >= 6){
			aluno->notaFinal = 6;
		}
	}
}


int main(){
	int n;
	int aprovados = 0;
	double soma=0;
	scanf("%d",&n);
	Aluno *a = malloc(sizeof(Aluno)*n);
	for(int i = 0; i<n; i++){
		scanf("%lf",&a[i].p1);
		scanf("%lf",&a[i].p2);
		scanf("%lf",&a[i].p3);
		scanf("%lf",&a[i].tp);
		a[i].notaFinal = ((a[i].p1 * 0.2)+(0.2 * a[i].p2)+(0.2 * a[i].p3)+(0.4*a[i].tp) );
		printf("%lf\n",a[i].notaFinal);
		soma += a[i].notaFinal;
		if(a[i].notaFinal >= 6){
			aprovados++;
		}
	}
	setAprovado(&a[1],a[1].notaFinal);	
	printf("%lf\n",a[1].notaFinal);	
	printf("Qtd de aprovados: %d\n",aprovados);
	printf("Media da turma: %.2lf\n",soma/n);
	return 0;
}
