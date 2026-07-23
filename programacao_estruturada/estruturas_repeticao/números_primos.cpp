#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	
	int n1, i, divisor = 0;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("== EXERCÍCIO 1 ==\n\n");
	printf("-> DIGITE UM NÚMERO PARA VERIFICAR SE É PRIMO OU NÃO\n");
	
	scanf("%d",&n1);
	
	for(i = 1; i <= n1; i++){
		
		if(n1%i == 0){
			
			divisor++;
			
		}	
	
	}
	
	if(divisor == 2){
		printf("é primo");
		
	}else{
		printf("Não é primo");
	}
	
	return 0;
}
