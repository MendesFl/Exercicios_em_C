#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char j1, j2;
char m[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void Jogadas(){
	
	int i, j;	
	char jogada1;
	char jogada2;
	
	printf("\t%c | %c | %c\n", m[0][0], m[0][1],m[0][2]);
	printf("\t%c | %c | %c\n", m[1][0], m[1][1],m[1][2]);
	printf("\t%c | %c | %c\n", m[2][0], m[2][1],m[2][2]);
	
	printf("\nJogada do j1 = ");
	scanf(" %c",&jogada1);
	
	for(i = 0; i < 3; i ++){
		for(j = 0; j < 3; j ++){
			
			if(jogada1 == m[i][j]){
				
				m[i][j] = j1;
				
				printf("\n");
				
				printf("\t%c | %c | %c\n", m[0][0], m[0][1],m[0][2]);
				printf("\t%c | %c | %c\n", m[1][0], m[1][1],m[1][2]);
				printf("\t%c | %c | %c\n", m[2][0], m[2][1],m[2][2]);
	
				printf("\nJogada do j2 = ");
				scanf(" %c",&jogada2);
				
			}
			
		}
	}
	
}

void DefinirJogador(){
	
	if(j1 == 'x'){
		
		j2 = 'o';
		
	}else{
		
		if(j1 == 'o'){
			
			j2 = 'x';
			
		}
		
	}
	
}

void MostrarTabuleiro(){
	
	printf("\t%c | %c | %c\n", m[0][0], m[0][1],m[0][2]);
	printf("\t%c | %c | %c\n", m[1][0], m[1][1],m[1][2]);
	printf("\t%c | %c | %c\n", m[2][0], m[2][1],m[2][2]);
}

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("<<< JOGO DA VELHA >>>\n\n");
	printf("- REGRAS PARA JOGAR:\n");
	printf("1) Haverá dois jogadores,o primeiro jogador poderá escolher um símbolo (X ou O)\n");
	printf("2) Para preencher os espaços no quadro deve seguir o teclado numérico:\n\n");
	printf("\t1 | 2 | 3         x | o | o\n");
	printf("\t4 | 5 | 6  ---->  x | x | o\n");
	printf("\t7 | 8 | 9         o | o | x\n\n");
	printf("3) Em caso de empate, o jogo reiniciará até um vencedor ser decidido\n");
		
	printf("\n-----------------------------------------------------------------------------------\n");
	
	printf("\nJogador 1 vai ficar com ? (X ou O) = ");
	scanf("%c",&j1);
	
	DefinirJogador();
	
	printf("\n");
	
	Jogadas();
	
	return 0;
}



