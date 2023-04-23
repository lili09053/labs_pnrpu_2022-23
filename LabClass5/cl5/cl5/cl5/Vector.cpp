#include "Vector.h"

Vector::Vector()
{
	begin = nullptr;
	size = 0;
	cur = 0;
}

Vector::Vector(int N)
{
	begin = new Object * [N];
	size = N;
	cur = 0;
}

Vector::~Vector()
{
	if (begin != nullptr)
		delete[] begin;
	begin = nullptr;
}

void Vector::Add(Object* p)
{
	if (cur < size)
	{
		begin[cur] = p;
		cur++;
	}

}

ostream& operator<<(ostream& out, const Vector& vec)
{
	if (vec.size == 0)
		out << "Vector is empty!" << endl;
	else
	{
		Object** ptr = vec.begin;
		for (int i = 0; i < vec.cur; i++)
		{
			(*ptr)->Show();
			ptr++;
		}
	}
	return out;
}
