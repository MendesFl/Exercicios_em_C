#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct{
	char nome[30];
	int idade;
}Dados; 

typedef struct no{
	Dados pessoa;
	struct no *proximo;
}No;

typedef struct{
	No *inicio, *fim;
	int tam;
}Fila;

void init(Fila *f){
	f->fim = f->inicio = NULL;
	f->tam = 0;
}

void Enfileirar(Fila *f, char nome[], int idade){

    No *novo = (No*) malloc(sizeof(No));

    if(novo == NULL){
        printf("Erro de alocacao!\n");
        return;
    }

    strcpy(novo->pessoa.nome, nome);
    novo->pessoa.idade = idade;
    novo->proximo = NULL;

    // fila vazia
    if(f->inicio == NULL){
        f->inicio = novo;
        f->fim = novo;
    }
	else if(idade >= 60){

        if(f->inicio->pessoa.idade < 60){
            novo->proximo = f->inicio;
            f->inicio = novo;
        }
        else{
            No *aux = f->inicio;

            while(aux->proximo != NULL &&
                  aux->proximo->pessoa.idade >= 60){
                aux = aux->proximo;
            }

            novo->proximo = aux->proximo;
            aux->proximo = novo;

            if(novo->proximo == NULL)
                f->fim = novo;
        }
    }else{
        f->fim->proximo = novo;
        f->fim = novo;
    }

    f->tam++;
}
void Desenfileirar(Fila *f, char removido[]){
	if(f->inicio == NULL){
		printf("Atenção! A fila está Vazia");
		return;
	}
	
	No *temp = f->inicio;	
	f->inicio = f->inicio->proximo;
	
	if(f->inicio == NULL){
		f->fim = NULL;
	}
	
	strcpy(removido,temp->pessoa.nome);
	
	free(temp);
	f->tam--;
}

void ImprimirFila(Fila *f){

    int posicao = 1;

    if(f->inicio == NULL){
        printf("Atenção! A fila está vazia.\n");
        return;
    }

    No *temp = f->inicio;

    while(temp != NULL){

        printf("\n%dº paciente:\n", posicao);
        printf("Nome Completo: %s\n", temp->pessoa.nome);
        printf("Idade: %d\n", temp->pessoa.idade);

        temp = temp->proximo;
        posicao++;
    }
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	Fila pacientes;
	char nome1[30] = "Ana luiza Pereira";
	char nome2[30] = "Marcos Antonio Silva";
	char nome3[30] = "José Diaz de Souza";
	char nome[30];
	int idade, op;
	
	init(&pacientes);
	Enfileirar(&pacientes, nome1, 27);
	Enfileirar(&pacientes, nome2, 56);
	Enfileirar(&pacientes, nome3, 34);

	do{	

		printf("\t===== FILA DE ATENDIMENTO MÉDICO =====\n\n");
		printf("<<< Menu de opções >>>\n\n0 > Sair\n1 > Enfileirar\n2 > Remover da Fila\n3 > Imprimir Fila\n");
		
		printf("\nopcão:");
		scanf("%d", &op);
		getchar();
	
		switch(op){
			case 1:
				printf("\n== Aba de registro ==\nDigite o nome do paciente: ");
				fgets(nome, 30, stdin);
				printf("Digite a idade: ");
				scanf("%d", &idade);
				Enfileirar(&pacientes, nome, idade);
				system("cls");
				break;
				
			case 2:
				Desenfileirar(&pacientes, nome);
				printf("Atendimento do paciente realizado: %s\n\n", nome);
				break;
				
			case 3:
				ImprimirFila(&pacientes);
				printf("\n\n");
				break;
		}
	}while(op != 0);
	
	return 0;
}


