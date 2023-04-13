#include <iostream>
#include "Pair.h"
using namespace std;

int main()
{
	system("chcp 1251>nul");
	Pair A;
	cout << "Инициализация объекта A\n";
	cin >> A;
	cout << "\nВывод объекта A\n";
	cout << A << endl;
	cout << "\nИзменение объекта A\n";
	for (int i = 0; i < 10; i++)
	{
		++A;		// префиксная форма
	}
	cout << "\nВывод объекта A\n";
	cout << A << endl;
	cout << "\nИнициализация объекта В\n";
	Pair B(4, 1.98);
	cout << "\nВывод объекта В\n";
	cout << B << endl;
	cout << "\nИзменение объекта B\n";
	for (int i = 0; i < 10; i++)
	{
		B++;		// постфиксная форма
	}
	cout << "\nВывод объекта В\n";
	cout << B << endl;
	Pair C;
	cout << "\nИнициализация объекта C\n";
	cout << "Введите a: ";
	int a;
	cin >> a;
	
	cout << "Введите b: ";
	double b;
	cin >> b;
	
	C.set_a(a);
	C.set_b(b);
	cout << "\nКопирование полей объекта C в объект D\n";
	Pair D = C;
	cout << "\nОбъект D\n" << D << endl << "Объект С\n" << C << endl;
	if (A < B)
	{
		cout << "\nОбъект A меньше объекта B\n";
	}
	else
	{
		if (A > B)
		{
			cout << "\nОбъект A больше объекта B\n";
		}
		else
		{
			cout << "\nОбъект A равен объекту B\n";
		}
	}
}