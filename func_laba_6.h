#ifndef FUNC_LABA_6_H
#define FUNC_LABA_6_H

// �������
void free(int**& matr, int n);

// ��������� �������
int** input_matrix(int n);

// ��������� ������� �� �������
int** multiply_matrix(int** matrix1, int** matrix2, int n);

// ���������� ������� � �������
int** matrix_power(int** matrix, int n, int m);

// ��������� �������
int** E_matrix(int n);

// ��������� ������� �� �����
int** matrix_multiplication_by_a_number(int** matrix, int n, int k);

// ����� ������
int** summ_matrix(int** matrix1, int** matrix2, int n);

#endif //FUNC_LABA_6_H