#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double eps=0.001;


	double sum = 0;
	double a = 1;
	double input;

	for (int n = 1;; n++)
	{
		a*=(double)4*n/((4*n)*(4*n+1)*(4*n+2)*(4*n+3));

		if (abs(a) < eps) {
			break;
		}
		sum += a;
	}

	cout << "Sum series: " << sum << endl;
	
	cout << endl;
	
	return 0;
}