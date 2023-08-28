#include "duende.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { NAO=0, SIM } ESCALADO;

struct duende {
    char nome[20];
    int idade;
    ESCALADO escalado;
};

// Manter como especificado
void lerQuantidade(int *qtd) { 
    /* Le a quantidade de duendes que serao inseridos */
    scanf("%d",qtd); 
    /* PREENCHER AQUI */ 
}

// Manter como especificado
Duende *alocaDuendes(int n) { 
    /* Aloca n de Duendes*/
    /* PREENCHER AQUI */
    Duende *mat = calloc(3,(n * sizeof(Duende)));

    return mat;
}

// Manter como especificado
Duende *copiaDuende(Duende *duendes, int i) {
    /* Aloca um novo duende baseado nos dados de um outro duende */ 
    /* PREENCHER AQUI */
    Duende *copia = malloc(sizeof(Duende));
    strcpy(copia->nome,duendes[i].nome);
    copia->idade = duendes[i].idade;
    copia->escalado = duendes[i].escalado;

    return copia;
}

// Manter como especificado
void desalocaDuendes(Duende **duendes){
    /* Desaloca um vetor ou um unico duende alocado dinamicamente */
    /* PREENCHER AQUI */
    free(*duendes);
}

// Manter como especificado
void lerDuendes(Duende *duendes, int n) {
    /* Lê os dados de n de Duendes */
    /* PREENCHER AQUI */
    for(int i = 0;i<n;i++){
		scanf("%s",duendes[i].nome);
		scanf("%d",&duendes[i].idade);
	}
}
void ordena(Duende *duendes,int n){
    int indice;
    Duende aux2;
    for(int j = 0;j<n;j++){
        indice = proximoMaisVelho(duendes,n);

        aux2.idade = duendes[j].idade;
        duendes[j].idade = duendes[indice].idade;
        duendes[indice].idade = aux2.idade;

        strcpy(aux2.nome,duendes[j].nome);
        strcpy(duendes[j].nome,duendes[indice].nome);
        strcpy(duendes[indice].nome,aux2.nome);
            
        aux2.escalado = duendes[j].escalado;
        duendes[j].escalado = duendes[indice].escalado;
        duendes[indice].escalado = aux2.escalado;
    }
}
// Manter como especificado
int proximoMaisVelho(Duende *duendes, int n) {
    /* Pega o próximo duende mais velho que ainda nao foi escalado */
    /* PREENCHER AQUI */
    int aux;
    int indice;

    for(int i = 0;i < n;i++){
        if(duendes[i].escalado == NAO){
            aux = duendes[i].idade;
            break;
        }
    }
        
        
    for(int i = 0;i < n;i++){
        if(duendes[i].idade >= aux && duendes[i].escalado == NAO){
            aux = duendes[i].idade;
            indice = i;
        }
    } 
	return indice;
}

// Manter como especificado
void escalarDuende(Duende *duendes, int index) {
    /* Dado um vetor de duendes, "seta" como escalado um duende */
    /* PREENCHER AQUI */ 
    duendes[index].escalado = SIM;
}

// Manter como especificado
void printDuende(Duende *duende) {
    /* Imprime os dados de um duende e um \n no final */
    printf("%s %d\n",duende->nome,duende->idade);
    /* PREENCHER AQUI */
}
