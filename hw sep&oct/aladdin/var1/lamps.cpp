#include <iostream>
using namespace std;

int main()
{
	system("chcp 1251>nul");
	float v1, v2, v3, v4, v5;
	cin >> v1 >> v2 >> v3 >> v4 >> v5;
	
	if (v1 > v2 && v1 > v3 && v1 > v4 && v1 > v5)
	{
		cout << "Лампа L1 самая волшебная" << endl;
	}
	else
	{
		if (v2 > v3 && v2 > v4 && v2 > v5)
		{
			cout << "Лампа L2 самая волшебная" << endl;
		}
		else
		{
			if (v3 > v4 && v3 > v5)
			{
				cout << "Лампа L3 самая волшебная" << endl;
			}
			else
			{
				if (v4 > v5)
				{
					cout << "Лампа L4 самая волшебная" << endl;
				}
				else
				{
					cout << "Лампа L5 самая волшебная" << endl;
				}
			}
		}
	}
}   

