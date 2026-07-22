#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	int i, seq[5];
	int *ptr;
	
	printf("Digite uma sequência de números a seguir:\n");
	
	ptr = seq;
	
	for(i = 0; i < 5; i++){
		
		printf("%dº posição:", i + 1);
		scanf("%d",(ptr + i));
	
	}
	
	printf("\n>> Sequência Original <<\n\n");
	
	for(i = 0; i < 5; i++){
		
		printf("%d ",*(seq + i));
	
	}
	
	printf("\n\n>> Sequência Invertida <<\n\n");
	
	for(i = 4; i >= 0; i--){
		
		printf("%d ",*(seq + i));
	
	}
	
	return 0;
}
