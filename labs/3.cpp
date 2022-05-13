#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void outputVectorElements(vector<int> arr) {
	for(int i = 0; i < arr.size(); i++) {
		cout << "Element: " << arr[i] << "\t" << endl;
	}
}

vector<int> getVectorWithRandomNumbers(int length)
{
    vector<int> numbers(length);

	for(int i = 0; i < length; i++) {
		int randomNumber = rand() % 100;
		numbers[i] = randomNumber;
	}
 
    return numbers;
}

vector<int> filterVector(vector<int> arr) {
	vector<int> filtered;


	copy_if(arr.begin(), arr.end(), back_inserter(filtered), [](int number) -> bool {

		return number % 4 == 0;
	});

	return filtered;
}

vector<int> addZeroToVector(vector<int> arr) {
	vector<int> r;

	for(int i = 0; i < arr.size(); i++) {
		r.push_back(arr[i]);

		if(i == 0 || i % 2 == 1) {
			r.push_back(0);
		}
	}

	return r;
}

void logDivider() {
	cout << "================" << endl;
}


int main() {
	const int LENGTH = 10;

	vector<int> numbers = getVectorWithRandomNumbers(LENGTH);
	outputVectorElements(numbers);
	logDivider();

	vector<int> filteredNumbers = filterVector(numbers);
	outputVectorElements(filteredNumbers);
	logDivider();

	vector<int> numbersWithZeros = addZeroToVector(filteredNumbers);
	outputVectorElements(numbersWithZeros);
	logDivider();
}