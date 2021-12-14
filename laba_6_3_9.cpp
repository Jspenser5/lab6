#include <iostream>
#include <windows.h>
#include "check.h"
#include "modul_matrix.h"
#include "check.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "¬ведите размерность n = ";
	int n, b;
	cin >> n;
	check_n(n);
	cout << "¬ведите матрицу a " << endl;
	double** matrix_a = matrix_input(n);
	cout << "¬ведите число b " << endl;
	cin >> b;
	check_elem(b);
	cout << "¬ведите матрицу c " << endl;
	double** matrix_c = matrix_input(n);

	double** matrix = matrix_creature(n);

	matrix = solution_of_the_equation(matrix_a, matrix_c, b, n);

	matrix_output(matrix, n);

	matrix_clearing(matrix, n);
	matrix_clearing(matrix_a, n);
	matrix_clearing(matrix_c, n);

	system("pause");
	return 0;
}