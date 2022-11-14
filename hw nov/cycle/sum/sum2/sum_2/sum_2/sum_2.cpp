#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	int l;
	cin >> l;
	int s = 0;

	for (int i = 1; i <= l; i++)
	{
		if (i % 3 == 0)
			s -= i;
		else
			s += i;
	}
	cout << "Результат выполнения. Цикл FOR: " << s << endl;

	int i = 1;
	s = 0;

	while (i <= l)
	{
		if (i % 3 == 0)
			s -= i;
		else
			s += i;
		i++;
	}

	cout << "Результат выполнения. Цикл WHILE: " << s << endl;

	i = 0;
	s = 0;

	do
	{
		{
			if (i % 3 == 0)
				s -= i;
			else
				s += i;
			i++;
		}
	}
	while (i <= l);
	
	cout << "Результат выполнения. Цикл DO WHILE: " << s << endl;

}


