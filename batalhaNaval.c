#include <stdio.h>

// Definindo o tamanho do tabuleiro
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    // Preenche o tabuleiro com água (valor 0)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; 
        }
    }
}

// Função para posicionar um navio horizontalmente no tabuleiro
void posicionarNavioHorizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe na posição dada
    if (coluna + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linha][coluna + i] = 3; 
        }
    } else {
        printf("Posição horizontal inválida para o navio.\n");
    }
}

// Função para posicionar um navio verticalmente no tabuleiro
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

// exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("0 ");  // Água
            } else if (tabuleiro[i][j] == 3) {
                printf("3 ");  // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf("5 ");  // Área afetada pela habilidade
            }
        }
        printf("\n");
    }
}

//aplicar a habilidade do Cone
void aplicarCone(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int origemX, int origemY) {
    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cone[i][j] == 1) {
                int x = origemX + i - 2;
                int y = origemY + j - 2;
                if (x >= 0 && x < TAM_TABULEIRO && y >= 0 && y < TAM_TABULEIRO) {
                    tabuleiro[x][y] = 5;
                }
            }
        }
    }
}

//aplicar a habilidade da Cruz
void aplicarCruz(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int origemX, int origemY) {
    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cruz[i][j] == 1) {
                int x = origemX + i - 2;
                int y = origemY + j - 2;
                if (x >= 0 && x < TAM_TABULEIRO && y >= 0 && y < TAM_TABULEIRO) {
                    tabuleiro[x][y] = 5;
                }
            }
        }
    }
}

// aplicar a habilidade do Octaedro
void aplicarOctaedro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int origemX, int origemY) {
    int octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (octaedro[i][j] == 1) {
                int x = origemX + i - 2;
                int y = origemY + j - 2;
                if (x >= 0 && x < TAM_TABULEIRO && y >= 0 && y < TAM_TABULEIRO) {
                    tabuleiro[x][y] = 5;
                }
            }
        }
    }
}

int main() {
   
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Definindo as coordenadas para os navios
    int linhaNavioHorizontal = 2, colunaNavioHorizontal = 3; 
    int linhaNavioVertical = 5, colunaNavioVertical = 6;

    // Posicionando os navios no tabuleiro
    posicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal);
    posicionarNavioVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical);

    // Aplicando habilidades especiais
    aplicarCone(tabuleiro, 2, 3); 
    aplicarCruz(tabuleiro, 5, 5);
    aplicarOctaedro(tabuleiro, 7, 2); 

    exibirTabuleiro(tabuleiro);

    return 0;
}