#include <iostream>
#include <algorithm>

using namespace std;

int* getArrayWithRandomNumbers(int length)
{
    int* arr = new int[length];

	for(int i = 0; i < length; i++) {
		arr[i] = rand() % 100;
	}
 
    return arr;
}

int* filterArray(int* arr) {
	int arrayLength = sizeof(arr) / sizeof(*arr);
	int filteredArray[arrayLength] = 
}

int main() {
	const int LENGTH = 10;

	int* arr = getArrayWithRandomNumbers(LENGTH);

	for(int i = 0; i < LENGTH; i++) {
		cout << arr[i];
	}
}