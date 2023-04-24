#include "List.h"

List::List()
{

	head = nullptr;
	tail = nullptr;
	size = 0;
}

List::List(int n, int k)
{
    size = n;
    head = nullptr;                                  // пока нет элементов, помимо первого, нет и ссылки на следующий элемент
    tail = nullptr;
   
    Node* node = new Node;                           // выделение памяти под узел
    node->data = k;                                 // заполнение первого узла данными
    node->next = nullptr;
    node->prev = nullptr;
    
    head = node;                                     //присваиваем данные первому узлу
    tail = node;
    for (int i = 1; i < n; i++)
    {
        Node* NewNode = new Node;                   // Выделение  димнамической памяти под новый элемент
        Node* PrevNode = node;                      //Указатель на "предыдущий" элемент(изначально тот, на котором стоит указатель на следующий)
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

List::List(const List&p)
{
    Node* node = p.head;
    while (node != nullptr) 
    {
        pushback(node->data);
        node = node->next;
    }
    beg.elem = head;
    end.elem = tail->next;
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
    end.elem = tail;
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

List List::operator+(List& p) 
{
    int tmpSize;
    if (size > p.size)
        tmpSize = p.size;
    else 
        tmpSize = size;
   
    List tmpList(tmpSize);
    for (int i = 0; i < tmpSize; i++) 
        tmpList[i] = (*this)[i] + p[i];
    return tmpList;

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
        cout << "Index outside!" << endl;
        exit(7);
    }
}

int& List::operator()() 
{
    return size;
}

List& List::operator=(const List&p)
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
    beg.elem = head;
    end.elem = tail->next;
    return *this;
}