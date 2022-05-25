#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double x;
	double eps;
	cout << "Введите x: ";
	cin >> x;
	cout << "Введите точность: ";
	cin >> eps;
	cout << endl;

	double sum = 0;
	double a = 1;
	double input;
	for (int n = 1;; n++)
	{
		sum += a;
		a=-a*x*(2*n+1)/(2*n);

		cout<<sum<<endl;

		if (abs(a) < eps) {
			break;
		}
	}

	cout << "Сумма ряда: " << sum << endl;
	cout << "Контрольная формула " << 1/sqrt((1+x)*(1+x)*(1+x));
	cout << endl;
}