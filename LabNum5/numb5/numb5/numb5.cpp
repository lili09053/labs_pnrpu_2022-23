/*
	18. Задан двумерный массив N x N. 
	Последовательно рассматриваются квадратные подмассивы, правый верхний элемент которых лежит на побочной диагонали.
	В каждом таком подмассиве находится максимальный элемент. 
	Путем перестановок строк и столбцов (целиком) элемент надо переместить в правый верхний угол подмассива. 
	Проверить получилась ли на побочной диагонали убывающая последовательность элементов.
*/

#include <iostream>
#include <ctime>
using namespace std;

int Imax;
int Jmax;


void MaxElem(int** mtx, int N) // нахождение макимального элемента
{
	int max = mtx[0][0];
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (mtx[i][j] > max)
			{
				max = mtx[i][j];
				Imax = i;
				Jmax = j;
			}
				
		}
	}
	
}


int** Swap(int ** mtr, int N)
{
	#pragma region Row 
	if (Imax != 0)			// поменять i-ю строку c первой
	{
		int*  temp = *mtr;		// запоминаем 0ю строку
		*mtr = *(mtr + Imax); // 0ю строку заполняем iой
		*(mtr + Imax) = temp; //i-ю строку заполняем 0ой
		temp = nullptr;	
	}
	#pragma endregion
	#pragma region Column 
	if (Jmax != N-1)
	{ 
		int elem;
		for (int i = 0; i < N; i++)
		{ 
			elem = mtr[i][N - 1]; // элемент запоминаем последний столбец
			mtr[i][N - 1] = mtr[i][Jmax];
			mtr[i][Jmax] = elem;

		}
	}
	#pragma endregion


	return mtr;

}


int** Podmas(int** mtr, int N)
{
	if (N > 1)
	{
		MaxElem(mtr, N);

		mtr = Swap(mtr, N);

		int** temp = new int* [N - 1];			// выделяется подмассив

		for (int i = 1; i < N; i++)				// первая строка не рассматривается
		{
			temp[i - 1] = new int[N - 1];
			for (int j = 0; j < N - 1; j++)		// не рассматривается последний столбец
			{
				temp[i - 1][j] = mtr[i][j];
			}
		}

		temp = Podmas(temp, N - 1);

		for (int i = 1; i < N; i++)				// первая строка не рассматривается
		{
			for (int j = 0; j < N - 1; j++)		// не рассматривается последний столбец
			{
				mtr[i][j] = temp[i - 1][j]; // возвращение отсортированного подмассива в массив
			}
		}

		for (int i = 0; i < N-1; i++) delete[] temp[i]; // сначала удаляются вложенные массивы, затем массив, содержащий их
		delete[] temp;
	
	}
	return mtr;
	
}


int main()
{
	#pragma region Matrix creation
	srand(time(NULL));
	
	int N;
	cout << "Enter N: ";
	cin >> N;

	int** Matr = new int *[N]; // массив, содержащий N указателей

	for (int i = 0; i < N; i++) // цикл отвечает за количество строк в матрице
	{
		Matr[i] = new int[N]; // создается массив, который будет содержать в себе элементы
		for (int j = 0; j < N; j++)
		{
			Matr[i][j] = rand() % 30 - 15;
		}
	}
	#pragma endregion
	
	#pragma region Start Matrix output
	cout << "-------------------------------START-----------------------------------" << endl;
	
	for (int i = 0; i < N; i++)  // вывод массива
	{
		for (int j = 0; j < N; j++)
		{
			cout << Matr[i][j] << "\t";
		}
		cout << endl;
	}

	cout << endl;
	#pragma endregion

	Matr = Podmas(Matr, N);

	#pragma region End Matrix output
	cout << "-------------------------------FINISH-----------------------------------" << endl;

	for (int i = 0; i < N; i++)  // вывод массива
	{
		for (int j = 0; j < N; j++)
		{
			cout << Matr[i][j] << "\t";
		}
		cout << endl;
	}
	#pragma endregion

	for (int i = 0; i < N; i++) delete [] Matr[i]; // сначала удаляются вложенные массивы, затем массив, содержащий их
	delete[] Matr;


}

