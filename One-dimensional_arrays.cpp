#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void creat_massive(int* A, int N); //Создание массива cо случайными элементами в промежутке от а до b.
void Add_k(int* A, int N); //Добавление k перед элементом массива.
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
            int N = rand() % 1 + 101;
            int* A = new int[N];
            creat_massive(A, N);
            Add_k(A, N);
            cout << "Задание 2 выполнено." << endl;
        }
        if (num > 2 || num < 0) cout << "Вы выбрали не существующую задачу. Повторите выбор." << endl;
        cout << "Введите номер задания(1 ИЛИ 2) или 0 для завершения работы: " << endl;
        cin >> num;
    }
    return 0;
}

void creat_massive(int* A, int N)
{
    fstream arr2;
    arr2.open("massive.txt", ios::out);
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
        cout << "Введите a: ";
        cin >> a;
        cout << "Введите b: ";
        cin >> b;
    }

    for (int i = 0; i <= N; i++)
    {
        A[i] = rand() % b + a;
    }


}

void Add_k(int* A, int N)
{
    fstream arr2;
    arr2.open("massive.txt", ios::out);
    int k;
    cout << "Введите число K для добавления его перед отрицальным элементом массива: ";
    cin >> k;
    for (int i = 0; i < N; i++)
    {
        arr2 << A[i] << " ";
        if (A[i] < 0)
        {
            arr2 << k << " "; // Запись k перед отрицательным элементом массива 
        }

    }
    arr2.close();
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