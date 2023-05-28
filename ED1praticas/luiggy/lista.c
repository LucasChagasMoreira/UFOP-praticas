#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicia as variaveis da lista
void TLista_Inicia(TLista *pLista) {
    pLista -> pPrimeiro = ( TCelula *) malloc ( sizeof ( TCelula )) ;
    pLista -> pUltimo = pLista -> pPrimeiro ;
    pLista -> pPrimeiro -> pProx = NULL ;
//semelhante ao visto em aula
}

//Retorna se a lista esta vazia
int TLista_EhVazia(TLista *pLista) {
//semelhante ao visto em aula
    return ( pLista -> pPrimeiro == pLista -> pUltimo );
}

// Insere um item no final da lista
int TLista_InsereFinal(TLista *pLista, TItem x) {
//semelhante ao visto em aula
    pLista -> pUltimo -> pProx =( TCelula *) malloc ( sizeof ( TCelula ));
    pLista -> pUltimo = pLista -> pUltimo -> pProx ;
    pLista -> pUltimo -> item = x;
    pLista -> pUltimo -> pProx = NULL ;
}

// Retira o primeiro item da lista
int TLista_RetiraPrimeiro(TLista *pLista, TItem *pX) {
    if ( TLista_EhVazia ( pLista ))
        return 0;
    TCelula * pAux ;
    pAux = pLista -> pPrimeiro -> pProx ;
    *pX = pAux -> item ;
    pLista -> pPrimeiro -> pProx = pAux -> pProx ;
    free ( pAux );
    return 1;
}

// Imprime os elementos da lista
void TLista_Imprime(TLista *pLista) {
//semelhante ao visto em aula
    if (TLista_EhVazia(pLista))
    {
        return;
    }

    TCelula *aux = pLista->pPrimeiro->pProx;
    while(aux != NULL){

        printf("%s ",aux->item.nome);
        aux = aux->pProx;
    }
    printf("\n");
}

//Remove cada elemento de uma lista e libera a memória
void TLista_Esvazia(TLista *pLista) {
    TCelula *temp = pLista->pPrimeiro;
    TCelula *temp2;
	while(temp != NULL)
	{
        temp2 = temp;
		temp = temp->pProx;
        
		free(temp2);
	}
    
}

// Acrescenta o conteudo de uma lista ao final de outra, apenas manipulando ponteiros
void TLista_append(TLista *pLista1, TLista *pLista2){
    if(TLista_EhVazia(pLista1) || TLista_EhVazia(pLista2)) return;
    pLista1->pUltimo->pProx = pLista2->pPrimeiro->pProx;
    free(pLista2->pPrimeiro);
}

// Inclui o conteudo de uma lista em outra, na posicao anterior a str, apenas manipulando ponteiros
void TLista_include(TLista *pLista1, TLista *pLista2, char *str){
    TCelula *busca = pLista1->pPrimeiro;
    while (busca != NULL)
    {
        TCelula *anteriorbusca;
        anteriorbusca = busca;
        busca = busca->pProx;

        if(strcmp(busca->item.nome,str)==0){
            anteriorbusca->pProx = pLista2->pPrimeiro->pProx;
            pLista2->pUltimo->pProx = busca;
            free(pLista2->pPrimeiro);
            return;
        }
    }
    
//preencher
}
