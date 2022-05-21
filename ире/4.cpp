#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

void logDivider() {
	cout << endl;
	cout << "==================================" << endl;	
}

int *getArray(int length) {
    int *numbers = new int[length];

	for(int i = 0; i < length; i++) {
		int randomNumber = rand() % 10;
		numbers[i] = randomNumber;
	}
 
    return numbers;
}

int** createDeepArray(int rows, int cols) {
	int **arr = new int* [rows];

	for(int i = 0; i < rows; i++) {
		arr[i] = getArray(cols);
	}

	return arr;
}

tuple<int*, int> filterArray(int arr[], int length) {
	int *filtered = new int;
	int filteredLength = 0;

	for(int i = 0; i < length; i++) {
		int el = arr[i];

		if(el % 2 == 0) {
			filtered[filteredLength] = arr[i];
			filteredLength++;
		}
	}


	return { filtered, filteredLength };
}

void logArray(int arr[], int length) {
	for(int i = 0; i < length; i++) {
		cout << arr[i] << "\t";
	}

	logDivider();
}

void logDeepArray(int rows, int cols, int **arr) {
	for(int r = 0; r < rows; r++) 
	{
		int *row = arr[r];

		for(int c = 0; c < cols; c++) 
		{
			int column = row[c];

			cout << column << "\t";
		}

		cout << endl;
	}

	logDivider();
}

int** addRows(int rowsCount, int arrRows, int cols, int **arr) {
	int totalRows = arrRows + rowsCount;
	int **newArr = new int* [totalRows];

	for(int r = 0; r < totalRows; r++) 
	{
		if(r >= arrRows) 
		{
			newArr[r] = getArray(cols);
		} else 
		{
			newArr[r] = arr[r];
		}
	}

	return newArr;
}

int main() {
	int length = 10;
	int *numbers = getArray(length);
	
	logArray(numbers, length);
	tuple<int*, int> result = filterArray(numbers, length);
	delete[] numbers;
	int *resultArr = get<0>(result);
	int resultArrLength = get<1>(result);
	logArray(resultArr, resultArrLength);

	int r = 5, c = 5;
	int **arr = createDeepArray(r, c);
	logDeepArray(r, c, arr);
	int **transformedArr = addRows(3, r, c, arr);
	delete[] arr;
	logDeepArray(r + 3, c, transformedArr);
	delete[] transformedArr;
}