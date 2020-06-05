#include <iostream>

using namespace std;

void SZ(int* a, int n, int N, int& count , float& sum);
int st2(int n);
int F(int i);
int G(int i);

int main()
{
    setlocale(LC_ALL, "Russian");
    int num;
    cout << "Введите номер задания(1, 2 или 3) или 0 для завершения работы: " << endl;
    cin >> num;
    cout << endl;
    system("cls");
    while (num)
    {
        if (num == 1)
        {
            int n, N, count = 0;
            float sum = 0;
            cout << "Введите n: ";
            cin >> n;
            cout << "Введите размер массива: ";
            cin >> N;
            int* a = new int[N];
            for (int i = 0; i < N; i++)
            {
                cout << "Введите число: ";
                cin >> a[i];
            }
            SZ(a, n, N, count, sum);
            cout << "Среднее арифметическое равно: "<< sum << endl;
        }
        if (num == 2)
        {
            int n, res;
            cout << "Введите степень числа 2: ";
            cin >> n;
            res = st2(n);
            cout << "2 в степени " << n << " равно: " << res << endl;
        }
        if (num == 3)
        {
            cout << "F(n) = 2 * F(n – 1) * G(n – 1),"<<endl<< "G(n) = 4 * F(n–1) + G(n – 1)" << endl << endl;
            for (int i = 1; i <= 10; i++)
                cout << "F(" << i << ")= " << F(i) << "   " << "G(" << i << ")= " << G(i) << endl;
        }
        if (num > 3 || num < 1) cout << "Вы выбрали не существующую задачу. Повторите выбор." << endl;
        cout << endl << "Введите номер задания(1, 2 или 3) или 0 для завершения работы: " << endl;
        cin >> num; cout << endl;
        system("cls");
    }
    return 0;
}

void SZ(int* a, int n,  int N, int& count, float& sum)
{
    if (N-1 == 0)
    {
        if (a[0] > n)
        {
            count++;
            sum += a[0];
        }
        sum = sum / count;
        return;
    }
    else if (N - 1) 
    {
        if (a[N - 1] > n)
        {
            count++;
            sum += a[N - 1];
            SZ(a, n, N - 1, count, sum);
        }
        else
        {
            SZ(a, n, N - 1, count, sum);
        }
    }
}

int st2(int n)
{
    if (n == 0)
        return 1;
    else
        return 2 * st2(n - 1);
}

int F(int i)
{
    if (i == 1)
        return 2;
    return 2 * F(i - 1) * G(i - 1);
}

int G(int i)
{
    if (i == 1)
        return 1;
    return 4 * F(i - 1) + G(i - 1);
}
