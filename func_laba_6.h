#ifndef FUNC_LABA_6_H
#define FUNC_LABA_6_H

// очистка
void free(int**& matr, int n);

// считываем матрицу
int** input_matrix(int n);

// умножение матрици на матрицу
int** multiply_matrix(int** matrix1, int** matrix2, int n);

// возведение матрици в степень
int** matrix_power(int** matrix, int n, int m);

// единичная матрица
int** E_matrix(int n);

// умножение матрицы на число
int** matrix_multiplication_by_a_number(int** matrix, int n, int k);

// сумма матриц
int** summ_matrix(int** matrix1, int** matrix2, int n);

#endif //FUNC_LABA_6_H