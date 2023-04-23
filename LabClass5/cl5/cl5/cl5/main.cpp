#include <iostream>
#include <string>
#include "Object.h"
#include "Person.h"
#include "Student.h"
#include "Vector.h"
using namespace std;

int main()
{
	/*
	Person A;
	cin >> A;
	cout << "Operator << " << endl;
	cout << A; // через перегруженную функцию

	Object* ptr = &A;
	cout << "Show()" << endl;
	ptr->Show();

	Student B;
	cin >> B;
	cout << "Operator << " << endl;
	cout << B;

	ptr = &B;
	cout << "Show()" << endl;
	ptr->Show();
	*/

	Vector m(3);

	Person A;
	cin >> A;

	Student B;
	cin >> B;

	Object* p = &A;
	m.Add(p);

	p = &B;
	m.Add(p);

	cout << m;

}
