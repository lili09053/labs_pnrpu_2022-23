#include <iostream>
#include <iomanip>
using namespace std;


const double eps = 0.0001;
int n = 50;
const long double PI = 3.1415926;

double funN(int i, float x)
{
    if (i <= n)
    {
        double S = (cos(2 * i * x)) / (4 * i * i - 1);
        return S + funN(i + 1, x);
    }
     return 0;
}


double funEps(int i, double x)
{
    if (abs((cos(2 * i * x)) / (4 * i * i - 1)) >= eps)
    {
        double S = (cos(2 * i * x)) / (4 * i * i - 1);
        return S + funEps(i + 1, x);
    }
    return 0;
}

int main()
{
    float a = 0.1;
    float b = 0.8;
    float x = a;
    cout << "_______________________________________________________________________";
    cout << "______________________________________" << endl;
    cout << "|               funN                  |                y                |";
    cout << "             funEps                |" << endl;
    cout << "______________________________________________________________________";
    cout << "_______________________________________" << endl;
    while (x <= b)
    { 
       
        cout << fixed << setprecision(5) << "|" << funN(1, x) << "                              |" << 0.5 - (PI / 4) * abs(sin(x)) << "                          |";
        cout << fixed << setprecision(5) << funEps(1, x) << "                            |" << endl;
        /*
        
        cout << funN(1, x) << "          |           ";
        cout << 0.5 - (PI / 4) * abs(sin(x)) <<"          |           " ;
        cout << funEps(1, x) << endl;
        */
        x += (b - a) / 10;
    }
}

