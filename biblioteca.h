#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef struct Livro {
    int codigo;
    char titulo[100];
    char autor[100];
    char genero[50];
    int ano;
    char editora[100];
    int numero_paginas;
} Livro;

typedef struct No {
    Livro livro;
    struct No* esquerda;
    struct No* direita;
} No;

No* inicializar_arvore();
void inserir_livro(No** raiz, Livro livro);
void buscar_por_genero(No* raiz, const char* genero);
No* carregar_livros(const char* nome_arquivo, No* raiz);
void exibir_arvore(No* raiz);
void liberar_arvore(No* raiz);

#endif // BIBLIOTECA_H
