#pragma once

class Tariff
{
public:
	unsigned int first;									    // ����������������� ��������� � �������
	float second;											// ��������� ������ � ������
	void Init(unsigned int first, float second);			// ����� ������������� ����� �������
	void Read();											// ����� ���������� ����� �������
	void Show();											// ����� ������ ����� �������
	float Cost();											// ��������� ���������
};
