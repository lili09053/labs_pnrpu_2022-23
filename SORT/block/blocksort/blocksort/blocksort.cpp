// блочная сортировка
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int MIN(vector <int> mas)
{
    int min = *min_element(mas.begin(), mas.end()); // минимальный элементт в массиве
      
    return min;
}

int MAX(vector <int> mas)
{
    int max = *max_element(mas.begin(), mas.end());  // максимальный элементт в массиве

    return max;
}



vector <int> SORT(vector <int> mas, int min, int max) 
{
    int len = mas.size();
    if (len < 2 or min == max)
        return mas;
    else
    {
        int range = max - min;
        int K = range / N; // количество "блоков"
        vector <vector <int>> buckets;
        vector <int> minbuckets;
        vector <int> maxbuckets;

        for (int i = 0; i < len; i++)
        {
            int index = (mas[i] * K) / range;
            buckets[index].push_back(mas[i]);
            int mintemp = MIN(buckets[index]);
            vector <int> temp = {mintemp, mas[i] };
            minbuckets[index] = MIN(temp);
            maxbuckets[index] = MAX(temp);
        }
        
        for (int i = 0; i < K; i++)
            buckets[i] = SORT(buckets[i], minbuckets[i], maxbuckets[i]);
        
        vector <int> result;
        
        for (int i = 0; i < K; i++)
        {
            for (int j = 0; j < buckets[i].size(); j++)
                result.push_back(buckets[i][j]);
        }
            
        
        return result;
    }
}




void PRINT(vector <int> mas) // вывод массива
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

    setlocale(LC_ALL, "RUS");

    int st, fin;
    cout << "Введите диапазон значений" << endl;
    cout << "от: ";
    cin >> st;
    cout << "до: ";
    cin >> fin;



    int range = fin - st + 1; // диапазон + длина массива
   // int* mas = new int[N];
    vector <int> mas (N);
    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        mas[i] = rand() % range + st;
    }

    cout << "начальный массив: ";
    PRINT(mas);
    int min = MIN(mas);
    int max = MAX(mas);

    mas = SORT(mas, min, max);

    cout << "конечный массив: ";
    PRINT(mas);



}