#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 100

typedef struct {
	int top;
	int size[MAX];
} Stack;

void init(Stack *s) {
	s->top = -1;
}

// Tornamos a verificação silenciosa e com retornos padrão (1 para sim, 0 para não)
int IsEmpty(Stack *s) {
	if (s->top == -1) {
		return 1; 
	} else {
		return 0;
	}
}

void IsFull(Stack *s) {
	if (s->top == MAX - 1) {
		printf("\n!! ATENÇÃO A PILHA ESTÁ CHEIA !!\n");
	}
}

void push(Stack *s, char value) {
	if (s->top < MAX - 1) {
		s->top++;
		s->size[s->top] = value;
	} else {
		IsFull(s);
	}
}

int pop(Stack *s) {
	if (IsEmpty(s)) {
		return -1;
	}
	int value = s->size[s->top]; // Correção da atribuição invertida
	s->top--;
	return value;
}

int balanced(char *expression) {
	Stack stack;
	int i = 0;
	init(&stack);
	
	while (expression[i] != '\0') {
		if (expression[i] == '(') {
			push(&stack, '(');
		} else if (expression[i] == ')') {
			if (IsEmpty(&stack)) {
				return 0; // Encontrou ')' mas não tinha nenhum '(' correspondente na pilha
			} else {
				pop(&stack);
			}
		}
		i++;
	}
	
	// Se a pilha terminar vazia, está balanceada (retorna 1). Se sobrar algo, retorna 0.
	return IsEmpty(&stack);
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	char expression[MAX];
		
	printf("\t== VERIFICADOR DE BALANCEAMENTO DE EXPRESSÕES ==\n");
	printf("\nInsira a expressão completa -> ");
	fgets(expression, MAX, stdin);
	
	if (balanced(expression)) {
		printf("\nResultado: Balanceada\n");
	} else {
		printf("\nResultado: Não Balanceada\n");
	}
	
	return 0;
}
