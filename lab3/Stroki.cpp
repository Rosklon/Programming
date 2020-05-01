﻿// Stroki.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

void LowerString(char* s);

int main()
{
    char* s = new char[1];
    cin.getline(s, 80);
    LowerString(s);
}

void LowerString(char* s)
{
    int n = strlen(s);
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (isalpha(s[i]))
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] += 'a' - 'A';
                cout << s[i];
            }
            else
                cout << s[i];
        }
        else
        {
            cout << s[i];
        }

    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.