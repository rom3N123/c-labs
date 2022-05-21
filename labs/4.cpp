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

// tuple<int**, int> filterDeepArray(int **arr, int rows, int cols) {
// 	int **newArr = new int*;
// 	int resultCols = 0;

// 	for(int row = 0; row < rows; row++) {
// 		newArr[row] = new int;
// 		int rowLength = 0;
// 		for(int col = 0; col < cols; col++) {
// 			if(col % 2 != 0) {
// 				newArr[row][rowLength] = arr[row][col];
// 				rowLength++;
// 			}
// 		}

// 		resultCols = rowLength + 1;
// 	}

// 	for(int i = 0; i < rows; i++) {
// 		for(int j = 0; j < cols; j++) {
// 			cout << newArr[i][j] << "\t";
// 		}
// 		cout << endl;
// 	}

// 	return { newArr , resultCols};
// }

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

int** addColumnAfterMax(int rows, int cols, int **arr) {
	int **newArr = new int* [rows];

	for(int r = 0; r < rows; r++) 
	{
		int *row = arr[r];

		int maxCol = 0;
		int maxColIndex;

		for(int c = 0; c < cols; c++)
		{
			int column = row[c];

			if(maxCol < column) 
			{
				maxCol = column;
				maxColIndex = c;
			}
		}

		bool hasInserted = false;
		int *newRow = new int;

		for(int c = 0; c < cols; c++) 
		{
			int column = row[c];

			bool isMaxCol = c == maxColIndex;
			int insertIndex = hasInserted ? c + 1 : c;

			newRow[insertIndex] = column;

			if(isMaxCol) 
			{
				hasInserted = true;
				newRow[c + 1] = 1000;
			}
		}

		newArr[r] = newRow;
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
	int **transformedArr = addColumnAfterMax(r, c, arr);
	delete[] arr;
	logDeepArray(r, c + 1, transformedArr);
	delete[] transformedArr;
}