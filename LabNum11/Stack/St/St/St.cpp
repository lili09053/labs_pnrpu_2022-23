#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Stack 
{
	int data;
	Stack* next;
};

int N; //временное количество элементов в стеке

Stack* peek;    // вершина стека


void Push(Stack* elem) // Добавление элемента в вершину стека
{
    if (N != 0)
        elem->next = peek;
    peek = elem;
    N++;
}

void Push_k(int k)
{
    int i = 0;
    
    Stack* node = new Stack;
    while (i < k)
    {
        node = new Stack;                      
        cin >> node->data;                    // Запись нового элемента
        Push(node);
        i++;
    }
}

Stack* Pop()            // удаление из вершины стека
{
    Stack* delElem = peek;
    peek = peek->next;
    delElem->next = nullptr;
    N--;
    return delElem;
}

void Pop_k(int k)
{
    int i = 0;

    while (i < k)
    {
        Pop();
        i++;
    }
}

void create()
{
    cout << "Метод создания стека вызван" << endl;
    peek = nullptr;
    Stack* node = new Stack; // выделение памяти под узел
    cout << "Введите элементы стека: ";
    cin >> node->data;
    node->next = nullptr;
    peek = node;
  
    int n = N;
    N = 1;
    for (int i = 1; i < n; i++)
    {
        node = new Stack;                      // Переход указателем на следующий элемент
        cin >> node->data;                    // Запись нового элемента
        node->next = nullptr;                       // Указатель на следующий элемент равен нулю, т. к. был записан последний элемент
        Push(node);
    }
    cout << "Стек заполнен" << endl;
}

void PrintConsole()
{
    Stack* first = peek;
    while (first != NULL)
    {
        cout << first->data << " ";
        first = first->next;
    }
    cout << endl;
}

fstream file;
string path = "Stack.txt";

void PrintFile()
{
    file.open(path, fstream::out); //открытие файла для записи
    if (!file.is_open())
        cout << "Ошибка открытия файла " << path << " для записи" << endl;
    else
    {
        Stack* first = peek;
        while (first != NULL)
        {
            file << first->data << endl;
            first = first->next;
        }

        cout << "Данные записаны в файл" << endl;
    }

    file.close();
}

void Delete()
{
    while (N != 0)
    {
        Stack* tmp = Pop();
        delete tmp;
    }
}

int r = 0;
void Recovery()
{
    file.open(path, fstream::in); //открытие файла для чтения
    if (!file.is_open())
        cout << "Ошибка открытия файла " << path << " для записи" << endl;
    else
    {
       
        Stack* node = new Stack; // выделение памяти под узел
        string tmp;
        getline(file,tmp);
        node->data = stoi(tmp);
        node->next = nullptr;
        peek = node;

        int i = 1; // позиция курсора
        N = 1;
        while (!file.eof())
        {
            if (i != 1)
            {
                node = new Stack;                   // Выделение  димнамической памяти под новый элемент
                getline(file, tmp);
                if (tmp != "")
                {
                    node->data = stoi(tmp);                // Запись нового элемента
                    node->next = nullptr;
                    Push(node);
                }
            }
            i++;
        }
        if (r == 0)
        {
            r++;
            PrintFile();
            Delete();
            Recovery();
        }
        r--;
        cout << "Стек восстановлен!" << endl;
    }

    file.close();
}

void print_menu() {
    system("cls"); // очищаем экран
   
    cout << "\t\t\t\t~~~~~~~~ СТЕК ~~~~~~~~" << endl << endl;

    cout << "\t\t\t\t1. Создать стек" << endl;
    cout << "\t\t\t\t2. Добавить k элементов в стек"  << endl;        // из вершины стека
    cout << "\t\t\t\t3. Удалить k элементов из стека"  << endl;        // из вершины стека
    cout << "\t\t\t\t4. Вывод стека в консоль" << endl;
    cout << "\t\t\t\t5. Запись стека в файл" << endl;
    cout << "\t\t\t\t6. Уничтожение стека" << endl;
    cout << "\t\t\t\t7. Восстановление стека из файла" << endl;
    cout << "\t\t\t\t8. Выход" << endl;
    cout << endl;
    cout << "______________________________________________" << endl;
    cout << endl;
      
    cout << ">> ";
}

int get_var(int count)
{
    int var;
    cin >> var;
    // пока ввод некорректен, сообщаем об этом и просим повторить его
    while (var < 1 or var > count) {
        cout << "НЕКОРРЕКТНЫЙ ВВОД! ПОПРОБУЙТЕ СНОВА " << endl; // выводим сообщение об ошибке
        system("pause");
        cout << ">> ";
        cin >> var; // считываем строку повторно
    }
    return var;
}


int main()
{
    system("chcp 1251>NULL");
    print_menu();

    int k;
    int var;

    do {
        print_menu(); // выводим меню на экран

        var = get_var(8); // получаем номер выбранного пункта меню

        switch (var)
        {
            case 1:
                cout << "Введите количество элементов стека:  ";
                cin >> N;
                create();
                break;

            case 2:
                cout << "Введите количество элементов, которое вы хотите добавить в стек:  ";
                cin >> k;
                cout << "Введите элементs: ";
                Push_k(k);
                break;


            case 3:
                cout << "Введите количество элементов, которое вы хотите удалить из стека:  ";
                cin >> k;
                Pop_k(k);
                break;


            case 4:
                if (N == 0)
                {
                    cout << "Элементы в стеке осутствуют!" << endl;
                }
                cout << "Cтек: ";
                PrintConsole();
                break;

            case 5:
                PrintFile();
                break;

            case 6:
                Delete();
                if (N == 0) {
                    cout << "Cтек удален!" << endl;
                    peek = nullptr;
                }
                break;

            case 7:
                Recovery();
                break;

        }

        if (var != 8)
            system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнения выбранного пункта
    } while (var != 8);


}




