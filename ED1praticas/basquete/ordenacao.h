#ifndef prioridade_h
#define prioridade_h

typedef struct
{
    int id;
    int pontof, pontoA, pontos;
    double razao;
}Time;

// Manter como especificado
Time *alocaVetor(Time *vetor, int n);
// Manter como especificado
Time *desalocaVetor(Time *vetor);
void Heap_Refaz(Time *heap, int esq, int dir);
void Heap_Constroi(Time *heap, int n);
// Manter como especificado
int compare(const Time t1, const Time t2);
// Manter como especificado
void ordena(Time *, int n);
void t1Won(Time *, int, int );
void t2Won(Time *, int t1, int );
void result(Time *, int, int , int , int );
double pointsDif(int , int);
void copia(Time *, Time *);
void printArray(Time *, int );
#endif