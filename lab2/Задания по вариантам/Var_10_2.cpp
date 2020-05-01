
#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;



int main()
{
	setlocale(LC_ALL, "Russian");

	int x;
	int m = 0; // Строки
	int n = 0; // Столбцы

	// Считывание матриц и веторов из файлов
	ifstream f1("B.txt");
	while (f1 >> x)
	{
		m++;
	}
	f1.close();

	int* B;
	B = new int[m];

	ifstream fb("B.txt");
	for (int i = 0; i < m; i++)
	{
		fb >> B[i];
	}
	fb.close();


	ifstream f2("D.txt");
	while (f2 >> x)
	{
		n++;
	}
	f2.close();

	int* D;
	D = new int[n];

	ifstream fd("D.txt");
	for (int i = 0; i < n; i++)
	{
		fd >> D[i];
	}
	fd.close();

	int** A;
	A = new int* [m];
	for (int i = 0; i < m; i++)
	{
		A[i] = new int[m];
	}

	ifstream fa("A.txt");
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
		{
			fa >> A[i][j];
		}
	fa.close();

	int** C;
	C = new int* [n];
	for (int i = 0; i < n; i++)
	{
		C[i] = new int[m];
	}

	ifstream fc("C.txt");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			fc >> C[i][j];
		}
	}
	fc.close();

	// Вывод матриц и веторов
	cout << "Матрица A:" << endl;// вывод матрицы A
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;


	cout << "Вектор B:" << endl;// вывод вектор строки
	for (int i = 0; i < m; i++)
	{
		cout << B[i] << endl;
	}
	cout << endl;

	cout << "Матрица C:" << endl;// вывод матрицы С
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "Вектор D:" << endl;// вывод вектор столбца
	for (int i = 0; i < n; i++)
	{
		cout << D[i] << " ";
	}
	cout << endl << endl;


	// Решение
	int** BD = new int* [m]; // выделение памяти под матрицу  ( 2 • B(m) • DT(m) )
	for (int i = 0; i < m; i++)
	{
		BD[i] = new int[n];
	}

	for (int i = 0; i < m; i++) // 2 • B(m) • DT(m)
		for (int j = 0; j < n; j++)
		{
			BD[i][j] = 2 * B[i] * D[j];
		}

	int** AC = new int* [m];// выделение памяти под матрицу ( - A(m,n) • CT(m,n) ) 
	for (int i = 0; i < m; i++)
	{
		AC[i] = new int[m];
	}

	for (int i = 0; i < m; i++) // - A(m,n) • CT(m,n)
	{
		for (int j = 0; j < n; j++)
		{
			AC[i][j] = 0;
			for (int k = 0; k < n; k++)
			{
				AC[i][j] += -1 * A[i][k] * C[j][k];
			}
		}
	}
	cout << endl;

	// - A(m,n) • CT(m,n) - 2 • B(m) • DT(m)
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
		{
			A[i][j] = AC[i][j] - BD[i][j]; // к каждому элементу матрицы A прибавляем соответствующий элемент матрицы BDC
		}

	cout << "Результат: " << endl; // вывод результати 

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
	// освобождение выделенной памяти
	for (int i = 0; i < m; i++)
	{
		delete[] AC[i];
	}
	delete[] AC;

	for (int i = 0; i < m; i++)
	{
		delete[] BD[i];
	}
	delete[] BD;

	delete[] D;

	for (int i = 0; i < n; i++)
	{
		delete[] C[i];
	}
	delete[] C;

	delete[] B;

	for (int i = 0; i < m; i++)
	{
		delete[] A[i];
}
	delete[] A;

	return 0;
}