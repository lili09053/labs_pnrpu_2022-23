#pragma once
#include <string>
#include <iostream>
using namespace std;

class Error											// ������� �����
{
public:
	virtual void what() {};
};

class IndexError : public Error						// ������ � ������� �������
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

class SizeError : public Error						// ������ � ������� �������
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

class MaxSizeError : public SizeError				// ���������� ������������� �������
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

class FullSizeError : public SizeError				// ���������� � ����������� ������
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

class MinIndexError : public IndexError				// ������ ������ ����
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

class MaxIndexError : public IndexError				// ������ ������ �������� ������� �������
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