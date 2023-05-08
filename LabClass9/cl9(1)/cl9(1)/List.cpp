#include "List.h"

#define SIZE_ERROR 1
#define MIN_INDEX_ERROR 2
#define MAX_INDEX_ERROR 3
#define FULL_SIZE_ERROR 4

List::List()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

List::List(int n, int k)
{
    if (n > MAX_SIZE || n < 1) throw SIZE_ERROR;
    size = n;
    head = nullptr;                                  // ���� ��� ���������, ������ �������, ��� � ������ �� ��������� �������
    tail = nullptr;

    Node* node = new Node;                           // ��������� ������ ��� ����
    node->data = k;                                 // ���������� ������� ���� �������
    node->next = nullptr;
    node->prev = nullptr;

    head = node;                                     //����������� ������ ������� ����
    tail = node;
    for (int i = 1; i < n; i++)
    {
        Node* NewNode = new Node;                   // ���������  ������������� ������ ��� ����� �������
        Node* PrevNode = node;                      //��������� �� "����������" �������(���������� ���, �� ������� ����� ��������� �� ���������)
        node->next = NewNode;
        node = node->next;                          // ������� ���������� �� ��������� �������
        node->data = k;               // ������ ������ ��������
        node->next = nullptr;                       // ��������� �� ��������� ������� ����� ����, �. �. ��� ������� ��������� �������
        node->prev = PrevNode;
    }

    tail = node;
}

List::List(const List& p)
{
    Node* node = p.head;
    while (node != nullptr)
    {
        pushback(node->data);
        node = node->next;
    }
}

void List::pushback(int k)
{
    Node* newNode = new Node;
    newNode->data = k;
    if (head == nullptr)
        head = newNode;
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
    }
    tail = newNode;
    size++;
}

List::~List()
{
    Node* tmp = head;
    while (tmp != nullptr)
    {
        head = tmp->next;
        delete tmp;
        tmp = head;
    }
}

ostream& operator<<(ostream& out, const List& p)
{
    Node* tmp = p.head;
    while (tmp != nullptr)
    {
        out << tmp->data << " ";
        tmp = tmp->next;
    }
    out << endl;
    return out;
}
istream& operator>>(istream& in, const List& p)
{
    Node* tmp = p.head;
    while (tmp != nullptr)
    {
        in >> tmp->data;
        tmp = tmp->next;
    }
    return in;
}


List List::operator+(int p)
{
    List tmpList(this->size);
    for (int i = 0; i < tmpList.size; i++)
        tmpList[i] = (*this)[i] + p;

    return tmpList;
}

List& List::operator++(int elem)
{
    if (size >= MAX_SIZE) throw FULL_SIZE_ERROR;
    this->pushback(elem);
    return *this;
}

int& List::operator[](int index)
{
    if (index < size && index >= 0)
    {
        Node* tmp = head;
        for (int i = 0; i < index; i++) tmp = tmp->next;
        return tmp->data;
    }
    else
    {
        if (index >= size)
        {
            throw MAX_INDEX_ERROR;
        }
        if (index < 0)
        {
            throw MIN_INDEX_ERROR;
        }
    }
}

int& List::operator()()
{
    return size;
}

List& List::operator=(const List& p)
{
    if (this == &p) return *this;
    Node* node = head;
    while (node != nullptr) {
        head = node->next;
        delete node;
        node = head;
        size--;
    }
    Node* curr = p.head;
    while (curr != nullptr) {
        pushback(curr->data);
        curr = curr->next;
    }

    return *this;
}