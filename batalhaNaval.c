#include <stdio.h>

int main() {
    // Declaração da matriz do tabuleiro (10x10)
    int tabuleiro[10][10];
    int i, j;

    // Inicializa todas as posições com 0 (água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Tamanho fixo dos navios: 3 posições

    // Posiciona navio horizontal (linha 2, coluna 4 até 6)
    int linha_h = 2;
    int coluna_h = 4;

    if (coluna_h + 3 <= 10) {
        for (i = 0; i < 3; i++) {
            tabuleiro[linha_h][coluna_h + i] = 3;
        }
    } else {
        printf("Erro: navio horizontal fora do tabuleiro.\n");
        return 1;
    }

    // Posiciona navio vertical (linha 5 até 7, coluna 7)
    int linha_v = 5;
    int coluna_v = 7;

    int sobreposicao = 0;

    if (linha_v + 3 <= 10) {
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linha_v + i][coluna_v] != 0) {
                sobreposicao = 1;
            }
        }

        if (sobreposicao == 0) {
            for (i = 0; i < 3; i++) {
                tabuleiro[linha_v + i][coluna_v] = 3;
            }
        } else {
            printf("Erro: navios sobrepostos.\n");
            return 1;
        }
    } else {
        printf("Erro: navio vertical fora do tabuleiro.\n");
        return 1;
    }

    // Imprime o tabuleiro no console
    printf("Tabuleiro:\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}