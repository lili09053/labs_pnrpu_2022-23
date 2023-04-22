#include <iostream>
#include "Student.h"
#include "Person.h"
#include <string>
using namespace std;

void func1(Person& p)																// Объект базового класса как параметр
{
	p.set_name("Вася");
	p.set_age(18);
	cout << p;
}

Person func2()																			// Возвращает объект базового класса как результат
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
	cout << "\nВывод объекта A с годом +1: \n" << A;

	cout << "\nПодстановка" << endl;
	func1(A);
	Person res = func2();			// подставновка
	cout << "\nObject A:\n" << A;
	cout << "\nResult \n" << res;

	cout << "class Person" << endl;
	Person One;
	cout << "\n Инициализация через конструктор по умолчанию\n" << One;
	
	string name;
	int age;
	cout << "\nEnter Name: ";
	cin >> name;
	cout << "Enter Age: ";
	cin >> age;
	
	Person Two;
	Two.set_name(name);
	Two.set_age(age);
	cout << "\n Инициализация через модификатор\n" << Two;


	Person Three("Петя", 20);
	cout << "\n Инициализация через конструктор с параметрами\n" << Three;
	
	Person Four(Three);
	cout << "\n Инициализация через конструктор копирования\n" << Four;

	Two = Four;
	cout << "\n Перегрузка операции присваивания\n" << Two;

}