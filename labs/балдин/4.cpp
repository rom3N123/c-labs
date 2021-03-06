#include <iostream>
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

int** createTwoDimensionalArray(int rows, int cols) {
	int **arr = new int* [rows];

	for(int i = 0; i < rows; i++) {
		arr[i] = getArray(cols);
	}

	return arr;
}

int* deleteFirstElement(int arr[], int length) {
	int *newArr = new int;

	bool hasDeleted = false;

	for(int i = 0; i < length; i++) 
	{
		int el = arr[i];

		if(el % 2 == 0 && !hasDeleted) {
			hasDeleted = true;
			continue;
		}

		newArr[hasDeleted ? i - 1 : i] = el;
	}

	return newArr;
}

void logArray(int arr[], int length) {
	for(int i = 0; i < length; i++) {
		cout << arr[i] << "\t";
	}

	logDivider();
}

void logTwoDimensionalArray(int rows, int cols, int **arr) {
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

int** deleteRowWithMaxValue(int rows, int cols, int **arr) {
	int **newArr = new int* [rows - 1];
	int maxValue = 0;
	int maxRowIndex = 0;

	for(int r = 0; r < rows; r++) 
	{
		int* row = arr[r];
		for (int c = 0; c < cols; c++) 
		{
			int el = row[c];

			if(el > maxValue) 
			{
				maxValue = el;
				maxRowIndex = r;
			}
		}
	}

	int lastInsertedIndex = 0;
	for(int r = 0; r < rows; r++) 
	{
		if(r == maxRowIndex) 
		{
			continue;
		}

		arr[lastInsertedIndex++] = arr[r];
	}

	arr = newArr;
}

int two() 
{
	// Двумерный массив
	int r = 5, c = 5;
	int **arr = createTwoDimensionalArray(r, c);
	logTwoDimensionalArray(r, c, arr);
	deleteRowWithMaxValue(r, c, arr);
	logTwoDimensionalArray(r - 1, c, arr);
	delete[] arr;
	return 0;
}

int one() 
{
	// Одномерный массив
	int length = 10;
	int *numbers = getArray(length);
	logArray(numbers, length);
	int* resultArr = deleteFirstElement(numbers, length);
	logArray(resultArr, length - 1);
	return 0;
}

int main() 
{
	two();

	one();
}