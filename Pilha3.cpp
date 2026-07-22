#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef struct{
	int topo;
	int tamanho[100];
}Stack;

void iniciar(Stack *s){
	s->topo = -1;
}

void VerificarPilha(Stack *s){
	if(s->topo == 99){
		printf("ERRO! A PILHA ESTÁ CHEIA!\n");
	}
	
	if(s->topo == -1){
		printf("ATENÇÃO! A PILHA ESTÁ VAZIA!\n");
	}
}

void Empilhar(Stack *s, int valor){
	if(s->topo == 99){
		printf("ERRO! A PILHA ESTÁ CHEIA!\n");
	}else{
		s->topo++;
		s->tamanho[s->topo] = valor;
	}
}

void Desempilhar(Stack *s, int valor){
	
	int x;
	
	if(VerificarPilha){
		VerificarPilha(s);
	}else{
		x = s->tamanho[s->topo];
		s->topo--;
	}
}

void VerificarTopo(Stack *s){
	
	if(s->topo == -1){
		printf("ATENÇÃO! A PILHA ESTÁ VAZIA!\n");
	}else{
		printf("Elemento no topo da pilha {%d}\n", s->tamanho[s->topo]);	
	}

}

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	int valor, op;
	Stack pilha;
	
	iniciar(&pilha);
	
	printf("\n\tOPERAÇÕES COM PILHA\n\n");
	printf("== MENU DE OPERAÇÕES ==\n");
	
	do{
		printf("\n");
		printf("1 ---- Empilhar Elemento    (Push)\n");
		printf("2 ---- Desempilhar Elemento (Pop)\n");
		printf("3 ---- Verificar topo       (Top)\n");
		printf("4 ---- Verificar Pilha      (Situation)\n\n");
		
		printf("Comando: ");
		scanf("%d",&op);
	
		switch(op){
			case 1:
				printf("Valor a ser inserido: ");
				scanf("%d",&valor);
				Empilhar(&pilha, valor);
				break;
				
			case 2:
				Desempilhar(&pilha, valor);
				printf("Elemento Desempilhado: %d\n", pilha.tamanho[pilha.topo]);
				break;
			
			case 3:
				VerificarTopo(&pilha);
				break;
			
			case 4:
				VerificarPilha(&pilha);
				break;
		}
		
	}while(op != 0);
	
	return 0;
}
