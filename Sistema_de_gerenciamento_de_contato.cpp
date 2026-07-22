#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct no{
	
	char nome[30];
	char telefone[20];
	char email[30];
	
	struct no *direita;
	struct no *esquerda;
	
}NoArv;

//Felipe

NoArv* InserirContato(NoArv *raiz, char nome[], char email[], char telefone[]){
	
	if(raiz == NULL){
		NoArv *aux = (NoArv*)malloc(sizeof(NoArv));
		
		strcpy(aux->nome, nome);
		strcpy(aux->telefone,telefone);
		strcpy(aux->email, email);
		
		aux->direita = NULL;
		aux->esquerda = NULL;
		
		return aux;
	
	}else if(strcmp(nome, raiz->nome) < 0){
		raiz->esquerda = InserirContato(raiz->esquerda, nome, email, telefone);
		return raiz;
		
	}else if(strcmp(nome, raiz->nome) > 0){
		raiz->direita = InserirContato(raiz->direita, nome, email, telefone);
		return raiz;

	}
}


//Roberto
NoArv* buscarContato(NoArv *raiz, char nome[])
{
    if(raiz == NULL)
    {
        return NULL;
    }

    if(strcmp(nome, raiz->nome) == 0)
    {
        return raiz;
    }

    if(strcmp(nome, raiz->nome) < 0)
    {
        return buscarContato(raiz->esquerda, nome);
    }

    return buscarContato(raiz->direita, nome);
}

//Roberta
NoArv* minValueNo(NoArv *raiz) {

    NoArv *atual = raiz;

    while (atual != NULL && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }

    return atual;
}

NoArv* removerContato(NoArv *raiz, char nome[]){
	
	if(raiz == NULL){
		
		return NULL;
	}
	
	if(strcmp(nome, raiz->nome) < 0){
		raiz->esquerda = removerContato(raiz->esquerda, nome);
		
	}else if(strcmp(nome, raiz->nome) > 0){
		raiz->direita = removerContato(raiz->direita, nome);

	} else { 
        if (raiz->esquerda == NULL) 
        { 
            NoArv *aux = raiz->direita; 
            free(raiz); 
            return aux; 
        } 
        else if (raiz->direita == NULL) 
        { 
            NoArv *aux = raiz->esquerda; 
            free(raiz); 
            return aux; 
        } 
  
        NoArv *aux = minValueNo(raiz->direita); 
 
        strcpy(raiz->nome, aux->nome);
		strcpy(raiz->email, aux->email);
		strcpy(raiz->telefone, aux->telefone);

        raiz->direita = removerContato(raiz->direita, aux->nome); 
    } 
    return raiz; 
}

//Icaro
void listagemContato(NoArv *raiz) {
	
    if (raiz != NULL) {
        listagemContato(raiz->esquerda);
        printf(" Nome     : %s\n", raiz->nome);
        printf(" Telefone : %s", raiz->telefone);
        printf(" E-mail   : %s\n", raiz->email);
        printf("-----------------------------------------\n");
        listagemContato(raiz->direita);
    }
}

int main() {
	setlocale(LC_ALL,"Portuguese");
	
	char nome[30], email[30],telefone[20];
	int opcao = 0;
	
	NoArv *raiz = NULL;
	NoArv *contato = NULL;
	
	do{
		
	    printf("\n");
        printf("=========================================\n");
        printf("      SISTEMA  DE CONTATOS - ABB\n");
        printf("=========================================\n");
        printf(" [1] Inserir Contato\n");
        printf(" [2] Buscar Contato\n");
        printf(" [3] Remover Contato\n");
        printf(" [4] Listar Contatos\n");
        printf(" [5] Sair\n");
        printf("=========================================\n");
        printf(" Escolha uma opcao: ");
		
		scanf("%d",&opcao);
        getchar();
        
		switch(opcao){
			
			case 1:
				printf("\n");
                printf("=========================================\n");
                printf("        CADASTRO DE CONTATO\n");
                printf("=========================================\n");

                printf(" Nome     : ");
                fgets(nome, 30, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf(" Telefone : ");
                fgets(telefone, 20,stdin);
                

                printf(" E-mail   : ");
                scanf("%s", email);
                getchar();
				
				raiz = InserirContato(raiz, nome, email, telefone); 
                printf("\n");
                printf("=========================================\n");
                printf("   CONTATO CADASTRADO COM SUCESSO!\n");
                printf("=========================================\n");
                
				break;
				
			case 2: {
                printf("\n");
                printf("=========================================\n");
                printf("          BUSCAR CONTATO\n");
                printf("=========================================\n");
                printf(" Nome: ");
                fgets(nome,30,stdin);
                nome[strcspn(nome, "\n")] = '\0';
                contato = buscarContato(raiz, nome);
                
                if(contato != NULL){
                    printf("\n");
                    printf("=========================================\n");
                    printf("        CONTATO ENCONTRADO\n");
                    printf("=========================================\n");
                    printf(" Nome     : %s\n", contato->nome);
                    printf(" Telefone : %s", contato->telefone);
                    printf(" E-mail   : %s\n", contato->email);
                    printf("=========================================\n");
                }else{
                  printf("\n");
                  printf("=========================================\n");
                  printf("          CONTATO NAO ENCONTRADO\n");
                  printf("=========================================\n");
                  printf(" Nenhum contato com esse nome foi\n");
                  printf(" localizado no sistema.\n");
                  printf("=========================================\n");
                }
                break;
			}
            case 3: { 
                printf("\n");
                printf("=========================================\n");
                printf("           REMOVER CONTATO\n");
                printf("=========================================\n");
                printf(" Nome: ");
                fgets(nome,30,stdin);
                nome[strcspn(nome, "\n")] = '\0';
				contato = buscarContato(raiz, nome);
                
                if(contato != NULL){
                	raiz = removerContato(raiz, nome);
                	
                    printf("\n");
                    printf("=========================================\n");
                    printf("     CONTATO ENCONTRADO E  REMOVIDO\n");
                    printf("=========================================\n");
                  
                }else{
                  printf("\n");
                  printf("=========================================\n");
                  printf("          CONTATO NAO ENCONTRADO\n");
                  printf("=========================================\n");
                  printf(" Nenhum contato com esse nome foi\n");
                  printf(" localizado no sistema.\n");
                  printf("=========================================\n");
                }
            	break;
			}
            case 4:
                printf("\n");
                printf("=========================================\n");
                printf("          LISTAGEM DE CONTATOS\n");
                printf("=========================================\n");
                if (raiz == NULL) {
                    printf(" A agenda de contatos esta vazia.\n");
                } else {
                    listagemContato(raiz);
                }
                printf("=========================================\n");
                break;
                
            case 5:
            	printf("\n");
                printf("=========================================\n");
                printf("\t\tSAINDO...\n");
                printf("=========================================\n");
                break;
                
		}
		
		
		
	}while(opcao != 5);
	
	return 0;
}
