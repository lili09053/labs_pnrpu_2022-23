/*18.	Сформировать массив строк. Удалить из него строку, начинающуюся на букву "а".*/

#include <iostream>
#include <string>
using namespace std;

int N;


string* FilSt()
{
    cout << "Введите количество строк: ";
    cin >> N;
    string* sts = new string[N];

    getline(cin, sts[0]);
    
    for (int i = 0; i < N; i++)
    {
        getline(cin, sts[i]);
    }
    
    cout << "_________________________________________________________" << endl;

    return sts;
   
}

void Output(string* temp)
{
    cout << "_________________________________________________________" << endl;

    for (int i = 0; i < N; i++) cout << temp[i] << endl;
    cout << "_________________________________________________________" << endl;

}

string* DelA(string* temp)
{
    int ct = 0; // счетчик строк, начинающихся с буквы а
    
    for (int i = 0; i << N; i++)
    {
        if (temp[i][0] == 'а' or temp[i][0] == 'А')
        {
            ct++;
        }
    }
    
    string* temp1 = new string[N - ct];
    int index = 0;
    for (int i = 0; i < N; i++)
    {
        if (temp[i][0] != 'а' and temp[i][0] != 'А') // !(temp[i][0] == 'а' or temp[i][0] == 'А')
        {
            temp1[index] = temp[i];
            index++;
        }
        
    }
    N -= ct;
    return temp1;
}

int main()
{
    system("chcp 1251>NULL");
    
    string* temp = new string[N];
    temp = FilSt();

    Output(temp);

    string* temp2 = new string[N];
    temp2 = DelA(temp);
    Output(temp2);

    delete[] temp;
    temp = nullptr;
    delete[] temp2;
    temp2 = nullptr;

}

