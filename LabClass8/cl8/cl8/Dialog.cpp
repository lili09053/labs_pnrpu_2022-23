#include "Dialog.h"
#include "Event.h"
#include <iostream>
#include <string>
using namespace std;

Dialog::Dialog() : Tree()
{
	EndState = 0;
}

Dialog::~Dialog()
{

}

void Dialog::GetEvent(Event& event)
{
	string OperationCodes = "+-&/qam";
	string Str;
	string Parameter;
	char Code;
	cout << "Введите код операции\n\n";
	cout << "m целое_число - создать группу из некоторого количества элементов\n";
	cout << "+ - добавить элемент в группу\n";
	cout << "- - удалить элемент из группы\n";
	cout << "s - вывод информации об элементах группы\n";
	cout << "z целое_число - вывод информации об имени элемента с заданным номером\n";
	cout << "q - конец работы\n\n";
	cout << "> ";
	getline(cin, Str);
	Code = Str[0];
	if (OperationCodes.find(Code) >= 0)
	{
		event.what = evMessage;
		switch (Code)
		{
		case 'm':
		{
			event.command = cmMake;
			break;
		}
		case '+':
		{
			event.command = cmAdd;
			break;
		}
		case '-':
		{
			event.command = cmDel;
			break;
		}
		case 's':
		{
			event.command = cmShow;
			break;
		}
		case 'z':
		{
			event.command = cmElem;
			break;
		}
		case 'q':
		{
			event.command = cmQuit;
			break;
		}
		default:
		{
			cout << "\nОперация не выполнена!\n\n";
		}
		}
	}
	if (Str.length() > 1)
	{
		Parameter = Str.substr(1, Str.length() - 1);
		int A = atoi(Parameter.c_str());
		if (A < 0)
		{
			cout << "\nЧисло элементов в группе не может быть отрицательным\n\n";
			event.what = evNothing;
		}
		else
		{
			event.parameter = A;
		}
	}
	else
	{
		if (Str.length() == 0)
		{
			event.what = evNothing;
		}
	}
}

int Dialog::Execute()
{
	Event event;
	do
	{
		EndState = 0;
		GetEvent(event);		// Получение события
		HandleEvent(event);		// Обработка события
	} while (!Valid());
	return EndState;
}

int Dialog::Valid()
{
	if (EndState == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void Dialog::ClearEvent(Event& event)
{
	event.what = evNothing;
}

void Dialog::EndExec()
{
	cout << "\nВыход из программы...\n\n";
	EndState = 1;
}

void Dialog::HandleEvent(Event& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake:					// Создание группы
		{
			if (event.parameter > 0)
			{
				Size = event.parameter;
				Beg = new Object * [Size];
				for (int i = 0; i < Size; i++)
				{
					Beg[i] = nullptr;
				}
				ClearEvent(event);
				cout << endl;
			}
			else
			{
				cout << "\nВы не ввели количество элементов! Введите код операции в соответствии с шаблоном m целое_число\n\n";
			}
			break;
		}
		case cmAdd:						// Добавление элемента в группу
		{
			Add();
			ClearEvent(event);
			break;
		}
		case cmDel:						// Удаление элемента из группы
		{
			Del();
			ClearEvent(event);
			break;
		}
		case cmShow:					// Вывод элементов группы
		{
			Show();
			ClearEvent(event);
			break;
		}
		case cmElem:					// Вывод элемента группы по номеру
		{
			int Index = event.parameter;
			Elem(Index);
			ClearEvent(event);
			break;
		}
		case cmQuit:					// Выход из программы
		{
			EndExec();
			ClearEvent(event);
			break;
		}
		}
	}
}