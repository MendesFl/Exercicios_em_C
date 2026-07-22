#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
	int dia, mes, ano;
}Data;

void ConverterDias(Data data[]){
	
	int Dias_dt_recente;
	int Dias_dt_antigo;
		
	Dias_dt_recente = data[0].dia + (data[0].mes * 30) + (data[0].ano * 360);
	Dias_dt_antigo = data[1].dia + (data[1].mes * 30) + (data[1].ano * 360);

	
	
	printf("\n\nA diferença entre os dias da data mais recente e a mais antiga é %d", Dias_dt_recente - Dias_dt_antigo);
	
}

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	Data data[2];
	
	printf("<<< EXERCICIO 4 DE STRUCT >>>\n\n");
	
	printf("--- Digite a data mais recente (dd/mm/aaaa)---\n");
	printf("{DIA:");
	scanf("%d",&data[0].dia);
	printf("{MÊS:");
	scanf("%d",&data[0].mes);
	printf("{ANO:");
	scanf("%d",&data[0].ano);
	
	printf("\n\n--- Digite a data mais antiga (dd/mm/aaaa)---\n");
	printf("{DIA:");
	scanf("%d",&data[1].dia);
	printf("{MÊS:");
	scanf("%d",&data[1].mes);
	printf("{ANO:");
	scanf("%d",&data[1].ano);
	
	ConverterDias(data);
	
	return 0;
}
