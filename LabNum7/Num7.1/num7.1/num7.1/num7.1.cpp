/*
    Написать перегруженные функции и основную программу, которая их вызывает.
        а) для массива целых чисел находит максимальный элемент;
        б) для строки находит длину самого длинного слова.
*/
#include <iostream>
#include <ctime>
#include <string>

using namespace std;


int Max(int* m, int N) // нахождение макимального элемента
{
	int max = m[0];

	for (int i = 1; i < N; i++)
	{
		if (m[i] > max)
			max = m[i];
	}
	return max;
}


string Max(string str)
{
	string word;			// "временное" слово
	string maxWord = "";	// максимальное по длине слово
	
	for (int i = 0; i < str.length(); i++) // проход по всей длине строки
	{
		
		if (str[i] != ' ' and str[i] != '.' and str[i] != '!' and str[i] != '?' and str[i] != ':' and str[i] != ';')// "вычленение" слова из строки без учета знаков 
			word += str[i];	// составление слова побуквенно
		else
		{
			if (word.length() > maxWord.length())
			{
				maxWord = word;
			}
			word.clear();	// "обнуление" переменной
			//word1 += '\0';
		}
	}
	
	if (word.length() > maxWord.length()) // проверка последнего введённого слова
	{
		maxWord = word;
	}
	word.clear();
	return maxWord;
}

int main()
{
	cout << "--------------------------------- INTEGER -------------------------------------" << endl;
	int N;
	cout << "Enter N: ";
	cin >> N;

	srand(time(NULL));
	int* m = new int[N];
	for (int i = 0; i < N; i++) m[i] = rand() % 101 - 50;

	for (int i = 0; i < N; i++) cout << m[i] << " ";
	cout << endl;

	cout << "Max elem: ";
	cout << Max(m, N) << endl;
	delete[] m;
	
	cout << "--------------------------------- STRING --------------------------------------" << endl;
	
	system("chcp 1251>NULL");

	string STR;
	cout << "Enter STRING: ";
	getline(cin, STR);
	getline(cin, STR);
	
	cout << "Max word: ";
	cout << Max(STR) << endl;



}

