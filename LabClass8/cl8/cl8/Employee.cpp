#include "Employee.h"

#include "Employee.h"
#include <iostream>

using namespace std;

Employee::Employee() : Human()
{
	Salary = 0;
	Position = "-";
}

Employee::Employee(string name, int age, float Salary, string pos) : Human(name, age)
{
	this->Salary = Salary;
	this->Position = pos;
}

Employee::Employee(const Employee& Ptr)
{
	Name = Ptr.Name;
	Age = Ptr.Age;
	Salary = Ptr.Salary;
	Position = Ptr.Position;
}

Employee::~Employee() {}

Employee& Employee::operator =(const Employee& Ptr)
{
	if (&Ptr != this)
	{
		Name = Ptr.Name;
		Age = Ptr.Age;
		Salary = Ptr.Salary;
		Position = Ptr.Position;
	}
	return *this;
}

void Employee::Show()
{
	cout << "\nВывод атрибутов...\n";
	cout << "Имя: " << Name << endl;
	cout << "Возраст: " << Age << endl;
	cout << "ЗП: " << Salary << endl << endl;
	cout << "Должность: " << Position << endl << endl;
}

void Employee::Input()
{
	cout << "\nВвод данных...\n\n";
	cout << "Введите имя: ";
	cin >> Name;
	cout << "Введите возраст: ";
	cin >> Age;
	while (Age <= 0)
	{
		cout << "Ошибка! Возраст не может быть отрицательным. Введите новый возраст: ";
		cin >> Age;
	}
	cout << "Введите ЗП: ";
	cin >> Salary;
	while (Salary <= 0)
	{
		cout << "Очень жаль, что ЗП отрицательная. Попытайтель исправить это ^_^ : ";
		cin >> Salary;
	}

	cout << "Введите должность: ";
	cin >> Position;

	cout << endl;
}