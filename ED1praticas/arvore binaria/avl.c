#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Manter como especificado */
void inicia(No **ppRaiz)
{
    // PREENCHER AQUI *
    *ppRaiz = NULL;
}

/* Manter como especificado */
void libera(No **ppRaiz)
{
    // PREENCHER AQUI
    if((*ppRaiz)==NULL){
        return;
    }

    libera(&(*ppRaiz)->pEsq);
    libera(&(*ppRaiz)->pDir);
    free((*ppRaiz));
}

/* Manter como especificado */
bool insere(No **ppRaiz, Item x)
{
    if (*ppRaiz == NULL)
    {
        *ppRaiz = (No*)malloc(sizeof(No));
        (*ppRaiz)->item = x;
        (*ppRaiz)->pEsq = NULL;
        (*ppRaiz)->pDir = NULL;
        (*ppRaiz)->cont = 1;
        return 1;
    } else if ( compara((*ppRaiz)->item,x) == MAIOR)
    {
        /* code */
        if(insere(&(*ppRaiz)->pEsq,x)){
            if(Balanceamento(ppRaiz)){
                return false;
            }else{
                return true;
            }
        }
    }else if (compara(( *ppRaiz )->item,x)==MENOR){
        if(insere(&(*ppRaiz)->pDir,x)){
            if(Balanceamento(ppRaiz)){
                return false;
            }else{
                return true;
            }
        } else{
            return false;
        }
    }else{
        (*ppRaiz)->cont++;
        return false;
    }
    
    
}

/* Manter como especificado */
No *criaNo(Item x)
{
    // PREENCHER AQUI
    No *pAux = (No *)malloc(sizeof(No));
    pAux->item = x;
    pAux->pEsq = NULL;
    pAux->pDir = NULL;
    pAux->cont = 0;
    return pAux;
}

/* Manter como especificado */
void caminhamento(No *pNo)
{
    // PREENCHER AQUI
    if (pNo == NULL)
        return;
    caminhamento(pNo->pEsq);
    printf("%s %d\n", pNo->item.chave,pNo->cont);
    caminhamento(pNo->pDir);
}
#
/* Manter como especificado */
RELACAO compara(const Item item1, const Item item2)
{
    int response = strcmp(item1.chave, item2.chave);
    if (response < 0)
        return MENOR;
    else if (response > 0)
        return MAIOR;
    return IGUAL;
}

/* Manter como especificado */
int FB(No *pRaiz)
{
    // PREENCHER AQUI
    if (pRaiz == NULL)
        return 0;

    return altura(pRaiz->pEsq) - altura(pRaiz->pDir);
}

/* Manter como especificado */
int altura(No *pRaiz)
{
    // PREENCHER AQUI
    int iEsq, iDir;

    if (pRaiz == NULL)
        return 0;

    iEsq = altura(pRaiz->pEsq);
    iDir = altura(pRaiz->pDir);

    if (iEsq > iDir)
        return iEsq + 1;
    else
        return iDir + 1;
}

/* Manter como especificado */
void RSE(No **ppRaiz)
{
    // PREENCHER AQUI
    No *pAux;
    pAux = (*ppRaiz)->pDir;
    (*ppRaiz)->pDir = pAux->pEsq;
    pAux->pEsq = (*ppRaiz);
    (*ppRaiz) = pAux;
}

/* Manter como especificado */
void RSD(No **ppRaiz)
{
    // PREENCHER AQUI
    No *pAux;
    pAux = (*ppRaiz)->pEsq;
    (*ppRaiz)->pEsq = pAux->pDir;
    pAux->pDir = (*ppRaiz);
    (*ppRaiz) = pAux;
}

/* Manter como especificado */
int BalancaEsquerda(No **ppRaiz)
{
    // PREENCHER AQUI
    int fbe = FB((*ppRaiz)->pEsq);
    if (fbe >= 0)
    {
        RSD(ppRaiz);
        return 1;
    }
    else
    {
        /* Rota ção Dupla Direita */
        RSE(&((*ppRaiz)->pEsq));
        RSD(ppRaiz); /* &(* ppRaiz ) */
        return 1;
    }
}

/* Manter como especificado */
int BalancaDireita(No **ppRaiz)
{
    // PREENCHER AQUI
    int fbd = FB((*ppRaiz)->pDir);
    if (fbd <= 0)
    {
        RSE(ppRaiz);
        return 1;
    }
    else
    {
        /* Rota ção Dupla Esquerda */
        RSD(&((*ppRaiz)->pDir));
        RSE(ppRaiz); /* &(* ppRaiz ) */
        return 1;
    }
    return 0;
}

/* Manter como especificado */
int Balanceamento(No **ppRaiz)
{
    // PREENCHER AQUI
    int fb = FB(*ppRaiz);
    if (fb > 1)
        return BalancaEsquerda(ppRaiz);
    else if (fb < -1)
        return BalancaDireita(ppRaiz);
    else
        return 0;
}
