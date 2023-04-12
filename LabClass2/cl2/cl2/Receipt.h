#pragma once
#include <string>
using namespace std;

class Receipt
{
private:
	int number;
	string date;
	double sum;

public:

	Receipt();		// конструктор по умолчанию
	Receipt(int Num, string Date, double Sum);	// конструктор с параметрами
	Receipt(const Receipt& p); // конструктор копирования
	~Receipt();
	
	int get_number();	//селектор 
	void set_number(int Num);	// модификатор
	string get_date();
	void set_date(string Date);
	double get_sum();
	void set_sum(double Sum);

	void Show();	// вывод атрибутов

};

