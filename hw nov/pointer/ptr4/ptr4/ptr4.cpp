#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    
    int a;
    int *ptra = &a;
    cout << "Введите значение переменной a:\t";
    cin >> *ptra;
     
    cout << "____________________ БЛОК ПРОВЕРКИ #1___________________________" << endl << endl;
    cout << "&a\t" << &a << endl;
    cout << "ptra\t" << ptra << endl;
    cout << "*ptra\t" << *ptra << endl;
    cout << "a\t" << a << endl;
    cout << "==============================================================" << endl << endl;

    int **ptr_ptra = &ptra;
    cout << **ptr_ptra << endl;
    cout << "Введите новое значение переменной a:\t";
    cin >> **ptr_ptra;


    cout << "____________________ БЛОК ПРОВЕРКИ #2___________________________" << endl << endl;
    cout << "&a\t" << &a << endl;
    cout << "ptra\t" << ptra << endl;
    cout << "*ptra\t" << *ptra << endl;
    cout << "a\t" << a << endl;
    cout << "ptr_ptra\t" << ptr_ptra << endl;
    cout << "**ptr_ptra\t" << **ptr_ptra << endl;
    cout << "a\t" << a << endl;
    cout << "==============================================================" << endl << endl;
   

}

