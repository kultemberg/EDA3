#include<stdio.h>
#include<stdlib.h>
#include "funcoes.h"

int main()
{
    TNo *lista;
    lista = NULL;
    lista = add(lista,2,10);
    lista = addFinal(lista,3,20);
    lista = add(lista,1,0);
    printLE(lista);
    printf("%d\n",buscaValor(lista,2));
    lista = removeNo(lista,2);
    printf("Soma LE: %d",somaLE(lista));
}
