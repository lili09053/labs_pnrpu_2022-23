#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int N; // длина диамического массива структур

struct Book
{
    string Title;
    string Author;
    int Year;
    int Pages;
};

ofstream fout;


Book* Filling() //создание и заполнение массива структур
{
    cout << "Введите количество экземпляров: ";
    cin >> N;


    Book *books = new Book[N];

    for (int i = 0; i < N; i++)
    {
        cout << "____________________________________________________________" << endl;
        cout << "Название: ";
        getline(cin, books[i].Title);
        getline(cin, books[i].Title);
        cout << "Автор: ";
        getline(cin, books[i].Author);
        cout << "Год издания: ";
        cin >> books[i].Year;
        cout << "Количество страниц: ";
        cin >> books[i].Pages;
        cout << endl;
    }
    return books;
}

void Output(Book*temp)
{
    string SOURCE = "test.txt";
   
    // fout.open(SOURCE, ofstream :: app);
    fout.open(SOURCE);

    if (fout.is_open())
    {
        cout << "OUTPUT" << endl;

        for (int i = 0; i < N; i++)
        {
          
            fout << "Название: ";
            fout << temp[i].Title << endl;
            fout << "Автор: ";
            fout << temp[i].Author << endl;
            fout << "Год издания: ";
            fout << temp[i].Year << endl;
            fout << "Количество страниц: ";
            fout << temp[i].Pages << endl;
            fout << "____________________________________________________________" << endl;
            fout << endl;

        }
    }
    else
    {
        cout << "Ошибка открытия файла!" << endl;
    }
    
    fout.close();
   
    
}

Book* DEL(Book* temp)
{
    cout << "Хотите удалить 3 элемента из начала файла?" << endl;
    string answer;
    cout << "да ИЛИ нет" << endl;
   
    cin >> answer;
    cin.ignore();

    Book* temp2 = new Book[1];

    if (answer == "да")
    {
        if (N < 3)
        {
            cout << "Ошибка! В файле недостаточно позиций, чтобы удалить 3 элемента!" << endl;
        }
        else 
        {
            N -= 3;
            delete[] temp2;
            temp2 = new Book [N];
            for (int i = 0; i < N; i++)
            {
                temp2[i] = temp[i + 3];
            }
            temp = temp2;
        }
    }
    else
    {
        cout << "ЖАЛЬ" << endl;
    }
    return temp;
}

Book* ADD(Book* temp)
{
    cout << "Хотите добавить информацию о книге?" << endl;
    string answer;
    cout << "да ИЛИ нет" << endl;

    cin >> answer;
    cin.ignore();
    
    string BookName;

    cout << "Введите название книги, перед которой вы хотите добавить позцию: ";
    cin >> BookName;
    
    Book* temp2 = new Book[1];

    if (answer == "да")
    {
        bool fl = false; // найдена ли книга с таким названием
        int i = 0;
        int index = 0;
        
        while (fl == false and i < N)
        {
            if (temp[i].Title == BookName)
            {
                fl = true;
                index = i;
            }
            i++;
        }
  
        if (fl == false)
        {
            cout << "Книги с таким названием не найдено!" << endl;
        }
        else
        {
            N++;
            delete[] temp2;
            temp2 = new Book[N];
            for (int i = 0; i < index; i++)
                temp2[i] = temp[i];
            cout << "Название: ";
            getline(cin, temp2[index].Title);
            getline(cin, temp2[index].Title);
            cout << "Автор: ";
            getline(cin, temp2[index].Author);
            cout << "Год издания: ";
            cin >> temp2[index].Year;
            cout << "Количество страниц: ";
            cin >> temp2[index].Pages;
            cout << "------------------------------------------------------------" << endl;
            cout << endl;
            for (int i = index + 1; i < N; i++)
                temp2[i] = temp[i - 1];
            temp = temp2;
        }
    }
    else
    {
        cout << "В другой раз!" << endl;
    }
    return temp;
}


int main()
{
    system("chcp 1251>NULL");
    Book* books = Filling();
    Output(books);  // вывод массива структур изначально заданных
    books = DEL(books);
    Output(books);
    books = ADD(books);
    Output(books);
}
