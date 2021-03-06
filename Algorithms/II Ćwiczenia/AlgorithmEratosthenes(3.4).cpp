// AlgorithmEratosthenes.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <math.h>

using namespace std;

void showVector(vector<int>array) {
	for (int i = 0; i < array.size(); i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

vector<int>cleanZeros(vector<int>array) {
	vector<int>withoutZeros;
	for (int i = 0; i < array.size(); i++)
	{
		if (array[i] != 0)
			withoutZeros.push_back(array[i]);
	}
	return withoutZeros;
}

vector<int>eratosthenes(vector<int>array) {
	for (int i = 0; i < sqrt(array.size()); i++)
	{
		for (int j = 1 + i; j < array.size(); j++)
		{
			if (array[i] == 0)
				break;
			if (array[j] % array[i] == 0)
					array[j] = 0;
		}
	}
	return cleanZeros(array);
}

int main()
{
	int n = 100;
	vector<int>array;
	for (int i = 2; i <= n; i++)
	{
		array.push_back(i);
	}
	showVector(eratosthenes(array));
	system("pause");
}

