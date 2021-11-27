#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;

// очистка
void free(int**& matr, int n)
{
	for (int i = 0; i < n; i++)
		delete[] matr[i];
	delete[] matr;
	matr = 0;
}

// считываем матрицу
int** input_matrix(int n)
{
	int** matrix = new int*[n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];
	return matrix;
}

// умножение матрици на матрицу
int** multiply_matrix(int** matrix1, int** matrix2, int n)
{
	int sum;
	int** rez_matrix = new int*[n];
	for (int i = 0; i < n; i++)
		rez_matrix[i] = new int[n];
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			sum = 0;
			for (int r = 0; r < n; r++)
				sum += matrix1[j][r] * matrix2[r][i];
			rez_matrix[j][i] = sum;
		}
	}
	return rez_matrix;
	for (int i = 0; i < n; i++)
		delete[] rez_matrix[i];
	delete[] rez_matrix;
}

// возведение матрици в степень
int** matrix_power(int** matrix, int n, int m)
{
	if (m == 1)
		return matrix;
	if (m % 2 == 1)
		return multiply_matrix(matrix_power(matrix, n, m - 1), matrix, n);
	else
	{
		matrix = matrix_power(matrix, n, m / 2);
		return multiply_matrix(matrix, matrix, n);
	}
}

// единичная матрица
int** E_matrix(int n)
{
	int** matrix = new int*[n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				matrix[i][j] = 1;
			else
				matrix[i][j] = 0;
		}
	return matrix;
}

// умножение матрицы на число
int** matrix_multiplication_by_a_number(int** matrix, int n, int k)
{
	int** rez_matrix = new int*[n];
	for (int i = 0; i < n; i++)
		rez_matrix[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			rez_matrix[i][j] = k * matrix[i][j];
	return rez_matrix;
	for (int i = 0; i < n; i++)
		delete[] rez_matrix[i];
	delete[] rez_matrix;
}

// сумма матриц
int** summ_matrix(int** matrix1, int** matrix2, int n)
{
	int** rez_matrix = new int*[n];
	for (int i = 0; i < n; i++)
		rez_matrix[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			rez_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
	return rez_matrix;
	for (int i = 0; i < n; i++)
		delete[] rez_matrix[i];
	delete[] rez_matrix;
}