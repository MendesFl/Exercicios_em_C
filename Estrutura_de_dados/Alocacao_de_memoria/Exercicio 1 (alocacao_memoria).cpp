#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	int qtd_aluno, i;
	float *avl1;
	float *avl2;
	float media;
	
	setlocale(LC_ALL,"Portuguese");
	
	printf(">>> CALCULADOR DE MÉDIA DAS AVALIAÇÕES <<<\n\n");
	printf("Digite a quantidade de alunos em sala de aula:");
	scanf("%d",&qtd_aluno);
	
	avl1 = (float*)malloc(qtd_aluno*sizeof(float));{
	
		if(avl1==NULL){
			
			printf("Memória Insuficiente");
			
		}

	}
	
	avl2 = (float*)malloc(qtd_aluno*sizeof(float));{
	
		if(avl2==NULL){
			
			printf("Memória Insuficiente");
			
		}
	
	}
	
	
	printf("\nDigite as notas das duas avaliações de cada aluno\n");
	
	for(i=0;i<qtd_aluno;i++){
		
		printf("\n--- ALUNO %d ---\n",i+1);
		printf("1º Avl:");
		scanf("%f",&avl1[i]);
		printf("\n2º Avl:");
		scanf("%f",&avl2[i]);
		
	}
	
	printf("\n\n //// MÉDIA E MAIOR NOTA DE TODAS AS NOTAS DOS ALUNOS //// \n\n");
	
	for(i=0;i<qtd_aluno;i++){
		
		media = (avl1[i] + avl2[i])/2;
		
		printf("\n--- ALUNO %d ---\n",i+1);
		printf("Média:%.2f\n",media);
		
		if(avl1[i] > avl2[i]){
			
			printf("Maior Nota:%.2f\n",avl1[i]);
			
		} else{
			
			printf("Maior Nota:%.2f\n",avl2[i]);
			
		  }
		
	}
	
	
	free(avl1);
	free(avl2);
	
	avl1=NULL;
	avl2=NULL;
	return 0;
}
