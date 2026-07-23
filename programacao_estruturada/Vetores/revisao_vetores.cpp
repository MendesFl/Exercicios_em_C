#include <stdio.h>
#include <locale.h>

char palavra[10];

int main (){
	setlocale(LC_ALL,"Portuguese");
	
	while(1){
		
		int i = 0;
		int cont = 0;
	
		printf("Digite uma palavra de até 10 posições:");
		fgets(palavra,sizeof(palavra),stdin);
		
		if(palavra[0]=='x'||palavra[0]=='X'){
			printf("programa encerrado");
			break;
		}
	
		for(i=0;i<10;i++){
		
			if(palavra[i]=='a'||palavra[i]=='e'||palavra[i]=='i'||palavra[i]=='o'||palavra[i]=='u'){
			
			cont++;
			}
			
		}
	
		printf("A palavra %s possui %d vogais\n\n", palavra, cont);
	}
	
	return 0;
}
