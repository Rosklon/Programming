#include <iostream>

int st2(int n);

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int n, res;
    cout << "Введите степень числа 2: ";
    cin >> n;
    res=st2(n);
    cout << "2 в степени " << n << " равно: "<< res<< endl;
}

int st2(int n)
{
    if (n == 0)
        return 1;
    else 
        return 2 * st2(n-1);
}
