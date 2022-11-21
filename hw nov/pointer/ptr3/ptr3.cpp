#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS"); 
    int a;              // идентифицируем переменную - выделяем память под переменную
    cout << "Введите значение переменной a: " << "\t";
    cin >> a;           // инициализируем переменную а - присваиваем значение
   
    int &aRef = a;      // ссылка на переменную    
    int *ptra = &a;     // указатель на переменную a
   
    cout << "aRef: " << aRef << endl;   // значение переменной, на которую ссылается переменная aRef
    cout << "&aRef: " << &aRef<< endl;  // адрес ячейки памяти переменной aRef
    cout << "&a: " << &a << endl;       // адрес ячейки памяти переменной a
    cout << "ptra: " << ptra << endl;   // указатель переменной а

    cout << "Введите новое значение переменной a: " << "\t";
    cin >> a;           // меняем значение переменной a

    cout << "NEW aRef: " << aRef << endl;
    cout << "NEW &aRef: " << &aRef << endl;
    cout << "NEW &a: " << &a << endl;
    cout << "NEW ptra: " << ptra << endl;
}