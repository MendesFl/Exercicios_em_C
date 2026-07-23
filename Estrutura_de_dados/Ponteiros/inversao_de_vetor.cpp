#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");

    int *ptr, *ptr_in, *ptr_fim, vetor[5], i, temp;
    
    printf("<<< EXERCÍCIO 1 DE PONTEIROS >>>\n\n");
    printf("Escreva uma sequencia de 5 inteiros\n\n");
    
    ptr = vetor;
    
    for(i = 0; i < 5; i++){
        printf("Elemento[%d]= ", i);
        scanf("%d",(ptr + i));
    }

    ptr_in = vetor;
    ptr_fim = vetor + 4;
    
    while(ptr_in < ptr_fim){
        temp = *ptr_in;
        *ptr_in = *ptr_fim;
        *ptr_fim = temp; 
    
        ptr_in++;
        ptr_fim--; 
    }
    
    printf("\n\n... Sequência Invertida na memória ...\n\n");
    
    for(i = 0; i < 5; i++){
        printf("Elemento[%d]= %d\n", i, *(ptr + i));
    }
	
	return 0;
	}
