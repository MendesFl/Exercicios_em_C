#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int ajusteSwitch(int sal){
	if(sal > 0 && sal <=1400){
		return 1;
	}
	if(sal > 1400 && sal <=1700){
		return 2;
	}
	if(sal > 1700 && sal <=10000){
		return 3;
	}
	if(sal > 10000 && sal <=18000){
		return 4;
	}
	if(sal > 18000 && sal <=25000){
		return 5;
	}
	if(sal > 25000){
		return 6;
	}
	
}

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	int sal;
	
	printf("\t== REAJUSTE SALARIAL DE ACORDO COM A TABELA ABAIXO ==\n\n");
	printf("  SALÁRIO ATUAL         ÍNDICE DE AUMENTO\n");
	printf(">0     e <= R$1400   |        15%%\n");
	printf(">1400  e <= R$1700   |        12%%\n");
	printf(">1700  e <= R$10000  |        10%%\n");
	printf(">10000 e <= R$18000  |         7%%\n");
	printf(">18000 e <= R$25000  |         4%%\n");
	printf("Acima de R$25000     |     sem aumento\n");

	int escolha = 1;

	do{
		printf("\n-> Qual o valor atual do seu salário ?\n");
		scanf("%d", &sal);
	
		int valor = ajusteSwitch(sal);
	
		switch(valor){
			case 1:
				sal = sal*1.15;
				printf("\n:Seu novo salário é %d", sal);
				break;
			case 2:
				sal = sal*1.12;
				printf("\n:Seu novo salário é %d", sal);
				break;
			case 3:
				sal = sal*1.10;
				printf("\n:Seu novo salário é %d", sal);
				break;
			case 4:
				sal = sal*1.07;
				printf("\n:Seu novo salário é %d", sal);
				break;
			case 5:
				sal = sal*1.04;
				printf("\n:Seu novo salário é %d", sal);
				break;
			case 6:
				printf("\n:Não houve aumento");
				break;
		}
	
		printf("\n\nContinuar ? (S-1/N-0)\n");
		scanf("%d",&escolha);
		
	}while(escolha != 0);
	
	return 0;
}
