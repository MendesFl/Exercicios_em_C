#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void soma(int *v1, int *v2, int tmn, int *v3){
	
	printf("\n\n<< Lista da soma dos valores entre os vetores >>\n");
	
	for(int i = 0; i < tmn; i++){
		
		*(v3 + i) = *(v1 + i) + *(v2 + i);
		
		printf("\nElemento[%d] = %d", i, *(v3 + i));
		
	}	
	
}

void ImprimirVetor1(int *v1, int tmn){
	
	printf("\n\n<< Lista dos valores no primeiro vetor >>\n");
	
	for(int i = 0; i < tmn; i++){
	
		printf("\nElemento[%d] = %d", i, *(v1 + i));
		
	}	
	
}

void ImprimirVetor2(int *v2, int tmn){
	
	printf("\n\n<< Lista dos valores no segundo vetor >>\n");
	
	for(int i = 0; i < tmn; i++){
	
		printf("\nElemento[%d] = %d", i, *(v2 + i));
		
	}	
	
}

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	int *v1, *v2, *v3, tmn;
	
	printf("<<< Exercício 3 de alocação da memória >>>\n\n");
	
	printf("Digite o tamanho dos Vetores:");
	scanf("%d",&tmn);


	v1 = (int*)malloc(tmn * sizeof(int));
	
		if(v1 == NULL){
			printf("Memória Insuficiente");
		}
		
		
	v2 = (int*)malloc(tmn * sizeof(int));
	
		if(v2 == NULL){
			printf("Memória Insuficiente");
		}
	
	v3 = (int*)malloc(tmn * sizeof(int));
	
		if(v3 == NULL){
			printf("Memória Insuficiente");
		}
		
	printf("\n--- Preencha cada elemento com o valores para o Vetor 1 ---\n\n");
	
	for(int i = 0; i < tmn; i++){
		
		printf("Elemento[%d]: ", i + 1);
		scanf("%d",(v1 + i));
		
	}

	printf("\n--- Preencha cada elemento com o valores para o Vetor 2 ---\n\n");
	
	for(int i = 0; i < tmn; i++){
		
		printf("Elemento[%d]: ", i + 1);
		scanf("%d",(v2 + i));
		
	}
	
	printf("\n------------------------------------------------------------------------------------------------------------------");
	
	ImprimirVetor1(v1, tmn);
	ImprimirVetor2(v2, tmn);
	soma(v1, v2, tmn, v3);
	
	free(v1);
	free(v2);
	free(v3); 
	
	v1=NULL;
	v2=NULL;
	v3=NULL;
	
	return 0;
}
