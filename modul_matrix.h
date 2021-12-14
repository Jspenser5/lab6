#ifndef MODUL_MATRIX_H
#define MODUL_MATRIX_H

// Функция создания матрицы
double** matrix_creature(int n);

// Считываем матрицу
double** matrix_input(int n);

// Функция вывода мартицы. 
double** matrix_output(double** matrix, int n);

// Очистка
void matrix_clearing(double**& matr, int n);

// Умножение матрици на матрицу
double** matrix_multiply(double** matrix1, double** matrix2, int n);

// Возведение матрици в степень
double** matrix_power(double** matrix, int n, int m);

// Единичная матрица
double** matrix_E(int n);

// Умножение матрицы на число
double** matrix_multiplication_by_a_number(double** matrix, int n, double k);

// Сумма матриц
double** matrix_summ(double** matrix1, double** matrix2, int n);

// Функция вычисления выражения. Входные данные: matrix - матрица, n - размерность матрицы
// f(x) = 3x^5 - 4x^4 - 10x^3 + 3x^2 - 7
double** calculating_the_expression(double** matrix, int n);

// 2
// Функция транспонирования матрицы
double** transp_matrix(double** matrix, int n);

// Функция проверки матрицы на симметричность
bool checking_for_symmetry(double** matrix, int n);

// Функция проверки матрицы на кососимметричность
bool checking_for_kososymmetry(double** matrix, int n);

//3
//Функция получения новой матрици без строки и столбца
double** get_matrix_without_row_and_col(double **matrix, int n, int row, int col);

//Вычисление определителя матрицы разложение по первой строке
double matrix_det(double** matrix, int n);

// Функция вычисления обратной матрицы 
double** matrix_inverse(double** matrix, int n);

// Решение уравнения: Ax - bx = С, где C, A - матрицы, b - число.
double** solution_of_the_equation(double** matrix_a, double** matrix_c, int b, int n);

#endif //MODUL_MATRIX_H


