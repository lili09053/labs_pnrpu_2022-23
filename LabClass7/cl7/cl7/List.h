#pragma once
#include <iostream>
using namespace std;
#ifndef LIST_H 
#define LIST_H 

template <class T>

struct Node
{
	T data;
	Node<T>* next;
	Node<T>* prev;

	Node()
	{
		next = nullptr;
		prev = nullptr;
	}
};

template <class T>

class Iterator
{
private:
	template <class T>
	friend class List;
	Node<T>* elem;

public:
	Iterator()
	{
		elem = nullptr;
	}

	Iterator(const Iterator<T>& it)
	{
		elem = it.elem;
	}

	Iterator<T>& operator=(const Iterator<T>& p)
	{
		elem = p.elem;
		return *this;
	}

	bool operator==(const Iterator<T>& it)
	{
		return elem == it.elem;
	}

	bool operator!=(const Iterator<T>& it)
	{
		return elem != it.elem;
	}

	Iterator<T>& operator++()
	{
		elem = elem->next;
		return *this;
	}

	Iterator<T>& operator--()
	{
		elem = elem->prev;
		return *this;
	}

	Iterator<T>& operator+(const int& p)
	{
		for (int i = 0; i < p; i++) elem = elem->next;
		return *this;
	}
	Iterator<T>& operator-(const int& p)
	{
		for (int i = 0; i < p; i++) elem = elem->prev;
		return *this;
	}

	T& operator *() const
	{
		return elem->data;
	}
};


template <class T>

class List
{
private:
	int size;
	Node<T>* head;
	Node<T>* tail;
	Iterator<T> beg;
	Iterator<T> end;

public:
	List();
	List(int n, T k = *(new T()));										// Конструктор с параметрами: выделение под s элементов и заполнение их значением k
	List(const List<T>&);												// Конструктор копирования

	~List();															// Деструктор

	friend ostream& operator << <T>(ostream&, const List<T>&);
	friend istream& operator >> <T>(istream&, const List<T>&);
	List<T>& operator=(const List<T>&);

	T& operator[](int index);										// Операция доступа по индексу
	int& operator()();												// Длина списка
	List<T> operator+(List<T>& el);											// Операция сложения
	List<T>& operator++(); // префиксная форма. Переход к другому элемента с помощью итератора

	Iterator<T> first()
	{
		return beg;
	}
	Iterator<T> last()
	{
		return end;
	}
	void pushback(T); // добавление в конец

};


template <class T>

List<T>::List()
{

    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <class T>

List<T>::List(int n, T k)
{
    size = n;
    head = nullptr;                                  // пока нет элементов, помимо первого, нет и ссылки на следующий элемент
    tail = nullptr;

    Node<T>* node = new Node<T>;                           // выделение памяти под узел
    node->data = k;                                 // заполнение первого узла данными
    node->next = nullptr;
    node->prev = nullptr;

    head = node;                                     //присваиваем данные первому узлу
    tail = node;
    for (int i = 1; i < n; i++)
    {
        Node<T>* NewNode = new Node<T>;                   // Выделение  димнамической памяти под новый элемент
        Node<T>* PrevNode = node;                      //Указатель на "предыдущий" элемент(изначально тот, на котором стоит указатель на следующий)
        node->next = NewNode;
        node = node->next;                          // Переход указателем на следующий элемент
        node->data = k;               // Запись нового элемента
        node->next = nullptr;                       // Указатель на следующий элемент равен нулю, т. к. был записан последний элемент
        node->prev = PrevNode;
    }

    tail = node;
    beg.elem = head;
    end.elem = tail->next;
}

template <class T>

List<T>::List(const List<T>& p)
{
    Node<T>* node = p.head;
    while (node != nullptr)
    {
        pushback(node->data);
        node = node->next;
    }
    beg.elem = head;
    end.elem = tail->next;
}

template <class T>

void List<T>::pushback(T k)
{
    Node<T>* newNode = new Node<T>;
    newNode->data = k;
    if (head == nullptr)
        head = newNode;
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
    }
    tail = newNode;
    end.elem = tail;
    size++;
}

template <class T>

List<T>::~List()
{
    Node<T>* tmp = head;
    while (tmp != nullptr)
    {
        head = tmp->next;
        delete tmp;
        tmp = head;
    }
}

template <class T>

ostream& operator<<(ostream& out, const List<T>& p)
{
    Node<T>* tmp = p.head;
    while (tmp != nullptr)
    {
        out << tmp->data << " ";
        tmp = tmp->next;
    }
    out << endl;
    return out;
}

template <class T>

istream& operator>>(istream& in, const List<T>& p)
{
    Node<T>* tmp = p.head;
    while (tmp != nullptr)
    {
        in >> tmp->data;
        tmp = tmp->next;
    }
    return in;
}

template <class T>

List<T> List<T>::operator+(List<T>& p)
{
    int tmpSize;
    if (size > p.size)
        tmpSize = p.size;
    else
        tmpSize = size;

    List<T> tmpList(tmpSize);
    for (int i = 0; i < tmpSize; i++)
        tmpList[i] = (*this)[i] + T(p[i]);
    return tmpList;

}

template <class T>

T& List<T>::operator[](int index)
{
    if (index < size && index >= 0)
    {
        Node<T>* tmp = head;
        for (int i = 0; i < index; i++) tmp = tmp->next;
        return tmp->data;
    }
    else
    {
        cout << "Index outside!" << endl;
        exit(7);
    }
}

template <class T>

int& List<T>::operator()()
{
    return size;
}

template <class T>

List<T>& List<T>::operator=(const List<T>& p)
{
    if (this == &p) return *this;
    Node<T>* node = head;
    while (node != nullptr) {
        head = node->next;
        delete node;
        node = head;
        size--;
    }
    Node<T>* curr = p.head;
    while (curr != nullptr) {
        pushback(curr->data);
        curr = curr->next;
    }
    beg.elem = head;
    end.elem = tail->next;
    return *this;
}

#endif