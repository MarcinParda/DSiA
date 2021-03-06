// RepeatingNumbers.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//


#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void showVector(vector <int> numbers) {
	for (int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;
}

bool isBelong(int number, vector <int> numbers) {
	for (int i = 0; i < numbers.size(); i++)
	{
		if (number == numbers[i])
			return true;
	}
	return false;
}

void repeatingNumbers(vector <int> numbers) {
	vector<int>empty;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (!isBelong(numbers[i], empty))
			empty.push_back(numbers[i]);
		else
			cout << numbers[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int>array;
	int n = 7;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cout << "Give value of element " << i << ": ";
		cin >> tmp;
		array.push_back(tmp);
	}
	cout << "Powtorzenia: ";
	repeatingNumbers(array);
	system("pause");
}