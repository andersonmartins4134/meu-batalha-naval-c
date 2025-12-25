#include <stdio.h>

int main() {
    // Matriz 10x10 para o tabuleiro principal
    int tabuleiro[10][10];
    
    // Inicializo o tabuleiro com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Mantenho os navios do nível anterior (valor 3)
    // Navio Horizontal
    for (int i = 0; i < 3; i++) tabuleiro[1][1 + i] = 3;
    // Navio Vertical
    for (int i = 0; i < 3; i++) tabuleiro[5 + i][8] = 3;
    // Navio Diagonal 1
    for (int i = 0; i < 3; i++) tabuleiro[0 + i][6 + i] = 3;
    // Navio Diagonal 2
    for (int i = 0; i < 3; i++) tabuleiro[6 + i][4 - i] = 3;

    // --- CRIAÇÃO DAS MATRIZES DE HABILIDADES (5x5) ---
    // Criei matrizes menores para desenhar o formato de cada ataque
    int matrizCone[5][5] = {0};
    int matrizCruz[5][5] = {0};
    int matrizOctaedro[5][5] = {0};

    // Desenho do Cone (Triângulo)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Lógica para formar o triângulo: linha 0 (1 ponto), linha 1 (3 pontos), linha 2 (5 pontos)
            if ((i == 0 && j == 2) || (i == 1 && (j >= 1 && j <= 3)) || (i == 2)) {
                matrizCone[i][j] = 1;
            }
        }
    }

    // Desenho da Cruz
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Preencho a linha do meio (2) e a coluna do meio (2)
            if (i == 2 || j == 2) {
                matrizCruz[i][j] = 1;
            }
        }
    }

    // Desenho do Octaedro (Losango)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Marco o centro e os pontos adjacentes para formar o diamante
            if ((i == 2 && j == 2) || (i == 1 && j == 2) || (i == 3 && j == 2) || 
                (i == 2 && j == 1) || (i == 2 && j == 3)) {
                matrizOctaedro[i][j] = 1;
            }
        }
    }

    // --- SOBREPOSIÇÃO NO TABULEIRO ---
    // Defini pontos de origem para as habilidades aparecerem em locais diferentes
    int origemConeL = 4, origemConeC = 1;
    int origemCruzL = 0, origemCruzC = 0;
    int origemOctL = 7, origemOctC = 5;

    // Apliquei o Cone no tabuleiro (uso valor 5 para a área de efeito)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrizCone[i][j] == 1) {
                // Valido se a posição está dentro do limite 10x10
                if (origemConeL + i < 10 && origemConeC + j < 10) {
                    tabuleiro[origemConeL + i][origemConeC + j] = 5;
                }
            }
        }
    }

    // Apliquei a Cruz no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrizCruz[i][j] == 1) {
                if (origemCruzL + i < 10 && origemCruzC + j < 10) {
                    tabuleiro[origemCruzL + i][origemCruzC + j] = 5;
                }
            }
        }
    }

    // Apliquei o Octaedro no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrizOctaedro[i][j] == 1) {
                if (origemOctL + i < 10 && origemOctC + j < 10) {
                    tabuleiro[origemOctL + i][origemOctC + j] = 5;
                }
            }
        }
    }

    // --- EXIBIÇÃO FINAL ---
    printf("\n*** TABULEIRO FINAL - BATALHA NAVAL (NÍVEL MESTRE) ***\n");
    printf("Legenda: 0=Agua | 3=Navio | 5=Habilidade\n\n");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}