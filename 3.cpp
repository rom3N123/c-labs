#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void outputVectorElements(vector<int> arr) {
	for(int i = 0; i < arr.size(); i++) {
		cout << arr[i];
	}
}

vector<int> getArrayWithRandomNumbers(int length)
{
    vector<int> numbers(length);

	for(int i = 0; i < length; i++) {
		int randomNumber = rand() % 100;
		numbers[i] = randomNumber;
	}
 
    return numbers;
}

vector<int> filterArray(vector<int> arr) {
	vector<int> filtered;


	copy_if(arr.begin(), arr.end(), back_inserter(filtered), [](int number) -> bool {
		return number % 4 == 0;
	});

	return filtered;
}

vector<int> mapVectorAndAddZeroAfterNumber(vector<int> arr) {}

int main() {
	const int LENGTH = 100;

	vector<int> numbers = getArrayWithRandomNumbers(LENGTH);

	// outputVectorElements(numbers);

	vector<int> filteredNumbers = filterArray(numbers);

	outputVectorElements(filteredNumbers);

	vector<int> transformed;


	transform(filteredNumbers.begin(), filteredNumbers.end(), back_inserter(transformed), [](int number) {
		return number + 1;
	});
}