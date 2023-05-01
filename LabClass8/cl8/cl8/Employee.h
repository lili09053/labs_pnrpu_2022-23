#pragma once
#include "Human.h"
#include <iostream>
#include <string>
using namespace std;


class Employee : public Human
{
protected:
	float Salary;
	string  Position;

public:
	Employee();
	Employee(string name, int age, float Salary, string pos);
	Employee(const Employee& Ptr);
	~Employee();
	float Get_Salary() { return Salary; }
	void Set_Salary(float Salary) { this->Salary = Salary; }
	string Get_Position() { return Position; }
	void Set_Position(string pos) { this->Position = pos; }
	void Show();
	void Input();
	Employee& operator =(const Employee& Ptr);
};

