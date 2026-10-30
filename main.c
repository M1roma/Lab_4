#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {
    int rows_a = 0, cols_a = 0;
    int rows_b = 0, cols_b = 0;

    /// Введення розмірів для матриці A
    printf("Enter rows and cols for Matrix A: ");
    scanf("%d %d", &rows_a, &cols_a);

    // Створення та введення елементів матриці A
    int** A = create_matrix(rows_a, cols_a);
    printf("Enter elements for Matrix A (%dx%d):\n", rows_a, cols_a);
    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_a; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // Введення розмірів для матриці B
    printf("\nEnter rows and cols for Matrix B: ");
    scanf("%d %d", &rows_b, &cols_b);

    // Створення та введення елементів матриці B
    int** B = create_matrix(rows_b, cols_b);
    printf("Enter elements for Matrix B (%dx%d):\n", rows_b, cols_b);
    for (int i = 0; i < rows_b; i++) {
        for (int j = 0; j < cols_b; j++) {
            printf("B[%d][%d] = ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

   // виведення вхідних матриць
    printf("\nMatrix A:\n");
    print_matrix(A, rows_a, cols_a);

    printf("\nMatrix B:\n");
    print_matrix(B, rows_b, cols_b);

    // Max та Min нижче діагоналі (працює для квадратної A)
    if (rows_a == cols_a && rows_a > 1) {
        int max_val = 0, min_val = 0;
        max_min(A, rows_a, &max_val, &min_val);
        printf("\nBelow diagonal in A: max = %d, min = %d\n", max_val, min_val);
    } else {
        printf("\nMatrix A is not square or too small for diagonal check.\n");
    }

    // транспотування B
    int** TransB = transpose_b(B, rows_b, cols_b);
    printf("\nTransposed Matrix B:\n");
    print_matrix(TransB, cols_b, rows_b);

    // Множення A * B
    int** C = mult_a_b(A, rows_a, cols_a, B, rows_b, cols_b);
    if (C != NULL) {
        printf("\nResult Matrix C (A * B):\n");
        print_matrix(C, rows_a, cols_b);
        free_matrix(C, rows_a);
    } else {
        printf("\nCannot multiply matrices A and B (cols_A != rows_B).\n");
    }

    // Звільнення пам'яті
    free_matrix(A, rows_a);
    free_matrix(B, rows_b);
    free_matrix(TransB, cols_b);

    return 0;
}
