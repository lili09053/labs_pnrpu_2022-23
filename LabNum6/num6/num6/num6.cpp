#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <string> ArrayWords(string str) // создание массива слов
{
	string word;			// "временное" слово
	int num = 0;			// длина массива
	vector <string> MasWord;

	for (int i = 0; i < str.length(); i++) // проход по всей длине строки
	{

		if (str[i] != ' ' and str[i] != '.' and str[i] != '!' and str[i] != '?' and str[i] != ':' and str[i] != ';')// "вычленение" слова из строки без учета знаков 
			word += str[i];	// составление слова побуквенно
		else
		{ 
			num++;
			MasWord.push_back(word);
			word.clear();
		}
	}
	num++;
	MasWord.push_back(word); // добавление слова в конец массива
	word.clear();
	
	return MasWord;
}


bool IsRuUpper(char c)				// проверка русской буквы на регистр
{
	return (c >= 'А') && (c <= 'Я');
}


void SORT(vector <string>& vect) // сортировка пузырьком
{
	for (int i = 0; i < vect.size() - 1; i++)
	{
		for (int j = 0; j < vect.size() - i - 1; j++) // n - i = длина неотсортированной части
		{
			string tmp;

			for (int k = 0; k < vect[j].size(); k++) // цикл, отвечающий за букву в слове
			{
				int	LetWord1 = (int)(vect[j][k]) + 32 * IsRuUpper(vect[j][k]); // преобразование к одному регистру букв слов
				int	LetWord2 = (int)(vect[j + 1][k]) + 32 * IsRuUpper(vect[j + 1][k]);

				if ((LetWord1 > LetWord2) or (vect[j + 1].size() < vect[j].size() and k == vect[j + 1].size() - 1)) // проверка на длины, есличасти слова одинаковая
				{
					tmp = vect[j];
					vect[j] = vect[j + 1];
					vect[j + 1] = tmp;
					k = vect[j].size(); // принудительный выход
				}
				if (LetWord1 < LetWord2) // проверка на длины, есличасти слова одинаковая
				{
					k = vect[j].size(); // принудительный выход
				}
					
			}
				
		}
	}
	cout << "---------------------------------  SORT_VECTOR --------------------------------------" << endl;

	for (int i = 0; i < vect.size(); i++) cout << vect[i] << " "; // вывод массива
	cout << endl;

}

int main()
{
	cout << "--------------------------------- STRING --------------------------------------" << endl;

	system("chcp 1251>NULL");

	string STR;
	cout << "Enter STRING: ";
	getline(cin, STR);
	cout << endl;

	vector <string> Words = ArrayWords(STR);

	SORT(Words);

}