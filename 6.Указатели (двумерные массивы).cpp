#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int i, g, j, n, m, k = 0;
	cout << "Enter quantity of strings = "; cin >> n;
	cout << "Enter quantity of columns = "; cin >> m;
	int **A = new int*[n];
	for (k = 0; k < n; k++)
		A[k] = new int[m];

	/*for (j = 0; j < m; j++) // ввод матрицы вручную
		for (i = 0; i < n; i++) {
			cout << "A[" << i << "," << j << "]= ";
			cin >> A[i][j];
		}*/

	cout << endl << "Initial matrix: " << endl;
	for (i = 0; i < n; i++) //вывод начальной матрицы
	{
		for (j = 0; j < m; j++)
		{
			A[i][j] = rand() % 18 - 9; // обьявление матрицы рандомом
			cout << A[i][j] << "    ";
		}
		cout << endl;
	}

	int *ch = new int[j]; // поиск характеристик столбцов
	for (j = 0; j < m; j++)
	{
		ch[j] = 0;
		for (i = 0; i < n; i++) {
			if (A[i][j] < 0 && A[i][j] % 2 != 0)
				ch[j] += (-A[i][j]);
		}
	}

	while (k <= m + 1) //перестановка матрицы
	{
		k += 1;
		for (j = 0; j < m - 1; j++)
			if (ch[j] > ch[j + 1])
			{
				g = ch[j + 1]; // смена характеристик
				ch[j + 1] = ch[j];
				ch[j] = g;
				for (i = 0; i < n; i++) {
					g = A[i][j + 1]; //смена столбцов
					A[i][j + 1] = A[i][j];
					A[i][j] = g;
				}
			}
	}
	cout << endl << "Changet matrix" << endl;
	for (i = 0; i < n; i++) //вывод измененной матрицы
	{
		for (j = 0; j < m; j++)
			cout << A[i][j] << "   ";
		cout << endl;
	}
	for (i = 0; i < n; i++) // поиск столбцов с отрицательными эл.
	{
		ch[j] = 0;
		for (j = 0; j < m; j++)
			if (A[i][j] < 0)
				ch[j] = 1;
	}
	for (j = 0; j < m; j++) //поиск и вывод суммы
		if (ch[j] == 1)
		{
			ch[j] = 0;
			for (i = 0; i < n; i++)
				ch[j] += A[i][j];
			cout << endl << "Sum of [" << j << "] column = " << ch[j];
		};

	system("pause");
	return 0;
}