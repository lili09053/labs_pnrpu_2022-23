// интерполяционный поиск

#include <iostream>
#include <ctime>
using namespace std;


void SORT(int* m, int start, int end) // быстрая сортировка
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


int main()
{
	bool fl = false;


    int SIZE;

	cout << "Enter N: ";
	cin >> SIZE;
	int* mas = new int[SIZE];

	srand(time(NULL));

	for (int i = 0; i < SIZE; i++)
		mas[i] = rand() % 31 - 20;

    SORT(mas, 0, SIZE - 1);

    for (int i = 0; i < SIZE; i++)
        cout << mas[i] << " ";
    cout << endl;


    int key;
    cout << "Enter key: ";
    cin >> key;

    int left = 0;
    int right = SIZE;

    
    while (left <= right and fl == false)
    {
        int mid = left + ((key - mas[left]) * (right - left)) / (mas[right] - mas[left]);
        if (mas[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            if (mas[mid] > key)
                right = mid + 1;
            else
                fl = true;
        }
    }

    if (key == mas[left])
        cout << "Index: " << left;
    else
    {
        if (key == mas[right])
            cout << "Index: " << right;
    }


	delete[] mas;
}
