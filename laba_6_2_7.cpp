/*Лабораторная работа 6.2.7
Определить является ли матрица симметричной или кососимметричной 
Ломтев Матвей ПМИ 13*/
#include <iostream>
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
	double** matrix = input_matrix(n);

	if (checking_for_symmetry(matrix, n) == true)
		cout << "Данная матрица симметрична" << endl;
	else if (checking_for_kososymmetry(matrix, n) == true)
		cout << "Данная матрица кососимметрична" << endl;
	else
		cout << "Данная матрица не симметрична и не кососимметрична" << endl;

	clearing_matrix(matrix, n);

	system("pause");
	return 0;
}