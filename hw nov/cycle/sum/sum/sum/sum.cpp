#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    int l;
    cin >> l;
    int s = 0;

    for (int i = 1; i <= l; i++)
        s += i * (pow(-1, i));

    cout << "Результат выполнения. Цикл FOR: " << s << endl;

    s = 0;
    int i = 1;

    while (i <= l)
    {
        s += i * (pow(-1, i));
        i++;
    }
    
    cout << "Результат выполнения. Цикл WHILE: " << s << endl;

    i = 1;
    s = 0;
    do
    {
        s += i * (pow(-1, i));
        i++;
    } 
    while (i <= l);

    cout << "Результат выполнения. Цикл DO WHILE: " << s << endl;


}

