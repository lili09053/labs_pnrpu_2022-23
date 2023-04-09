#include <iostream>
#include <stdarg.h>
using namespace std;


int NOD_TWO(int a, int b) // расчёт НОД по алгоритму Евклида между 2мя числами
{
	if (a != 0 and b != 0)
	{
		if (a > b) return NOD_TWO(a % b, b);
		if (a < b) return NOD_TWO(a, b % a);
	}
	return a + b;

}


int NOK_TWO(int a, int b)		// расчёт НОK по алгоритму Евклида между 2мя числами
{
	return a * b / NOD_TWO(a, b);
}

int NOK_SET(int n, ...) // Нахождение НОК множества чисел
{
	va_list fac;	// тип указателя, на список аргументов
	va_start(fac, n); // задаёт указатель на первый необязательный элемент
	
	int res = NOK_TWO(va_arg(fac, int), va_arg(fac, int)); // НОК первых двух параметров
	
	for (int i = 0; i < n - 2; i++) // n - 2 т.к. первые два параметра рассмотрены
	{
		res = NOK_TWO(res, va_arg(fac, int)); // НОК между результатом и следующим параметром
	}

	va_end(fac); // сбрасывание указателя
	
	return res;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "НОК для трёх параметров: ";
	cout << NOK_SET(3, 10, 14, 35) << endl; //70
	
	cout << "НОК для пяти параметров: ";
	cout << NOK_SET(5, 6, 84, 48, 7, 143) << endl; // 48048

	cout << "НОК для шести параметров: ";
	cout << NOK_SET(6, 6, 45, 30, 60, 120, 135) << endl;//1080

}