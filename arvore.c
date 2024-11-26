#include "arvore.h"

No* criar_no(int valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;
    return novo_no;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criar_no(valor);
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;
}

No* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    }

    if (valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);
    } else {
        return buscar(raiz->direita, valor);
    }
}

No* encontrar_minimo(No* raiz) {
    while (raiz && raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}

void exibir_em_ordem(No* raiz) {
    if (raiz != NULL) {
        exibir_em_ordem(raiz->esquerda);
        printf("%d ", raiz->valor);
        exibir_em_ordem(raiz->direita);
    }
}
