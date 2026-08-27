#include <stdio.h>
#include <stdlib.h>

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
		l->inicio = novo;
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
	novo->prox = NULL;
	
	if(l->inicio == NULL){
		l->inicio = novo;
	}
	else{
		No *aux = l->inicio;
		
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = novo;
	}
}

void ImprimirLista(Lista *l){	
	No *aux = l->inicio;
	
	printf("Inicio\n");
	
	while(aux != NULL){
		printf("%d -> ", aux->valor);
		aux = aux->prox;
	}
	
	printf("NULL");
}


int main(){
	Lista lista;
	
	init(&lista);
	
	InsertInicio(&lista, 10);
	InsertFim(&lista, 20);
	InsertFim(&lista, 30);
	InsertMeio(&lista, 15, 10);
	InsertMeio(&lista, 25, 20);
	ImprimirLista(&lista);
	
	return 0;
}
