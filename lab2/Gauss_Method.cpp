#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

void testmatrix(double** A); // создание матрицыц 3x3 с ответом (3, -2, 1)
void randMatrix(double** A, int n); //создающие случайной матрицы
void matrix0(double** A); //создание матрицы размером 3x3 с нулевой строкой
void GilbertMatrix(double** A, int n); // создание матрицы Гильберта
void prMatrix(double** A, int n); // вывод матрицы
void GaussMethod(double** A, double* x, int n); // метод Гаусса
double delta(double** A, double* x, int n); // нахождение погрешности

int main()
{
	setlocale(LC_ALL, "Russian");

	int n; // переменная для размера матрицы

	cout << "Выберите тип матрицы (или введите 0 для выхода): " << endl
		<< "1 - Матрица размером 3х3, заданная явно с ответом (-1, 3, 2)" << endl
		<< "2 - Матрица, заданная случайным образом" << endl
		<< "3 - Нулевая матрица" << endl
		<< "4 - Матрица Гильберта" << endl;

	int num;
	cin >> num;
	while (num)
	{
		
		if (num == 1)
		{
			// Выделяем память под расширенную матрицу
			double** A = new double* [3];
			for (int i = 0; i < 3; i++)
				A[i] = new double[4];
			// Выделяем память под вектор переменных
			double* x = new double[3];

		testmatrix(A);
		prMatrix(A, 3);
		GaussMethod(A, x, 3); 
		// вывод решения
		cout << "Результат решения методом Гаусса: (";
		for (int i = 0; i < 3; i++)
			cout << x[i] << "; ";
		cout << ")" << endl;
		cout << "Погрешность = " << delta(A, x, 3) << endl;

		// Освобождаем память
		delete[] x;
		for (int i = 0; i < 3; i++)
			delete[] A[i];
		delete[] A;
		}

		if (num == 2)
		{
			cout << "Введите размер матрицы: ";
			cin >> n;
			
			double** A = new double* [n];
			for (int i = 0; i < n; i++)
				A[i] = new double[n + 1];
			double* x = new double[n];

		randMatrix(A, n);
		GaussMethod(A, x, n);
		
		cout << "Результат решения методом Гаусса: (";
		for (int i = 0; i < n; i++)
			cout << x[i] << "; ";
		cout << ")" << endl;
		cout << "Погрешность = " << delta(A, x, n) << endl;

		
		delete[] x;
		for (int i = 0; i < n; i++)
			delete[] A[i];
		delete[] A;
		}

		if (num == 3) 
		{
			double** A = new double* [3];
			for (int i = 0; i < 3; i++)
				A[i] = new double[4];
			double* x = new double[3];

		matrix0(A);  
		prMatrix(A, 3);
		GaussMethod(A, x, 3);
		
		delete[] x;
		for (int i = 0; i < n; i++)
			delete[] A[i];
		delete[] A;
		}

		if (num == 4)
		{
			cout << "Введите размер матрицы: ";
			cin >> n;
		double** A = new double* [n];
		for (int i = 0; i < n; i++)
			A[i] = new double[n + 1];
		double* x = new double[n];

		GilbertMatrix(A, n);
		GaussMethod(A, x, n); 

		cout << "Результат решения методом Гаусса: (";
		for (int i = 0; i < n; i++)
			cout << x[i] << "; ";
		cout << ")" << endl;
		cout << "Погрешность = " << delta(A, x, n) << endl;

		delete[] x;
		for (int i = 0; i < n; i++)
			delete[] A[i];
		delete[] A;
		}
		if (num > 4 || num < 0) cout << "Вы выбрали не существующую номер. Повторите выбор." << endl;
		cout << endl << "Выберите тип матрицы (или введите 0 для выхода): " << endl
			<< "1 - Матрица размером 3х3, заданная явно с ответом (-1, 3, 2)" << endl
			<< "2 - Матрица, заданная случайным образом" << endl
			<< "3 - Нулевая матрица" << endl
			<< "4 - Матрица Гильберта" << endl;
		cin >> num;
	}
	return 0;
}

void testmatrix(double** A)
{
		A[0][0] = 3;
		A[0][1] = 2;
		A[0][2] = 1;
		A[0][3] = 5;
		A[1][0] = 1;
		A[1][1] = 1;
		A[1][2] = -1;
		A[1][3] = 0;
		A[2][0] = 4;
		A[2][1] = -1;
		A[2][2] = 5;
		A[2][3] = 3;
}

void randMatrix(double** A, int n)
{
	srand(time(0)); 
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n + 1; j++) 
			A[i][j] = rand() % 101 - 50; 
}

void matrix0(double** A)
{
		A[0][0] = 3;
		A[0][1] = 2;
		A[0][2] = 1;
		A[0][3] = 5;
		A[1][0] = 0;
		A[1][1] = 0;
		A[1][2] = 0;
		A[1][3] = 0;
		A[2][0] = 4;
		A[2][1] = -1;
		A[2][2] = 5;
		A[2][3] = 3;
}

void GilbertMatrix(double** A, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n + 1; j++) 
			A[i][j] = 1.0 / (i + j + 1); 
}

void prMatrix(double** A, int n)
{
	for (int i = 0; i < n; i++)
	{ 
		for (int j = 0; j < n; j++) 
			cout << A[i][j] << " "; 
		cout << "| " << A[i][n] << endl;
	}
}

void GaussMethod(double** A, double* x, int n)
{
	// прямой ход 
	for (int i = 0; i < n; i++) 
	{
		double m = A[i][i]; 
		int jm = i; 
		for (int j = i; j < n; j++)
			if (A[i][j] > m)
			{ 
				m = A[i][j]; 
				jm = j; 
			}

		for (int k = 0; k < n; k++) {

			double t = A[k][i];
			A[k][i] = A[k][jm];
			A[k][jm] = t;
		}

		if (m == 0) 
		{ 
			cout << "Матрица не определена, единственного решения нет" << endl;
			return; 
		}

		for (int j = i; j < n + 1; j++)
			A[i][j] = A[i][j] / m;
		for (int k = i + 1; k < n; k++) 
		{
			double t = A[k][i];
			for (int j = i; j < n + 1; j++) 
			{
				A[k][j] = A[k][j] - A[i][j] * t;
			}
		}
	}
	// обратный ход
	for (int i = n - 1; i >= 0; i--)
	{
		double t = A[i][n]; 
		for (int j = i + 1; j < n; j++)

			t = t - A[i][j] * x[j]; 
		x[i] = t;
	}
}

double delta(double** A, double* x, int n) 
{
	
	double* B1 = new double[n];
	double d = 0.0;  // погрешность больше
	// вычисляем вектор правой части: умножаем матрицу A на вектор х
	for (int i = 0; i < n; i++) {
		B1[i] = 0.0;
		for (int j = 0; j < n; j++)
			B1[i] += A[i][j] * x[j];
	}

	for (int i = 0; i < n; i++) 
		if (fabs(B1[i] - A[i][n]) > d) 
			d = fabs(B1[i] - A[i][n]); 

	delete[] B1;
	return d;
}