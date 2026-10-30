#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

// 1. Створення динамічної матриці
int** create_matrix(int rows, int cols) {
    int** m = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        m[i] = (int*)malloc(cols * sizeof(int));
    }
    return m;
}

// 2. Звільнення пам'яті
void free_matrix(int** m, int rows) {
    for (int i = 0; i < rows; i++) {
        free(m[i]);
    }
    free(m);
}

// 3. Друк матриці
void print_matrix(int** m, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", m[i][j]);
        }
        printf("\n");
    }
}

// 4. Пошук max та min нижче діагоналі
void max_min(int** A, int n, int* max_a, int* min_a) {
    // Перший елемент під діагоналлю — це A[1][0]
    *max_a = A[1][0];
    *min_a = A[1][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j) { // Умова "нижче головної діагоналі"
                if (A[i][j] > *max_a) *max_a = A[i][j];
                if (A[i][j] < *min_a) *min_a = A[i][j];
            }
        }
    }
}

// 5. Транспонування (міняємо рядки та стовпці місцями)
int** transpose_b(int** B, int n, int m) {
    int** T = create_matrix(m, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            T[j][i] = B[i][j];
        }
    }
    return T;
}

// 6. Множення A * B
int** mult_a_b(int** A, int rA, int cA, int** B, int rB, int cB) {
    if (cA != rB) return NULL; // Перевірка: стовпці A мають дорівнювати рядкам B

    int** C = create_matrix(rA, cB);
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < cA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}
