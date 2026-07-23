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

	return 0;
}
