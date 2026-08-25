#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
	int valor;
	no *proximo;	
}No;

typedef struct{
	No *inicio;
	No *fim;
}Fila;

void init(Fila *f){
	f->inicio = f->fim = NULL;
}

void insert(Fila *f, int v){
	
	No *novo = (No*)malloc(sizeof(No));
	if(novo == NULL){
		printf("Erro de Alocação! Memória Insuficiente");
		return;
	}
	
	novo->valor = v;
	novo->proximo = NULL;
	
	if(f->inicio == NULL){
		f->fim = f->inicio = novo;
	}
	else if(v >= 60){
		
		if(f->inicio->valor < 60){
			novo->proximo = f->inicio;
			f->inicio = novo;
			
		}else{
			No *aux = f->inicio;
			
			while(aux->proximo != NULL && aux->valor >= 60){
				if(aux->proximo->valor < 60){
					break;
				}
				aux = aux->proximo;
			}
			
			novo->proximo = aux->proximo; 
			aux->proximo = novo; //ou f->inicio->proximo = novo
			
			if(novo->proximo == NULL){
				f->fim = novo;
			}
			
		}
		
	}else{
		f->fim->proximo = novo;
		f->fim = novo;
	}
}

void dequeue(Fila *f){
	if(f->inicio == NULL){
		printf("Atenção! A fila está Vazia");
		return;
	}
	No *temp = f->inicio;
	f->inicio = temp->proximo;
	
	if(f->inicio == NULL){
		f->fim = NULL;
	}
	
	printf("Valor removido {%d}\n", temp->valor);
	free(temp);
}

void imprimir(Fila *f){	
	if(f->inicio == NULL){
		printf("Atenção! A fila está Vazia");
		return;
	}
	No *temp = f->inicio;
	
	int i = 1;
	
	while(temp != NULL){
		printf("|Nó %d valor = %d  ", i++, temp->valor);
		temp = temp->proximo;
	}
	
	printf("\n");
}


int main(){
	setlocale(LC_ALL, "Portuguese");
	
	Fila fila;
	int op, valor;
	
	init(&fila);
	
	do{
		printf("<<< Menu de opções >>>\n\n0 > Sair\n1 > Enfileirar\n2 > Remover da Fila\n3 > Imprimir Fila\n");
		printf("\nopcão:");
		scanf("%d", &op);
		getchar();
		
		switch(op){
			case 1:
				printf("Digite um valor (caso o valor seja maior ou igual 60 ele será o primeiro da fila): ");
				scanf("%d", &valor);
				insert(&fila, valor);
				system("cls");
				break;
			
			case 2:
				dequeue(&fila);
				break;
				
			case 3:
				imprimir(&fila);
				break;
			
			default:
				printf("Comando inválido");
				break;
		}
		
	}while(op != 0);
		
	return 0;
}

