#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX 100

typedef struct{
	char string[MAX];
	int top;	
}Stack;

void init(Stack *s){
	s->top = -1;
}

int IsEmpty(Stack *s){
	if(s->top == -1){
		return 1;
	}
		return 0;
}

int IsFull(Stack *s){
	if(s->top == MAX - 1){
		return 1;
	}
		return 0;
}

void push(Stack *s, char letra){
	if(IsFull(s) == 1){
		printf("!!ATENÇÃO A PILHA ESTÁ CHEIA!!");
	}else{
		s->top++;
		s->string[s->top] = letra;
	}
}

char pop(Stack *s){
	if(IsEmpty(s) == 1){
		printf("!!ATENÇÃO A PILHA ESTÁ VAZIA!!");
	}else{
		char letra = s->string[s->top];
		s->top--;
	
		return letra;
	}
		
}

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	Stack stack1;
	char nome[MAX], temp[MAX];
	int i = 0;
	
	init(&stack1);
	
	printf("== PALAVRAS PALÍNDROMAS ==\n\n");
	printf("Digite a palavra correspondente: ");
	fgets(nome,MAX,stdin);
	
	nome[strcspn(nome, "\n")] = '\0';
	
	printf("\nNome Original: ");
	
	while(nome[i] != '\0'){
		push(&stack1,nome[i]);
		
		printf("%c",stack1.string[i]);
		
		i++;
	}
	
	i = 0;
	
	printf("\n\nNome Invertido: ");
	
	while(stack1.top != -1){
		temp[i] = pop(&stack1);
	
		printf("%c",temp[i]);

		i++;

	}
	
	temp[i] = '\0';
	
		if(strcmp(nome, temp)== 0){
			printf("\n\nA palavra é um Palíndrome");
		}else{
			printf("\n\nA palavra não é um Palíndrome");
		}

		
	
	return 0;
}
