#include <stdio.h>

int main() {
    // Declaração da matriz 10x10 do tabuleiro
    int tabuleiro[10][10];
    int i, j;

    // Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Tamanho fixo dos navios: 3
    int tamanho_navio = 3;

    // Posiciona navio horizontalmente (linha 1, colunas 2 a 4)
    int linha_h = 1;
    int coluna_h = 2;
    int sobreposicao = 0;

    if (coluna_h + tamanho_navio <= 10) {
        for (i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[linha_h][coluna_h + i] != 0) {
                sobreposicao = 1;
            }
        }
        if (sobreposicao == 0) {
            for (i = 0; i < tamanho_navio; i++) {
                tabuleiro[linha_h][coluna_h + i] = 3;
            }
        }
    }

    // Posiciona navio verticalmente (coluna 6, linhas 4 a 6)
    int linha_v = 4;
    int coluna_v = 6;
    sobreposicao = 0;

    if (linha_v + tamanho_navio <= 10) {
        for (i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[linha_v + i][coluna_v] != 0) {
                sobreposicao = 1;
            }
        }
        if (sobreposicao == 0) {
            for (i = 0; i < tamanho_navio; i++) {
                tabuleiro[linha_v + i][coluna_v] = 3;
            }
        }
    }

    // Posiciona navio na diagonal principal (de cima para baixo)
    int linha_d1 = 0;
    int coluna_d1 = 0;
    sobreposicao = 0;

    if (linha_d1 + tamanho_navio <= 10 && coluna_d1 + tamanho_navio <= 10) {
        for (i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[linha_d1 + i][coluna_d1 + i] != 0) {
                sobreposicao = 1;
            }
        }
        if (sobreposicao == 0) {
            for (i = 0; i < tamanho_navio; i++) {
                tabuleiro[linha_d1 + i][coluna_d1 + i] = 3;
            }
        }
    }

    // Posiciona navio na diagonal secundária (de cima para baixo invertido)
    int linha_d2 = 0;
    int coluna_d2 = 9;
    sobreposicao = 0;

    if (linha_d2 + tamanho_navio <= 10 && coluna_d2 - tamanho_navio + 1 >= 0) {
        for (i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[linha_d2 + i][coluna_d2 - i] != 0) {
                sobreposicao = 1;
            }
        }
        if (sobreposicao == 0) {
            for (i = 0; i < tamanho_navio; i++) {
                tabuleiro[linha_d2 + i][coluna_d2 - i] = 3;
            }
        }
    }

    // Exibe o tabuleiro
    printf("Tabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
