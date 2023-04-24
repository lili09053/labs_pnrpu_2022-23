#include <iostream>
#include <ctime>
#include "List.h"
using namespace std;

int main()
{
	List A(10, 8);
	cout << A << endl;
	
	srand(time(NULL));
	for (int i = 0; i < A(); i++) A[i] = rand() % 100 - 40;
	
	cout << A << endl;
	
	List B(A);
	cout << "Copy:\n";
	cout << B << endl;
	
	A = A + B;
	cout << A << endl;
	
	List C(10, 7);
	for (Iterator iter = B.first(); iter != B.last(); ++iter)
		cout << *iter << " ";

	return 0;
}