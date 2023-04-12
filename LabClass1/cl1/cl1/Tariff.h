#pragma once

class Tariff
{
public:
	unsigned int first;									    // Продолжительность разговора в минутах
	float second;											// Стоимость минуты в рублях
	void Init(unsigned int first, float second);			// Метод инициализации полей объекта
	void Read();											// Метод заполнения полей объекта
	void Show();											// Метод вывода полей объекта
	float Cost();											// Стоимость разговора
};
