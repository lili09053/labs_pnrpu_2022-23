#pragma once
#include "Object.h"
#include <iostream>
using namespace std;


class Human : public Object
{
protected:
	string Name;
	int Age;
public:
	Human();
	Human(string name, int age);
	Human(const Human& Ptr);
	virtual ~Human();
	void Show();
	void Input();
	string Get_Name() { return Name; }
	int Get_Age() { return Age; }
	void Set_Name(string name) { Name = name; }
	void Set_Age(int age) { Age = age; }
	Human& operator =(const Human& Ptr);
};

