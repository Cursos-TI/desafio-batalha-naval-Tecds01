#include <stdio.h>
#define linhas 10
#define coluna 10

int main(){

    char linha[10] = {'A','B','C','D','E','F','G','H','I','J'}; //LINHAS DO TABULEIRO.
    int  numero [10] = {1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10}; //coluna do tabuleiro
    
    // Definição do ponto de origem do cone (exemplo: linha 1, coluna 2)
        int xcone = 1, ycone = 2;

    // Definição do ponto de origem do octaedro (exemplo: linha 4, coluna 7)
        int xoctaedro = 4, yoctaedro = 7;
     // Definição da forma do octaedro usando padrões de deslocamento
        int deslocamentos[5][2] = {
        {0,  0},  // Centro
        {-1, 0},  // Acima do centro
        {1,  0},  // Abaixo do centro
        {0, -1},  // Esquerda do centro
        {0,  1}   // Direita do centro
    };
    // Definição do centro da cruz (exemplo: linha 7, coluna 5)
    int xcruz = 9, ycruz = 5;
    int des_cruz[3][5] = {
        {0, 0, 1, 0, 0},  
        {1, 1, 1, 1, 1},  
        {0, 0, 1, 0, 0},  
    };

    //tabuliero.
    int tabuleiro [10][10] = {
        { 0,3,3,3,0,0,0,0,0,3},
        { 0,0,0,0,0,0,0,0,3,0},
        { 0,0,0,0,0,0,0,3,0,0},
        { 0,0,0,0,0,0,0,0,0,0},
        { 0,0,0,0,0,0,0,0,0,0},
        { 0,0,0,0,0,0,0,0,3,0},
        { 3,0,0,0,0,0,0,0,3,0},
        { 0,3,0,0,0,0,0,0,3,0},
        { 0,0,3,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };
 
    // Habilidade Cone  
    for (int i = 0; i < 3; i++) { // Altura do cone
        for (int j = -i; j <= i; j++) { // Largura do cone
            int x = xcone + i; // Move para baixo
            int y = ycone + j; // Expande lateralmente
            if (x >= 0 && x < 10 && y >= 0 && y < 10) { // Garante que está dentro dos limites
                tabuleiro[x][y] = 1;
            }
        }
    }

    // Habilidade Octaedro
    // Aplicando os deslocamentos ao tabuleiro
    for (int i = 0; i < 5; i++) {
        int x = xoctaedro + deslocamentos[i][0];
        int y = yoctaedro + deslocamentos[i][1];
    
        if (x >= 0 && x < 10 && y >= 0 && y < 10) {// Garante que a posição está dentro dos limites do tabuleiro
            tabuleiro[x][y] = 1;
        }
    }
    
    // Habilidade Cruz
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int x = xcruz + i - 2;
            int y = ycruz + j - 2;
            if (x >= 0 && x < 10 && y >= 0 && y < 10) {
                tabuleiro[x][y] = des_cruz[i][j];
            }
        }
    }

    // Imprime o tabuleiro com as habilidades e com os navios.
    printf(" TABULEIRO DE BATALHA NAVAL!\n");
    printf("  A B C D E F G H I J\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d", numero[i]);
        for (int j = 0; j < 10; j++)
        {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}