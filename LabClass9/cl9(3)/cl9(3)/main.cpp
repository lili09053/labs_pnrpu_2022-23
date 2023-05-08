#include <iostream>
#include "List.h"
#include "Error.h"

using namespace std;

int main()
{
	List A1(4);

	try
	{
		List A2(-2);
	}
	catch (Error& e) { cout << "List size error!" << endl; }

	try
	{
		List A3(15);
	}
	catch (Error& e) { cout << "List size error!" << endl; }

	List B1(A1 + 5);
	cout << "List B1: element 3 is " << B1[2] << endl;

	try
	{
		cout << "List B1: element 3 is " << B1[-3] << endl;
	}
	catch (Error& e) { cout << "Min index error!" << endl; }

	try
	{
		cout << "List B1: element 3 is " << B1[6] << endl;
	}
	catch (Error& e) {  cout << "Max index error!" << endl; }

	List C1(10);

	try
	{
		C1++;
	}
	catch (Error& e) { cout << "List is already full! Can't add new element" << endl; }

	return 0;
}