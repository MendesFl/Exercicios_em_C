#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(){
	
	int cont = 0;
	char String[10], Sub_string[5], *ptr1, *ptr2;
	
	setlocale(LC_ALL,"Portuguese");
	
	ptr1 = String;
	ptr2 = Sub_string;
	
	printf("<<< EXERCÍCIO 3 DE PONTEIROS >>>\n\n");
	
	printf("Digite uma sequência de caracteres para a String (MÁX 10)\n");
	scanf("%s",&String);
	
	printf("Digite uma sequência de caracteres para a Segunda String (MÁX 5)\n");
	scanf("%s",&Sub_string);
	
	for(int j = 0; j < 10; j++){
		for(int i = 0; i < 5; i++){
			
			*(ptr2 + i);	
			*(ptr1 + j + i);
			
			if(*(ptr2 + i) == *(ptr1 + j + i)){
				
				cont ++;
				
			}else {
				
				cont = 0;
				break;
				
			}
				
		}	
		
			if(cont >= 4){
				break;
			}
	}	

	if (cont >= 4){
		
		printf("A segunda String é uma SubString da Primeira.");
		
	}else {
		
		printf("A segunda String não faz parte da Primeira.");
		
	}
	
	return 0;
}
