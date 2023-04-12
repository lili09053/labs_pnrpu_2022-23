#include <iostream>
#include <string>
#include "Receipt.h"
using namespace std;

Receipt make_Receipt()									// ������� �������� ������� � ���������� ��� ����� �������
{
	int number;
	string date;
	double sum;
	cout << "����� ���������: ";
	cin >> number;
	cout << "������� ����: ";
	getline(cin, date);
	getline(cin, date);
	cout << "������� �����: ";
	cin >> sum;
	while (sum < 0)
	{
		cout << "������� ������� �����! ���������� ��� ���: ";
		cin >> sum;
	}
	cin.ignore();
	Receipt Element(number, date, sum);
	return Element;
}

void Print_Receipt(Receipt Element)						// ������� ������ ������ �������
{
	Element.Show();								// ����� ������ ����� �������
}

int main()
{
	system("chcp 1251>nul");
	Receipt Elem1;									// ����� ������������ ��� ��������� ��� 1-�� �������
	Elem1.Show();								// ����� ������ ������ ����� 1-�� �������
	Receipt Elem2(8903784, "01.01.2001", 150.089);	// ����� ������������ � ����������� ��� 2-�� �������
	Elem2.Show();								// ����� ������ ������ ����� 2-�� �������
	Receipt Elem3 = Elem2;							// ����� ������������ ����������� ��� 3-�� ������� (����������� ����� 2-�� �������)
	Print_Receipt(Elem3);							// ������� ������ ������ 3-�� �������
	Elem3.set_number(111111);						// ����� ���������  3-�� �������
	Elem3.set_date("12.06.2000");			// ����� ��������� ����  3-�� �������
	Elem3.set_sum(240.708);						// ����� ��������� ����  3-�� �������
	Elem1 = make_Receipt();							// ����� ������� �������� ������� � ���������� ��� ����� ������� (���������� ������������� ������ ������� � ������������ 1-��)
	Elem1.Show();								// ����� ������ ����� 1-�� �������
}