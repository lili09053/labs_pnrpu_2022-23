#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#include "Pair.h"
using namespace std;

typedef multimap<Pair, Pair> mmp;
typedef pair<Pair, Pair> pr;

mmp make_list(int n)
{
	mmp l;
	for (int i = 0; i < n; i++)
	{
		Pair key, val;
		cout << "\nEnter key: \n";
		cin >> key;
		cout << "\nEnter value: \n";
		cin >> val;
		l.emplace(key, val);
	}

	return l;
}

void print(mmp& l)
{
	for (auto it = l.begin(); it != l.end(); it++)
	{
		cout << "\nkey - value\n";
		cout << it->first;
		cout << it->second;
	}
	cout << endl;
}

pr average(mmp& l)
{
	Pair sum_key;
	Pair sum_val;
	for (auto it = l.begin(); it != l.end(); it++)
	{
		sum_key += it->first;
		sum_val += it->second;
	}
	int size = l.size();
	pr p(sum_key / size, sum_val / size);
	return p;
}

void change(const pr &sr, mmp& l)
{
	mmp tmp;
	for (auto it = l.begin(); it != l.end(); it++)
	{
		tmp.emplace(it->first - sr.first, it->second - sr.second);
	}
	swap(l, tmp);
}

void sort_desc(mmp t)
{
	multimap<Pair, Pair, greater<Pair>> p;
	for (auto it = t.begin(); it != t.end(); it++)
		p.emplace(it->first, it->second);
	
	for (auto it = p.begin(); it != p.end(); it++)
	{
		cout << "\nkey - value\n";
		cout << it->first;
		cout << it->second;
	}
	cout << endl;
}


void find(const mmp& l, const pr& t)
{
	if (find_if(l.begin(), l.end(), [&t](const pr& p) { return (t.first == p.first and t.second == p.second); }) != l.end())
		cout << "\nelement found\n\n";
	else
		cout << "\nelement missing\n\n";
}

void add(mmp& l, const pr& sr) // вставка невозможна по заданной позиции, т.к. контейнер отсортирован
{
	l.emplace(sr.first, sr.second);
}

void del(mmp& t, const Pair& l, const Pair& r)
{
	auto it = remove_if(t.begin(), t.end(), [&l, &r](const pr& t) { return (l <= t.first and t.first <= r); });
	t.erase(it, t.end());
}

int main()
{
	try
	{
		mmp tmp;
		int n;
		cout << "enter n: ";
		cin >> n;

		tmp = make_list(n);
		cout << "\nmake: \n";
		print(tmp);

		pr sr = average(tmp);
		cout << "\naverage: \n";
		cout << sr.first;
		cout << sr.second;

		cout << "\nchange: \n";
		//for_each(tmp.begin(), tmp.end(), [&sr](pr &t) { t.first -= sr.first; t.second -= sr.second; }); // не работает!
		change(sr, tmp);
		print(tmp);

		cout << "\nsort asc: \n";
		print(tmp);

		cout << "\nsort desc: \n";
		sort_desc(tmp);

		pr t;
		cout << "\nenter pair: \n";
		cout << "\nEnter key: \n";
		cin >> t.first;
		cout << "\nEnter value: \n";
		cin >> t.second;
		find(tmp, t);

		Pair l, r;
		cout << "\nenter range: \n";
		cin >> l >> r;
		del(tmp, l, r);
		cout << "\ndel: \n";
		print(tmp);
	}	
	catch (int)
	{
		cout << "\nError!\n";
	}
}