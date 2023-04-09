// поиск Бойера - Мура

#include <iostream>
#include <string>
using namespace std;

int* table(string substr)
{
    int tab[256];
    int size = substr.size(); // длина подстроки

    for (int i = 0; i < 256; i++)
    {
        tab[i] = size; //заполняем массив длиной образа
    }
    
    for (int i = size - 2; i >= 0; i--)																// substr[size - 2] -  предпоследний символ образа (индекс)
    {
        if (tab[int(unsigned char(substr[i]))] == size)											// Для символов образа находим их ячейку в массиве - код буквы - позиция в массиве - 1
        {
            tab[int(unsigned char(substr[i]))] = size - i - 1;									// И присваиваем необходимое значение - удалённость символа от последнего
        }
    }
    return tab;
}

int search(string str, string substr)
{
    int size = substr.size();
    int* tab = table(substr);

    int res = -1;
    
    int i = size - 1;
  
    while(i < str.size())
    {
        if (substr[size - 1] != str[i])
        {
            i += tab[int(unsigned char(str[i]))];
           // break;
        }
        else 
        {
            for (int j = size - 1; j >= 0; j--)
            {
                if (substr[j] != str[i - size + j + 1])									// Если обнаружено несовпадение
                {
                    i += tab[int((unsigned char)str[i])];							// Сдвиг
                    break;																				// Прерывание текущей проверки
                }
               
                if (j == 0 and substr[j] == str[i - size + j + 1])																		// Если поиск окончен (Шаблон нашелся в подстроке)
                {
                    res = i - size + 1;
                    break;
                }
            }
        }
        
        if (res == i - size + 1)
            break;
        
    }
    return res;
}


int main()
{
    system("chcp 1251>NULL");
    string str;
    string substr;
    
    cout << "Введите строку: " ;
    getline(cin, str);
    cout << "Введите образ: ";
    getline(cin, substr);

    cout << "result: " << search(str, substr);
}

