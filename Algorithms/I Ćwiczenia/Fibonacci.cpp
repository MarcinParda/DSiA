// Fibonacci.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

double fibonacci(int n) {
	if (n <= 1)
		return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
	cout << fibonacci(1) << fibonacci(2) << fibonacci(3) << fibonacci(4) << fibonacci(5) << endl;
	system("pause");
}

