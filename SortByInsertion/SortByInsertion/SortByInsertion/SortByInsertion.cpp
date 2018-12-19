// SortByInsertion.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

int n;

void InsertSort(int tab[]) {
	for (int i = 1; i < n; i++) {
		int j = i;
		int temp = tab[j];
		while ((j>0) && (tab[j-1] > temp))
		{
			tab[j] = tab[j - 1];
			j--;
		}
		tab[j] = temp;
	}
}

int sum(int tab[]) {
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += tab[i];
	}
	return sum;
}

int main()
{
	srand(time(NULL));

	cout << "Podaj rozmiar tablicy: ";
	cin >> n;
	cout << endl;

	int *tab = new int[n];

	if (n < 1) {
		cout << "Zle dane wejsciowe!";
		return 0;
	}

	string in, out;
	cout << "Podaj nazwe pliku wejscia: ";
	cin >> in;
	cout << endl;

	cout << "Podaj nazwe pliku wyjscia: ";
	cin >> out;
	cout << endl;

	ifstream file;
	file.open(in);


	if (!file.good())
		cout << "Nie ma takiego pliku" << endl;
	else
	{
		int sumOfIntsInFile = rand() % 100;

		for (int i = 0; i < sumOfIntsInFile; i++) //zapisywanie losowych danych do pliku
		{
			int a = rand() % 100;
			file << a;
		}

		for (int i = 0; i < n; i++)
		{
			int a;
			file >> a;
			tab[i] = a;
		}
	}
	file.close();

	cout << "Suma liczb przed posortowaniem: " << sum(tab) << endl;

	cout << "Nieposortowana: " << endl;
	for (int i = 0; i < n; i++)
		cout << tab[i] << " ";
	cout << endl << endl;

	int timeA = clock();
	InsertSort(tab);
	int timeB = clock();

	cout << "Suma liczb po posortowaniu: " << sum(tab) << endl;

	cout << "Posortowana: " << endl;
	for (int i = 0; i < n; i++)
		cout << tab[i] << " ";
	cout << endl << endl;

	cout << "Wykonanie zajelo " << timeB - timeA << " milisekund" << endl;

	ofstream fileOut;
	fileOut.open(out, ios::out | ios::trunc);

	if (!fileOut.good())
		cout << "Nie ma takiego pliku wyjsciowego" << endl;
	else {
		fileOut.clear();
		for (int i = 0; i < n; i++)
		{
			fileOut << tab[i] << " ";
		}
	}
	fileOut.close();

	delete tab;


	system("pause");
	return 0;
}