//сортировка слиянием
#include <iostream>
#include <ctime>
using namespace std;

int N;

void SORT(int*, int, int);

void DIV(int* mas, int start, int end)  //деление массива пополам
{
    if (start < end)
    {
        DIV(mas, start, (start + end) / 2); // левая часть
        DIV(mas, (start + end) / 2 + 1, end); // правая
        SORT(mas, start, end);
    }
}

void SORT(int* mas, int start, int end) // https://www.geeksforgeeks.org/merge-sort/
{
    int mid = (start + end) / 2;
    int lenLeft = mid - start + 1;
    int lenRight = end - mid;
    
    int* Left = new int[lenLeft];
    int* Right = new int[lenRight];

    for (int i = 0; i < lenLeft; i++)
    {
        Left[i] = mas[start + i];
    }

    for (int j = 0; j < lenRight; j++)
    {
        Right[j] = mas[mid + 1 + j];
    }

    int indexLeft = 0;
    int indexRight = 0;
    int indexMas = start;


    while (indexLeft < lenLeft and indexRight < lenRight) 
    {
        if (Left[indexLeft] <= Right[indexRight]) 
        {
            mas[indexMas] = Left[indexLeft];
            indexLeft++;
        }
        else 
        {
            mas[indexMas] = Right[indexRight];
            indexRight++;
        }
        indexMas++;
    }
    
    while (indexLeft < lenLeft) 
    {
        mas[indexMas] = Left[indexLeft];
        indexLeft++;
        indexMas++;
    }
    
    while (indexRight < lenRight) 
    {
        mas[indexMas] = Right[indexRight];
        indexRight++;
        indexMas++;
    }
    delete[] Left;
    delete[] Right;
    return;
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

    DIV(mas, 0, N - 1);

    cout << "конечный массив: " ;
    PRINT(mas);

    delete[] mas;
    mas = nullptr;
 

}