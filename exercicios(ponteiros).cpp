#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void comparador(int *ptr1, int *ptr2){
	
	if(ptr1 > ptr2){
		
		printf("<<< O endereço de ptr1 é maior que ptr2");
		
	}else{
		
		printf("<<< O endereço de ptr2 é maior que ptr1");
		
	}
	
}

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	/*
	printf("1) Escreva um programa que contenha duas variáveis inteiras e dois ponteiros. Compare seus endereços e exiba o maior endereço.\n\n");
	
	int v1 = 20, v2 = 10;
	int *ptr1, *ptr2;
	
	ptr1 = &v1;
	ptr2 = &v2;
	
	printf("{Endereço: ptr1 -> %p\n", ptr1);
	printf("{Endereço: ptr2 -> %p\n\n", ptr2);
	
	printf("{Endereço: v1 -> %p\n", v1);
	printf("{Endereço: v2 -> %p\n\n", v2);
	
	printf("{Conteúdo: v1 -> %d\n", v1);
	printf("{Conteúdo: v1 -> %d\n\n", v2);
	
	printf("{Conteúdo: ptr1 -> %p\n", *ptr1);
	printf("{Conteúdo: ptr2 -> %p\n\n", *ptr2);
		
	printf("{Conteúdo apontado: ptr1 -> %d\n", *ptr1);
	printf("{Conteúdo apontado: ptr2 -> %d\n\n", *ptr2);
	
	comparador(ptr1, ptr2);
	
	
	printf(">>> Após Declarações de Variáveis <<< \n\n");
	printf("Endereço de n: %p\n",&n);
	printf("Endereço de p1: %p\n",&p1);
	printf("Endereço de p2: %p\n\n",&p2);
	
	printf("Conteúdo de n: %d\n",n);
	printf("Conteúdo de p1: %d\n",p1);
	printf("Conteúdo de p2: %d\n\n",p2);
	
	p1 = &n;
	p2 = p1;
	*p2 = 5;
	
	printf(">>> Após Atribuições nas Variáveis <<< \n\n");
	printf("Endereço de n: %p\n",&n);
	printf("Endereço de p1: %p\n",&p1);
	printf("Endereço de p2: %p\n\n",&p2);
	
	printf("Conteúdo de n: %d\n",n);
	printf("Conteúdo de p1: %d\n",*p1);
	printf("Conteúdo de p2: %d\n\n",*p2);
	
	printf(">>> Outra forma de vizualizar: <<<\n\n");
	
	int var = 15;
	int *ptr;
	
	ptr = &var;
		printf("Conteúdo de 'var':%d\n",var);
		printf("Endereço de 'var':%p\n",&var);
		printf("Conteúdo apontado por 'ptr':%d\n",*ptr);
		printf("endereço apontado por 'ptr':%p\n",ptr);
		printf("endereço do 'ptr':%p\n\n",&ptr);
		
	*ptr = 20;
		printf("Conteúdo de 'var':%d\n",var);
		printf("Endereço de 'var':%p\n",&var);
		printf("Conteúdo apontado por 'ptr':%d\n",*ptr);
		printf("endereço apontado por 'ptr':%p\n",ptr);
		printf("endereço do 'ptr':%p\n\n",&ptr);
		
	printf(">>> Aritmética de ponteiros <<<\n\n");
	
	printf("#Ponteiros e Vetores\n\n");
	
	printf("Com v[i]\n");
	int v[10], i;
	
		for(i=0; i<10; i++){
			v[i] = i;
			printf("%d\n",v[i]);
		}
		
	printf("\nCom v + i\n");
	
		for(i=0; i<10; i++){
			v[i] = i;
			printf("%d\n",v + i);
		}
		
	printf("\nCom *(v + i)\n");
	
		for(i=0; i<10; i++){
			v[i] = i;
			printf("%d\n",*(v + i) );
		}
	
	
		
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
	
	
	
	// É boa prática inicializar os ponteiros
    int *ptr, *ptr_in, *ptr_fim, vetor[5], i, temp;
    
    printf("<<< EXERCÍCIO 1 DE PONTEIROS >>>\n\n");
    printf("Escreva uma sequencia de 5 inteiros\n\n");
    
    ptr = vetor;
    
    for(i = 0; i < 5; i++){
        printf("Elemento[%d]= ", i);
        scanf("%d",(ptr + i));
    }

    // 1. Inicializamos os ponteiros FORA do loop
    ptr_in = vetor;
    ptr_fim = vetor + 4;
    
    // 2. O loop move os ponteiros para o centro
    while(ptr_in < ptr_fim){
        // Troca os valores usando o "balde" temp
        temp = *ptr_in;
        *ptr_in = *ptr_fim;
        *ptr_fim = temp; // Corrigido: temp vai para o fim
        
        // Move os ponteiros
        ptr_in++;
        ptr_fim--; 
    }

    

    printf("\n\n... Sequência Invertida na memória ...\n\n");
    
    // 3. i++ para percorrer o vetor do início ao fim
    for(i = 0; i < 5; i++){
        printf("Elemento[%d]= %d\n", i, *(ptr + i));
    }
    
    
    
    	int cont = 0;
	char String[10], Sub_string[5], *ptr1, *ptr2;
	
	setlocale(LC_ALL,"Portuguese");
	
	ptr1 = String;
	ptr2 = Sub_string;
	
	
	
	
	printf("<<< EXERCÍCIO 3 DE PONTEIROS >>>\n\n");
	
	printf("Digite uma sequência de caracteres para a String (MÁX 10)\n");
	scanf("%s",&String);
	
	printf("Digite uma sequência de caracteres para a Segunda String (MÁX 5)\n");
	scanf("%s",&Sub_string);
	
	for(int j = 0; j < 10; j++){
		for(int i = 0; i < 5; i++){
			
			*(ptr2 + i);	
			*(ptr1 + j + i);
			
			if(*(ptr2 + i) == *(ptr1 + j + i)){
				
				cont ++;
				
			}else {
				
				cont = 0;
				break;
				
			}
				
		}	
		
			if(cont >= 4){
				break;
			}
	}	

	if (cont >= 4){
		
		printf("A segunda String é uma SubString da Primeira.");
		
	}else {
		
		printf("A segunda String não faz parte da Primeira.");
		
	}
    
	*/
	
	return 0;
}
