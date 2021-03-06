// SumOfArray.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#define SIZE 5

using namespace std;

void showArray(int array[]) {
	for (int i = 0; i < SIZE; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

int sumOfPositive(int array[]) {
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (array[i] > 0)
			sum+=array[i];
	}
	return sum;
}

int sumOfNegative(int array[]) {
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (array[i] < 0)
			sum += array[i];
	}
	return sum;
}

int main()
{
	int array[SIZE];
	cout << endl << "Give value of elements in array: ";
	for (int i = 0; i < SIZE; i++)
	{
		cout << i + 1 << " element: ";
		int tmp;
		cin >> tmp;
		array[i] = tmp;
	}
	showArray(array);
	cout << "Sum of positive: " << sumOfPositive(array) << endl;
	cout << "Sum of negative: " << sumOfNegative(array) << endl;

	system("pause");
	return 0;
}