#pragma once
#include <iostream>
#include "Object.h"
#include <string>
using namespace std;

class Vector
{
private:
	Object** begin;														// ��������� �� ������ ������� �������
	int size;															// ������
	int cur;															// ������� �������

public: 
	Vector(); 
	Vector(int); // ����������� �����������
	~Vector();
	friend ostream& operator<< (ostream& out, const Vector& Pointer);	
	void Add(Object* p);												// ���������� �������� � ������

};

