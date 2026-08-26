#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
	int valor;
	no *prox;
}No;

typedef struct{
	int tam;
	No *inicio;
}Lista;

void init(Lista *l){
	l->inicio = NULL;
	l->tam = 0;
}

void InsertInicio(Lista *l, int valor){
	No *novo = (No*)malloc(sizeof(No));
	
	if(novo == NULL){
		printf("ERRO DE ALOCAÇÃO! MEMÓRIA INSUFICIENTE\n");
		return;
	}
	
	novo->valor = valor;
	novo->prox = l->inicio;
	l->inicio = novo;
	l->tam++;
}

void InsertMeio(Lista *l, int valor, int ant){
	No *novo = (No*)malloc(sizeof(No));
	
	if(novo == NULL){
		printf("ERRO DE ALOCAÇÃO! MEMÓRIA INSUFICIENTE\n");
		return;
	}
	
	novo->valor = valor;
	
	if(l->inicio == NULL){
		InsertInicio(l, valor);
	}
	else{
		No *aux = l->inicio;
	
		while(aux->prox != NULL && aux->valor != ant){
			aux = aux->prox;
		}
	
		novo->prox = aux->prox;
		aux->prox = novo;
		l->tam++;
	}	
	
}

void InsertFim(Lista *l, int valor){
	No *novo = (No*)malloc(sizeof(No));
	
	if(novo == NULL){
		printf("ERRO DE ALOCAÇÃO! MEMÓRIA INSUFICIENTE\n");
		return;
	}
	
	novo->valor = valor;
	
	if(l->inicio == NULL){
		InsertInicio(l, valor);
	}
	else{
		No *aux = l->inicio;
		
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = novo;
	}
}

int main(){
	
	
	return 0;
}
