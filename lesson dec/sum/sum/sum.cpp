#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int s = 0;
    for (int i = 1; i <= n; i++)

    {
        int p = 1;
        for (int j = 1; j <= n; j++)
        { 
            p *= j;

        }
        s += p;
    }

    cout << s;
}

