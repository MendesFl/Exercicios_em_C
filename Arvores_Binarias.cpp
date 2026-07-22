#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef struct no{
	int valor;
	struct no *direita;
	struct no *esquerda;
}NoArvore;

/* método que usa retorno e usa recursividade

NoArvore* inserir_versao_1(NoArvore *raiz, int num){
	
	if(raiz == NULL){
		NoArvore *aux = (NoArvore*)malloc(sizeof(NoArvore));
		aux->valor = num;
		aux->direita = NULL;
		aux->esquerda = NULL;
		
		return aux;
		
	}else if(num < raiz->valor){
		raiz->esquerda = inserir_versao_1(raiz->esquerda, num);
		return raiz;
		
	}else if(num > raiz->valor){
		raiz->direita = inserir_versao_1(raiz->direita, num);
		return raiz;
	}

}

*/

/* método que não usa retorno mas possui recursividade */

void inserir_versao_2(NoArvore **raiz, int num){
	if(*raiz == NULL){
		*raiz = (NoArvore*)malloc(sizeof(NoArvore));
		(*raiz)->valor = num;
		(*raiz)->esquerda = NULL;
		(*raiz)->direita = NULL;
		
	}else if(num < (*raiz)->valor){
		inserir_versao_2(&((*raiz)->esquerda), num);
		
	}else if(num > (*raiz)->valor){
		inserir_versao_2(&((*raiz)->direita), num);
	}
}

/*Maneira PRÉ-ORDEM*/

void imprimir_versao_1(NoArvore *raiz){
	if(raiz != NULL){
		printf("%d ", raiz->valor);
		imprimir_versao_1(raiz->esquerda);
		imprimir_versao_1(raiz->direita);
	}
}

/*Maneira ordenada*/

void imprimir_versao_2(NoArvore *raiz){
	if(raiz != NULL){
		imprimir_versao_2(raiz->esquerda);
		printf("%d ", raiz->valor);
		imprimir_versao_2(raiz->direita);
	}
}

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	NoArvore *raiz = NULL;
	int opcao, valor;
	
	do{
		printf("\n\t0 - Sair\n\t1 - Inserir \n\t2 - Imprimir\n");
		scanf("%d",&opcao);
		
		switch(opcao){
			case 1:
				printf("\n\tDigite um valor a ser inserido: ");
				scanf("%d",&valor);
				//raiz = inserir_versao_1(raiz, valor); /*variavel que recebe o retorno*/
				inserir_versao_2(&raiz, valor);
				break;
			case 2:
				printf("\n\tPrimeira Versão(Desordenada):\n");
				imprimir_versao_1(raiz);
				printf("\n");
				printf("\n\tSegunda Versão(Ordenada):\n");
				imprimir_versao_2(raiz);
				printf("\n");
				break;
				default:
					if(opcao != 0){
						printf("\n\topcão inválida\n");
					}
		}
		
	}while(opcao != 0);
	
	return 0;
}
