#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	int num, soma = 0, temp;
	
	printf("== EXERCÍCIO 1 ==\n\n");
	printf("-> ESCREVA ABAIXO UM SEQUÊNCIA DE NÚMEROS INTEIROS\n");
	
	scanf("%d",&num);
	
	while(num > 0){
		
		temp = num % 10;
		
		soma = temp + soma;
		
		num = num / 10;
	}
	
	printf("O resultado é %d", soma);
	
	return 0;
}
