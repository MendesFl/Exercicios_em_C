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
		
	}	
	l->tam++;
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
	l->tam++;
}

void ImprimirLista(Lista *l){	
	No *aux = l->inicio;
	
	printf("Inicio\n");
	
	while(aux != NULL){
		printf("%d -> ", aux->valor);
		aux = aux->prox;
	}
	
	printf("NULL \t | Tamanho -> %d", l->tam);
	free(aux);
}

No* Remover(Lista *l, int valor){
	
	No *remover;
	
	if(l->inicio != NULL){
		if(l->inicio->valor == valor){		
			remover = l->inicio;
			l->inicio = remover->prox;

		}
		else{
			No *aux = l->inicio;
			while(aux->prox != NULL && aux->prox->valor != valor){
				aux = aux->prox;
			}
			if(aux->prox != NULL){
				remover = aux->prox;
				aux->prox = remover->prox;	
			}
		}
		
		l->tam--;
		return remover;
	}

}

void Busca(Lista *l, int valor){
	if(l->inicio != NULL){
		No *aux = l->inicio;
		while(aux->prox != NULL && aux->valor != valor){
			aux = aux->prox;
		}
		if(aux->prox == NULL && aux->valor != valor){
			printf("Valor nao encontrado");
		}
		else{
			printf("Valor encontrado = %d", aux->valor);
		}
	}
	else{
		printf("Atenção a pilha esta vazia");
	}
}

int main(){
	Lista lista;
	
	init(&lista);
	
	InsertInicio(&lista, 13);
	InsertFim(&lista, 215);
	InsertFim(&lista, 10);
	ImprimirLista(&lista);
	
	printf("\n\n");
	
	InsertMeio(&lista, 69, 215);
	InsertMeio(&lista, 32, 10);
	InsertInicio(&lista, 90);
	ImprimirLista(&lista);
	
	printf("\n\n");
	
	No *removido = Remover(&lista, 69);
	printf("\nValor removido: %d\n", removido->valor);
	free(removido);
	ImprimirLista(&lista);
		
	printf("\n\n");
	
	removido = Remover(&lista, 32);
	printf("\nValor removido: %d\n", removido->valor);
	free(removido);
	ImprimirLista(&lista);
	
	printf("\n\n");	
	Busca(&lista, 10);
	
	printf("\n\n");
	Busca(&lista, 215);
	
	printf("\n\n");
	Busca(&lista, 69);
	
	return 0;
}
