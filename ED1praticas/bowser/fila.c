#include "fila.h"
#include "pilha.h"

bool FilaInicia(Fila* pFila) {
    /* Preencher aqui */
    return ListaInicia(pFila);
}

bool FilaEnfileira(Fila* pFila, Item item) {
    /* Preencher aqui */
    return ListaInsereFinal(pFila,item);
}

bool FilaDesinfeleira(Fila* pFila, Item* pItem) {
    /* Preencher aqui */
    return ListaRetiraPrimeiro(pFila, pItem);
}

bool FilaEhVazia(Fila* pFila) {
    /* Preencher aqui */
    return ListaEhVazia(pFila);
}

void FilaLibera(Fila* pFila) {
    /* Preencher aqui */
    Celula *temp = pFila->cabeca;
    Celula *temp2;
	while(temp != NULL)
	{
        temp2 = temp;
		temp = temp->prox;
        
		free(temp2);
	}
}

bool FilaInverte(Fila* pFila) {
    Item armazena;
    
    Fila pilha;
    PilhaInicia(&pilha);

    Celula *auxpilha;
    auxpilha = pFila->cabeca->prox;
    //botando os elementos na pilha temporaria
    while(auxpilha != NULL){
        PilhaPush(&pilha,auxpilha->item);
        //printf("%s\n", auxpilha->item.nome);
        auxpilha = auxpilha->prox;
        
    }
    //esvaziando fila;
    auxpilha = pFila->cabeca->prox;
    while(auxpilha != NULL){
        FilaDesinfeleira(pFila,&armazena);
        auxpilha = auxpilha->prox;
    }
    auxpilha = pilha.cabeca->prox;
    pFila->ultimo = pFila->cabeca;
    while(auxpilha != NULL){
        FilaEnfileira(pFila,auxpilha->item);
        auxpilha = auxpilha->prox;
    }
    /*Celula *auxcabeca;
    auxcabeca = pilha.cabeca;
    pFila->cabeca->prox = pilha.cabeca->prox;
    free(auxcabeca);*/
    
    PilhaLibera(&pilha);
    
    return true;

}
