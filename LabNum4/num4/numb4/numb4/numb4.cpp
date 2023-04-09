/* 18 var
	1) 	Реализовать с использованием массива однонаправленное кольцо (просмотр возможен слева направо, от последнего элемента можно перейти к первому).
	2) 	Распечатать полученный массив, начиная с К-ого элемента и до К-1.
	3) 	Добавить в кольцо первый и последний элементы.
	4) 	Удалить из кольца четные элементы.
	5) 	Распечатать полученный массив, начиная с К-ого элемента и до К-1.
*/

#include <iostream>
#include <ctime>
using namespace std;

int len = 0; // длина массива после удаления элементов


//Распечатать полученный массив, начиная с К-ого элемента и до К-1.
void Output(int* m, int SIZE, int k) // вывод с k-го элемента до k-1
{
	if (k > SIZE) k %= SIZE;
	
	cout << "ARRAY FROM (K) TO (K - 1): ";
	for (int i = k - 1; i < SIZE; i++) cout << m[i] << " "; // k - 1 т.к. k - номер
	for (int i = 0; i <= k - 2; i++)  cout << m[i] << " "; //  k - 2 = (k - 1) - 1;
}

int* AddElemArr(int*, int );

// разворачивание кольца
int* NewArr(int* m, int SIZE, int k) // Ring from к to к - 1
{
	int* temp = new int[SIZE];
	if (k > SIZE) k %= SIZE;

	for (int i = k - 1; i < SIZE; i++) temp[i - (k - 1)] = m[i]; // k - 1 т.к. k - номер
	for (int i = 0; i < k - 1; i++) temp[SIZE - k + i + 1] = m[i]; //  k - 1;

	return AddElemArr(temp, SIZE);
} 

//Добавить в заданный массив первый и последний элементы
int* AddElemArr(int* m, int SIZE)
{

	int* NewM = new int[SIZE + 2]; // создание массива с добавлением 2х элементов к оригинальному массиву, а не к массиву от к до к - 1, т.к если 
	// {0, 5, 11, 18,, -8, 9} -> {{0, 5,кон, нач, 11, 18,, -8, 9}, то нач != k,  а нач = k + 1  и порядок нарушается

	for (int i = 0; i < SIZE + 2; i++)
	{
		if (i == 0 or i == SIZE + 1)
		{
			NewM[i] = rand() % 20 - 10;
		}
		else
		{
			NewM[i] = m[i - 1];
		}
	}

	return NewM;
}

//Удалить из кольца четные элементы.

int* DelEvenEl(int* m, int SIZE)
{
	int* temp = new int[SIZE];
	
	for (int i = 0; i < SIZE; i++)
	{
		if (abs(m[i]) % 2 != 0)
		{
			temp[len] = m[i];
			len++;
		}
	}
	return temp;
}

int main()
{
	srand(time(NULL));
	int SIZE, k; //  k номер эл-та с которого начнется вывод
	cout << "ENTER THE LENGHT OF THE ARRAY: ";
	cin >> SIZE;
	int *m = new int[SIZE]; //  массив
	for (int i = 0; i < SIZE; i++) m[i] = rand() % 20 - 10;

	cout << "ORIGINAL ARRAY: ";
	for (int i = 0; i < SIZE; i++) cout << m[i] << " "; // вывод заданного массива
	cout << endl;
						
	cout << "ENTER INT K: ";
	cin >> k;

	Output(m, SIZE, k); // вывод массива от k до k -1
	cout << endl;

/*
	delete[] m;
	m = NewM;
	NewM = nullptr;// пустой указатель
*/


	m = NewArr(m, SIZE, k);
	cout << "RING ARRAY WITH TWO ADDED ELEMENTS: ";
	for (int i = 0; i < SIZE + 2; i++) cout << m[i] << " ";
	cout << endl;

	m = DelEvenEl(m, SIZE + 2);
	cout << "RING ARRAY OF ODD ELEMENTS: ";
	if (len != 0)
	{
		for (int i = 0; i < len; i++) cout << m[i] << " ";
	}
	else
		cout << " ARRAY HAS EVEN ELEMENTS: ";
	cout << endl;
	
	cout << "ENTER INT K: ";
	cin >> k;
	Output(m, len, k);

	delete[] m;
}

