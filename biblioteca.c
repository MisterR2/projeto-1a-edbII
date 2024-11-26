#include "biblioteca.h"

No* inicializar_arvore() {
    return NULL;
}

No* criar_no(Livro livro) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no) {
        novo_no->livro = livro;
        novo_no->esquerda = NULL;
        novo_no->direita = NULL;
    }
    return novo_no;
}

void inserir_livro(No** raiz, Livro livro) {
    if (*raiz == NULL) {
        *raiz = criar_no(livro);
    } else if (livro.codigo < (*raiz)->livro.codigo) {
        inserir_livro(&(*raiz)->esquerda, livro);
    } else if (livro.codigo > (*raiz)->livro.codigo) {
        inserir_livro(&(*raiz)->direita, livro);
    } else {
        printf("Livro com código %d já existe!\n", livro.codigo);
    }
}

void buscar_por_genero(No* raiz, const char* genero) {
    if (raiz) {
        buscar_por_genero(raiz->esquerda, genero);
        if (strcasecmp(raiz->livro.genero, genero) == 0) {
            printf("\nCódigo: %d, Título: %s, Autor: %s, Ano: %d, Editora: %s, Páginas: %d\n",
                   raiz->livro.codigo, raiz->livro.titulo, raiz->livro.autor, 
                   raiz->livro.ano, raiz->livro.editora, raiz->livro.numero_paginas);
        }
        buscar_por_genero(raiz->direita, genero);
    }
}

No* carregar_livros(const char* nome_arquivo, No* raiz) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return raiz;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo)) {
        Livro livro;
        sscanf(linha, "%d,%99[^,],%99[^,],%49[^,],%d,%99[^,],%d",
               &livro.codigo, livro.titulo, livro.autor, livro.genero,
               &livro.ano, livro.editora, &livro.numero_paginas);
        inserir_livro(&raiz, livro);
    }

    fclose(arquivo);
    return raiz;
}


void exibir_arvore(No* raiz) {
    if (raiz != NULL) {
        exibir_arvore(raiz->esquerda); // Exibe subárvore esquerda
        printf("\nCódigo: %d, Título: %s, Autor: %s, Gênero: %s, Ano: %d, Editora: %s, Páginas: %d\n",
               raiz->livro.codigo, raiz->livro.titulo, raiz->livro.autor, 
               raiz->livro.genero, raiz->livro.ano, raiz->livro.editora, 
               raiz->livro.numero_paginas);
        exibir_arvore(raiz->direita);  // Exibe subárvore direita
    }
}


void liberar_arvore(No* raiz) {
    if (raiz) {
        liberar_arvore(raiz->esquerda);
        liberar_arvore(raiz->direita);
        free(raiz);
    }
}
