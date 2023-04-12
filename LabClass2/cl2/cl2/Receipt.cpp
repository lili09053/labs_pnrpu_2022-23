#include "Receipt.h"
#include <iostream>
#include <string>
using namespace std;


Receipt::Receipt()		// ����������� �� ���������
{
	number = 0;
	date = " ";
	sum = 0.00;
	cout << "������ ����������� ��� ����������" << endl;
}

Receipt::Receipt(int Num, string Date, double Sum)	// ����������� � �����������
{
	number = Num;
	date = Date;
	sum = Sum;
	cout << "������ ����������� � �����������" << endl;
}

Receipt::Receipt(const Receipt& p) // ����������� �����������
{
	number = p.number;
	date = p.date;
	sum = p.sum;
	cout << "������ ����������� �����������" << endl;
}
Receipt::~Receipt()
{
	cout << "������ ����������" << endl;
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

void Receipt::Show()	// ����� ���������
{
	cout << "�����: " << number << endl;
	cout << "����: " << date << endl;
	cout << "�����: " << sum << endl;
}
