#include "Student.h"
#include <iostream>
using namespace std;

Student::Student()
{
	year = 0;
}

Student::Student(int Year)
{
	year = Year;
}

Student::Student(const Student& p)
{
	year = p.year;
	name = p.name;
	age = p.age;
}

Student::~Student()
{

}

int Student::get_year()
{
	return year;
}

void Student::set_year(int Year)
{
	year = Year;
}

Student& Student ::operator = (const Student& p)
{
	if (&p == this) return *this;
	name = p.name;
	age = p.age;
	year = p.year;
	return *this;
}

istream& operator >> (istream& in, Student& p)				// Оператор ввода
{
	
	cout << "\nINPUT NAME: ";
	in >> p.name;
	cout << "INPUT AGE: ";
	in >> p.age;
	cout << "INPUT YEAR: ";
	in >> p.year;
	return in;
}

ostream& operator << (ostream& out, const Student& p)		// Оператор вывода
{
	out << "\nNAME: " << p.name << endl;
	out << "AGE: " << p.age<<endl;
	out << "YEAR: " << p.year << endl;
	return out;
}

void Student::increase_year()
{
	year += 1;
}

void Student::Show()
{
	cout << "\nNAME: " << name;
	cout << "\nAGE: " << age;
	cout << "\nYEAR: " << year << endl;

}
