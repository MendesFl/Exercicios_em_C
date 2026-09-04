#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int valor;
	struct no *prox;	
}No;

void InsertInicio(No **lista, int valor){
	No *novo = (No*)malloc(sizeof(No));
	
	if(novo == NULL){
		printf("ERRO DE ALOCAÇÃO! MEMÓRIA INSUFICIENTE\n");
		return;
	}
	
	novo->valor = valor;
	novo->prox = *lista;
	*lista = novo;
}

void InsertMeio(No **lista, int valor, int ant){
	No *novo = (No*)malloc(sizeof(No));
	
	if(novo == NULL){
		printf("ERRO DE ALOCAÇÃO! MEMÓRIA INSUFICIENTE\n");
		return;
	}
	
	novo->valor = valor;
	
	if(*lista == NULL){
		novo->prox = NULL;
		*lista = novo;
	}
	else{
		No *aux = *lista;
		
		while(aux->valor != ant && aux->prox != NULL){
			aux= aux->prox;
		}
		
		novo->prox = aux->prox;
		aux->prox = novo;
	}
}

void InsertFim(No **lista, int valor){
	No *novo = (No*)malloc(sizeof(No));
	
	if(novo == NULL){
		printf("ERRO DE ALOCAÇÃO! MEMÓRIA INSUFICIENTE\n");
		return;
	}
	
	novo->valor = valor;
	novo->prox = NULL;
	
	if(*lista == NULL){
		*lista = novo;
	}
	else{
		No *aux = *lista;
		
		while(aux->prox != NULL){
			aux = aux->prox;
		}	
		aux->prox = novo;
	}
}

void Imprimir(No **lista){
	
	if(*lista == NULL){
		printf("Atenção a lista esta vazia");
		return;
	}
	
	No *aux = *lista;
	
	while(aux != NULL){
		printf("%d -> ", aux->valor);
		aux = aux->prox;
	}
	printf("NULL");
}

void Buscar(No **lista, int valor){
	
	if(*lista == NULL){
		printf("Atenção a lista esta vazia");
		return;
	}
	
	No *aux = *lista;
	
	while(aux != NULL && aux->valor != valor){
		aux = aux->prox;
	}
	if(aux == NULL){
		printf("Valor nao encontrado");
	}
	else{
		printf("Valor encontrado = %d", aux->valor);
	}
}

No* Remover(No **lista, int valor){
	
	if(*lista == NULL){
		printf("Atenção a lista esta vazia");
		return NULL;
	}
	
	No *aux = *lista;
	No *remover = NULL;
	
	if((*lista)-> valor == valor){
		remover = *lista;
		*lista = remover->prox;
	}
	else{
		while(aux->prox != NULL && aux->prox->valor != valor){
			aux = aux->prox;
		}
		if(aux->prox != NULL){
			remover = aux->prox;
			aux->prox = remover->prox;
		}
	}
	
	return remover;
}

int main(){
	No *lista = NULL;
	
	InsertInicio(&lista, 13);
	InsertFim(&lista, 215);
	InsertFim(&lista, 10);
	Imprimir(&lista);
	
	printf("\n\n");
	
	InsertInicio(&lista, 133);
	InsertFim(&lista, 15);
	InsertMeio(&lista, 89, 215);
	Imprimir(&lista);
	
	printf("\n\n");
	
	No *removido = Remover(&lista, 215);
	printf("\nValor removido: %d\n", removido->valor);
	free(removido);
	Imprimir(&lista);
	
	printf("\n\n");
	
	removido = Remover(&lista, 89);
	printf("\nValor removido: %d\n", removido->valor);
	free(removido);
	Imprimir(&lista);
	
	printf("\n\n");
	
	Buscar(&lista, 133);
	
	printf("\n\n");
	
	Buscar(&lista, 215);
	
	return 0;
}
