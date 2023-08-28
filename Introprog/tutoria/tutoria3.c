#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
typedef struct{
	char nome[128];
	int idade;
	char posicao[4];
	char crub[128];
}Jogador;
void inverter(char vet[]){
    int i, aux, fim, tam = strlen(vet);

    fim = tam - 1; // índice do último caracter
    for(i = 0; i < tam/2; i++){
        aux = vet[i];
        vet[i] = vet[fim];
        vet[fim] = aux;
        fim--;
    }
}
void ahhh(char *a){
	char novo[128];
	int b = 0;
	int cont = 0;
	for(int i = 0; i < strlen(a) ; i++){
		if(a[i] == ' '){
			cont = 1;
		}
	}
	if(cont == 1){
		for(int i = strlen(a)-1;a[i] != ' ';i--){
			novo[b] = a[i];
			b++;
		}
		novo[b] = '\0';
		inverter(novo);
		strcpy(a,novo);
	}
}

int main(){
	int n;
	FILE *amogus;
	amogus = fopen("Jogadores.txt","w");
	Jogador *a = malloc(sizeof(Jogador)*n);
	scanf("%d",&n);
	for(int i = 0; i<n; i++){
		scanf(" %[^\n]",a[i].nome);
		ahhh(a[i].nome);
		printf("%s\n",a[i].nome);
		scanf("%d",&a[i].idade);
		scanf("%s",a[i].posicao);
		scanf("%s",a[i].crub);
	}
	
	for(int i = 0; i<n; i++){
		fprintf(amogus,"Jogador %d\n",i+1);
		fprintf(amogus,"\tnome: %s\n",a[i].nome);
		fprintf(amogus,"\tidade:%d\n",a[i].idade);		
		fprintf(amogus,"\tposição:%s\n",a[i].posicao);
		fprintf(amogus,"\tclube:%s\n",a[i].crub);
	}
	free(a);
	fclose(amogus);
	return 0;
}
