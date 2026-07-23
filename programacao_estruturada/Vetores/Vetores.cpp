#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (){
	setlocale(LC_ALL,"Portuguese");
	
	int Va = 10;
	int Vb = 20;
	int Vaux = NULL;
	
	printf("O valor da variável A antes da atribuição é %d e a variável B é %d \n", Va, Vb);
	
	Vaux = Va;
	Va = Vb;
	Vb = Vaux;
	
	printf("\nO valor da variável A após a atribuição é %d e a variável B é %d", Va, Vb);
	
	return 0;
}
