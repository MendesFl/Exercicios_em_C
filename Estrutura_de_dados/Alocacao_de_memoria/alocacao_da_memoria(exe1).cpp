#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
	int *array;
	int tmn_inicial, tmn_novo, i;
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("Digite o tamanho inicial da array:");
	scanf("%d",&tmn_inicial);
	
	array = (int*)malloc(tmn_inicial*sizeof(int));{
	
		if(array==NULL){
			printf("Memória Insuficiente");
		}
		
	}
	
	printf("Preencha os %d elementos da array:\n",tmn_inicial);
	
	for(i=0; i<tmn_inicial; i++){
		
		printf("\nElemento[%d]= ",i);
		scanf("%d",&array[i]);
		
	}
	
	for(i=0; i<tmn_inicial; i++){
		printf("\nElemento[%d]= %d",i,array[i]);

	}
	
	printf("\n\nAgora Digite um novo tamanho para array:");
	scanf("%d",&tmn_novo);
	
	printf("\nPreencha os novos %d elementos da array:\n",tmn_novo - tmn_inicial);
	
	for(i=tmn_inicial; i<tmn_novo; i++){
		
	printf("\nElemento[%d]= ",i);
	scanf("%d",&array[i]);
		
	}
	
	for(i=0; i<tmn_novo; i++){
		printf("\nElemento[%d]= %d",i,array[i]);

	}
	
	free(array);
	array=NULL; 
	
	return 0;
}
