//сортировка подсчётом
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int N;

void PRINT(vector <int> temp) // вывод массива
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
    int st, fin;
    cout << "Введите диапазон значений" << endl;
    cout << "от: "; 
    cin >> st;
    cout << "до: ";
    cin >> fin;

    vector <int> StartVect(N);

    srand(time(NULL));

    int range = fin - st + 1; // диапазон + длина массива, хранящего количество повтор.
    
    for (int i = 0; i < N; i++)    //заполнение рандомными числами из диапазона
    {
        StartVect[i] = rand() % (range) + st;
    }
     
    cout << "начальный массив: ";
    PRINT(StartVect);


    vector <int> count(range);          // массив, хран. кол-во повторов
       
    for (int i = 0; i < N; i++)
        count[StartVect[i] - st]++;     // смещение на левую границу дапазона

   
    cout << "массив счётчика: ";
    for (int i = 0; i < range; i++)
        cout << count[i] << " ";
    cout << endl;


    int k = 0;
    for (int i = 0; i < range; i++)         // проходимся по каждому эл-ту массива счетчика
    {
        for (int j = 0; j < count[i]; j++) // теперь цикл выполняется столько раз, сколько повторений было каждого числа
        {
               StartVect[k] = i + st;       // занесение эл-та массива с учетом смещения
               k++;
        }
    }

    cout << "конечный массив: ";
    PRINT(StartVect);
    

 }
