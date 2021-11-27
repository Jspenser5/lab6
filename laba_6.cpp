#include  <iostream>
#include <windows.h>
#include <string>
#include <sstream>
#include "func laba 6.1.9.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "¬ведите размер матрицы " << endl;
	cin >> n;
	cout << "¬ведите элементы матрицы " << endl;
	int** matrix = input_matrix(n);

	int** matrix_5th_degree = matrix_power(matrix, n, 5);
	int** matrix_4th_degree = matrix_power(matrix, n, 4);
	int** matrix_3th_degree = matrix_power(matrix, n, 3);
	int** matrix_2th_degree = matrix_power(matrix, n, 2);
	int** matrix_e = E_matrix(n);

	matrix_5th_degree = matrix_multiplication_by_a_number(matrix_5th_degree, n, 3);
	matrix_4th_degree = matrix_multiplication_by_a_number(matrix_4th_degree, n, -4);
	matrix_3th_degree = matrix_multiplication_by_a_number(matrix_3th_degree, n, -10);
	matrix_2th_degree = matrix_multiplication_by_a_number(matrix_2th_degree, n, 3);
	matrix_e = matrix_multiplication_by_a_number(matrix_e, n, -7);

	matrix = summ_matrix(matrix_5th_degree, matrix_4th_degree, n);
	matrix = summ_matrix(matrix, matrix_3th_degree, n);
	matrix = summ_matrix(matrix, matrix_2th_degree, n);
	matrix = summ_matrix(matrix, matrix_e, n);
	for (int i1 = 0; i1 < n; i1++)
	{
		for (int i2 = 0; i2 < n; i2++)
		{
			cout << matrix[i1][i2] << " ";
		}
		cout << endl;
	}
	free(matrix, n);
	free(matrix_5th_degree, n);
	free(matrix_4th_degree, n);
	free(matrix_3th_degree, n);
	free(matrix_2th_degree, n);
	free(matrix_e, n);
	system("pause");
	return 0;
}