// поисk Кнутта-Мориса-Пратта

#include <iostream>
#include <string>
using namespace std;


int* func(string substr)																			// Функция формирвания префикс-функции (массив сдвига)
{
    int size = substr.size();
    int* tab = new int[size];																	
    int i = 1;
    int j = 0;
    tab[0] = 0;																								// Первый символ всегда имеет сдвиг 0 
    while (i < size)
    {
        if (substr[j] == substr[i])
        {
            tab[i] = j + 1;																					// Сдвиг на позицию этого символа
            i++;
            j++;
        }
        else
        {
            if (j == 0)
            {
                tab[i] = 0;																					// Сдвиг на первый символ
                i++;
            }
            else
            {
                j = tab[j - 1];																				// Сдвиг на первое вхождение символа												
            }
        }
    }
    return tab;																								
}

int search(string str, string substr)
{
    int* tmp = func(substr);
    int res = -1;
    int i = 0;
    int j = 0;
    while (i < str.size())																					// Проход по строке
    {
        if (substr[j] == str[i])
        {
            if (j == substr.size() - 1)													// Если совпали последний символ шаблона и символ строки и до этого совпадения у них не было
            {
                res = i - j;											
                break;
            }
            else																						// Если совпали не последний символ шаблона и символ строки (или совпадение уже произошло)
            {
                j++;
                i++;
            }
        }
        else if (substr[j] != str[i])
        {
            if (j == 0)																					// Если символ первый в шаблоне
            {
                i++;																					// Переходим на следующий символ
            }
            else																						// Если смивол не первый в шаблоне
            {
                j = tmp[j - 1];																			// Сдигаем согласно префикс-функции
            }
        }
        
    }
   return res;  
}

int main()
{
    system("chcp 1251>NULL");
    string str;
    string substr;

    cout << "Введите строку: ";
    getline(cin, str);
    cout << "Введите образ: ";
    getline(cin, substr);

    cout << "result: " << search(str, substr) << endl;

}

