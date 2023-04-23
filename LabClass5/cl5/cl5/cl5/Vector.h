#pragma once
#include <iostream>
#include "Object.h"
#include <string>
using namespace std;

class Vector
{
private:
	Object** begin;														// Указатель на первый элемент вектора
	int size;															// Размер
	int cur;															// Текущая позиция

public: 
	Vector(); 
	Vector(int); // конструктор копирования
	~Vector();
	friend ostream& operator<< (ostream& out, const Vector& Pointer);	
	void Add(Object* p);												// Добавление элемента в вектор

};

