#include "pch.h"
#include <iostream>
using namespace std;


int main()
{
	int i, j, n;
	cout << "n = "; cin >> n;
	float *mas = new float[n];

	for (i = 0; i < n; i++)
		{
		cout << "mas[" << i << "] =";
		cin >> mas[i];
		} //прием массива

	int index, min= mas[0];
	for (i = 0; i < n; i++)
	{
		if (min > mas[i])
		{
			min = mas[i];
			index = i;
		} 
	}
	cout << "MinNumber: " << index << endl; // Подсчет и вывод номера минимального эл. (index)

	int index2; float sum = 0;
	i = 0; index = i;
	while (mas[i] >= 0) 
		{
		index = i;
		i++;
		} //Подсчет номера первого отрицательного эл. (i = index)
		cout << "First NegNumber: " << index +1 << endl;
	index2 = index + 2;
	while (mas[index +2] >= 0) 
		{
		index2 = index + 2;
		sum += mas[index +2];
		index++;
		} //Подсчет номера второго отрицательного эл. (index2) и суммы
		cout << "Second NegNumber: " << index2 +1 << endl;
	cout << "The sum: " << sum << endl;

	float value;
	for (j = 0; j <= n - 2; j += 1)
		for (i = 0; i <= n - 1; i += 1)
			if (fabs(mas[i + 1]) <= 1)
			{
				value = mas[i + 1];
				mas[i + 1] = mas[i];
				mas[i] = value;
			} //сортировка массива

	for (i = 0; i < n; i++)
	{
		cout << "mas[" << i << "] =" << mas[i] << endl;
	}  //вывод массива

	system("pause");
	return 0;
}
