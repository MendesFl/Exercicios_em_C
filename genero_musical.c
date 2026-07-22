#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct{
	
	char nome[15];
	int membros;
	char genero[15];
	int ranking;
	
}Dados;

void SelecionarRanking(Dados banda[], int i){
	
	int numero;
	
	printf("\n\n> Selecione a banda pelo ranking:");
	scanf("%d",&numero);
	
	for(i = 0; i < 5; i++){
		
		if(numero == banda[i].ranking){
			
			printf("\n*A banda com o ranking %d é %s", numero, banda[i]);
			break;
			
		}else{
			
			printf("\n*Não há nenhuma banda cadastrada com esse ranking");
			break;
			
		}
		
	}
}

void SelecionarNome(Dados banda[], int i){
	
	char Nome;
	
	printf("\n\n> Digite o nome da banda:");
	scanf("%s",Nome);
	
	for(i = 0; i < 5; i++){
		
		if(Nome == banda[i].nome){
			
			printf("\n- GÊNERO:%s",banda[i].genero);
			printf("\n- MEMBROS:%d",banda[i].membros);
			printf("\n- RANKING:%d",banda[i].ranking);
			
		}else{
			
			printf("\n*Não há nenhuma banda cadastrada com esse ranking");
			break;
		}
	}
}
void SelecionarGenero(Dados banda[], int i){

	char Genero;
	
	printf("\n\n> Digite o Genero da banda:");
	scanf("%s",Genero);
	
	for(i = 0; i < 5; i++){
		
		if(Genero == banda[i].nome){
			
			printf("\n- NOME:%s",banda[i].nome);
			printf("\n- MEMBROS:%d",banda[i].membros);
			printf("\n- RANKING:%d",banda[i].ranking);
			
		}else{
			
			printf("\n*Não há bandas cadastradas com esse ranking");
			break;
		}
	
	}
}

void TodasBandas(Dados banda[], int i){
	
	printf("\n\nINFORMAÇÕES DAS BANDAS:\n");
	
	for(i = 0; i < 5; i ++){
		printf("\n\n(BANDA %d)\n", i + 1);
		printf("\n- NOME:%s",banda[i].nome);
		printf("\n- GÊNERO:%s",banda[i].genero);
		printf("\n- MEMBROS:%d",banda[i].membros);
		printf("\n- RANKING:%d",banda[i].ranking);
	}
	
}

void CadastrarBandas(Dados banda[], int i){
	
	printf("\n> DIGITE OS DADOS DAS BANDAS ABAIXO PARA CADASTRAR:\n");
	
	for(i = 0; i < 5; i ++){
		printf("\n>>> BANDA %d <<<\n\n", i + 1);
		
		printf("- NOME:");
		scanf("%s",banda[i].nome);
		
		printf("- MEMBROS:");
		scanf("%d",&banda[i].membros);
		
		printf("- GÊNERO:");
		scanf("%s",banda[i].genero);
		
		printf("- RANKING(1º - 5º):");
		scanf("%d",&banda[i].ranking);
		
	}
	
}

int main() {
	int i, opcao;
	setlocale(LC_ALL,"Portuguese");
	Dados banda[5];
	
	while(opcao != 6){
		
		printf(">>MENU DE REGISTROS DAS BANDAS <<\n\n");
		printf("Selecione a opção conforme abaixo:\n\n");
		printf("1)Cadastrar Bandas\n");
		printf("2)Selecionar Ranking\n");
		printf("3)Selecionar Gênero Musical\n");
		printf("4)Selecionar Nome\n");
		printf("5)Listar bandas\n");
		printf("6)Encerrar\n\n");
		printf("Opção:");
		scanf("%d",&opcao);
	
		switch(opcao){
		
			case 1: 
			CadastrarBandas(banda, i);
			break;
		
			case 2:
			SelecionarRanking(banda, i);
			break;
		
			case 3:
			SelecionarGenero(banda, i);
			break;
		
			case 4:
			SelecionarNome(banda, i);
			break;
		
			case 5:
			TodasBandas(banda, i);
			break;
		
			default:
			printf("\n\nValor inválido!\n");
		}
		
	}
	
	return 0;
}
