#pragma once
#include "Pair.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);		// Открыть для записи
	if (!stream) return -1;										// Ошибка открытия файла
	
	int size;
	Pair elem;
	
	cout << "input size: ";
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		cin >> elem;									// Ввод атрибутов объекта из стандартного потока
		stream << elem << endl;							// Запись объекта в файловый поток
	}
	stream.close();										// Закрыть поток
	return size;										// Вернуть количество записанных объектов
}

int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);					// Открыть для чтения
	if (!stream) return -1;										// Ошибка открытия файла
	
	Pair p;
	int i = 0;
	while (stream >> p)
	{
		cout << p;
		i++;
	}
	stream.close();
	return i;
}

int del_file(const char* file_name, Pair k)
{
	fstream temp("temp", ios::out);		// Открыть для записи
	fstream stream(file_name, ios::in);	// Открыть для чтения
	if (!stream)return -1;				// Ошибка открытия файла
	int i = 0;
	Pair p;
	while (stream >> p)					// Пока нет конца файла выполняем чтение объекта
	{
		if (stream.eof()) break;				// Если прочитан признак конца файла,то выход из цикла
		i++;
		if (k > p)						
		{
			temp << p;
		}
	}

	stream.close();						// Закрыть файл
	temp.close();						// Закрыть файл
	remove(file_name);						// Удалить старый файл
	rename("temp", file_name);				// Переименовать temp
	return i;							// Количество прочитанных 
}

int add_file(const char* f_name, int k, int K)
{
	fstream temp("temp", ios::out);						// Открыть для записи
	fstream stream(f_name, ios::in);					// Открыть для чтения
	if (!stream)return -1;

	Pair p;
	int i = 0, l = 0;
	while (stream >> p)
	{
		if (stream.eof()) break;
		i++;
		temp << p;

		if (i == k)
		{
			for (int j = 0; j < K; j++)
			{
				Pair newP;
				cin >> newP;
				temp << newP;							// Записать в temp новую запись
				l++;
			}
		}
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;											// Количество добавленных
}

int add_end(const char* f_name, int K)
{
	fstream stream(f_name, ios::app);					// Открыть для добавления
	if (!stream)return -1;
	for (int j = 0; j < K; j++)
	{
		Pair newP;
		cin >> newP;
		stream << newP;									// Записать новую запись
	}
	return 1;
}

int change_file(const char* fname, double k)
{
	fstream temp("temp", ios::out);						// Открыть для записи
	fstream stream(fname, ios::in);					// Открыть для чтения
	if (!stream)return -1;

	Pair p;
	int l = 0;

	while (stream >> p)
	{
		if (stream.eof()) break;
		if (k == (int)(k)) 	p + (int)(k);
		else p + k;
		temp << p;
	}
	stream.close(); temp.close();
	remove(fname);
	rename("temp", fname);
	return l;											// Количество измененных элементов
}