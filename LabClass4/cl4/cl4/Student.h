#pragma once
#include "Person.h"
class Student : public Person
{
private:
	int year;

public:
	Student();
	Student(int Year);
	Student(const Student& p);
	~Student();

	int get_year();
	void set_year(int Year);

	Student& operator= (const Student& p);								// Оператор присваивания
	friend istream& operator>> (istream& in, Student& p);			// Оператор вывода
	friend ostream& operator<< (ostream& out, const Student& p); // Оператор ввода
	void increase_year();
};

