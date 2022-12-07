#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a, b, c; // вводим длины сторон произвольно, т.е. мы не знаем, какая длина максимальная
    cin >> a >> b >> c;

    bool f = false;
    int x = 0;              // единственое значение x которое необходимо по условию задачи
    

    int * maxLen = &x; // инициализировали переменные, чтобы избежать ошибок. Это ни на что не влияет, т.к адрес ячейки сменится
    int * len1 = &x;    // инициализировали переменные, чтобы избежать ошибок. Это ни на что не влияет, т.к адрес ячейки сменится
    int * len2 = &x;    // инициализировали переменные, чтобы избежать ошибок. Это ни на что не влияет, т.к адрес ячейки сменится
   
    if (c > a && c > b)
    {
        maxLen = &c;
        len1 = &a;
        len2 = &b;
    }
    else
    {
        if (a > c && a > b)
        {
            maxLen = &a;
            len1 = &b;
            len2 = &c;
        }
    }
    if (b > a && b > c)
    {
        maxLen = &b;
        len1 = &a;
        len2 = &c;
    }


    if (*maxLen < (*len1 + *len2)) // выясняем соответствует ли максимальное значение условию существования треугольника
    {
        int d0 = *maxLen - *len1 - *len2;
        int d = pow((-2 * d0), 2) - 4 * (pow(*len1, 2) + pow(*len2, 2) - pow(*maxLen, 2)); // дискриминант должен быть целым, чтобы вывести целое значение x
        if (d > 0 and pow(pow(d, 0.5), 2) == d) // проверка на иррациональность дискриминанта. опора на накопительную ошибку
        {
            int x1 = (2 * d0 + pow(d, 0.5)) / 2; // находим значение x1
            int x2 = (2 * d0 - pow(d, 0.5)) / 2; // находим значение x2

            if (x2 > 0 and x1 > 0)              // проверка условий 
            {
                if (x1 > x2)                    // максимальное значение среди  x1, x2 
                    x = x1;
                else
                    x = x2;
            }
            else
            {
                if (x2 > 0 and x1 < 0 and abs(x2) == abs(x1)) // вывод положительного числа среди двух чисел, равных по модулю --- вывод положительного
                    x = x2;

                else
                {
                    if (x1 > 0 and x2 < 0 and abs(x2) == abs(x1)) // вывод положительного числа среди двух чисел, равных по модулю --- вывод положительного
                        x = x1;
                    else
                    {
                        if (x2 > 0 and x1 < 0 and abs(x2) != abs(x1))  // выводим положительное
                            x = x2;
                        else
                        {
                            if (x1 > 0 and x2 < 0 and abs(x2) != abs(x1))
                                x = x1;
                            else
                            {
                                if (x2 < 0 and x1 < 0)
                                {
                                    if (x1 > x2)
                                        x = x1;
                                    else
                                        x = x2;
                                }
                            }
                        }
                    }
                }
            }
          
           if (x > (c - a - b) and x > (a - b - c) and x > (b - a - c) and (a + x) > 0 and (b + x) > 0 and (c + x) > 0)
                f = true;
        }
    }
/*


    if (c > a and c > b and c < (a + b)) // выясняем максимально ли c и проверяем, соответствует ли оно условию существования треугольника
    {
        int d = pow((-2 * d0), 2) - 4 * (pow(a, 2) + pow(b, 2) - pow(c, 2)); // дискриминант должен быть целым, чтобы вывести целое значение x
        if (d > 0)
        {
            int x1 = (2 * d0 + pow(d, 0.5)) / 2; // находим значение x1
            int x2 = (2 * d0 - pow(d, 0.5)) / 2; // находим значение x2
                                        

            if (x2 > 0 and x1 > 0)              // проверка условий 
            {
                if (x1 > x2)                    // максимальное значение среди  x1, x2 
                    x = x1;
                else
                    x = x2;
            }
            else
            {
                if (x2 > 0 and x1 < 0 and abs(x2) == abs(x1))
                    x = x2;

                else
                {
                    if (x1 > 0 and x2 < 0 and abs(x2) == abs(x1))
                        x = x1;
                    else
                    {
                        if (x2 > 0 and x1 < 0 and abs(x2) != abs(x1))
                            x = x2;
                        else
                        {
                            if (x1 > 0 and x2 < 0 and abs(x2) != abs(x1))
                                x = x1;
                            else
                            {
                                if (x2 < 0 and x1 < 0)
                                {
                                    if (x1 > x2)
                                        x = x1;
                                    else
                                        x = x2;
                                }
                            }
                        }
                    }
                }
            }
            if (x > d0 and x > d1 and x > d2 and (a + b) > (c - x) and (a + x) > 0 and (b + x) > 0 and (c + x) > 0)
                f = true;
        }
    
    }
   
    
    
    if (b > a and c < b and b < (c + a)) // выясняем максимально ли c и проверяем, соответствует ли оно условию существования треугольника
    {
        int d = pow((-2 * d2), 2) - 4 * (pow(a, 2) + pow(c, 2) - pow(b, 2)); // дискриминант должен быть целым, чтобы вывести целое значение x
        if (d > 0)
        {
            int x1 = (2 * d2 + pow(d, 0.5)) / 2; // находим значение x1
            int x2 = (2 * d2 - pow(d, 0.5)) / 2; // находим значение x2


            if (x2 > 0 and x1 > 0)              // проверка условий 
            {
                if (x1 > x2)                    // максимальное значение среди  x1, x2 
                    x = x1;
                else
                    x = x2;
            }
            else
            {
                if (x2 > 0 and x1 < 0 and abs(x2) == abs(x1))
                    x = x2;

                else
                {
                    if (x1 > 0 and x2 < 0 and abs(x2) == abs(x1))
                        x = x1;
                    else
                    {
                        if (x2 > 0 and x1 < 0 and abs(x2) != abs(x1))
                            x = x2;
                        else
                        {
                            if (x1 > 0 and x2 < 0 and abs(x2) != abs(x1))
                                x = x1;
                            else
                            {
                                if (x2 < 0 and x1 < 0)
                                {
                                    if (x1 > x2)
                                        x = x1;
                                    else
                                        x = x2;
                                }
                            }
                        }
                    }
                }
            }
            if (x > d0 and x > d1 and x > d2 and (a + b) > (c - x) and (a + x) > 0 and (b + x) > 0 and (c + x) > 0)
                f = true;
        }

    }
    

    if (a > b and a > c and b < (c + a)) // выясняем максимально ли c и проверяем, соответствует ли оно условию существования треугольника
    {
        int d = pow((-2 * d1), 2) - 4 * (pow(c, 2) + pow(b, 2) - pow(a, 2)); // дискриминант должен быть целым, чтобы вывести целое значение x
        if (d > 0)
        {
            int x1 = (2 * d1 + pow(d, 0.5)) / 2; // находим значение x1
            int x2 = (2 * d1 - pow(d, 0.5)) / 2; // находим значение x2


            if (x2 > 0 and x1 > 0)              // проверка условий 
            {
                if (x1 > x2)                    // максимальное значение среди  x1, x2 
                    x = x1;
                else
                    x = x2;
            }
            else
            {
                if (x2 > 0 and x1 < 0 and abs(x2) == abs(x1))
                    x = x2;

                else
                {
                    if (x1 > 0 and x2 < 0 and abs(x2) == abs(x1))
                        x = x1;
                    else
                    {
                        if (x2 > 0 and x1 < 0 and abs(x2) != abs(x1))
                            x = x2;
                        else
                        {
                            if (x1 > 0 and x2 < 0 and abs(x2) != abs(x1))
                                x = x1;
                            else
                            {
                                if (x2 < 0 and x1 < 0)
                                {
                                    if (x1 > x2)
                                        x = x1;
                                    else
                                        x = x2;
                                }
                            }
                        }
                    }
                }
            }
            if (x > d0 and x > d1 and x > d2 and (a + b) > (c - x) and (a + x) > 0 and (b + x) > 0 and (c + x) > 0)
                f = true;
        }

    }

*/
    
    if (f)
    { 
        cout << "Possible" << endl;
        cout << "Value x: " << x << endl;
    }
    else
        cout << "Impossible" << endl;

}

