#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
	int valor;
	struct no *proximo;
}No;

typedef struct{
	int tam;
	No *inicio;
	No *fim;
}Fila;

void init(Fila *f){
	f->fim = NULL;
	f->inicio = NULL;
	f->tam = 0;
}

void enqueue(Fila *f, int valor){
	
	No *novo = (No*)malloc(sizeof(No));
	
	if(novo == NULL){
		printf("Erro de Alocação: Memória insuficiente");
		return;
	}
	
	novo->valor = valor;
	novo->proximo = NULL;
	
	if(f->inicio == NULL){
		f->inicio = novo;
		f->fim = novo;
	}else{
		f->fim->proximo = novo;
		f->fim = novo;
	}
	
	f->tam++;
	
}

int dequeue(Fila *f){
	
	if(f->inicio == NULL){
		printf("Atenção! A fila está vazia");
		return -1;
	}
	
	No *temp = f->inicio;
	f->inicio = f->inicio->proximo;
	int remover = temp->valor;
	f->tam--;
	
	if(f->inicio == NULL){
		f->fim = NULL;
	}
	
	free(temp);
	return remover;	
}

void PrintQueue(Fila *f){
	
	No *temp = f->inicio;
	
	printf("-------------------\n\nFila\n\n");
	
	while(temp != NULL){
		printf("{%d} -> ", temp->valor);
		temp = temp->proximo;
	}
	
	printf("NULL");
	
	printf("\nTamanho da Fila: %d",f->tam);
	
}

void AcessarFim(Fila *f){
	
	if(f->fim == NULL){
		printf("\n\n-------------------\n");
		printf("A fila está Vazia");
		return;
	}
	printf("Fim da Fila: %d\n", f->fim->valor);
	
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	Fila fila;
	
	init(&fila);
	
	enqueue(&fila, 10);
	AcessarFim(&fila);
	enqueue(&fila, 20);
	enqueue(&fila, 30);
	enqueue(&fila, 40);
	enqueue(&fila, 50);
	
	PrintQueue(&fila);

	while(fila.inicio != NULL){
		dequeue(&fila);
	
		printf("\n\n");
	
		PrintQueue(&fila);
	}
	
	AcessarFim(&fila);
	
	return 0;
}
