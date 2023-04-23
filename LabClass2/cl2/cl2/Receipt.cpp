#include "Receipt.h"
#include <iostream>
#include <string>
using namespace std;


Receipt::Receipt()		// конструктор по умолчанию
{
	number = 0;
	date = " ";
	sum = 0.00;
	cout << "Вызван конструктор без параметров" << endl;
}

Receipt::Receipt(int Num, string Date, double Sum)	// конструктор с параметрами
{
	number = Num;
	date = Date;
	sum = Sum;
	cout << "Вызван конструктор с параметрами" << endl;
}

Receipt::Receipt(const Receipt& p) // конструктор копирования
{
	number = p.number;
	date = p.date;
	sum = p.sum;
	cout << "Вызван конструктор копирования" << endl;
}
Receipt::~Receipt()
{
	cout << "Вызван деструктор" << endl;
}

int Receipt::get_number()
{
	return number;
}

void Receipt::set_number(int Num)
{
	number = Num;
}

string Receipt::get_date()
{
	return date;
}

void Receipt::set_date(string Date)
{
	date = Date;
}

double Receipt::get_sum()
{
	return sum;
}

void Receipt::set_sum(double Sum)
{
	sum = Sum;
}

void Receipt::Show()	// вывод атрибутов
{
	cout << "Номер: " << number << endl;
	cout << "Дата: " << date << endl;
	cout << "Сумма: " << sum << endl;
}
