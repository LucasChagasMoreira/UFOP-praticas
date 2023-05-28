#include "ordenacao.h"
#include <stdio.h>

int main ()
{
	int n, k;
	Aluno* alunos;

	// ler as quantidades
	// PREENCHER AQUI
	leQuantidades(&n,&k);
	

	// alocar o vetor dinamico de alunos
	// PREENCHER AQUI
	alunos = alocaAlunos(n);;
	// preencher o vetor
	// PREENCHER AQUI
	leAlunos(alunos,n);

	// ordenar o vetor usando o shellsort
	// PREENCHER AQUI
	ordena(alunos,n);

	// imprimir a resposta
	// PREENCHER AQUI
	imprimeResposta(alunos,n,k);

	// desalocar o vetor
	// PREENCHER AQUI
	liberaAlunos(&alunos);

  	return 0;
}
