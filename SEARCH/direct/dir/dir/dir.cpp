// прямой поиск подстроки в строке

#include <iostream>
#include <string>
using namespace std;

int main()
{
	system("chcp 1251>NULL");

	string str;
	cout << "Введите строку: ";
	getline(cin, str);

	string SubStr;
	cout << "Введите подстроку: ";
	getline(cin, SubStr);
	bool fl = false;
	
	int res = 0;

	for (int i = 0; i < str.size() - SubStr.size() + 1; i++)
	{
		int k = 0;
		while (k < SubStr.size())
		{
			if (str[i + k] != SubStr[k])
			{
				k = SubStr.size(); //принудительный выход
			}
			else
			{
				if (k == SubStr.size() - 1)
				{
					fl = true;
					res = i;
				}

			}
			k++;
		}			
	}
	

	if (fl)
		cout << "Подстрока есть в строке!" << " начиная с " << res + 1 <<" -го символа" << endl;
	else
		cout << "Подстроки нет в строке!" << endl;

}

