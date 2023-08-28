#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "duende.h"

struct duende {
	char nome[21];
	int idade;
	ESCALADO escalado; 
};

struct time {
	char nomeLider[21];
	char nomeConfeiteiro[21];
	char nomeEntregador[21];
	char nomeEmbrulhador[21];
	
	int idadeLider;
	int idadeConfeiteiro;
	int idadeEntregador;
	int idadeEmbrulhador;
};

// Manter como especificado
void lerQuantidade(int *qtdDuendes){
	scanf("%d",qtdDuendes); 
}

// Manter como especificado
Duende *alocaDuendes(int qtdDuendes){
    Duende *mat = malloc(qtdDuendes * sizeof(Duende));

    return mat;
}

// Manter como especificado
Time *alocaTimes(int qtdTimes){
    Time *mat = malloc(qtdTimes * sizeof(Time));
    
    return mat;
}

// Manter como especificado
void desalocaDuendes(Duende **duendes){
	free(*duendes);
}

// Manter como especificado
void desalocaTimes(Time **times){
	free(*times);
}

// Manter como especificado
void lerDuendes(Duende *duendes, int qtdDuendes){
	for(int i = 0;i<qtdDuendes;i++){
		scanf("%s",duendes[i].nome);
		scanf("%d",&duendes[i].idade);
	}
}

// Manter como especificado
void escalarTimes(Duende *duendes, Time *times, int qtdDuendes){
    int i, index;
    int qtdTime = qtdDuendes/4;
    // Escalando os lideres
    for (i=0; i<qtdTime; i++) {
        // Bucar o proximo mais velho disponivel
        index = proximoMaisVelho(duendes,qtdDuendes);
        //printf("%d\n",index);
        // Marca o duende como escalado
        duendes[index].escalado = SIM;
        // Copiar o nome do duende encontrado como lider de um time
        strcpy(times[i].nomeLider,duendes[index].nome);
        // Copiar a idade do duende encontrado como lider de um time
        times[i].idadeLider = duendes[index].idade;
    }

    // Escalando os confeiteiros
    for (i=0; i<qtdTime; i++) {
        // Bucar o proximo mais velho disponivel
        index = proximoMaisVelho(duendes,qtdDuendes);
        //printf("%d\n",index);
        // Marca o duende como escalado
        duendes[index].escalado = SIM;
        // Copiar o nome do duende encontrado como confeiteiro de um time
        strcpy(times[i].nomeConfeiteiro,duendes[index].nome);
        // Copiar a idade do duende encontrado como confeiteiro de um time
        times[i].idadeConfeiteiro = duendes[index].idade;
    }

    // Escalando os entregador
    for (i=0; i<qtdTime; i++) {
        // Bucar o proximo mais velho disponivel
        index = proximoMaisVelho(duendes,qtdDuendes);
        //printf("%d\n",index);
        // Marca o duende como escalado
        duendes[index].escalado = SIM;
        // Copiar o nome do duende encontrado como entregador de um time
        strcpy(times[i].nomeEntregador,duendes[index].nome);
        // Copiar a idade do duende encontrado como entregador de um time
        times[i].idadeEntregador = duendes[index].idade;
    }

    // Escalando os embrulhador
    for (i=0; i<qtdTime; i++) {
        // Bucar o proximo mais velho disponivel
        index = proximoMaisVelho(duendes,qtdDuendes);
        //printf("%d\n",index);
        // Marca o duende como escalado
        duendes[index].escalado = SIM;
        // Copiar o nome do duende encontrado como embrulhador de um time
        strcpy(times[i].nomeEmbrulhador,duendes[index].nome);
        // Copiar a idade do duende encontrado como embrulhador de um time
        times[i].idadeEmbrulhador = duendes[index].idade;
    }
}
//desconsiderando as funçoes de "proximoMaisVelho" dentro desta funçao, os todos os loops somados irao ser executados (qtdTime*4) vezes.
int proximoMaisVelho(Duende *duendes, int qtdDuendes){
	int aux;
	
	for(int i = 0;i<qtdDuendes;i++){
		if(duendes[i].escalado == NAO){
			aux = duendes[i].idade;
			break;
		}
	}
	
	int indice;
	for(int i = 0;i < qtdDuendes;i++){
		if(duendes[i].idade >= aux && duendes[i].escalado == NAO){
			aux = duendes[i].idade;
			indice = i;
		}
	}
	return indice;
}
//complexidade da funçao "proximomaisvelho": o primeiro loop ira ser executado no maximo (qtdDuendes) vezes e o segundo ira ser executado (qtdDuendes) vezes. Entao, considerando um valor medio para o primeiro loop, o custo desta funçao sera em torno de qtdDuendes + qtdDuendes/2.
// Manter como especificado
void printTimes(Time *times, int qtdTimes){
    for (int i=0; i<qtdTimes; i++) {
        printf("Time %d\n", i+1);
        printf("PILOTO > %s %d\n", times[i].nomeLider, times[i].idadeLider);
        printf("CONFEI > %s %d\n", times[i].nomeConfeiteiro, times[i].idadeConfeiteiro);
        printf("ENTREG > %s %d\n", times[i].nomeEntregador, times[i].idadeEntregador);
        printf("EMBRUL > %s %d\n\n", times[i].nomeEmbrulhador, times[i].idadeEmbrulhador);
    }
}
