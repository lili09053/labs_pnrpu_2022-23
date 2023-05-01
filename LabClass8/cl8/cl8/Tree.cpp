#include "Tree.h"
#include "Human.h"
#include "Employee.h"
#include <iostream>
using namespace std;

Tree::Tree()
{
	Beg = 0;
	Cur = 0;
	Size = 0;
}

Tree::Tree(int N)
{
	Beg = new Object * [N];
	Object* ptr = nullptr;
	for (int i = 0; i < N; i++)
	{
		Beg[i] = ptr;
	}
	Cur = 0;
	Size = N;
}

Tree::~Tree()
{
	if (Beg != 0)
	{
		delete[] Beg;
	}
	Beg = 0;
}

void Tree::Add()
{
	if (Size > 0)
	{
		Object* ptr;
		cout << "\nВыберите класс нового объекта:\n\n";
		cout << "1. Класс Human\n";
		cout << "2. Класс Employee\n";
		cout << "\nВведите номер операции: ";
		int Code;
		cin >> Code;
		if (Code == 1)
		{
			Human* elem1 = new (Human);
			elem1->Input();
			ptr = elem1;
			if (Cur < Size)
			{
				Beg[Cur] = ptr;
				Cur++;
			}
			else
			{
				Size++;
				Beg[Cur] = ptr;
				Cur++;
			}
			cin.ignore();
		}
		else
		{
			if (Code == 2)
			{
				Employee* elem2 = new Employee;
				elem2->Input();
				ptr = elem2;
				if (Cur < Size)
				{
					Beg[Cur] = ptr;
					Cur++;
				}
				else
				{
					Size++;
					Beg[Cur] = ptr;
					Cur++;
				}
				cin.ignore();
			}
			else
			{
				cout << "\nОшибка: введен неверный номер. Элемент не может быть добавлен...\n\n";
			}
		}
	}
	else
	{
		cout << "\nВы не создали группу! Выполните команду m целое_число, прежде чем работать с другими командами (исключение: q)\n\n";
	}
}

void Tree::Show()
{
	if (Size > 0)
	{
		if (Beg[0] == nullptr)
		{
			cout << "\nМножество не заполнено...\n\n";
		}
		else
		{
			cout << "\nВывожу элементы дерева...\n\n";
			Object** ptr = Beg;
			int i = 0;
			while (i < Size)
			{
				cout << "Объект # " << i + 1 << endl;
				if (*ptr != nullptr)
				{
					(*ptr)->Show();
				}
				else
				{
					cout << "\nОбъект пуст!\n\n";
				}
				ptr++;
				i++;
			}
		}
	}
	else
	{
		cout << "\nВы не создали группу! Выполните команду m целое_число, прежде чем работать с другими командами (исключение: q)\n\n";
	}
}

void Tree::Elem(int Index)
{
	Index -= 1; // т.к номер элемента
	if (Size > 0)
	{
		if (Index >= Size)
		{
			cout << "\nИндекс за пределами размерности дерева!\n\n";
		}
		else
		{
			Object* ptr = Beg[Index];
			if (ptr != nullptr)
			{
				cout << "\nВывожу данные элемента с индексом " << Index << endl << endl;
				ptr->Show();
			}
			else
			{
				cout << "\nЭлемента под данным индексом не существует. Заполните данный элемент!\n\n";
			}
		}
	}
	else
	{
		cout << "Вы не создали группу! Выполните команду m целое_число, прежде чем работать с другими командами (исключение: q)\n";
	}
}

int Tree::operator () ()
{
	return Size;
}

void Tree::Del()			// "Удаление", память не освобождается!
{
	if (Size > 0)
	{
		int temp = Size - 1;
		while (Beg[temp] == nullptr)
		{
			Size--;
			temp--;
		}
		Size--;
		Cur--;
	}
	else
	{
		cout << "Удаление невозможно: размер группы равен 0 или группа не создана\n";
		Size = 0;
	}
}
