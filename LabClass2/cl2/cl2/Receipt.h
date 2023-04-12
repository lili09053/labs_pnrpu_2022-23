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

	Receipt();		// ����������� �� ���������
	Receipt(int Num, string Date, double Sum);	// ����������� � �����������
	Receipt(const Receipt& p); // ����������� �����������
	~Receipt();
	
	int get_number();	//�������� 
	void set_number(int Num);	// �����������
	string get_date();
	void set_date(string Date);
	double get_sum();
	void set_sum(double Sum);

	void Show();	// ����� ���������

};

