﻿#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;
 // дихотомия
// отрезок [1, 2] - корректно работает; [3, 7] - просит ввести пользователя ввести интервал заново

const double eps = pow(10, -6);


double f(double x)
{  
    return pow(x, 2) - sin(x) - 1;
}


int main()
{   
    /*
    double a = 1;
    double b = 2;
    */
    setlocale(LC_ALL, "RUS");

    bool fl = false;
    
    while (fl == false)

    {   
        double a, b;
        cout << "Введите левую границу интервала: ";
        cin >> a;
        cout << "Введите правую границу интервала: ";
        cin >> b;

        if (f(a) * f(b) < 0) // проверка на сходимость
        {
            fl = true;
            cout << "_______________________________________________________________________";
            cout << "______________________________________________________________________" << endl;
            cout << "|               a                  |                b                |";
            cout << "             f(a)                 |             f(c)                   |" << endl;
            cout << "______________________________________________________________________";
            cout << "_______________________________________________________________________" << endl;

            while (abs(b - a) >= eps)
            {
                double c = (a + b) / 2;
                if (f(a) * f(c) < 0)
                    b = c;
                else
                    a = c;

                cout << fixed << setprecision(5) << "|" << a << "                           |" << b << "                          |"; // fixed << setprecision(5)  позволяет вывести заданное количество знаков после запятой
                cout << fixed << setprecision(5) << f(a) << "                          |" << f(c) << "                            |" << endl;
                cout << "_______________________________________________________________________";
                cout << "_______________________________________________________________________" << endl;
            }
            cout << a << endl;
        }
        else
            cout << "Измените рассматриваемый интервал" << endl;
    }
}       

