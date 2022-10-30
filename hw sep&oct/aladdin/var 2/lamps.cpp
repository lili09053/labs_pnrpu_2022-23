#include <iostream>
using namespace std;

int main()
{
	system("chcp 1251>nul");
	float v1, v2, v3, v4, v5;
	cin >> v1 >> v2 >> v3 >> v4 >> v5;
	string lampName;
	
	if (v1 > v2 && v1 > v3 && v1 > v4 && v1 > v5)
	{
		lampName = "L1"
	}
	
	else
	{
		if (v2 > v3 && v2 > v4 && v2 > v5)
		{
			lampName = "L2"
		}
		
		else
		{
			if (v3 > v4 && v3 > v5)
			{
				lampName = "L3"
			}
			
			else
			{
				if (v4 > v5)
				{
					lampName = "L4"
				}
				
				else
				{
					lampName = "L5"
				}
			}
		}
	}
	cout << "Лампа" << lampName << "самая волшебная" << endl;
}   

