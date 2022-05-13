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

int** createDeepArray(int rows, int cols) {
	int **arr = new int* [rows];

	for(int i = 0; i < rows; i++) {
		arr[i] = getArray(cols);
	}

	return arr;
}

int** filterDeepArray(int **arr, int rows, int cols) {
	int **newArr = new int*;
	int resultCols = 0;

	for(int row = 0; row < rows; row++) {
		newArr[row] = new int;
		int rowLength = 0;
		for(int col = 0; col < cols; col++) {
			if(col % 2 != 0) {
				newArr[row][rowLength] = arr[row][col];
				rowLength++;
			}
		}

		resultCols = rowLength;
	}

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			cout << newArr[i][j] << "\t";
		}
		cout << endl;
	}

	return newArr;
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
	// int length = 10;
	// int *numbers = getArray(length);
	
	// tuple<int*, int> result = filterArray(numbers, length);

	// delete[] numbers;

	// int *resultArr = get<0>(result);
	// int resultArrLength = get<1>(result);

	// logArray(resultArr, resultArrLength);
	int **arr = createDeepArray(5, 5);
	int **filtered = filterDeepArray(arr, 5, 5);

	// for(int i = 0; i < 5; i++) {
	// 	cout << filtered[0][i] << endl;
	// }

	// delete[] resultArr;
}