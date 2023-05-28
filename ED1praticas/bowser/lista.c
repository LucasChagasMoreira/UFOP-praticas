#include "lista.h"
#include <stdlib.h>

bool ListaInicia(Lista* pLista) {
    pLista->cabeca = (Celula*) malloc(sizeof(Celula));
    if (pLista->cabeca == NULL)
        return false;
    pLista->ultimo = pLista->cabeca;
    return true;
}

bool ListaEhVazia(Lista* pLista) {
    if(pLista->cabeca == pLista->ultimo)
        return true;
    return false;
}

bool ListaInsereFinal(Lista* pLista, Item item) {
    /* Preencher aqui */
    if(pLista == NULL) return false;
    pLista -> ultimo -> prox = ( Celula *) malloc ( sizeof ( Celula ));
    pLista -> ultimo = pLista -> ultimo -> prox ;
    pLista -> ultimo -> item = item;
    pLista -> ultimo -> prox = NULL ;
    return true;
}

bool ListaInsereInicio(Lista* pLista, Item item) {
    /* Preencher aqui */
    Celula *aux = (Celula*) malloc(sizeof(Celula));
    if(aux == NULL) return false;
    aux->prox = pLista->cabeca->prox;
    aux->item = item;
    pLista->cabeca->prox = aux;
    return true;
}

bool ListaRetiraPrimeiro(Lista* pLista, Item* pItem) {
    if(pLista == NULL) return false;
    Celula *aux;
    aux = pLista->cabeca->prox;
    *pItem =aux->item;
    pLista->cabeca->prox = pLista->cabeca->prox->prox;
    free(aux);
    return true;
}

void ListaLibera(Lista* pLista) {
    /* Preencher aqui */
    Celula *temp = pLista->cabeca;
    Celula *temp2;
	while(temp != NULL)
	{
        temp2 = temp;
		temp = temp->prox;
        
		free(temp2);
	}
}