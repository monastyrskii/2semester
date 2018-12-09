#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int i, j, n, k, above, below, min, mink, mini;
	double x1, y1, x0, y0, r;
	cout << "Enter the number of points: "; 
	cin >> n;
	double *Mx = new double[n]; double *My = new double[n];
	
	for (i = 0; i < n; i++) // запись точек в массив
	{
		cout << "Enter X and Y for the [" << i << "] point: ";
		cin >> x1 >> y1;
		Mx[i] = x1; My[i] = y1;
	}

	cout << "Enter the center of the circle (X,Y) and the radius: "; // описание окружности
	cin >> x0 >> y0 >> r;
	min = n;

	for (k = 0; k < n - 1; k++) // k - первая точка прямой
		for (i = 1 + k; i < n; i++) // i - вторая точка прямой
		{
			above = 0; // Счётчик точек выше(справа) прямой
			below = 0; // Счётчик точек ниже(слева) прямой
			for (j = 0; j < n; j++) // j - свободная точка
				if (Mx[k] == Mx[i]) // Если прямая || оси У (1)
				{
					if (pow(x0 - Mx[j], 2) + pow(y0 - My[j], 2) <= r * r) // Проверка на вхождение в круг 
					{
						if (Mx[j] > (((Mx[i] - Mx[k])*(My[j] - My[k])) / (My[i] - My[k])) + Mx[k])
							above += 1;
						else
							if (Mx[j] < (((Mx[i] - Mx[k])*(My[j] - My[k])) / (My[i] - My[k])) + Mx[k])
								below += 1;
					}
				}
				else // Все случаи, кроме (1)
					if (pow(x0 - Mx[j], 2) + pow(y0 - My[j], 2) <= r * r) // Проверка на вхождение в круг
					{
						if (My[j] > (((Mx[j] - Mx[k])*(My[i] - My[k])) / (Mx[i] - Mx[k])) + My[k])
							above += 1;
						else
							if (My[j] < (((Mx[j] - Mx[k])*(My[i] - My[k])) / (Mx[i] - Mx[k])) + My[k])
								below += 1;
					}
			if (abs(above - below) < min) // Минимальная разность между выше/ниже
			{
				min = above - below;
				mink = k;
				mini = i;
			}
		}

	cout << "The desired points is [" << mink << "] and [" << mini << "]. " << endl;
	cout << "The difference between the points, lying on opposite sides of the line, passing through them is " << min << " points" << endl;

	system("pause");
	return 0;
}
