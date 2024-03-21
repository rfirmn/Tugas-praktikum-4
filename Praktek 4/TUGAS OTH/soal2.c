#include <stdio.h>
#include <stdlib.h>

void koboImaginaryChess(int i, int j, int size, int *chessBoard) { 
    // fungsi yang menentukan benar atau tidak nya posisi kuda 
    if (i < 0 || j < 0 || i >= size || j >= size) {  
        printf("Koordinat tidak valid\n");  
        return;
    }

    //ini merupakan semua kemungkinan perpindahan 
    int pindah[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}}; //algoritma penempatan kuda

    //ini merupakan loop yang digunakan untuk menyatakan semua kemungkinan diatas lalu ditandai dengan 1 
    for (int k = 0; k < 8; k++) {
        int ni = i + pindah[k][0];
        int nj = j + pindah[k][1];  
        if (ni >= 0 && nj >= 0 && ni < size && nj < size) {
            chessBoard[ni * size + nj] = 1;
        }
    }
}

int main() {
    int catur[8][8] = {0};

    int i, j;
    scanf("%d %d", &i, &j);

    koboImaginaryChess(i, j, 8, (int *)catur);

    //menampilkan papan catur yang telah di perbarui 
    for (int a = 0; a < 8; a++) {
        for (int b = 0; b < 8; b++) {  
            printf("%d ", catur[a][b]);
        }
        printf("\n");
    }

    return 0;
}