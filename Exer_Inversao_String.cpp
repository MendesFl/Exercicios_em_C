#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX 100

typedef struct{
	int top;
	char size[MAX];
}Stack;

void init(Stack *s){
	s->top= -1;
}

void push(Stack *s, char letra){
	s->top++;
	s->size[s->top] = letra;
}

char pop(Stack *s){
	char letra = s->size[s->top];
	s->top--;
	
	return letra;
}

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	int i = 0;
	Stack pilha1;
	char nome[MAX], temp;
	
	init(&pilha1);
	
	printf("== INVERTOR DE STRINGS ==\n\n");
	printf("Coloque seu Nome completo: ");
	fgets(nome, MAX, stdin);
	
	while(nome[i] != '\0'){
		push(&pilha1, nome[i]);
		
		printf("%c",pilha1.size[i]);
		
		i++;
		
	}
		
	while(pilha1.top != -1){
		temp = pop(&pilha1);
	
		printf("%c",temp);

	}	
	

	return 0;
}
