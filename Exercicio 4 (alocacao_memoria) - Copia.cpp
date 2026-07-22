#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	int qtd; 
	float soma=0;
	float *v;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite a quantidade de números para o vetor:");
	scanf("%d",&qtd);
	
	v = (float*)malloc(qtd * sizeof(float));{
		
		if(v==NULL){
			printf("Memória insuficiente");
		}
	}
	
	printf("\n>>Digite os elementos<<\n");
	
	for(int i=0; i<qtd; i++){
		printf("Element[%d]=",i);
		scanf("%f",&v[i]);
		soma += v[i];
	}
	
	printf("\n>>Mostrar lista e média<<\n");
	
	for(int i=0; i<qtd; i++){
		printf("%.2f ", v[i]);
	}
	
	printf("\nMédia=%.2f",soma/qtd);
	
	free(v);
	v = NULL;
	return 0;
}
