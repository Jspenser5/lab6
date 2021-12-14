#include <iostream>
#include "check.h"
#include <math.h>
using namespace std;

// ������� �������� �������
double** matrix_creature(int n)
{
	double** matrix = new double*[n];
	for (int i = 0; i < n; i++)
		matrix[i] = new double[n];
	return matrix;
}

// ��������� �������. ������� ������: n - ����������� �������
double** matrix_input(int n)
{
	double** matrix = matrix_creature(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "a" << i << j << "= ";
			cin >> matrix[i][j];
			check_elem(matrix[i][j]);
		}
	return matrix;
}


// ������� ������ �������. ������� ������: matrix - ������� ��� ������, n - ����������� �������
double** matrix_output(double** matrix, int n)
{
	for (int i1 = 0; i1 < n; i1++)
	{
		for (int i2 = 0; i2 < n; i2++)
		{
			cout << matrix[i1][i2] << " ";
		}
		cout << endl;
	}
	return 0;
}

// �������. ������� ������: matr - �������, n - �����������
void matrix_clearing(double**& matr, int n)
{
	for (int i = 0; i < n; i++)
		delete[] matr[i];
	delete[] matr;
	matr = 0;
}

// ��������� ������� �� �������. ������� ������: matrix1 - �������1, matrix2 - �������2, n - ����������� ������
double** matrix_multiply(double** matrix1, double** matrix2, int n)
{
	double sum;
	double** matrix_rez = matrix_creature(n);
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			sum = 0;
			for (int r = 0; r < n; r++)
				sum += matrix1[j][r] * matrix2[r][i];
			matrix_rez[j][i] = sum;
		}
	}
	return matrix_rez;
	matrix_clearing(matrix_rez, n);
}

// ���������� ������� � �������. ������� ������: matrix - �������, ������� ����� �������� � �������, n - ����������� �������, m - �������
double** matrix_power(double** matrix, int n, int m)
{
	if (m == 1)
		return matrix;
	if (m % 2 == 1)
		return matrix_multiply(matrix_power(matrix, n, m - 1), matrix, n);
	else
	{
		matrix = matrix_power(matrix, n, m / 2);
		return matrix_multiply(matrix, matrix, n);
	}
}

// ��������� �������. ������� ������: n - ����������� �������
double** matrix_E(int n)
{
	double** matrix = matrix_creature(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				matrix[i][j] = 1.0;
			else
				matrix[i][j] = 0.0;
		}
	return matrix;
}

// ��������� ������� �� �����. ������� ������: matrix - �������, n - ����������� �������, k - �����, �� ������� ����� �������� �������
double** matrix_multiplication_by_a_number(double** matrix, int n, double k)
{
	double** matrix_rez = matrix_creature(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix_rez[i][j] = k * matrix[i][j];
	return matrix_rez;
	matrix_clearing(matrix_rez, n);
}

// ����� ������. ������� ������: matrix1 - �������1, matrix2 - �������2, n - ����������� ������
double** matrix_summ(double** matrix1, double** matrix2, int n)
{
	double** matrix_rez = matrix_creature(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix_rez[i][j] = matrix1[i][j] + matrix2[i][j];
	return matrix_rez;
	matrix_clearing(matrix_rez, n);
}

// ������� ���������� ���������. ������� ������: matrix - �������, n - ����������� �������
double** calculating_the_expression(double** matrix, int n)
{
	double** matrix_rez = matrix_creature(n);
	double** matrix_5th_degree = matrix_power(matrix, n, 5);
	double** matrix_4th_degree = matrix_power(matrix, n, 4);
	double** matrix_3th_degree = matrix_power(matrix, n, 3);
	double** matrix_2th_degree = matrix_power(matrix, n, 2);
	double** matrix_e = matrix_E(n);

	matrix_5th_degree = matrix_multiplication_by_a_number(matrix_5th_degree, n, 3);
	matrix_4th_degree = matrix_multiplication_by_a_number(matrix_4th_degree, n, -4);
	matrix_3th_degree = matrix_multiplication_by_a_number(matrix_3th_degree, n, -10);
	matrix_2th_degree = matrix_multiplication_by_a_number(matrix_2th_degree, n, 3);
	matrix_e = matrix_multiplication_by_a_number(matrix_e, n, -7);

	matrix_rez = matrix_summ(matrix_5th_degree, matrix_4th_degree, n);
	matrix_rez = matrix_summ(matrix_rez, matrix_3th_degree, n);
	matrix_rez = matrix_summ(matrix_rez, matrix_2th_degree, n);
	matrix_rez = matrix_summ(matrix_rez, matrix_e, n);

	return matrix_rez;
	matrix_clearing(matrix_rez, n);
	matrix_clearing(matrix_5th_degree, n);
	matrix_clearing(matrix_4th_degree, n);
	matrix_clearing(matrix_3th_degree, n);
	matrix_clearing(matrix_2th_degree, n);
	matrix_clearing(matrix_e, n);
}
// ����� 2
// ������� ���������������� �������. ������� ������: matrix - �������, n - ����������� �������
double** transp_matrix(double** matrix, int n)
{
	double** matrix2 = matrix_creature(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix2[i][j] = matrix[j][i];
	return matrix2;
	matrix_clearing(matrix2, n);
}

// ������� �������� ������� �� ��������������. ������� ������: matrix - �������, n - ����������� �������
bool checking_for_symmetry(double** matrix, int n)
{
	double** matrix_t = transp_matrix(matrix, n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (matrix_t[i][j] != matrix[i][j])
				return false;
	return true;
}

// ������� �������� ������� �� ������������������. ������� ������: matrix - �������, n - ����������� �������
bool checking_for_kososymmetry(double** matrix, int n)
{
	double** matrix_t = transp_matrix(matrix, n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (matrix_t[i][j] != -(matrix[i][j]) || matrix[i][i] != 0)
				return false;
	return true;
}

// ����� 3
//������� ��������� ����� ������� ��� ������ � �������
double** get_matrix_without_row_and_col(double** matrix, int n, int row, int col)
{
	double** new_matrix = matrix_creature(n - 1);
	int offsetRow = 0; //�������� ������� ������ � �������
	int offsetCol = 0; //�������� ������� ������� � �������
	for (int i = 0; i < n - 1; i++)
	{
		//���������� row-�� ������
		if (i == row)
		{
			offsetRow = 1; //��� ������ ��������� ������, ������� ���� ����������, ������ �������� ��� �������� �������
		}

		offsetCol = 0; //�������� �������� �������
		for (int j = 0; j < n - 1; j++)
		{
			//���������� col-�� �������
			if (j == col)
			{
				offsetCol = 1; //��������� ������ �������, ��������� ��� ���������
			}

			new_matrix[i][j] = matrix[i + offsetRow][j + offsetCol];
		}
	}
	return new_matrix;
	matrix_clearing(new_matrix, n - 1);
}


//���������� ������������ ������� ���������� �� ������ ������
double matrix_det(double** matrix, int n)
{
	int det = 0;
	int degree = 1; // (-1)^(1+j) �� ������� ������������

	//������� ������ �� ��������
	if (n == 1)
	{
		return matrix[0][0];
	}
	//������� ������ �� ��������
	else if (n == 2)
	{
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}
	else
	{
		//������� ��� ������ � �������
		double** temp_matr = matrix_creature(n);

		//������������ �� 0-�� ������, ���� ����� �� ��������
		for (int j = 0; j < n; j++)
		{
			int m = n - 1;
			//������� �� ������� i-� ������ � j-�� �������
			//��������� � newMatrix
			temp_matr = get_matrix_without_row_and_col(matrix, n, 0, j);

			//����������� �����
			//�� �������: ����� �� j, (-1)^(1+j) * matrix[0][j] * minor_j (��� � ���� ����� �� �������)
			//��� minor_j - �������������� ����� �������� matrix[0][j]
			// (�������, ��� ����� ��� ������������ ������� ��� 0-�� ������ � j-�� �������)
			det = det + (degree * matrix[0][j] * matrix_det(temp_matr, m));
			//"�����������" ������� ���������
			degree = -degree;
			//������ ������ �� ������ ���� ��������
			matrix_clearing(temp_matr, m);
		}
	}
	return det;
}
// ������� ���������� �������� ������� 
double** matrix_inverse(double** matrix, int n)
{
	double det = matrix_det(matrix, n);
	double** matrix_rez = matrix_creature(n);
	if (det == 0)
	{
		// �.�. ������������ ������� = 0,\n�� ������� ����������� � �������� �� �����!!!
		cout << "������� ���!!!" << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int m = n - 1;
				double** temp_matr = matrix_creature(n);
				temp_matr = get_matrix_without_row_and_col(matrix, n, i, j);
				matrix_rez[i][j] = pow(-1.0, i + j + 2) * matrix_det(temp_matr, m) / det;
				matrix_clearing(temp_matr, m);
			}
		}
		matrix_rez = transp_matrix(matrix_rez, n);
		return matrix_rez;
		matrix_clearing(matrix_rez, n);
	}
}

// ������� ���������: Ax - bx = �, ��� C, A - �������, b - �����.
double** solution_of_the_equation(double** matrix_a, double** matrix_c, int b, int n)
{
	double** matrix_rez = matrix_creature(n);
	double** e_matrix = matrix_E(n);
	e_matrix = matrix_multiplication_by_a_number(e_matrix, n, -b);
	matrix_rez = matrix_summ(matrix_a, e_matrix, n);
	matrix_rez = matrix_inverse(matrix_rez, n);
	matrix_rez = matrix_multiply(matrix_rez, matrix_c, n);
	return matrix_rez;
	matrix_clearing(matrix_rez, n);
}