#include <iostream>

using namespace std;

int F(int i);
int G(int i);

int main()
{
    for (int i = 1; i <= 10; i++)
        cout << "F(" << i << ")= " << F(i) << "   " << "G(" << i << ")= " << G(i) << endl;
    return 0;
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
