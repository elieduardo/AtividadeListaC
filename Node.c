#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

Node* cria() {
    Node* cabeca = NULL;
    cabeca = (Node*) malloc(sizeof(Node));
    if (cabeca == NULL) {
        return 1;
    }
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
		printf("Entrou!");
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
	while( atual->proximo != NULL){
		//Verifa se a info do proximo é igual ao valor recebido
        if(atual->proximo->info == value){
        	free(atual->proximo);		
        	atual->proximo = atual->proximo->proximo;
		}
		atual = atual->proximo;		
    }	
}


void imprimir(Node* cabeca){	
    Node* atual = cabeca;
    while( atual != NULL){
        printf("valor: %d\n", atual->info);
        atual = atual->proximo;
    }
}
