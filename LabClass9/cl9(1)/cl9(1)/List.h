#pragma once
#include <iostream>
using namespace std;

#define MAX_SIZE 10

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


class List
{
private:
	int size;
	Node* head;
	Node* tail;
	//	Iterator beg;
	//	Iterator end;

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
	List operator+(int p);											// Операция сложения
	List& operator++(int elem);												 //добавление элемена в конец 

	void pushback(int); // добавление в конец

};

