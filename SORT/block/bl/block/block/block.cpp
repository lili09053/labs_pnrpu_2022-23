//блочная сортировка

#include <iostream>
#include <ctime>
using namespace std;

int N;
const int offset = 105;
const int maxSize = 100;


void SORT(int* arr)
{
    int j;
    int buckets[offset];

    for (int i = 0; i < offset; i++)
        buckets[i] = 0;

    for (int i = 0; i < N; i++)
        buckets[arr[i]]++;

    for (int i = 0, j = 0; i < offset; i++)
    {
        while (buckets[i] > 0)
        {
            arr[j] = i;
            buckets[i]--;
            j++;
        }
    }
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
        mas[i] = rand() % 100;
    }

    cout << "начальный массив: ";
    PRINT(mas);


    SORT(mas);
    cout << "конечный массив: ";
    PRINT(mas);

    delete[] mas;
    mas = nullptr;
}

