#include <iostream>
#include <math.h>
using namespace std;

// double calcFormula(double a, double b);
// float calcFormula(float a, float b);

// double calcFormula(double a, double b) {
// 	return (pow(a - b, 3) - (pow(a, 3) - 3 * pow(a, 2) * b)) / pow(b, 3) - (3 * a * pow(b, 2));
// }
// float calcFormula(float a, float b) {
// 	return (pow(a - b, 3) - (pow(a, 3) - 3 * pow(a, 2) * b)) / pow(b, 3) - (3 * a * pow(b, 2));
// }

// double calculate(double a, double b);
// float calculate(float a,)

double calculate(double a, double b) {
	double result = 0;
	result = (pow(a - b, 3) - (pow(a, 3) - 3 * pow(a, 2) * b)) / pow(b, 3) - (3 * a * pow(b, 2));
	return result;
}

int main() 
{
	double a = 1000;
	double b = 0.0001;
	double result = calculate(a, b);
	cout << result << endl;
}

