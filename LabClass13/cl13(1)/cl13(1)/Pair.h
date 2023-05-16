#pragma once
#include <iostream>
using namespace std;

class Pair
{
private:
	int a;
	double b;

public:
	Pair();
	Pair(int A, double B);
	Pair(const Pair& p);
	~Pair();

	int get_a();
	void set_a(int A);

	double get_b();
	void set_b(double B);

	Pair& operator ++();												// Оператор префиксного инкремента
	Pair& operator ++(int);										// Оператор постфиксного инкремента
	Pair& operator = (const Pair& Link);								// Оператор присваивания
	friend bool operator < (const Pair& p, const Pair& q);						// Оператор сравнения
	friend bool operator > (const Pair& p, const Pair& q);						// Оператор сравнения
	friend bool operator ==(const Pair& p, const Pair& q);
	friend istream& operator >> (istream& in, Pair& Pointer);			// Оператор ввода
	friend ostream& operator << (ostream& out, const Pair& Pointer);	// Оператор вывода
	Pair& operator /(const int);
	Pair& operator +=(const Pair& p);
	Pair& operator -(const Pair& p);
	friend bool operator <= (const Pair& p, const Pair& q);						// Оператор сравнения
	friend bool operator >= (const Pair& p, const Pair& q);
	Pair& operator -=(const Pair& p);

	friend Pair& operator-(const Pair& p,  const Pair& q);
};




