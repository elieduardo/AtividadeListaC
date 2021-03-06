#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

Node* cria() {
    Node* cabeca = NULL;
    cabeca = (Node*) malloc(sizeof(Node));
    
    return cabeca;
}

void adicionaAoInicio(Node* cabeca, int valor) {
    // CRIA NOVO NÓ
    Node* novoNodo = cria();
    novoNodo->info = valor;
    novoNodo->proximo = cabeca;

    cabeca = novoNodo;
}

void adicionaAoFinal(Node* cabeca, int valor) {
    // PERCORRE ATÉ O FINAL
    Node* atual = cabeca;
    while( atual->proximo != NULL){
        atual = atual->proximo;
    }

    // CRIA NOVO NÓ
    Node* novoNodo = cria();
    novoNodo->info = valor;
    novoNodo->proximo = NULL;

    // SETA O NOVO NÓ COMO ÚLTIMO
    atual->proximo = novoNodo;
}

int removeDoFinal(Node* cabeca){
    int valorRemovido = 0;
    // VERIFICA SE TEM ALGO NA LISTA
    if (cabeca->proximo == NULL) {
		printf("Nao existe conteudo para ser excluido.\n");
		return 1;
    }
    else if(cabeca->proximo == NULL){
    	valorRemovido = cabeca->info;		
		free(cabeca);
		
        cabeca = NULL;
		        	        
        return valorRemovido;
	}

    // PERCORRE ATÉ O FINAL
    Node* atual = cabeca;
    while( atual->proximo->proximo != NULL){
        atual = atual->proximo;
    }

    valorRemovido = atual->proximo->info;
    free(atual->proximo);
    atual->proximo = NULL;
    return valorRemovido;
}

void removeEscolhido(Node* cabeca, int value){
	// PERCORRE ATÉ O FINAL
    Node* atual = cabeca;
	while(atual->proximo != NULL){
		//Verifa se a info do proximo é igual ao valor recebido
        if(atual->proximo->info == value){
			Node* aux = atual->proximo; 
			atual->proximo = atual->proximo->proximo; 
			free(aux);
		}
		atual = atual->proximo;		
    }	
}


void imprimir(Node* cabeca){	
    Node* atual = cabeca;
    if (cabeca->proximo == NULL) {
		printf("Nao existe valor para ser impresso.\n");
		return;
	}
    
    while( atual != NULL){
        printf("valor: %d\n", atual->info);
        atual = atual->proximo;
    }
}

void adicionaOrdenado(Node* head, int value) {
    Node* atual = head;
    while (atual != NULL) {
        if (value < atual->info) {
            Node* cloneAtual = cria();
            cloneAtual->info = atual->info;
            cloneAtual->proximo = atual->proximo;
            
            atual->proximo = cloneAtual;
            atual->info = value;

            return;
        }

        atual = atual->proximo;
    }

    adicionaAoFinal(head, value);
}
