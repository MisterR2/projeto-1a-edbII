#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

No* criar_no(int valor);
No* inserir(No* raiz, int valor);
No* buscar(No* raiz, int valor);
No* encontrar_minimo(No* raiz);
void exibir_em_ordem(No* raiz);

#endif // ARVORE_H
