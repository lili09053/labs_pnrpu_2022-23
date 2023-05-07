#include "Stack.h"
#include <iostream>
#include <ctime>
using namespace std;


int main()
{
    system("chcp 1251>NULL");
    srand(time(NULL));

    Stack A;
    cout << A << endl;

    cout << A.is_empty() << endl;
    
    A.Push(8);
    A.Push(10);
    cout << A << endl;
    cout << A.size() << endl;

    A.Pop();
    cout << A << endl;

    Stack B(10);
    cout << B << endl;
   
}
