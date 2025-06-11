#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    // Inicializa o tabuleiro com água (0)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posiciona navios no tabuleiro (valor 3)
    // Navio horizontal
    for (i = 0; i < 3; i++) {
        tabuleiro[2][2 + i] = 3;
    }
    // Navio vertical
    for (i = 0; i < 3; i++) {
        tabuleiro[5 + i][5] = 3;
    }
    // Diagonal principal
    for (i = 0; i < 3; i++) {
        tabuleiro[1 + i][1 + i] = 3;
    }
    // Diagonal secundária
    for (i = 0; i < 3; i++) {
        tabuleiro[1 + i][7 - i] = 3;
    }

    // MATRIZES DE HABILIDADE (tamanho 5x5)
    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    // Inicializa todas com 0
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            cone[i][j] = 0;
            cruz[i][j] = 0;
            octaedro[i][j] = 0;
        }
    }

    // Matriz Cone (aponta para baixo, centro no topo)
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (j >= 2 - i && j <= 2 + i) {
                cone[i][j] = 1;
            }
        }
    }

    // Matriz Cruz (em forma de +)
    for (i = 0; i < 5; i++) {
        cruz[i][2] = 1; // coluna central
        cruz[2][i] = 1; // linha central
    }

    // Matriz Octaedro (losango)
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if ((i + j >= 2) && (i + j <= 6) && (i - j <= 2) && (j - i <= 2)) {
                octaedro[i][j] = 1;
            }
        }
    }

    // Função para aplicar habilidade ao tabuleiro
    // origem_linha e origem_coluna são o centro onde será aplicada
    int origem_linha, origem_coluna;

    // Aplica Cone (centro no topo da matriz cone)
    origem_linha = 1;
    origem_coluna = 4;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int linha_tab = origem_linha + i;
            int coluna_tab = origem_coluna - 2 + j;
            if (linha_tab >= 0 && linha_tab < 10 && coluna_tab >= 0 && coluna_tab < 10) {
                if (cone[i][j] == 1 && tabuleiro[linha_tab][coluna_tab] == 0) {
                    tabuleiro[linha_tab][coluna_tab] = 5;
                }
            }
        }
    }

    // Aplica Cruz (centro da matriz é centro da cruz)
    origem_linha = 6;
    origem_coluna = 2;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int linha_tab = origem_linha - 2 + i;
            int coluna_tab = origem_coluna - 2 + j;
            if (linha_tab >= 0 && linha_tab < 10 && coluna_tab >= 0 && coluna_tab < 10) {
                if (cruz[i][j] == 1 && tabuleiro[linha_tab][coluna_tab] == 0) {
                    tabuleiro[linha_tab][coluna_tab] = 5;
                }
            }
        }
    }

    // Aplica Octaedro (losango centrado)
    origem_linha = 7;
    origem_coluna = 7;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int linha_tab = origem_linha - 2 + i;
            int coluna_tab = origem_coluna - 2 + j;
            if (linha_tab >= 0 && linha_tab < 10 && coluna_tab >= 0 && coluna_tab < 10) {
                if (octaedro[i][j] == 1 && tabuleiro[linha_tab][coluna_tab] == 0) {
                    tabuleiro[linha_tab][coluna_tab] = 5;
                }
            }
        }
    }

    // Exibe o tabuleiro final
    printf("Tabuleiro com habilidades:\n");
    printf("0 = Água, 3 = Navio, 5 = Área de Habilidade\n\n");

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
