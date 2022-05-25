#include <iostream>
#include <math.h>

using namespace std;

int main() 
{
	double eps = 0.001;

	double sum = 0;
	double a = 1;

	for (int n = 1; ; n++)
	{
		a *= pow(-1, n - 1)
					   / 
				   pow(n, n);

		if (abs(a) < eps) {
			break;
		}

		sum += a;
	}

	cout << sum << endl;
}

