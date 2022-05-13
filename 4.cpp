#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

int *getArray(int length) {
    int *numbers = new int[length];

	for(int i = 0; i < length; i++) {
		int randomNumber = rand() % 10;
		numbers[i] = randomNumber;
	}
 
    return numbers;
}


tuple<int*, int> filterArray(int arr[], int length) {
	int *filtered = new int;
	int filteredLength = 0;

	for(int i = 0; i < length; i++) {
		if(i % 2 != 0) {
			filtered[filteredLength] = arr[i];
			filteredLength++;
		}
	}


	return { filtered, filteredLength };
}

void logArray(int arr[], int length) {
	for(int i = 0; i < length; i++) {
		cout << "Element: " << arr[i] << "\t" << endl;
	}
}

int main() {
	int length = 10;
	int *numbers = getArray(length);
	
	auto result = filterArray(numbers, length);

	logArray(get<0>(result), get<1>(result));
	delete [] numbers;
}