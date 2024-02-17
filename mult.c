#include <stdio.h>
#include <stdlib.h>
#include <cblas.h>

#define ROWS 3
#define COLS 3

int main() {
    double a[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double b[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    double c[ROWS][COLS] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    // Inmultirea matricilor a si b
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, ROWS, COLS, COLS, 1, (double *)a, COLS, (double *)b, COLS, 0, (double *)c, COLS);

    // Afisarea matricii rezultat
    printf("Matricea rezultat:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%lf ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
