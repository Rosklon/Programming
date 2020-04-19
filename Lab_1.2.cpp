// Lab_1.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void creat_massive(int* A, int N); //Создание массива cо случайными элементами в промежутке от а до b.
 //Добавление k перед элементом массива.
void sort(int a[], int n); //Сортировка прямого выбора.

int main()
{
    setlocale(LC_ALL, "ru");
    int num;
    cout << "Введите номер задания(1 ИЛИ 2) или 0 для завершения работы: " << endl;
    cin >> num;
    while (num)
    {
        if (num == 1)
        {
            int i, n = 0, m = 0, j = 0;
            ifstream F1;
            ofstream F2;
            F2.open("mass.txt", ios::out);
            F1.open("randord.txt", ios::in);
            while (!F1.eof())
            {
                F1 >> m;
                if (m < 0)
                    n++;// Счетчик количества отрицательных чисел в масиве.
            }
            F1.close();
            cout << "Количество отрицательных чисел: " << n << endl;//Вывод количества чисел в массиве. 
            int* a = new int[n];//Создание массива. 
            F1.open("randord.txt", ios::in);
            while (!F1.eof())
            {
                F1 >> m;
                if (m < 0)
                {
                    a[j] = m;//Наполнение массива отрицательными числами. 
                    j += 1;
                }
            }
            sort(a, n);//Сортировка массива по возрастанию. 
            for (i = 0; i < n; i++)
            {
                F2 << a[i] << endl;//Вывод отсортированного массива в файл. 
            }
            cout << "Задание 1 выполнено." << endl;
            F1.close();
            F2.close();
        }
        if (num == 2)
        {
            int N;
            cout << "Введите количество элементов в массиве: ";
            cin >> N;
            
            int* A = new int[N];
            creat_massive(A, N);
            int kol = 0;
            int k;
            
            cout << "Введите число K для добавления его перед отрицальным элементом массива: ";
            cin >> k;
            for (int i = 0; i < N; i++)
            {
                if (A[i] < 0)
                {
                    kol++;
                }
            }
            
            N =N + kol;
            int* AwK = new int[N];
            int j = 0;

            for (int i = 0; i < N; i++)
            {
                
                if (A[j] < 0)
                {
                    AwK[i] = k;
                    i++;
                    AwK[i] = A[j];
                }
                else
                    AwK[i] = A[j];
                j++;
            }
            for (int i = 0; i < N ; i++)
            {
                cout << AwK[i] << "     ";
            }
            cout << endl << "Задание 2 выполнено." << endl;
        }
        if (num > 2 || num < 0) cout << "Вы выбрали не существующую задачу. Повторите выбор." << endl;
        cout << "Введите номер задания(1 ИЛИ 2) или 0 для завершения работы: " << endl;
        cin >> num;
    }
    return 0;
}

void creat_massive(int* A, int N)
{
    int a, b;
    cout << "Необходимо ввести диапазон элементов массива [a,b]." << endl;
    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    while (a > b || a == b)//Проверка достоверности введенных данных.
    {
        if (a > b || a == b) cout << "Повторите ввод a и b. Необходимо чтобы выполнялись условия: a меньше b и a не равно d." << endl;
        cout << "Введите a: ";
        cin >> a;
        cout << "Введите b: ";
        cin >> b;
    }

    for (int i = 0; i <= N; i++)
    {
        A[i] = a + rand() % (b - a + 1);
      
    }


}




void sort(int a[], int n)
{
    int i, j, min, mink = 0, t;
    for (i = 0; i < n - 1; i++)
    {
        min = a[i];
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                mink = j;
            }
        }
        if (a[i] > min)
        {
            t = a[i];
            a[i] = a[mink];
            a[mink] = t;
        }
    }
}

