// бинарный поиск
#include <iostream>
#include <ctime>
using namespace std;

int N;

void SORT(int* m, int start, int end) //быстрая сортировка
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

void PRINT(int* m)
{
    for (int i = 0; i < N; i++)
        cout << m[i] << " ";
    cout << endl;
}

int main()
{
	cout << "Enter N: ";
	cin >> N;

	int* mas = new int[N];
	
	srand(time(NULL));

	for (int i = 0; i < N; i++)
		mas[i] = rand() % 101 - 50;

    PRINT(mas);

    int start = 0;
    int end = N - 1;

    SORT(mas, start, end);
    PRINT(mas);
    
    int k;
    cout << "Enter key: ";
    cin >> k;

	bool fl = false;
    int mid;

    while (start <= end and fl == false)
    {
        mid = (start + end) / 2;
        if (mas[mid] == k)
            fl = true;
        if (mas[mid] > k)
            end = mid - 1;
        if (mas[mid] < k)
            start = mid + 1;

    }

    cout << "Index: " << mid;


}
