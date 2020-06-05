
#include <iostream> 

using namespace std;

void LowerString(char* s);

int main()
{
    setlocale(LC_ALL, "ru");
    char* s = new char[1];
    cout << "Введите предложение на английском языке: " << endl;
    cin.getline(s, 80);
    cout << "Измененное предложение: " << endl;
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

