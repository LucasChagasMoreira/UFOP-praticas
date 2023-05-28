#include "pilha.h"

bool PilhaInicia(Pilha* pPilha) {
    /* Preencher aqui */
    return ListaInicia(pPilha);
}

bool PilhaPush(Pilha* pPilha, Item item) {
    /* Preencher aqui */
    return ListaInsereInicio(pPilha,item);
}

bool PilhaPop(Pilha* pPilha, Item* pItem) {
    /* Preencher aqui */
    return ListaRetiraPrimeiro(pPilha,pItem);
 }

bool PilhaEhVazia(Pilha* pPilha) {
    /* Preencher aqui */
    return ListaEhVazia(pPilha);
}

void PilhaLibera(Pilha* pPilha) {
    /* Preencher aqui */
    return ListaLibera(pPilha);
}