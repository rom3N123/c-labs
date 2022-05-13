#include <iostream>
#include <vector>

using namespace std;

void mutate(vector<int> &arr) {
	arr[0] = 100;

	cout << arr[0] << endl;
}

int main() {
	int a = 5;
	int *pa = &a;

pa++;
cout << pa <<endl;
}