#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

int main()
{
    // LISTA CRIADA VAZIA
    Node* head = cria();
    head->info = 0;
    head->proximo = NULL;

    adicionaAoFinal(head, 1);
    adicionaAoFinal(head, 5);
    adicionaAoFinal(head, 2);
    adicionaAoFinal(head, 4);

    //imprimir(head);
    adicionaOrdenado(head, 3);
    imprimir(head);
    
    //removeEscolhido
	removeDoFinal(head);
	imprimir(head);

    return 0;
}

