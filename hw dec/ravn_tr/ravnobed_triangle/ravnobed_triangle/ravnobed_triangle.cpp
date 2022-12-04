#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int n;
	cin >> n;
	
	if (n % 2 != 0 and n > 0)
	{
		for (int i = 1; i <= n; i += 2)
		{
			for (int k = 1; k <= (n - i) / 2; k++)
				cout << ' ';

			for (int j = 1; j <= i; j++)
				cout << '*';
			cout << endl;
		}

		cout << "______________________________________________-" << endl << endl;

		for (int i = n; i >= 1; i -= 2)
		{
			for (int k = 1; k <= (n - i) / 2; k++)
				cout << ' ';

			for (int j = 1; j <= i; j++)
				cout << '*';
			cout << endl;
		}

	}
	else
	{
		cout << "Введите модуль нечетного числа\n";
	}
}
