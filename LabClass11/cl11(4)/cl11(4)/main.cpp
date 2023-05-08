#include <iostream>
#include "Pair.h"
#include <queue>
#include<list>
using namespace std;


typedef priority_queue <Pair> pq;

pq make(int n)
{
	pq tmp;
	Pair el;
	for (int i = 0; i < n; i++)
	{
		cin >> el;
		tmp.push(el);
	}
	return tmp;
}

void print(pq t)
{
	while(!t.empty())
	{
		cout << t.top();
		t.pop();
	}

	cout << endl;
}

Pair average(pq t)
{
	Pair sum;
	int size = t.size();
	while (!t.empty())
	{
		sum += t.top();
		t.pop();
	}
	return sum / size;
}


void add(pq& t) //в данном случае, не получиться добавить в указанную позицию. Добавление по приоритету
{
	Pair el = average(t);
	t.push(el);
}

void del(pq& t, int l, int r)
{
	pq tmp;
	int i = 1;
	
	while (!t.empty())
	{
		Pair el = t.top();
		if (i < l or i > r) tmp.push(el);
		t.pop();
		i++;
	}
	swap(tmp, t);
}

void change(pq& t)
{
	Pair el = average(t);
	pq tmp;
	while (!t.empty())
	{
		Pair elem = t.top();
		Pair em = elem - el;
		tmp.push(em);
		t.pop();
	}
	swap(tmp, t);
}

int main()
{
	try
	{
		int n;
		cout << "enter n: ";
		cin >> n;
		pq tmp;
		tmp = make(n);

		cout << "\nmake: " << endl;
		print(tmp);

		add(tmp);
		cout << "\nadd: " << endl;
		print(tmp);

		int l, r;
		cout << "enter range: ";
		cin >> l >> r;
		del(tmp, l, r);
		cout << "\ndel: " << endl;
		print(tmp);
		
		change(tmp);
		cout << "\nchange: " << endl;
		print(tmp);
	}
	catch (int)
	{
		cout << "\nError!\n";
	}
}