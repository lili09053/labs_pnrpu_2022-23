#include <iostream>
#include <map>
#include "Pair.h"
using namespace std;

typedef map <Pair, Pair> Tmap;

Tmap make(int n)
{
	Tmap tmp;
	Pair el, k;
	for (int i = 1; i <= n; i++)
	{
		cout << "\nenter key: \n";
		cin >> k;
		cout << "\nenter elem: \n";
		cin >> el;
		tmp.emplace(k, el);
	}
	return tmp;
}

void print(Tmap& t)
{
	for (auto it = t.begin(); it != t.end(); ++it)
		cout << "\nkey - value\n" << it->first << it->second << "\n";
	cout << endl;
}


Pair average(Tmap& t)
{
	Pair sum;
	int size = 0;
	for (auto it = t.begin(); it != t.end(); ++it)
	{
		sum += it->second;
		size++;
	}

	return sum / size;
}


void add(Tmap& t, Pair pos)
{
	Pair elem = average(t);
	if (t.count(pos))
	{
		cout << "adding with this key is not possible" << endl;	// ключ должен быть уникальный
		return;
	}
	else
	{
		t.insert(make_pair(pos, elem));
	}

}

Tmap del(Tmap& t, Pair l, Pair r)
{
	Tmap tmp = t;
	for (auto it = t.begin(); it != t.end(); ++it)
	{
		if (it->first >= l and it->first <= r)
			tmp.erase(it->first);
	}
	return tmp;

}

void change(Tmap& t)
{
	Pair el = average(t);
	for (auto it = t.begin(); it != t.end(); ++it)
		it->second -= el;
}

int main()
{
	int n;
	Tmap ex;

	cout << "enter n: ";
	cin >> n;

	ex = make(n);
	print(ex);
   
	Pair pos;
	cout << "enter pos: \n";
	cin >> pos;

	add(ex, pos);
	cout << "\nadd: " << endl;
	print(ex);

	
	change(ex);
	cout << "change: " << endl;
	print(ex);
	

	Pair l, r;
	cout << "enter range: \n";
	cout << "left: \n";
	cin >> l;
	cout << "right: \n";
	cin >> r;
	ex = del(ex, l, r);
	cout << "\ndel: " << endl;
	print(ex);
}