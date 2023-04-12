#include "Tariff.h"
#include <iostream>
using namespace std;

void Tariff::Init(unsigned int min, float rub) // ����� ������������� ����� ������� - "�����������"
{
	first = min;
	second = rub;
}

void Tariff::Read()			// Get
{
	cout << "����������������� ��������� (� �������): ";
	cin >> first;
	while (first < 0)
	{
		cout << "������� ������� ����������������� ���������! ���������� ��� ���: ";
		cin >> first;
	}

	cout << "��������� ������ ���������: ";
	cin >> second;

	while (second < 0)
	{
		cout << "������� ������� ��������� ���������! ���������� ��� ���: ";
		cin >> second;
	}
}

void Tariff::Show() // ����� ������ ����� �������
{
	cout << "����������������� ���������:  " << first << " ���" << endl;
	cout << "��������� ����� ������ ���������: " << second << " �" << endl;
}

float Tariff::Cost()											// ��������� ���������
{
	return first * second;
}

