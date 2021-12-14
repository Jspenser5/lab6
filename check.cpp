#include <iostream>
using namespace std;

//Функция проверки вводимых для элементов матрицы
double check_elem(double d)
{
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Введите коректные данные\n";
		cin >> d;
	}
	return d;
}

//Функция проверки вводимых данных для n
int check_n(int d)
{
	while (std::cin.fail() || d < 0)
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Введите коректные данные\n";
		cin >> d;
	}
	return d;
}