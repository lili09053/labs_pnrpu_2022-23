#pragma once
#include <iostream>
using namespace std;

struct Node
{
    int data = 0;
    Node* next = nullptr;
};


class Stack
{
private:
    int N; //временное количество элементов в стеке
    Node* peek;    // вершина стека

public:
    Stack();
    Stack(int);
    ~Stack();
    void Push(int);
    Node* Pop();
    bool is_empty();
    int size();
    friend ostream& operator <<(ostream&, const Stack&);
  
};









