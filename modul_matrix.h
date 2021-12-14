#ifndef MODUL_MATRIX_H
#define MODUL_MATRIX_H

// ������� �������� �������
double** matrix_creature(int n);

// ��������� �������
double** matrix_input(int n);

// ������� ������ �������. 
double** matrix_output(double** matrix, int n);

// �������
void matrix_clearing(double**& matr, int n);

// ��������� ������� �� �������
double** matrix_multiply(double** matrix1, double** matrix2, int n);

// ���������� ������� � �������
double** matrix_power(double** matrix, int n, int m);

// ��������� �������
double** matrix_E(int n);

// ��������� ������� �� �����
double** matrix_multiplication_by_a_number(double** matrix, int n, double k);

// ����� ������
double** matrix_summ(double** matrix1, double** matrix2, int n);

// ������� ���������� ���������. ������� ������: matrix - �������, n - ����������� �������
// f(x) = 3x^5 - 4x^4 - 10x^3 + 3x^2 - 7
double** calculating_the_expression(double** matrix, int n);

// 2
// ������� ���������������� �������
double** transp_matrix(double** matrix, int n);

// ������� �������� ������� �� ��������������
bool checking_for_symmetry(double** matrix, int n);

// ������� �������� ������� �� ������������������
bool checking_for_kososymmetry(double** matrix, int n);

//3
//������� ��������� ����� ������� ��� ������ � �������
double** get_matrix_without_row_and_col(double **matrix, int n, int row, int col);

//���������� ������������ ������� ���������� �� ������ ������
double matrix_det(double** matrix, int n);

// ������� ���������� �������� ������� 
double** matrix_inverse(double** matrix, int n);

// ������� ���������: Ax - bx = �, ��� C, A - �������, b - �����.
double** solution_of_the_equation(double** matrix_a, double** matrix_c, int b, int n);

#endif //MODUL_MATRIX_H


