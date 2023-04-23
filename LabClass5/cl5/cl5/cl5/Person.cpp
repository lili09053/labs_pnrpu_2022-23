#include "Person.h"
#include "Object.h"
#include<string>
#include <iostream>
using namespace std;

Person::Person()
{
	name = " ";
	age = 0;
}

Person::Person(string Name, int Age)
{
	name = Name;
	age = Age;
}

Person::Person(const Person& p)
{
	name = p.name;
	age = p.age;
}

Person::~Person()
{

}

string Person::get_name()
{
	return name;
}

void Person::set_name(string Name)
{
	name = Name;
}

int Person::get_age()
{
	return age;
}

void Person::set_age(int Age)
{
	age = Age;
}

Person& Person ::operator = (const Person& p)
{
	name = p.name;
	age = p.age;

	return *this;
}

istream& operator >> (istream& in, Person& p)				// Оператор ввода
{
	cout << "INPUT NAME: ";
	in >> p.name;
	cout << "INPUT AGE: ";
	in >> p.age;
	return in;
}

ostream& operator << (ostream& out, const Person& p)		// Оператор вывода
{
	out << "\nNAME: " << p.name << endl;
	out << "AGE: " << p.age << endl;

	return out;
}

void Person::Show()
{
	cout << "\nNAME: " << name;
	cout << "\nAGE: " << age << endl;
}
