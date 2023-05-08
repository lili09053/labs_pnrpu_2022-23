#pragma once
#include <iostream>
#include <list>
#include <queue>
using namespace std;


template <class T>
class List
{
private:
    priority_queue <T> pq;
    int size;
public:
    List();
    List(int);										// Конструктор с параметрами: выделение под s элементов и заполнение их значением k
    ~List();															// Деструктор

    T average();
    void add();
    void del(int, int);
    void change();
    void print();

};


template <class T>

List<T>::List() { size = 0; }


template <class T>

List<T>::List(int n)
{
    T el;
    for (int i = 0; i < n; i++)
    {
        cin >> el;
        pq.push(el);
    }
    size = pq.size();
}

template <class T>

List<T>::~List() {}


template <class T>

void List<T>::print()
{
    priority_queue<T> tmp;
    while (!pq.empty())
    {
        T el = pq.top();
        cout << el << "\n";
        tmp.push(el);
        pq.pop();
    }
    swap(tmp, pq);
    cout << endl;
}


template <class T>

T List<T>::average()
{
    T sum;
    size = pq.size();
    priority_queue<T> tmp = pq;
    while (!tmp.empty())
    {
        sum += tmp.top();
        tmp.pop();
    }
    return sum / size;
}

template <class T>

void List<T>::add()
{
    T el = average();
    pq.push(el);
}



template <class T>

void List<T>::del(int l, int r)
{
    priority_queue <T> tmp;
    int i = 1;

    while (!pq.empty())
    {
        T el = pq.top();
        if (i < l or i > r) tmp.push(el);
        pq.pop();
        i++;
    }
    swap(tmp, pq);
}

template <class T>

void List<T>::change()
{
    T el = average();
    priority_queue <T> tmp;
    while (!pq.empty())
    {
        T elem = pq.top();
        T em = elem - el;
        tmp.push(em);
        pq.pop();
    }
    swap(tmp, pq);
}


