//быстрая сортировка
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

int N;

void SORT(int *m, int start, int end)
{
    int i = start;
    int j = end;

    int x = m[(i + j) / 2];
    
    while (i <= j)
    {
        while (m[i] < x)
            i++;
        while (m[j] > x)
            j--;
        if (i <= j)
        {
            swap(m[i], m[j]);
            i++;
            j--;
        }
    }
    if (j > start)
        SORT(m, start, j);
    if (i < end)
        SORT(m, i, end);

}


void PRINT(int* temp) // вывод массива
{
    for (int i = 0; i < N; i++)
        cout << temp[i] << " ";
    cout << endl;
}


int main()
{
    setlocale(LC_ALL, "RUS");
       
    cout << "Введите N: ";
    cin >> N;
    int* mas = new int[N];

    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
       mas[i] = rand() % 30 - 15;
    }

    cout << "начальный массив: ";
    PRINT(mas);

    SORT(mas, 0, N - 1);

    cout << "конечный массив: ";
    PRINT(mas);

    delete[] mas;
    mas = nullptr;
   
}


//https://gist.github.com/christophewang/ad056af4b3ab0ceebacf