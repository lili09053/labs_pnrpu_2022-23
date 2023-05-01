#include "Human.h"
#include <iostream>
using namespace std;

Human::Human()
{
	Name = "";
	Age = 0;
}

Human::Human(string name, int age)
{
	Name = name;
	Age = age;
}

Human::Human(const Human& Ptr)
{
	Name = Ptr.Name;
	Age = Ptr.Age;
}

Human::~Human()
{

}

Human& Human::operator =(const Human& Ptr)
{
	if (&Ptr != this)
	{
		Name = Ptr.Name;
		Age = Ptr.Age;
	}
	return *this;
}

void Human::Show()
{
	cout << "\nВывод атрибутов...\n";
	cout << "Имя: " << Name << endl;
	cout << "Возраст: " << Age << endl << endl;
}

void Human::Input()
{
	cout << "\nВвод данных...\n\n";
	
	cout << "Введите имя: ";
	cin >> Name;
	
	cout << "Введите возраст: ";
	cin >> Age;
	
	while (Age <= 0)
	{
		cout << "Ошибка: возраст не может быть отрицательным. Введите новый возраст: ";
		cin >> Age;
	}
	cout << endl;
}