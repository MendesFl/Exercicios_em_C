#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	int *ptr; 
	int m[6][6], i, j, soma;
	
	ptr = &m[0][0];
	
	printf("<<< EXERCÍCIO 2 DE PONTEIROS >>>\n\n");
	
	printf("Digite um Sequência de inteiros para uma matriz 3x3:\n\n");
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			printf("Elemento[%d][%d]=",i,j);
			scanf("%d",(ptr + (i*3) + j));
		}
	}
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			soma = *(ptr + (i*3) + j) + soma;
		}
	}
	
	printf("\n\n... A soma dos números da matriz é %d ...", soma);	
	
	return 0;
	}
