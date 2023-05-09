#include <iostream>
#include <ctime>
#include "Pair.h"
#include "List.h"
using namespace std;


int main()
{
	try
	{
		int n;
		cout << "enter n: ";
		cin >> n;
		List <Pair> tmp(n);
		List <Pair> tmp2;

		cout << "\nmake: " << endl;
		tmp.print();

		Pair pos;
		cout << "enter pos: \n";
		cin >> pos;
		tmp.add(pos);
		cout << "\nadd: " << endl;
		tmp.print();

		tmp.change();
		cout << "\nchange: " << endl;
		tmp.print();

		Pair l, r;
		cout << "left: \n";
		cin >> l;
		cout << "right: \n";
		cin >> r;

		tmp = tmp.del(l, r);
		cout << "\ndel: " << endl;
		tmp.print();

		
	}
	catch (int)
	{
		cout << "\nError!\n";
	}
}