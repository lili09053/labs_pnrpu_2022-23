#include "Stack.h"
#include <iostream>
using namespace std;


Stack::Stack()
{
    N = 0;
    peek = nullptr;
}

Stack::Stack(int size)
{
    for (int i = 0; i < size; i++)
        Push(rand() % 25 - 15);
    N = size;
}

Stack::~Stack()
{
    while (N != 0)
    {
        Node* tmp = Pop();
        delete tmp;
    }
}

void Stack::Push(int elem) // Добавление элемента в вершину стека
{
    Node* node = new Node; // выделение памяти под узел
    node->data = elem;
    node->next = peek;
    peek = node;
    N++;
}


Node* Stack::Pop()            // удаление из вершины стека
{
    Node* delElem = peek;
    peek = peek->next;
    delElem->next = nullptr;
    N--;
    return delElem;
}

bool Stack::is_empty()
{
    return N == 0;
}

int Stack::size()
{
    return N;
}


ostream& operator<<(ostream& out, const Stack& p)
{
    Node* first = p.peek;
    while (first != NULL)
    {
        cout << first->data << " ";
        first = first->next;
    }
    cout << endl;
    return out;
}
