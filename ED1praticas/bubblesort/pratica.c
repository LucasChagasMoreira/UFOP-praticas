#include "ordenacao.h"
#include <stdio.h>

int main ()
{

	int *vetor;
	int i, n, movimentos;
	while(scanf("%d", &n), n)
	{
		//alocar o vetor
		vetor = alocaVetor(vetor,n);
		//preencher o vetor
		for (i = 0; i < n; i++)
		{
			scanf("%d",&vetor[i]);
		}
		
		//ordenar o vetor e determinar o número de movimentos
		ordenacao(vetor,n,&movimentos);
		//imprimir o resultado
		if(n == 0){
			return 0;
		}
		if(movimentos%2 == 0){
			printf("Marcelo\n");
		}else{
			printf("Carlos\n");
		}
		//desalocar o vetor
		vetor = desalocaVetor(vetor);
	}

	return 0;
}
