#include <iostream>
#include "Student.h"
#include "Person.h"
#include <string>
using namespace std;

void func1(Person& p)																// ������ �������� ������ ��� ��������
{
	p.set_name("����");
	p.set_age(18);
	cout << p;
}

Person func2()																			// ���������� ������ �������� ������ ��� ���������
{
	Student year(4);
	return year;
}

int main()
{
	system("chcp 1251>nul");
	
	cout << "class Student" << endl;
	Student A;
	cin >> A;
	cout << "\nObject A :\n" << A;

	A.increase_year();
	cout << "\n����� ������� A � ����� +1: \n" << A;

	cout << "\n�����������" << endl;
	func1(A);
	Person res = func2();			// ������������
	cout << "\nObject A:\n" << A;
	cout << "\nResult \n" << res;

	cout << "class Person" << endl;
	Person One;
	cout << "\n ������������� ����� ����������� �� ���������\n" << One;
	
	string name;
	int age;
	cout << "\nEnter Name: ";
	cin >> name;
	cout << "Enter Age: ";
	cin >> age;
	
	Person Two;
	Two.set_name(name);
	Two.set_age(age);
	cout << "\n ������������� ����� �����������\n" << Two;


	Person Three("����", 20);
	cout << "\n ������������� ����� ����������� � �����������\n" << Three;
	
	Person Four(Three);
	cout << "\n ������������� ����� ����������� �����������\n" << Four;

	Two = Four;
	cout << "\n ���������� �������� ������������\n" << Two;

}