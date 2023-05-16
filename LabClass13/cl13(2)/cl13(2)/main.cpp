#include <iostream>
#include "Pair.h"
#include <queue>
using namespace std;
// практически все функции остаются неизменными, если работать непосредственно с адаптером контейнера - очередь с приоритетом
// можно из очереди перенести данные в другие контейнеры, поработать с ними и вернуть в очередь [как по мне бессмысленно]
//очередь с приоритетом уже является отсортированной по убыванию

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
	while (!t.empty())
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

void del(pq& t, Pair l, Pair r)
{
	pq tmp;
	
	while (!t.empty())
	{
		Pair el = t.top();
		if (el < l or el > r) tmp.push(el);
		t.pop();
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

void sort_asc(pq t)
{
	priority_queue < Pair, vector<Pair>, greater<Pair>> que;
	while (!t.empty())
	{
		Pair el = t.top();
		que.push(el);
		t.pop();
	}
	
	while (!que.empty())	// вывод
	{
		cout << que.top();
		que.pop();
	}
	cout << endl;
}

void find_el(pq t, Pair a)
{
	vector<Pair> que;
	while (!t.empty())
	{
		Pair el = t.top();
		que.push_back(el);
		t.pop();
	}


	auto it = find_if(que.begin(), que.end(), [&](const Pair& i) {
		return i == a;});

	if (it != que.end())
		cout << "\nelement found\n\n";
	else
		cout << "\nelement missing\n\n";

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
		cout << "\nmake: \n";
		print(tmp);

		Pair sr = average(tmp);
		cout << "\naverage: \n" << sr << endl;

		cout << "\nchange: \n";
		change(tmp);
		print(tmp);

		Pair l, r;
		cout << "\nenter range: \n";
		cin >> l >> r;
		del(tmp, l, r);
		cout << "\ndel: \n";
		print(tmp);

		cout << "\nsort asc: \n";
		sort_asc(tmp);
		
		cout << "\nsort desc: \n";
		print(tmp);

		add(tmp);
		cout << "\nadd: " << endl;
		print(tmp);

		Pair t;
		cout << "\nenter pair: \n";
		cin >> t;
		find_el(tmp, t);
	}
	catch (int)
	{
		cout << "\nError!\n";
	}
}