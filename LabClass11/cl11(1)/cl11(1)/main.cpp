﻿#include <iostream>
#include <list>
#include <ctime>
using namespace std;

typedef list<int> lst;

lst make_list(int n)
{
	lst l;
	for (int i = 0; i < n; i++)
		l.push_back(rand() % 100 - 65);

	return l;
}

void print_list(lst &l)
{
	for (auto it = l.begin(); it != l.end(); it++)
		cout << *it << " ";
	cout << endl;
}

int average(lst &l)
{
	int sum = 0;
	for (auto it = l.begin(); it != l.end(); it++)
		sum += *it;
	int size = l.size();
	return sum / size;
}

lst add(lst& l, int pos)
{
	int elem = average(l);
	auto it = l.begin();
	advance(it, pos - 1); // -1, т.к учитывается begin
	l.insert(it, elem);
	return l;
}

lst del(lst& l, int start, int finish)
{
	auto it = l.begin();
	advance(it, start - 1);
	auto start_it = it;
	it = l.begin();
	advance(it, finish);
	auto finish_it = it;
	l.erase(start_it, finish_it);
	return l;
}

lst change(lst& l)
{
	int elem = average(l);
	for (auto it = l.begin(); it != l.end(); it++)
		*it = *it - elem;
	return l;
}

void main()
{
	srand(time(NULL));

	try 
	{
		list <int> tmp;
		int n;
		cout << "enter n: ";
		cin >> n;
		
		tmp = make_list(n);
		cout << "make: ";
		print_list(tmp);
		
		int pos;
		cout << "enter pos: ";
		cin >> pos; 

		tmp = add(tmp, pos);
		cout << "add: ";
		print_list(tmp);

		int l, r;
		cout << "enter range: ";
		cin >> l >> r;
		tmp = del(tmp, l, r);
		cout << "del: ";
		print_list(tmp);

		tmp = change(tmp);
		cout << "change: ";
		print_list(tmp);
	}
	catch(int) 
	{
		cout << "\nError!\n";
	}
}