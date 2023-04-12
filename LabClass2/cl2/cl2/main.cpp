#include <iostream>
#include <string>
#include "Receipt.h"
using namespace std;

Receipt make_Receipt()									// Функция создания объекта и заполнения его полей данными
{
	int number;
	string date;
	double sum;
	cout << "Номер квитанции: ";
	cin >> number;
	cout << "Введите дату: ";
	getline(cin, date);
	getline(cin, date);
	cout << "Введите сумму: ";
	cin >> sum;
	while (sum < 0)
	{
		cout << "Неверно введена сумма! Попробуйте ещё раз: ";
		cin >> sum;
	}
	cin.ignore();
	Receipt Element(number, date, sum);
	return Element;
}

void Print_Receipt(Receipt Element)						// Функция вывода данных объекта
{
	Element.Show();								// Метод вывода полей объекта
}

int main()
{
	system("chcp 1251>nul");
	Receipt Elem1;									// Вызов конструктора без параметра для 1-го объекта
	Elem1.Show();								// Вызов метода вывода полей 1-го объекта
	Receipt Elem2(8903784, "01.01.2001", 150.089);	// Вызов конструктора с параметрами для 2-го объекта
	Elem2.Show();								// Вызов метода вывода полей 2-го объекта
	Receipt Elem3 = Elem2;							// Вызов конструктора копирования для 3-го объекта (копирование полей 2-го объекта)
	Print_Receipt(Elem3);							// Функция вывода данных 3-го объекта
	Elem3.set_number(111111);						// Вызов селектора  3-го объекта
	Elem3.set_date("12.06.2000");			// Вызов селектора поля  3-го объекта
	Elem3.set_sum(240.708);						// Вызов селектора поля  3-го объекта
	Elem1 = make_Receipt();							// Вызов функции создания объекта и заполнения его полей данными (Происходит инициализация нового объекта и присваивание 1-му)
	Elem1.Show();								// Метод вывода полей 1-го объекта
}