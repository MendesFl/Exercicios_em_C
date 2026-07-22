#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef struct{
	int size[2];
	int top;
}Stack;

void Iniciar(Stack *p){
	p->top = -1;
}

void Empilhar(Stack *p, int valor){
	if(p->top == 1){
		printf("Pilha cheia");
	}else{
		p->top++;
		p->size[p->top] = valor;
	}
}

int Desempilhar(Stack *p){
	
	int remover;
	
	if(p->top == -1){
		printf("Pilha Vazia");
		
		return -1;		
	}else{
		remover = p->size[p->top];
		p->top--;
		
		return remover;
	}
}

void ChecarDivisao(int v1, int v2){
	
	if(v1 == 0){
		printf("Não é possível dividir por zero, por favor digite outro número para o denominador\n");
	}else{
		printf("%d / %d = %d\n",v2 ,v1 ,v2 /v1);
	}
	
}

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	Stack stack;
	int valor, op, v1, v2, opcao;
	
	Iniciar(&stack);
	
	do{
			printf("\t== Calculadora ==\n\n");
		printf("== MENU DE OPERAÇÕES == \n\n");
		printf("1 ---- Soma          (+)\n");
		printf("2 ---- Subtração     (-)\n");
		printf("3 ---- Multiplicação (x)\n");
		printf("4 ---- Divisão       (/)\n");
	
		printf("\nDigite o primeiro número: ");
		scanf("%d",&valor);
		Empilhar(&stack, valor);
	
		printf("\nDigite o segundo número: ");
		scanf("%d",&valor);
		Empilhar(&stack, valor);

		printf("\nEscolha uma Operação: ");
		scanf("%d",&op);
	
		switch(op){
			case 1:
				v1 = Desempilhar(&stack);
				v2 = Desempilhar(&stack);
				printf("%d + %d = %d\n",v2 ,v1  ,v1 + v2);
				break;
			
			case 2:
				v1 = Desempilhar(&stack);
				v2 = Desempilhar(&stack);
				printf("%d - %d = %d\n",v2 ,v1 ,v2 - v1);
				break;
			
			case 3:
				v1 = Desempilhar(&stack);
				v2 = Desempilhar(&stack);
				printf("%d x %d = %d\n",v2 ,v1 ,v1 * v2);
				break;
			
			case 4:
				v1 = Desempilhar(&stack);
				v2 = Desempilhar(&stack);
				ChecarDivisao(v1, v2);
				break;
				
			default:
				printf("Opção inválida, Por favor escolhar as opções listadas no Menu\n");
		}
	
		printf("\nDeseja continuar ? (0 -> Sim | 1 -> Não)");
		printf("\nOpção: ");
		scanf("%d",&opcao);
		
		if(opcao == 0){
			system("cls");;
		}
		
		if(opcao == 1){
			printf("\nENCERRANDO PROGRAMA...");
		}
		
	}while(opcao != 1);
	
	return 0;
}
