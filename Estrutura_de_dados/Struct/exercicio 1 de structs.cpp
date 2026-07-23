#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
	
	int inscricao, idade, categoria;
	char nome[50];
	
}competidor;

competidor compt1 = {200, 20, 1,"Marcelo"};
competidor compt2 = {201, 17, 3,"Davi"};
competidor compt3 = {202, 19, 5,"Gabriela"};

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("--- DADOS DOS COMPETIDORES DE NATA��O ---\n\n");
	printf("--- Competidor 1:\n\n");
	printf("-> Inscri��o:%d\n", compt1.inscricao);
	printf("-> Idade:%d\n", compt1.idade);
	printf("-> Categoria:%d\n", compt1.categoria);
	printf("-> Nome:%s\n\n", compt1.nome);
	
	printf("--- Competidor 2:\n\n");
	printf("-> Inscri��o:%d\n", compt2.inscricao);
	printf("-> Idade:%d\n", compt2.idade);
	printf("-> Categoria:%d\n", compt2.categoria);
	printf("-> Nome:%s\n\n", compt2.nome);	
	
	printf("--- Competidor 3:\n\n");
	printf("-> Inscri��o:%d\n", compt3.inscricao);
	printf("-> Idade:%d\n", compt3.idade);
	printf("-> Categoria:%d\n", compt3.categoria);
	printf("-> Nome:%s\n\n", compt3.nome);	
	
	return 0;
}
