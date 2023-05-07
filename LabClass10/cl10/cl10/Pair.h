#pragma once
#include <iostream>
#include <fstream>
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
	friend bool operator < (Pair& p, Pair& q);						// Оператор сравнения
	friend bool operator > (Pair& p, Pair& q);						// Оператор сравнения
	friend istream& operator >> (istream& in, Pair& p);			// Оператор ввода
	friend ostream& operator << (ostream& out, const Pair& p);	// Оператор вывода в консоль
	friend fstream& operator >> (fstream& fin, Pair& p);			// Оператор ввода
	friend fstream& operator << (fstream& fout, const Pair& p);	// Оператор вывода в консоль
	Pair& operator +(const int);
	Pair& operator +(const double);
};






