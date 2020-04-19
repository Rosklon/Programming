// ShootingСompetitions.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void table(int** a, int m, int n);
void winner(int** a, int* b, int m, int n);

int main()
{
    setlocale(LC_ALL, "ru");
    srand(unsigned(time(NULL)));
    int n, m;
    cout << "Введите количество стрелков: ";
    cin >> m;
    cout << "Введите количество выстрелов: ";
    cin >> n;
    int** a = new int* [m];
    for (int i = 0; i < m; i++)
        a[i] = new int[n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            /**cin >> a[i][j];**/
            a[i][j]=rand() % 11;
    cout << endl;
    table(a, m, n);
    int* b = new int [m];
    winner(a, b, m, n);
}

void table(int** a, int m, int n)
{
    cout << "Выстрелы:";
    for (int i = 1; i <= n; i++)
        cout << "  " << i;
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        cout << "Стрелок " << i + 1;
        for (int j = 0; j < n; j++)
            cout << "  " << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void winner(int** a, int* b, int m, int n)
{
    int max = 0, mi = 0, p = 0, k = 0, l=0;
    for (int i = 0; i < m; i++)
    {
        int mi = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] > mi)
            {
                mi = a[i][j];
            }
        }
        b[i] = mi;
        /**cout << "Лучший результат cтрелка " << i + 1 << ": " << b[i] << endl;**/
    }
    cout << endl << endl;
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        if (b[i] > max)
        {
            max = b[i];
        }
        
    }
    for (int i = 0; i < m; i++)
    {
        if (b[i] == max)
        {
            k=i+1;
            count++;
        }

    }
    if (count > 1)
    {
        cout << "Победитель: ";
        int p;
        for (int i = 0; i < m; i++)
        {
            if (b[i] == max)
            {
                p = 0;
                for (int j = 0; j < n; j++)
                {
                    p = p + a[i][j];
                }
                if(p>l)
                { 
                    k = i+1;
                    cout << "Cтрелок " << k ;
                }
                else if (p == l)
                {
                    k = i + 1;
                    cout << ", Cтрелок " << k ;
                }
                l = p;
            }
            
        }
    }
    else 
    {
        cout << "Победитель: Cтрелок " << k;
    }
}



