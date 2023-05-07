#include "Pair.h"
#include "FileWork.h"
#include <iostream>
#include <fstream>
#include <string>

/*не работает печать файла, если я вызываю 1 и создаю tmp1
* а далее его же пытаюсь прочитать 2
* переделать под условие
*/

int main()
{
	Pair p;
	int k, c;
	char filename[30];
	do
	{
		//меню
		cout << "\n 1. Make file"; //создание файла
		cout << "\n 2. Print file"; //печать файла
		cout << "\n 3. Delete record from file"; //Удаление записи
		cout << "\n 4. Add record to file";
		cout << "\n 5. Change record in file";
		cout << "\n 0. Exit\n";

		cin >> c;
		if (c < 0) cout << "\nError!\n";
		else
		{
			Pair p;
			switch (c)
			{
			case 1:
				cout << "file name?\n";
				cin >> filename;

				k = make_file(filename); //вызов для записи в файл
				if (k < 0) cout << "Can't make file";
				break;

			case 2:
				cout << "file name?\n";
				cin >> filename;

				k = print_file(filename); //вызов для печати файла
				if (k == 0) cout << "Empty file\n";
				if (k < 0) cout << "Can't read file";
				break;

			case 3:
				cout << "file name?\n"; // удаление
				cin >> filename;

				cout << "Num: ";
				cin >> p;

				k = del_file(filename, p);
				if (k < 0) cout << "Can't read file";
				break;

			case 4:
				cout << "file name?\n";
				cin >> filename;

				int num;
				cout << "Num: ";
				cin >> num;

				int K;
				cout << "Add K elem: ";
				cin >> K;

				k = add_file(filename, num, K);
				if (k == 0) k = add_end(filename, K);
				if (k < 0) cout << "Can't make file";
				break;

			case 5:
				cout << "file name?\n"; // удаление
				cin >> filename;

				double numb;
				cout << "Num: ";
				cin >> numb;
				k = change_file(filename, numb);
				if (k < 0) cout << "Can't make file";
				if (k == 0) cout << "\nNot such record!\n";
				break;

			}
		}
	} while (c != 0);
}

