#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream> 
#include "string.h"
#include "time.h"

using namespace std;

void sortmatrix(int** mask, int n, int m);

int main()
{
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));

    int num;
    cout << "Введите номер задания(2 или 3) или 0 для завершения работы: " << endl;
    cin >> num;
    cout << endl;
    system("cls");
    while (num)
    {
        if (num == 2)
        {
            char* str = new char[256];
            char* tok = new char[80];
            int count = 0;
            ifstream f("text.txt");
            f.getline(str, 255);
            while (f.getline(str, 255))
            {
                tok = strtok(str, " !?.,");
                while (tok != 0)
                {
                    if (strlen(tok) == 1) count++;
                    tok = strtok(NULL, " !?.,");
                }
            }
            cout << "Количество слов из одного символа: " << count << endl;

            delete[] str;
            delete[] tok;
        }
        if (num == 3)
        {
            char* str = new char[256];
            char* tempstr = new char[256];
            char* strsort = new char[256];
            char* tok = new char[80];
            int** a;
            int n = 0, m = 0;

            ifstream f("text.txt");
            f.getline(str, 255);

            cout << "Не измененная строка: " << endl << "Do you like prоgramming?" << endl << endl;

            strcpy(tempstr, str);
            tok = strtok(tempstr, " ,.?!");
            while (tok != 0)
            {
                n++;
                if (strlen(tok) >= m) m = strlen(tok);
                tok = strtok(NULL, " ,.?!");
            }
            a = new int* [n];
            for (int i = 0; i < n; i++)
            {
                a[i] = new int[m];
            }

            strcpy(tempstr, str);
            tok = strtok(str, " ,.?!");
            int i = 0;
            while (tok != 0)
            {
                int j = 0;
                for (; tok[j] != '\0'; j++)
                {
                    a[i][j] = tolower(tok[j]);
                }
                for (; j < m; j++)
                {
                    a[i][j] = 0;
                }
                i++;
                tok = strtok(NULL, " ,.?!");
            }

            sortmatrix(a, n, m);

            int k = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; a[i][j] != 0 && j < m; j++)
                {
                    strsort[k] = a[i][j];
                    k++;
                }
                strsort[k] = ' ';
                k++;
            }
            k--;
            strsort[k] = '\0';
            cout << "Строка в порядке, обратном алфавиту: " << endl << strsort << endl << endl;

            delete[] str;
            delete[] tempstr;
            delete[] strsort;
            delete[] tok;
            for (int i = 0; i < n; i++) 
                delete[] a[i];
            delete[]a;
        }
        if (num > 3 || num < 2) cout << "Вы выбрали не существующую задачу. Повторите выбор." << endl;
        cout << endl << "Введите номер задания(1 ИЛИ 2) или 0 для завершения работы: " << endl;
        cin >> num; cout << endl;
        system("cls");
    }
    return 0;
}


void sortmatrix(int** a, int n, int m) //Сортирует строки целочисленной матрицы mask размерностью n на m в порядке возрастания элементов первого столбца. Если найдет равные элементы, то будет смотреть строки, пока не найдет неравные
{
    for (int i = 0; i < n; i++)
    {
        int mini = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j][0] > a[mini][0]) mini = j;
            if (a[j][0] == a[mini][0])
            {
                for (int k = 0; k < m; k++)
                {
                    if (a[j][k] > a[mini][k])
                    {
                        mini = j;
                        break;
                    }
                }
            }
        }

        int* min = new int[m];
        for (int j = 0; j < m; j++)
        {
            min[j] = a[mini][j];
        }

        for (int j = mini; j > i; j--)
        {
            for (int k = 0; k < m; k++)
            {
                a[j][k] = a[j - 1][k];
            }
        }
        for (int j = 0; j < m; j++)
        {
            a[i][j] = min[j];
        }

        delete[]min;
    }
}