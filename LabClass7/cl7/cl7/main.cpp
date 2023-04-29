#include <iostream>
#include "List.h"
#include "Pair.h"
using namespace std;


int main() {
	setlocale(0, "");
	Pair p1(2, 2.5);
	List<Pair> a(3, p1);
	cout << a << endl;
	
	cin >> a;
	cout << a << endl;
	
	List<Pair> b(a);
	cout << b << endl;
	
	List<Pair> c = a + b;
	cout << "a + b\n" << c << endl;
		
	for (Iterator<Pair> iter = b.first(); iter != b.last(); ++iter)
		cout << *iter << '\n';
	return 0;
}