#pragma once
#include <iostream>
#include <list>
using namespace std;


template <class T>
class List
{
private:
    list <T> lst;
    int size;
public:
    List();
    List(int);										// Конструктор с параметрами: выделение под s элементов и заполнение их значением k
    ~List();															// Деструктор

    T average();
    void add(int);
    void del(int, int);
    void change();
    void print();
    
};


template <class T>

List<T>::List() { size = 0;}


template <class T>

List<T>::List(int n)
{
    T el;
    for (int i = 0; i < n; i++)
    {
        cin >> el;
        lst.push_back(el);
    }
    size = lst.size();
}

template <class T>

List<T>::~List() {}


template <class T>

void List<T>::print()
{
    for (auto it = lst.begin(); it != lst.end(); it++)
        cout << *it;
    cout << endl;
}


template <class T>

T List<T>::average()
{
    T sum;
    for (auto it = lst.begin(); it != lst.end(); it++)
        sum += *it;
    size = lst.size();
    return sum / size;
}

template <class T>

void List<T>::add(int pos)
{
    T elem = average();
    auto it = lst.begin();
    advance(it, pos - 1); // -1, т.к учитывается begin
    lst.insert(it, elem);
}



template <class T>

void List<T>::del(int start, int finish)
{
    auto it = lst.begin();
    advance(it, start - 1);
    auto start_it = it;
    it = lst.begin();
    advance(it, finish);
    auto finish_it = it;
    lst.erase(start_it, finish_it);
}

template <class T>

void List<T>::change()
{
    T elem = average();
    for (auto it = lst.begin(); it != lst.end(); it++)
        *it = *it - elem;
}


