#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
	int valor;
	struct no *proximo;
}No;

typedef struct{
	int tam;
	No *topo;
}Pilha;

void init(Pilha *p){
	p->topo = NULL;
	p->tam = 0;
}

void push(Pilha *p, int valor){
	No *novo = (No*)malloc(sizeof(No));
	
	if(novo == NULL){
		printf("\n Erro: Memória insuficiente!\n");
		return;
	}
	
	novo->valor = valor;
	novo->proximo = p->topo;
	p->topo = novo;
	p->tam++;
}

int pop(Pilha *p){

	if(p->topo == NULL){
		printf("\nErro: A pilha está vazia");
		return -1;
	}
	
	No *temp = p->topo;
	p->topo = temp->proximo; //mesma coisa eu escrever assim p->topo = p->topo->proximo;
	p->tam--;
	
	int remover = temp->valor;
	
	free(temp);
	return remover;
}

void ImprimirPilha(Pilha *p){
	
	printf("\t=== Pilha ===\n");
	
	if(p->topo == NULL){
			printf("\n\tA pilha está vazia\n");
			return;
		}
	
	No *atual = p->topo;
	
	while(atual != NULL){
		
		printf("\t    { %d }\n", atual->valor);
		atual = atual->proximo;
		 
	}
	
	printf("Tamanho da Pilha: %d unidades\n\n", p->tam);
	
}

void AcessarTopo(Pilha *p){
	if(p->topo == NULL){
		printf("\n\tA pilha está vazia\n");
		return;
	}
	printf("\t\nTopo da Pilha {%d}\n\n", p->topo->valor);
}

void DestruirPilha(Pilha *p){
	
	while(p->topo != NULL){
		pop(p);
	}
	printf("Todas as unidades foram deletadas\n\n");
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int op, valor;
	Pilha pilha;
	
	init(&pilha);
	
	do{
		
		printf("\t=== MENU DE INTERAÇÃO ===\n\n");
		printf("\t0 - Sair\n");
		printf("\t1 - Inserir na Pilha\n");
		printf("\t2 - Remover na Pilha\n");
		printf("\t3 - Imprimir a Pilha\n");
		printf("\t4 - Acessar topo da Pilha\n");
		printf("\t5 - Destruir Pilha\n");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				printf("\nPor Favor digite o valor a ser inserido: ");
				scanf("%d", &valor);
				push(&pilha, valor);
				system("cls");
				break;
			case 2:
				valor = pop(&pilha);
				system("cls");
				printf("Unidade removida: %d\n\n", valor);
				break;
			case 3:
				system("cls");
				ImprimirPilha(&pilha);
				break;
			case 4:
				system("cls");
				AcessarTopo(&pilha);
				break;
			case 5:
				system("cls");
				DestruirPilha(&pilha);
				break;

		}
		
		
	}while(op != 0);
	
	
	return 0;
}
