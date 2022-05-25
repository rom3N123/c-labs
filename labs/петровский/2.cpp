#include <iostream>
#include <math.h>

using namespace std;

double factorial(double number) {
	return number == 1 ? number : number * factorial(number - 1);
}

int main() 
{
	double eps = 0.001;

	double sum = 0;
	double a = 1;

	for (int n = 1; ; n++)
	{
		a *= pow(factorial(n), 2)
					   / 
				   pow(2, pow(n, 2));

		if (abs(a) < eps) {
			break;
		}

		sum += a;
	}

	cout << sum << endl;
}

