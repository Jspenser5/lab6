#include <iostream>
using namespace std;

//������� �������� �������� ��� ��������� �������
double check_elem(double d)
{
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "������� ��������� ������\n";
		cin >> d;
	}
	return d;
}

//������� �������� �������� ������ ��� n
int check_n(int d)
{
	while (std::cin.fail() || d < 0)
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "������� ��������� ������\n";
		cin >> d;
	}
	return d;
}