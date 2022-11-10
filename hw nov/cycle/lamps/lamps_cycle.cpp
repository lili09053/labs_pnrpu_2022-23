#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    
    float volume[5];              
    for (int i = 0; i < 5; i++)         // создание массив
        cin >> volume[i];
    
    int size = sizeof(volume) / sizeof(volume[0]); /* sizeof вероятнее всего работает с памятью массива, поэтому необходимо общую занимаемую массивом память поделить на обьем памяти, занимаемым  одним элементом массива */
        
    /* проверка массива
    for (int i = 0; i < size; i++)
        cout << volume[i] << endl;
    */

    float max_value = 0;
    int num = 0;            //номер лампы
    
    
    
    for (int i = 0; i < size; i++) // цикл for
    {
        if (volume[i] > max_value)
        {
            max_value = volume[i];
            num = i;
        }
    } 
    cout << "Проверка циклом FOR: " << "Лампа " << ++num << " имеет набольший объём волшебства, равный " << max_value << endl; // ++ num - префикс, т.е операция +1 выполнится раньше, чем выведется знасение num

    int i = 0;
    max_value = 0;
    num = 0;

   
    while (i < size)
    {
        if (volume[i] > max_value)
        {
            max_value = volume[i];
            num = i;
        }
        i++;

    }
    cout << "Проверка циклом WHILE: " << "Лампа " << ++num << " имеет набольший объём волшебства, равный " << max_value << endl;

    i = 0;
    max_value = 0;
    num = 0;        
    do
    {
        if (volume[i] > max_value)
        {
            max_value = volume[i];
            num = i;
        }
        i++;  
    }
    while (i < size);

    cout << "Проверка циклом  DO WHILE: " << "Лампа " << ++num << " имеет набольший объём волшебства, равный " << max_value << endl;


}
