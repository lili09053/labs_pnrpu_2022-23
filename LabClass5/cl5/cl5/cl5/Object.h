#pragma once
class Object
{
public:
	Object() {} // конструктор по умолчанию
	~Object() {} //деструктор
	virtual void Show() = 0; // чисто виртуальная функция
};

