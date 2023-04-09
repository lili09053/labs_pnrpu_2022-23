// СБАЛАНСИРОВАННОЕ ДВУХФАЗНОЕ СЛИЯНИЕ
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

int N;

fstream F1;
fstream F2;
fstream MainFile;


string path1 = "F1.txt"; 
string path2 = "F2.txt";
string pathM = "M.txt";

void SORT(int*, int, int);

void DIV(string PATH, int start, int end)  //деление массива пополам
{
    if (start < end)
    {
        DIV(PATH, start, (start + end) / 2); // левая часть
        DIV(PATH, (start + end) / 2 + 1, end); // правая
        SORT(PATH, start, end);
    }
}

void SORT(string PATH, int start, int end) // https://www.geeksforgeeks.org/merge-sort/
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
    system("chcp 1251>NULL");

    cout << "Введите количество элементов для сортировки N: ";
    cin >> N;
    
    MainFile.open(pathM, fstream :: out); //открытие файла для записи


    if (!MainFile.is_open())
    {
        cout << "Ошибка открытия файла Main для записи!" << endl;
    }
    
    else
    {
        srand(time(NULL));

        for (int i = 0; i < N; i++) // заполнение файла рандомными числами
        {
            int a = rand() % 101 - 50;
            if (i != N - 1)
            {
                F1 << a << endl;
                cout << a << endl;
            }
            else
            {
                if (i == N - 1) // чтобы после вывода последнего числа не было переноса на друную строку
                {
                    F1 << a;
                    cout << a;
                }
            }

        }
        cout <<endl << "Файл Main заполнен!" << endl;
    }
   MainFile.close();

}