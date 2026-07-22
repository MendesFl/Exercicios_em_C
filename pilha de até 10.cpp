#include <stdio.h>
#include <locale.h>
#define TAM 10 // Tamanho máximo da pilha
int stack[TAM]; // Declaração da pilha
int topo = -1; // Inicialização do topo da pilha
// Função para empilhar um elemento na pilha
void empilhar(int value) {
	if (topo == TAM - 1) {
		printf("Erro: Pilha cheia, não é possível empilhar!\n");
		return;
	}
	stack[++topo] = value;
}
// Função para desempilhar um elemento da pilha
int desempilhar() {
	if (topo == -1) {
		printf("Erro: Pilha vazia, não é possível desempilhar!\n");
		return -1; // Valor de retorno inválido para indicar erro
	}
	return stack[topo--];
}
// Função para verificar se a pilha está vazia
int IsVazia() {
	return topo == -1;
}
// Função para verificar se a pilha está cheia
int IsCheia() {
	return topo == TAM - 1;
}
// Função para mostrar o elemento no topo da pilha
void mostraTopo() {
	if (topo == -1) {
		printf("Pilha vazia, não há elemento no topo!\n");
		return;
}
	printf("Elemento no topo: %d\n", stack[topo]);
}
int main() {
	
	int opcao, value;
	setlocale(LC_ALL,"Portuguese");
	
do {
	printf("\n\nEscolha uma operacao:\n");
	printf("---------------------------------------\n");
	printf("1. Empilhar\n");
	printf("2. Desempilhar\n");
	printf("3. Verificar se a pilha esta vazia\n");
	printf("4. Verificar se a pilha esta cheia\n");
	printf("5. Mostrar o elemento no topo da pilha\n");
	printf("0. Sair\n");
	printf("---------------------------------------\n");
	printf("Opcao: ");
	scanf("%d", &opcao);
	
	switch (opcao) {
				
	case 1:
		printf("Digite o valor a ser empilhado: ");
		scanf("%d", &value);
		empilhar(value);
	break;
	
	case 2:
		value = desempilhar();
		if (value != -1){
			printf("Elemento desempilhado: %d\n", value);
		}		
		break;
		
	case 3:
	if (IsVazia())
	
		printf("A pilha esta vazia.\n");
		
			else
			
				printf("A pilha nao esta vazia.\n");
	break;
	
	case 4:
	
		if (IsCheia())
			printf("A pilha esta cheia.\n");
		else
			printf("A pilha nao esta cheia.\n");
	break;
	
	case 5:
	
		mostraTopo();
	
	break;
	
	case 0:
	
		printf("Saindo do programa.\n");
	
	break;
	
	default:
		printf("Opcao invalida!\n");
	}
} while (opcao != 0);

	return 0;
}
