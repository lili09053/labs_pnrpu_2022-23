// iteration.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <math.h>
using namespace std;

const double eps = pow(10, -6);


double f(double x)              //функция от х
{
    return pow(x, 2) - sin(x) - 1;      //    x^2 - sin(x) - 1
}                                       //  |x| = sqrt(sin(x) + 1)

double fi(double x)
{
    return pow((sin(x) + 1), 0.5);          // fi(x) = sqrt(sin(x) + 1)
}

double y(double x)                          // y = |x|
{
    return abs(x);
}

long double dfi(double x) // первая производная функции fi
{
    return (fi(x + eps) - fi(x)) / eps; // производная функции по определению

}


long double df(double x) // первая производная функции f
{
    return (f(x + eps) - f(x)) / eps; // производная функции по определению

}



bool monot(double a, double b)   //  если интервал, например, [-0.9;1] - заходит в проверку
{
    bool flMon = true;
    while (a <= b && flMon == true)        // рассматриваем монотонность функц на интервале 
    {
        if (df(a) * df(b) <= 0)     // функция монотонно возрастает или убывает
            flMon = false;
        a += eps;
    }
    return flMon;
}


int main()
{
    setlocale(LC_ALL, "RUS");

    bool fl = false;

    while (fl == false)

    {
        double a, b;
        cout << "Введите левую границу интервала: ";
        cin >> a;
        cout << "Введите правую границу интервала: ";
        cin >> b;

        if (b < a)
        {
            double n; // промежyточная переменная
            n = a;
            a = b;
            b = n; // поменяли местами значения

        }


        if (monot(a, b) == true) // проверка на мнотонность
        {
            fl = true;
            double x0 = a;
            double x = fi(x0);
                
            if (abs(dfi(x0) < 1) && abs(dfi(b) < 1)
            {
                int ltr = 0;

                while (abs(x - x0) >= eps)
                {
                    ltr += 1;
                    x0 = x;
                    x = fi(x0);
                }

                cout << x << endl;
                cout << "Количество итераций: " << ltr << endl;

            }
            else
            {
                cout << "Условие на сходимость не выполнено. Введите интервал повторно.";
                fl = false;
            }
        }
        
        else
        {
            cout << "Функция на интервале не монотонна. Введите другой интервал." << endl;
            fl = false;
        }
    
        
    }
}
