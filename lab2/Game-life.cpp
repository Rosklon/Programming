#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <random>
#include <Windows.h>

using namespace std;

void field(int** a, int n, int m);
void CyLtField(int** a, int** a1, int n, int m);
void NewGen(int** a, int** a1, int n, int m);
int Comp(int** a, int** a1, int n, int m);
int lifepnts(int** a, int n, int m);
void NBPoints(int nb[][2], int x, int y);
int lifeNBpoints(int** a, int n, int m, int x, int y);


int main()
{
	setlocale(LC_ALL, "ru");
	int n, m;
	cout << "Введите количество строк: ";
	cin >> n;
	cout << "Введите количество столбцов: ";
	cin >> m;
	int** a;
	a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[m];
	}

	random_device rand;
	mt19937 gener(rand());
	uniform_int_distribution<> distr(1, 10000);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			int num = distr(gener);
			if (num % 2 == 0)
				a[i][j] = 1;
			else
				a[i][j] = 0;
		}

	int** PrevField;
	PrevField = new int* [n];
	for (int i = 0; i < n; i++)
		PrevField[i] = new int[m];
	int livpnts = -1;
	bool i = false;
	do
	{
		field(a, n, m);
		CyLtField(a, PrevField, n, m);
		NewGen(a, PrevField, n, m);
		i = Comp(a, PrevField, n, m) == 0;
		livpnts = lifepnts(a, n, m);
		if (i)
			cout << "Win\n";
		if (livpnts == 0)
			cout << "GameOver\n";
		Sleep(2000);
	} while (livpnts != 0 || i);
	return 0;
}

void field(int** a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 1)
				cout << '*';
			else
				cout << ' ';
			cout << ' ';
		}
		cout << endl;
	}
	cout << "__________________" << endl;
}

void CyLtField(int** a, int** a1, int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a1[i][j] = a[i][j];
}

void NewGen(int** a, int** a1, int n, int m)
{
	int livNB, p;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			p = a1[i][j];
			livNB = lifeNBpoints(a1, n, m, i, j);
			if (p == 0)
			{
				if (livNB == 3)
					a[i][j] = 1;
			}
			else
				if (livNB < 2 || livNB > 3)
					a[i][j] = 0;
		}
}

int Comp(int** a, int** a1, int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a != a1)
				return -1;
	return 0;
}

int lifepnts(int** a, int n, int m)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == 1)
				count++;
	return count;
}

void NBPoints(int nb[][2], int x, int y)
{
	int k = 0;
	for (int i = x - 1; i <= x + 1; i++)
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (i == x && j == y)
				continue;
			nb[k][0] = i;
			nb[k][1] = j;
			k++;
		}

}

int lifeNBpoints(int** a, int n, int m, int x, int y)
{
	int count = 0;
	int nb[8][2];
	int x_, y_;
	NBPoints(nb, x, y);
	for (int i = 0; i < 8; i++)
	{
		x_ = nb[i][0];
		y_ = nb[i][1];
		if (x_ < 0 || y_ < 0)
			continue;
		if (x_ >= n || y_ >= m)
			continue;
		if (a[x_][y_] == 1)
			count++;
	}
	return count;
}
