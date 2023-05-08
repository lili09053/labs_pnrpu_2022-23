#include "Pair.h"

Pair::Pair()
{
	a = 0;
	b = 0.0;
}

Pair::Pair(int A, double B)
{
	a = A;
	b = B;
}

Pair::Pair(const Pair& p)
{
	a = p.a;
	b = p.b;
}

Pair::~Pair()
{

}

int Pair::get_a()
{
	return a;
}

void Pair::set_a(int A)
{
	a = A;
}

double Pair::get_b()
{
	return b;
}

void Pair::set_b(double B)
{
	b = B;
}

Pair& Pair::operator ++()									// Оператор префиксного инкремента
{
	++a;
	return *this;
}

Pair& Pair::operator ++(int)							// Оператор постфиксного инкремента
{
	b++;
	return *this;
}

Pair& Pair::operator = (const Pair& Link)				// Оператор присваивания
{
	if (&Link != this)
	{
		a = Link.a;
		b = Link.b;
	}
	return *this;
}

bool operator < (Pair& p, Pair& q)						// Оператор сравнения
{
	if (p.a < q.a)
	{
		return true;
	}
	else
	{
		if (p.a > q.a)
		{
			return false;
		}
		else
		{
			if (p.b < q.b)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

bool operator > (Pair& p, Pair& q)						// Оператор сравнения
{
	if (p.a > q.a)
	{
		return true;
	}
	else
	{
		if (p.a < q.a)
		{
			return false;
		}
		else
		{
			if (p.b > q.b)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

istream& operator >> (istream& in, Pair& Pointer)			// Оператор ввода
{
	cout << "input a: ";
	in >> Pointer.a;

	cout << "input b: ";
	in >> Pointer.b;

	return in;
}

ostream& operator << (ostream& out, const Pair& Pointer)	// Оператор вывода
{
	cout << "a:b  ";
	return (out << Pointer.a << " : " << Pointer.b << "\n");
}

Pair& Pair::operator /(const int x)
{
	a = a / x;
	b = b / x;
	return *this;
}

Pair& Pair::operator +=(const Pair& p)
{
	this->a += p.a;
	this->b += p.b;
	return *this;
}

Pair& Pair::operator -(const Pair& p) {
	this->a -= p.a;
	this->b -= p.b;
	return *this;
}