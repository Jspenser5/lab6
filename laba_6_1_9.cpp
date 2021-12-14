/*Лабораторная работа 6.1.9
f(x) = 3x^5 - 4x^4 - 10x^3 + 3x^2 - 7. Найти f(A)
Ломтев Матвей ПМИ 13*/
#include  <iostream>
#include <windows.h>
#include "modul_matrix.h"
#include "check.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите размер матрицы " << endl;
	cin >> n;
	check_n(n);
	cout << "Введите элементы матрицы " << endl;
	double** matrix = matrix_input(n);

	matrix = calculating_the_expression(matrix, n);

	matrix_output(matrix, n);
	matrix_clearing(matrix, n);

	system("pause");
	return 0;
}