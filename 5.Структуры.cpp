#include "pch.h"
#include<iostream>
#include <iosfwd> 
using namespace std;

struct train
{
	char destination[256];
	char number[64];
	int hours;
	int minutes;
};

void GetTrain(train Tr[6], int n) // Ввод данных о поездах
{
	for (int i = 1; i <= n; i++)  
	{
		cout << "Enter the destination of [" << i << "] train: ";
		cin >> Tr[i].destination;
		cout << "Enter the train numder of [" << i << "] train: ";
		cin >> Tr[i].number;
		cout << "Enter the hour of arrival of [" << i << "] train: ";
		cin >> Tr[i].hours;
		cout << "Enter the minute of arrival of [" << i << "] train: ";
		cin >> Tr[i].minutes;
		cout << endl;
	}
}

void ShowTrain(train Tr[6], int n)  // Вывод данных о поездах
{
	for (int i = 1; i <= n; i++)  
	{
		cout << "The destination of [" << i << "] train: " << Tr[i].destination << endl;
		cout << "The train numder of [" << i << "] train: " << Tr[i].number << endl;
		if (Tr[i].minutes / 10 != 0)
			cout << "The of arrival of [" << i << "] train: " << Tr[i].hours << ":" << Tr[i].minutes << endl;
		else
			cout << "The of arrival of [" << i << "] train: " << Tr[i].hours << ":0" << Tr[i].minutes << endl;
		cout << endl;
	}
}

void Destination(train Tr[6], int n) // Поиск поезда по пункту назначения
{
	char dest1[256]; int c = 1;
	cout << "Enter the destination: " << endl;
	cin >> dest1;

	for (int i = 1; i <= n; i++)
		if (strcmp(Tr[i].destination, dest1) == 0)
		{
			cout << "The destination of [" << i << "] train: " << Tr[i].destination << endl;
			cout << "The train numder of [" << i << "] train: " << Tr[i].number << endl;
			if (Tr[i].minutes / 10 != 0)
				cout << "The of arrival of [" << i << "] train: " << Tr[i].hours << ":" << Tr[i].minutes << endl;
			else
				cout << "The of arrival of [" << i << "] train: " << Tr[i].hours << ":0" << Tr[i].minutes << endl;
			cout << endl;
			c = 32;
		}
	if (c != 32)
		cout << "No matching trains found" << endl;

}

int main()
{
	const int n = 6;
	int i, j; train g;
	train Tr[6];

	GetTrain(Tr, n);

	for (j = 1; j < n; j++)	// Сортировка массива по времени отправления
		for (i = 1; i < n; i++)
		{
			if (Tr[i].hours > Tr[i + 1].hours)
			{
				g = Tr[i + 1];
				Tr[i + 1] = Tr[i];
				Tr[i] = g;
			}
			if (Tr[i].hours == Tr[i + 1].hours && Tr[i].minutes > Tr[i + 1].minutes)
			{
				g = Tr[i + 1];
				Tr[i + 1] = Tr[i];
				Tr[i] = g;
			}
		}

	ShowTrain(Tr, n);

	Destination(Tr, n);

	system("pause");
	return 0;
}
