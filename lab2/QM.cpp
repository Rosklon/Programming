#include "iostream"
#include "iomanip"
#include "ctime"

using namespace std;

void matr_out(int** a, int n, int m);//Вывод матрицы
void green_zone(int** a, int n, int m, int z, int& ind, int& jnd);//Нахождение максимального отрицательного элемента в «зеленой» области
void red_zone(int** a, int n, int m, int x, int& ind, int& jnd);//Нахождение минимального положительного элемента в «красной» области

int main()
{
	setlocale(LC_ALL, "ru");
	int n, z, x, gzi, gzj, rzi, rzj;
	cout << "Введите размер квадратной матрицы: " << endl;
	cin >> n; 
	cout << endl;
	cout << "Необходимо ввести диапазон элементов матрицы [a,b]." << endl;
	cout << "Введите a: ";
	cin >> z;
	cout << "Введите b: ";
	cin >> x;
	while (z >x || z == x)
	{
		if (z > x || z == x) cout << "Повторите ввод a и b. Необходимо чтобы выполнялись условия: a меньше b и a не равно d." << endl;
		cout << "Введите a: ";
		cin >>z;
		cout << "Введите b: ";
		cin >> x;
	}
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = z + rand() % (x - z + 1);
		}
	}
	
	matr_out(a, n, n);
	green_zone(a, n, n, z, gzi, gzj);
	red_zone(a, n, n, x, rzi, rzj);
	a[gzi][gzj] = a[gzi][gzj] + a[rzi][rzj];//Сумма максимального элемента и минимального элемента
	a[rzi][rzj] = a[gzi][gzj] - a[rzi][rzj];//Замена положительного элемента на отрицательный
	a[gzi][gzj] = a[gzi][gzj] - a[rzi][rzj];//Замена отрицательного элемента на положительный
	matr_out(a, n, n);
	return 0;
}


void matr_out(int** a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (int j = 0; j < m; j++)
		{
			cout << setw(5) << a[i][j];
		}
	}
	cout << endl;
}

void green_zone(int** a, int n, int m, int z, int& ind, int& jnd)
{
	int max = z - 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i < n - j - 1)
			{
				if (a[i][j] < 0 && a[i][j] > max)
				{
					max = a[i][j];
					ind = i;
					jnd = j;
				}
			}
		}
	}
	if (max == z - 1)
	{
		cout << endl << "Нет максимальных отрицательных чисел в зеленой зоне" << endl;
	}
	else cout << endl << "Максимальный отрицательный элемент в зеленой зоне: " << max << endl;
}

void red_zone(int** a, int n, int m, int x, int& ind, int& jnd)
{
	int min = x + 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i < j && i > n - j - 1)
			{
				if (a[i][j] > 0 && a[i][j] < min)
				{
					min = a[i][j];
					ind = i;
					jnd = j;
				}
			}
		}
	}
	if (min == x + 1)
	{
		cout << endl << "Нет минимальных положительных чисел чисел в красной зоне" << endl;
	}
	else cout << endl << "Минимальный положительный элемент в красной зоне: " << min << endl;
}
