#pragma once
#include <string>
#include <iostream>
using namespace std;

class Error											// Базовый класс
{
public:
	virtual void what() {};
};

class IndexError : public Error						// Ошибка в индексе вектора
{
protected:
	string message;
public:
	IndexError()
	{
		message = "Index error!\n";
	}
	virtual void what()
	{
		cout << message;
	}
};

class SizeError : public Error						// Ошибка в размере вектора
{
protected:
	string message;
public:
	SizeError()
	{
		message = "Size error!\n";
	}
	virtual void what()
	{
		cout << message;
	}
};

class MaxSizeError : public SizeError				// Превышение максимального размера
{
protected:
	string message_;
public:
	MaxSizeError()
	{
		SizeError();
		message_ = "Size > MAX_SIZE!\n";
	}
	virtual void what()
	{
		cout << message << message_;
	}
};

class FullSizeError : public SizeError				// Добавление в заполненный вектор
{
protected:
	string message_;
public:
	FullSizeError()
	{
		SizeError();
		message_ = "List is full!\n";
	}
	virtual void what()
	{
		cout << message << message_;
	}
};

class MinIndexError : public IndexError				// Индекс меньше нуля
{
protected:
	string message_;
public:
	MinIndexError()
	{
		IndexError();
		message_ = "Index < 0!\n";
	}
	virtual void what()
	{
		cout << message << message_;
	}
};

class MaxIndexError : public IndexError				// Индекс больше текущего размера вектора
{
protected:
	string message_;
public:
	MaxIndexError()
	{
		IndexError();
		message_ = "Index > Size!\n";
	}
	virtual void what()
	{
		cout << message << message_;
	}
};