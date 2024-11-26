#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

void exibir_menu() {
    printf("\n=== Gerenciador de Biblioteca ===\n");
    printf("1. Carregar livros de um arquivo CSV\n");
    printf("2. Inserir um novo livro\n");
    printf("3. Buscar livros por gênero\n");
    printf("4. Exibir todos os livros\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    No* raiz = inicializar_arvore();
    int opcao;
    char nome_arquivo[100];
    
    do {
        exibir_menu();
        scanf("%d", &opcao);
        getchar(); // Consumir o caractere de nova linha após a opção

        switch (opcao) {
            case 1:
                printf("Digite o nome do arquivo CSV: ");
                scanf("%99s", nome_arquivo);
                raiz = carregar_livros(nome_arquivo, raiz);
                printf("Livros carregados com sucesso!\n");
                break;

            case 2: {
                Livro novo_livro;
                
                printf("Digite o código do livro: ");
                if (scanf("%d", &novo_livro.codigo) != 1) {
                    printf("Código inválido! Insira um número inteiro.\n");
                    while (getchar() != '\n');
                    break;
                }
                getchar(); // Consumir nova linha

                printf("Digite o título do livro: ");
                fgets(novo_livro.titulo, sizeof(novo_livro.titulo), stdin);
                novo_livro.titulo[strcspn(novo_livro.titulo, "\n")] = '\0';

                printf("Digite o autor do livro: ");
                fgets(novo_livro.autor, sizeof(novo_livro.autor), stdin);
                novo_livro.autor[strcspn(novo_livro.autor, "\n")] = '\0';

                printf("Digite o gênero do livro: ");
                fgets(novo_livro.genero, sizeof(novo_livro.genero), stdin);
                novo_livro.genero[strcspn(novo_livro.genero, "\n")] = '\0';

                printf("Digite o ano de publicação: ");
                if (scanf("%d", &novo_livro.ano) != 1) {
                    printf("Ano inválido! Insira um número inteiro.\n");
                    while (getchar() != '\n');
                    break;
                }
                getchar();

                printf("Digite a editora do livro: ");
                fgets(novo_livro.editora, sizeof(novo_livro.editora), stdin);
                novo_livro.editora[strcspn(novo_livro.editora, "\n")] = '\0';

                printf("Digite o número de páginas: ");
                if (scanf("%d", &novo_livro.numero_paginas) != 1) {
                    printf("Número de páginas inválido! Insira um número inteiro.\n");
                    while (getchar() != '\n');
                    break;
                }

                inserir_livro(&raiz, novo_livro);
                printf("Livro inserido com sucesso!\n");
                break;
            }

            case 3: {
                char genero[50];
                printf("Digite o gênero a buscar: ");
                scanf("%49s", genero);
                printf("Livros do gênero %s:\n", genero);
                buscar_por_genero(raiz, genero);
                break;
            }

            case 4:
                printf("Exibindo todos os livros:\n");
                exibir_arvore(raiz);
                break;

            case 5:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    liberar_arvore(raiz);
    return 0;
    printf("Hello, World!\n");
    
    return 0;
}