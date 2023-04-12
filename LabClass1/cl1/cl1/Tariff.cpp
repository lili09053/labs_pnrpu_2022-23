#include "Tariff.h"
#include <iostream>
using namespace std;

void Tariff::Init(unsigned int min, float rub) // Метод инициализации полей объекта - "конструктор"
{
	first = min;
	second = rub;
}

void Tariff::Read()			// Get
{
	cout << "Продолжительность разговора (в минутах): ";
	cin >> first;
	while (first < 0)
	{
		cout << "Неверно введена продолжительность разговора! Попробуйте ещё раз: ";
		cin >> first;
	}

	cout << "Стоимость минуты разговора: ";
	cin >> second;

	while (second < 0)
	{
		cout << "Неверно введена стоимость разговора! Попррбуйте ещё раз: ";
		cin >> second;
	}
}

void Tariff::Show() // Метод вывода полей объекта
{
	cout << "Продолжительность разговора:  " << first << " мин" << endl;
	cout << "Стоимость одной минуты разговора: " << second << " р" << endl;
}

float Tariff::Cost()											// Стоимость разговора
{
	return first * second;
}

