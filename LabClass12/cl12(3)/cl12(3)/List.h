#pragma once
#include <iostream>
#include <list>
#include <map>
using namespace std;


template <class T>
class List
{
private:
    map <T, T> m;
    int size;
public:
    List();
    List(int);										// Конструктор с параметрами: выделение под s элементов и заполнение их значением k
    ~List();															// Деструктор

    T average();
    void add(T);
    List <T> del(T, T);
    void change();
    void print();

};


template <class T>

List<T>::List() { size = 0; }


template <class T>

List<T>::List(int n)
{   
    T el, k;
    for (int i = 1; i <= n; i++)
    {
        cout << "\nenter key: \n";
        cin >> k;
        cout << "\nenter elem: \n";
        cin >> el;
        m.emplace(k, el);
    }
    size = m.size();
}

template <class T>

List<T>::~List() {}


template <class T>

void List<T>::print()
{
    for (auto it = m.begin(); it != m.end(); ++it)
        cout << "\nkey - value\n" << it->first << it->second << "\n";
    cout << endl;
}


template <class T>

T List<T>::average()
{
    T sum;
    size = 0;
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        sum += it->second;
        size++;
    }
    return sum / size;
}

template <class T>

void List<T>::add(T pos)
{
    T elem = average();
    if (m.count(pos))
    {
        cout << "adding with this key is not possible" << endl;	// ключ должен быть уникальный
        return;
    }
    else
    {
        m.insert(make_pair(pos, elem));
    }
}



template <class T>

List<T> List<T>::del(T l, T r)
{
    map <T, T> tmp = m;
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        if (it->first >= l and it->first <= r)
            tmp.erase(it->first);
    }
    m = tmp;
    return *this;
}


template <class T>

void List<T>::change()
{
    T el = average();
    for (auto it = m.begin(); it != m.end(); ++it)
        it->second -= el;
}


