/*������������ ������ 6.2.7
���������� �������� �� ������� ������������ ��� ���������������� 
������ ������ ��� 13*/
#include <iostream>
#include <windows.h>
#include "modul_matrix.h"
#include "check.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");

	int n;
	cout << "������� ������ ������� " << endl;
	cin >> n;
	check_n(n);
	cout << "������� �������� ������� " << endl;
	double** matrix = input_matrix(n);

	if (checking_for_symmetry(matrix, n) == true)
		cout << "������ ������� �����������" << endl;
	else if (checking_for_kososymmetry(matrix, n) == true)
		cout << "������ ������� ���������������" << endl;
	else
		cout << "������ ������� �� ����������� � �� ���������������" << endl;

	clearing_matrix(matrix, n);

	system("pause");
	return 0;
}