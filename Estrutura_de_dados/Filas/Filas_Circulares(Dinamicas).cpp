#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
	int elemento;
	struct no *proximo;
}No;

typedef struct{
	No *inicio;
	No *fim;
	int tam;
}Queue;

void init(Queue *q){
	q->inicio = NULL;
	q->fim = NULL;
	q->tam = 0;
}

void enqueue(Queue *q, int valor){
	
	No *novo = (No*)malloc(sizeof(No));
	
	if(novo == NULL){
		printf("Erro de Alocação: Memória Insuficiente");
		return;
	}else{
		
		novo->elemento = valor;
		
		if(q->inicio == NULL){
			q->inicio = novo;
			q->fim = novo;
			novo->proximo = novo;
		}else{
			q->fim->proximo = novo;
			q->fim = novo;
			novo->proximo = q->inicio;
		}
		
		q->tam++;
	}		
}

int dequeue(Queue *q) {
	
    if (q->inicio == NULL) {
        printf("Atenção! A fila está vazia\n");
        return -1;
    }
    
    No *temp = q->inicio;
    int removed = temp->elemento;
 
    if (q->inicio == q->fim) {
        q->inicio = NULL;
        q->fim = NULL;
    } 
 
    else {
        q->inicio = q->inicio->proximo; 
        q->fim->proximo = q->inicio;    
    }
    
    q->tam--;
    free(temp);
    return removed;
}
	
void PrintQueue(Queue *q){

    if(q->inicio == NULL){
        printf("A fila está vazia -> volta para NULL\n");
        printf("Tamanho da fila: %d\n", q->tam);
        return;
    }

    No *temp = q->inicio;

    do{
        printf("{%d|próximo} -> ", temp->elemento);
        temp = temp->proximo;
    }while(temp != q->inicio);

    printf("volta para {%d}\n", q->inicio->elemento);
    printf("Tamanho da fila: %d\n\n", q->tam);
}
		
void peek(Queue *q){
	
	No *temp = q->fim;
	
	if(q->fim == NULL){
		printf("Atenção! A fila está vazia");
		return;
	}
	
	printf("\nO item no final da fila é %d\n\n", temp->elemento);
}

void destroy(Queue *q){
	
	while(q->inicio != NULL){
		dequeue(q);
	}
	printf("\n\nTodas as Unidades foram deletadas\n\n");
}

int main(){
	setlocale(LC_ALL, "Portuguese");	
	Queue queue;
	
	init(&queue);
	
	//outra forma de testar
	
	printf("-----------------------------------\nPrimeira forma:\n-----------------------------------\n");

	enqueue(&queue,10);
	PrintQueue(&queue);
	enqueue(&queue,20);
	PrintQueue(&queue);
	dequeue(&queue);
	PrintQueue(&queue);
	enqueue(&queue,30);
	PrintQueue(&queue);
	enqueue(&queue,40);
	PrintQueue(&queue);
	dequeue(&queue);
	PrintQueue(&queue);
	enqueue(&queue,50);
	PrintQueue(&queue);
	
	peek(&queue);
	
	printf("\n== Após a função Destroy ==");
	
	destroy(&queue);
	PrintQueue(&queue);	

	printf("\n\n-----------------------------------\nSegunda forma:\n-----------------------------------");

	enqueue(&queue,10);
	enqueue(&queue,20);
	enqueue(&queue,30);
	enqueue(&queue,40);
	enqueue(&queue,50);
	peek(&queue);
	PrintQueue(&queue);	
		
	while(queue.inicio != NULL){
		dequeue(&queue);
		printf("\n");
		PrintQueue(&queue);
	}
	
	return 0;
}
