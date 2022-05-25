#include <iostream>
#include <math.h>

using namespace std;

double calcFormula(double a, double b);
float calcFormula(float a, float b);

double calcFormula(double a, double b) {
	return (pow(a + b, 2) - (pow(a, 2) + 2 * a * b)) / pow(b, 2);
}
float calcFormula(float a, float b) {
	return (pow(a + b, 2) - (pow(a, 2) + 2 * a * b)) / pow(b, 2);
}

int main() 
{
	double doubleA = 1000;
	double doubleB = 0.0001;
	double doubleResult = calcFormula(doubleA, doubleB);

	float floatA = 1000;
	float floatB = 0.0001;
	float floatResult = calcFormula(floatA, floatB);

	cout << "Double: " << doubleResult << endl;
	cout << "Float: " <<  floatResult << endl;
}

