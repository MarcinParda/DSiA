// Spiral.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

char random(int i)
{
	if (i % 2 == 0)
		return 'X';
	if (i % 2 == 1)
		return 'D';
}

void showVector(vector<char>numbers) {
	for (int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;
}

void showMatrix(vector<vector<char>>matrix) {
	for (int i = 0; i < matrix.size(); i++)
	{
		showVector(matrix[i]);
	}
	cout << endl;
}

vector<vector<char>>drawSpiral(vector<vector<char>>spiral, int length, int space, int iteration = 0) {
	if(length <= space * 2)
		return spiral;
	for (int i = 0; i < length; i++){
		spiral[iteration][iteration + i] = random(i);
	}
	for (int i = 0; i < length + 1 - space; i++)
	{
		spiral[iteration + i][iteration] = random(i);
	}
	for (int i = 0; i < length - space; i++){
		spiral[iteration + length - space][iteration + i] = random(i);
	}
	for (int i = 0; i < length + 1 - space * 2; i++){
		spiral[iteration + length - space - i][iteration + length - 1 - space] = random(i);
	}
	iteration += space;
	showMatrix(spiral);
	return drawSpiral(spiral, length - space * 2, space, iteration);
}

int main()
{
	int n = 31;
	vector<vector<char>>spiral;
	vector<char>empty;

	for (int i = 0; i < n; i++)
	{
		spiral.push_back(empty);
		for (int j = 0; j < n; j++)
		{
			spiral[i].push_back(' ');
		}
	}
	
	drawSpiral(spiral, n, 2);

    system("pause");
}

