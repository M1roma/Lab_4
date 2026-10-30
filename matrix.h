#ifndef MATRIX_H
#define MATRIX_H

/**
 * @file matrix.h
 * @brief Модуль для роботи з двовимірними динамічними масивами.
 */

/**
 * @brief Виділення пам'яті під матрицю розміром rows x cols
 * @param rows Кількість рядків
 * @param cols Кількість стовпців
 * @return Вказівник на створену матрицю
 */
int** create_matrix(int rows, int cols);

/**
 * @brief Звільнення динамічної пам'яті матриці
 * @param matrix Вказівник на матрицю
 * @param rows Кількість рядків
 */
void free_matrix(int** matrix, int rows);

/**
 * @brief Виведення матриці на екран
 * @param matrix Матриця для виводу
 * @param rows Кількість рядків
 * @param cols Кількість стовпців
 */
void print_matrix(int** matrix, int rows, int cols);

/**
 * @brief Пошук max та min нижче головної діагоналі (Варіант 2)
 * @param A Квадратна матриця
 * @param n Розмірність матриці (n x n)
 * @param max_a Вказівник для збереження максимуму
 * @param min_a Вказівник для збереження мінімуму
 */
 void max_min(int** A, int n, int* max_a, int* min_a);

/**
 * @brief Транспонування матриці B
 * @param B Початкова матриця
 * @param n Рядки
 * @param m Стовпці
 * @return Нова транспонована матриця (m x n)
 */
int** transpose_b(int** B, int n, int m);

/**
 * @brief Множення матриць A * B
 * @param A Перша матриця
 * @param rA Рядки A
 * @param cA Стовпці A
 * @param B Друга матриця
 * @param rB Рядки B
 * @param cB Стовпці B
 * @return Матриця-результат C = A * B
 */
int** mult_a_b(int** A, int rA, int cA, int** B, int rB, int cB);

#endif
