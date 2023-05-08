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
	List(int n, int k = 0);										// ����������� � �����������: ��������� ��� s ��������� � ���������� �� ��������� k
	List(const List&);												// ����������� �����������

	~List();															// ����������

	friend ostream& operator <<(ostream&, const List&);
	friend istream& operator >>(istream&, const List&);
	List& operator=(const List&);

	int& operator[](int index);										// �������� ������� �� �������
	int& operator()();												// ����� ������
	List operator+(int p);											// �������� ��������
	List& operator++(int elem);												 //���������� ������� � ����� 

	void pushback(int); // ���������� � �����

};

