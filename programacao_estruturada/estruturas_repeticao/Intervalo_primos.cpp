#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int VerificarPrimo(int i){
    if (num <= 1){
    	return 0;
	} 

    int i;
    int divisor = 0;
    
    for(i = 1; i <= num; i++){
        if(num % i == 0){
            divisor++;
        }   
    }
    
    if(divisor == 2){
        return 1; 
    } else {
        return 0; 
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    
    int n1, n2, i;
    
    printf("-> DIGITE DOIS NÚMEROS PARA VERIFICAR O INTERVALO ENTRE ELES\n");
    
    printf("Início: ");
    scanf("%d", &n1);
    
    printf("Fim: ");
    scanf("%d", &n2);
    
    printf("\nNúmeros primos no intervalo [%d, %d]:\n", n1, n2);
    
    for(i = n1; i <= n2; i++){
        
        if(VerificarPrimo(i)){
            printf("%d ", i);
        }
    }
        
    return 0;
}
