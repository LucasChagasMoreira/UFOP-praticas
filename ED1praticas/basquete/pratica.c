#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count = 1;

    // enquanto houver dados
    while (1)
    {
        int n;
        int time1, time2, pontos1, pontos2;
        int i, npartidas;
        Time *heap;

        // leia o numero de times
        scanf("%d", &n);

        // se for zero, o programa acaba
        if(n == 0) return 0;

        // aloque o heap
        heap = alocaVetor(heap, n);

        // calcula o numero de partidas
        npartidas = n * (n - 1) / 2;

        // para cada partida...
        for (i = 0; i < npartidas; ++i)
        {
            scanf("%d%d%d%d", &time1, &pontos1, &time2, &pontos2);

            // preencher o heap de estruturas de acordo com os dados lidos
            heap[time1 - 1].pontof += pontos1;
            heap[time1 - 1].pontoA += pontos2;
            heap[time1 - 1].razao = pointsDif(heap[time1 - 1].pontof, heap[time1 - 1].pontoA);

            heap[time2 - 1].pontof += pontos2;
            heap[time2 - 1].pontoA += pontos1;
            heap[time2 - 1].razao = pointsDif(heap[time2 - 1].pontof, heap[time2 - 1].pontoA);

            result(heap, time1, time2, pontos1, pontos2);
        }

        // ordenar os times
        ordena(heap, n);

        // imprima o resultado
        if(count > 1) printf("\n");
        printf("Instancia %d", count);
        printArray(heap, n);

        count++;
/*
        for(int i = 0; i < n; i++)
        {
            printf("id: %d, pontos: %d, saldo: %lf, pts marc: %d\n", heap[i].id, heap[i].pontos, heap[i].razao, heap[i].pontof);
        }
*/
        // desaloque o heap
        heap = desalocaVetor(heap);
    }

    return 0;
}
