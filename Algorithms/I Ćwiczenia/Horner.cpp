// Horner.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void showHornerResult(int n, vector<int>a, int divider) {
	cout << "(";
	for (int i = n - 1; i >= 0; i--)
	{
		cout << a[n - i - 1] << "*x^" << i - 1;

		if (i != 1 && i != 0)
			cout << " + ";
		else if(i == 1)
			cout << ") * (x + " << divider << ") + ";
	}
	cout << endl;
}

vector<int>horner(int n, vector<int>a, int divider) {
	vector<int>divisionResult;
	divisionResult.push_back(a[0]);

	for (int i = 1; i < n; i++)
	{
		divisionResult.push_back(divisionResult[i - 1] * divider * (-1) + a[i]);
	}
	showHornerResult(n, divisionResult, divider);
	return divisionResult;
}



int main()
{
	vector<int>a;
	int n = 4;

	for (int i = 0; i < n; i++)
	{
		cout << "Give a" << i + 1 << " factor: ";
		int factor;
		cin >> factor;
		a.push_back(factor);
	}

	int divider;
	cout << endl << "Divide by: x + ";
	cin >> divider;

	horner(n, a, divider);

	system("pause");
}

