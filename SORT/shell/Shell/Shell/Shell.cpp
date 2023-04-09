//сортировка Шелла
#include <iostream>
#include <ctime>
using namespace std;

int N;

void SORT(int* mas)
{
    int d = N / 2; //шаг
    while (d > 0)
    {
        for (int i = d; i < N; i++)
        {
            int j = i;
            while ((j >= d) and (mas[j - d] > mas[j]))
            {
                swap(mas[j], mas[j - d]);
                j -= d;
            }
        }
        d /= 2;
    }
}


void PRINT(int* mas) // вывод массива
{
    for (int i = 0; i < N; i++)
        cout << mas[i] << " ";
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

    SORT(mas);

    cout << "конечный массив: ";
    PRINT(mas);

    delete[] mas;
    mas = nullptr;


}