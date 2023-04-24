﻿#pragma once
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;

	Node()
	{
		data = 0;
		next = nullptr;
		prev = nullptr;
	}
};

class Iterator
{
private:
	friend class List;
	Node* elem;

public:
	Iterator() 
	{
		elem = nullptr; 
	}

	Iterator(const Iterator& it) 
	{ 
		elem = it.elem; 
	}
	
	Iterator& operator=(const Iterator& p) 
	{
		elem = p.elem;
		return *this;
	}

	bool operator==(const Iterator& it) 
	{ 
		return elem == it.elem; 
	}
	
	bool operator!=(const Iterator& it) 
	{ 
		return elem != it.elem; 
	}
	
	Iterator& operator++()
	{
		elem = elem->next;
		return *this;
	}
	
	Iterator& operator--() 
	{
		elem = elem->prev;
		return *this;
	}

	Iterator& operator+(const int& p) 
	{
		for (int i = 0; i < p; i++) elem = elem->next;
		return *this;
	}
	Iterator& operator-(const int& p) 
	{
		for (int i = 0; i < p; i++) elem = elem->prev;
		return *this;
	}
	
	int& operator *() const 
	{
		return elem->data; 
	}
};



class List
{
private:
	int size;
	Node* head;
	Node* tail;
	Iterator beg;
	Iterator end;

public:
	List();
	List(int n, int k = 0);										// Конструктор с параметрами: выделение под s элементов и заполнение их значением k
	List(const List&);												// Конструктор копирования
	
	~List();															// Деструктор
	
	friend ostream& operator <<(ostream&, const List&);
	friend istream& operator >>(istream&, const List&);
	List& operator=(const List&);
	
	int& operator[](int index);										// Операция доступа по индексу
	int& operator()();												// Длина списка
	List operator+(List& el);											// Операция сложения
	List& operator++(); // префиксная форма. Переход к другому элемента с помощью итератора

	Iterator first() 
	{ 
		return beg; 
	}
	Iterator last() 
	{
		return end; 
	}
	void pushback(int); // добавление в конец

};

