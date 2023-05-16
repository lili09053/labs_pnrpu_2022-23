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

	Pair& operator ++();												// �������� ����������� ����������
	Pair& operator ++(int);										// �������� ������������ ����������
	Pair& operator = (const Pair& Link);								// �������� ������������
	friend bool operator < (const Pair& p, const Pair& q);						// �������� ���������
	friend bool operator > (const Pair& p, const Pair& q);						// �������� ���������
	friend bool operator ==(const Pair& p, const Pair& q);
	friend istream& operator >> (istream& in, Pair& Pointer);			// �������� �����
	friend ostream& operator << (ostream& out, const Pair& Pointer);	// �������� ������
	Pair& operator /(const int);
	Pair& operator +=(const Pair& p);
	Pair& operator -(const Pair& p);
	friend bool operator <= (const Pair& p, const Pair& q);						// �������� ���������
	friend bool operator >= (const Pair& p, const Pair& q);
	Pair& operator -=(const Pair& p);

	friend Pair& operator-(const Pair& p,  const Pair& q);
};




