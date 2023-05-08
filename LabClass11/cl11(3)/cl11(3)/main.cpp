#include <iostream>
#include <ctime>
#include "Pair.h"
#include "List.h"
using namespace std;


int main()
{
	srand(time(NULL));

	try
	{
		int n;
		cout << "enter n: ";
		cin >> n;
		List <Pair> tmp(n);

		cout << "\nmake: " << endl;
		tmp.print();

		int pos;
		cout << "enter pos: ";
		cin >> pos;

		tmp.add(pos);
		cout << "\nadd: " << endl;
		tmp.print();

		int l, r;
		cout << "enter range: ";
		cin >> l >> r;
		tmp.del(l, r);
		cout << "\ndel: " << endl;
		tmp.print();

		tmp.change();
		cout << "\nchange: " << endl;
		tmp.print();
	}
	catch (int)
	{
		cout << "\nError!\n";
	}
}