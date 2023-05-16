#include <iostream>
#include <list>
#include <algorithm>
#include <functional>
#include "Pair.h"
using namespace std;

typedef list<Pair> lst;


lst make_list(int n)
{
	lst l;
	for (int i = 0; i < n; i++)
	{
		Pair a;
		cin >> a;
		l.push_back(a);
	}

	return l;
}

void print_list(lst& l)
{
	for (auto it = l.begin(); it != l.end(); it++)
		cout << *it;
	cout << endl;
}


Pair average(lst& l)
{
	Pair sum;
	for (auto it = l.begin(); it != l.end(); it++)
		sum += *it;
	int size = l.size();
	return sum / size;
}

void find(const lst& l,const Pair &t)
{
	if (find(l.begin(), l.end(), t) != l.end())
		cout << "\nelement found\n\n";
	else
		cout << "\nelement missing\n\n";	
}

lst add(lst& l, int pos)
{
	Pair elem = average(l);
	auto it = l.begin();
	advance(it, pos - 1); // -1, т.к учитывается begin
	l.insert(it, elem);
	return l;
}


void main()
{
	srand(time(NULL));

	try
	{
		list <Pair> tmp;
		int n;
		cout << "enter n: ";
		cin >> n;

		tmp = make_list(n);
		cout << "\nmake: \n";
		print_list(tmp);

		Pair sr = average(tmp);
		cout << "\naverage: \n" << sr << endl;


		cout << "\nchange: \n";
		for_each(begin(tmp), end(tmp), [&sr](Pair& p) { p -= sr; });
		print_list(tmp);


		cout << "\nsort asc: \n";
		tmp.sort();
		print_list(tmp);

		cout << "\nsort desc: \n";
		tmp.sort([](Pair a, Pair b) {return a > b;});
		print_list(tmp);
		
		
		Pair l, r;
		cout << "\nenter range: \n";
		cin >> l >> r;
		auto it = remove_if(tmp.begin(), tmp.end(), [&l, &r](const Pair& p) { return (l <= p and p <= r); });
		tmp.erase(it, tmp.end());
		cout << "\ndel: \n";
		print_list(tmp);

		Pair t;
		cout << "\nenter pair: \n";
		cin >> t;
		find(tmp, t);

		
		int pos;
		cout << "\nenter pos: ";
		cin >> pos;

		tmp = add(tmp, pos);
		cout << "\nadd: \n";
		print_list(tmp);

	}
	catch (int)
	{
		cout << "\nError!\n";
	}
}