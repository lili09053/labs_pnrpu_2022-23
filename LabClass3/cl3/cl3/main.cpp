#include <iostream>
#include "Pair.h"
using namespace std;

int main()
{
	system("chcp 1251>nul");
	Pair A;
	cout << "������������� ������� A\n";
	cin >> A;
	cout << "\n����� ������� A\n";
	cout << A << endl;
	cout << "\n��������� ������� A\n";
	for (int i = 0; i < 10; i++)
	{
		++A;		// ���������� �����
	}
	cout << "\n����� ������� A\n";
	cout << A << endl;
	cout << "\n������������� ������� �\n";
	Pair B(4, 1.98);
	cout << "\n����� ������� �\n";
	cout << B << endl;
	cout << "\n��������� ������� B\n";
	for (int i = 0; i < 10; i++)
	{
		B++;		// ����������� �����
	}
	cout << "\n����� ������� �\n";
	cout << B << endl;
	Pair C;
	cout << "\n������������� ������� C\n";
	cout << "������� a: ";
	int a;
	cin >> a;
	
	cout << "������� b: ";
	double b;
	cin >> b;
	
	C.set_a(a);
	C.set_b(b);
	cout << "\n����������� ����� ������� C � ������ D\n";
	Pair D = C;
	cout << "\n������ D\n" << D << endl << "������ �\n" << C << endl;
	if (A < B)
	{
		cout << "\n������ A ������ ������� B\n";
	}
	else
	{
		if (A > B)
		{
			cout << "\n������ A ������ ������� B\n";
		}
		else
		{
			cout << "\n������ A ����� ������� B\n";
		}
	}
}