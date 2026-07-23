#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
	
	int matricula;
	char nome[20];
	float avl1, avl2;
	
}Aluno;

Aluno aluno[3];


void ComparadorAvl1(Aluno aluno[]){
	
	float MaiorAvl1 = 0;
	int indc;
	
	for(int i = 0; i < 3; i++){
		
		if (aluno[i].avl1 > MaiorAvl1){
			
			MaiorAvl1 = aluno[i].avl1;
			indc = i;
			
		}
		
	}
	
	printf("O nome do aluno com a Maior Nota da Primeira Avaliação é %s com %.2f", aluno[indc].nome ,MaiorAvl1);
	
}


void ComparadorAvl2(Aluno aluno[]){
	
	float MaiorAvl2 = 0;
	int indc;
	
	for(int i = 0; i < 3; i++){
		
		if (aluno[i].avl2 > MaiorAvl2){
			
			MaiorAvl2 = aluno[i].avl2;
			indc = i;
			
		}
		
	}
	
	printf("O nome do aluno com a Maior Nota da Segunda Avaliação é %s com %.2f", aluno[indc].nome ,MaiorAvl2);
	
}


void ComparadorMedia(Aluno aluno[]){
	
	float MaiorMedia = 0;
	int indc;

	for(int i = 0; i < 3; i++){
		
		float media = (aluno[i].avl1 + aluno[i].avl2)/2;
		
		if (media > MaiorMedia){
			
			MaiorMedia = media;
			indc = i;
			
		}
		
	}
	
	printf("O nome do aluno com a Maior Média entre os outros é %s com %.2f", aluno[indc].nome, MaiorMedia);
	
}

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("<<< CADASTRO DOS ALUNOS >>>\n");
	
	for(int i = 0; i < 3; i++){
		
		printf("\n--- DADOS REQUISITADOS DO ALUNO %d ---\n\n", i + 1);
		
		printf("{ Matrícula:");
		scanf("%d",&aluno[i].matricula);
		
		printf("{ Nome:");
		scanf("%s",&aluno[i].nome);
		
		printf("{ Primeira Avaliação:");
		scanf("%f",&aluno[i].avl1);
		
		printf("{ Segunda Avaliação:");
		scanf("%f",&aluno[i].avl2);
		
	}
	
	int opcao;
	
	do{
	
		printf("\n\n<<< MENU DE INFORMAÇÕES >>>\n\n");
		printf("- Aperte o número de acordo com as opções\n");
		printf("1) Nome do aluno com a maior nota da Primeria Avaliação\n");
		printf("2) Nome do aluno com a maior nota da Segunda Avaliação\n");
		printf("3) Nome do aluno com a maior média geral\n");
		printf("4) Sair\n\n");
		
		printf("Opção:");
		scanf("%d",&opcao);
		
		switch(opcao){
			
			case 1:
				
				ComparadorAvl1(aluno);
				break;
				
				
			case 2:
					
				ComparadorAvl2(aluno);
				break;
					

				
			case 3:
					
				ComparadorMedia(aluno);
				break;
					
				
			
			case 4:
				
				break;
		}
	
	} while(opcao != 4);
	
	return 0;
	}
