#include <stdio.h>

//tamanho do tabuleiro
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

// inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    // Preenche o tabuleiro com água (valor 0)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;  // 0 representa água
        }
    }
}

//posicionar um navio horizontalmente no tabuleiro
// O navio é representado pelo valor 3
void posicionarNavioHorizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe na posição dada
    if (coluna + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linha][coluna + i] = 3;  // 3 representa parte do navio
        }
    } else {
        printf("Posição horizontal inválida para o navio.\n");
    }
}

//  posicionando um navio verticalmente no tabuleiro
void posicionarNavioVertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe na posição dada
    if (linha + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = 3;  
        }
    } else {
        printf("Posição vertical inválida para o navio.\n");
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);  
        }
        printf("\n"); 
    }
}

int main() {
    // Inicializando o tabuleiro
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Definindo as coordenadas para os navios
    int linhaNavioHorizontal = 2, colunaNavioHorizontal = 3; 
    int linhaNavioVertical = 5, colunaNavioVertical = 6; 

    // Posicionando os navios no tabuleiro
    posicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal);
    posicionarNavioVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical);

    // Exibição
    exibirTabuleiro(tabuleiro);

    return 0;
}