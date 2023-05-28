#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

// Manter como especificado
void Heap_Refaz(Time *heap, int esq, int dir)
{
    int i = esq;
    int j = (i * 2) + 1;
    Time aux;
    copia(&aux, &heap[i]);

    while(j <= dir)
    {
        if(j < dir && compare(heap[j], heap[j + 1])) //a[j] < a[j + 1]) // aq
        {
            j++;
        }

        // if(aux >= heap[j]) break;
        if(!compare(aux, heap[j])) break;

        copia(&heap[i], &heap[j]);
        i = j;
        j = (i * 2) + 1;
    }

    copia(&heap[i], &aux);
}

// Manter como especificado
void Heap_Constroi(Time *heap, int n)
{
    int lef = (n / 2) - 1;

    while(lef >= 0)
    {
        Heap_Refaz(heap, lef, n - 1);
        lef--;
    }
}

// Manter como especificado
Time* alocaVetor(Time *vetor, int n)
{
    vetor = (Time*) malloc(n * sizeof(Time));

    for(int i = 0; i < n; i++)
    {
        vetor[i].id = i + 1;
        vetor[i].pontof = 0;
        vetor[i].pontoA = 0;
        vetor[i].razao = 0.0;
        vetor[i].pontos = 0;
    }

    return vetor;
}

// Manter como especificado
Time* desalocaVetor(Time *vetor)
{
    free(vetor);
    vetor = NULL;

    return vetor;
}

// Manter como especificado
void ordena(Time *heap, int n)
{
    Heap_Constroi(heap, n);

    Time aux;
    while(n > 1)
    {
        copia(&aux, &heap[n - 1]);
        copia(&heap[n - 1], &heap[0]);
        copia(&heap[0], &aux);

        n--;

        Heap_Refaz(heap, 0, n - 1);
    }
}

// Manter como especificado
int compare(const Time t1, const Time t2)
{
    if(t1.pontos > t2.pontos)
    {
        return 1;
    }
    else if(t1.pontos < t2.pontos)
    {
        return 0;
    }
    else // tie: points difference
    {
        if(t1.razao > t2.razao)
        {
            // printf("s\n");
            return 1;
        }
        else if(t1.razao < t2.razao)
        {
            // printf("n\n");
            return 0;
        }
        else // points for
        {
            // printf("ee\n");
            if(t1.pontof > t2.pontof)
            {
                return 1;
            }
            else if(t1.pontof < t2.pontof)
            {
                return 0;
            }
            else // less id
            {
                if(t1.id < t2.id)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
}

void t1Won(Time v[], int t1, int t2)
{
    v[t1 - 1].pontos += 2;
    v[t2 - 1].pontos++;
}

void t2Won(Time v[], int t1, int t2)
{
    v[t2 - 1].pontos += 2;
    v[t1 - 1].pontos++;
}

void result(Time v[], int t1, int t2, int p1, int p2)
{
    if(p1 > p2)
    {
        t1Won(v, t1, t2);
    }
    else// if(p2 > p1)
    {
        t2Won(v, t1, t2);
    }
}

double pointsDif(int pontof, int pontoA)
{
    double razao;

    if(pontoA != 0)
    {
        razao = (double)pontof / pontoA;
    }
    else
    {
        razao = (double)pontof;
    }

    return razao;
}

void copia(Time *t1, Time *t2)
{
    t1->id = t2->id;
    t1->pontoA = t2->pontoA;
    t1->razao = t2->razao;
    t1->pontof = t2->pontof;
    t1->pontos = t2->pontos;
}

void printArray(Time v[], int n)
{
    printf("\n");
    for(int i = 0; i < n - 1; i++)
    {
        printf("%d ", v[i].id);
    }
    printf("%d\n", v[n - 1].id);
}
