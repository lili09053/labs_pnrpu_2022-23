#include <iostream>
#include <map>
using namespace std;

typedef map <int, int> Tmap;

Tmap make(int n)
{
	Tmap tmp;
	int el;
	for (int i = 1; i <= n; i++)
	{
		cout << "enter elem: ";
		cin >> el;
		tmp.emplace(i, el);
	}
	return tmp;
}

void print(Tmap& t)
{
	for (auto it = t.begin(); it != t.end(); ++it)
		cout << it->first << " _ " << it->second << "\n";
	cout << endl;
}

int average(Tmap& t)
{
	int sum = 0;
	int size = 0;
	for (auto it = t.begin(); it != t.end(); ++it)
	{
		sum += it->second;
		size++;
	}
	
	return sum / size;
}

void add(Tmap& t, int pos)
{
	int elem = average(t);
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

Tmap del(Tmap& t, int l, int r)
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
	int el = average(t);
	for (auto it = t.begin(); it != t.end(); ++it)
		it->second -=  el;
}

int main() 
{
	int n;
	Tmap ex;
	
	cout << "enter n: ";
	cin >> n;
	
	ex = make(n);
	print(ex);

	int pos;
	cout << "enter pos: ";
	cin >> pos;
	
	add(ex, pos);
	cout << "\nadd: " << endl;
	print(ex);


	change(ex);
	cout << "change: " << endl;
	print(ex);
	
	int l, r;
	cout << "enter range: ";
	cin >> l >> r;
	ex = del(ex, l, r);
	cout << "del: " << endl;
	print(ex);
}