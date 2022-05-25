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

int* addFirstELement(int arr[], int length) {
	int *newArr = new int;

	newArr[0] = 1000;

	for(int i = 0; i < length; i++) 
	{
		newArr[i + 1] = arr[i];
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

int** deleteRow(int rows, int cols, int **arr, int K) {
	int **newArr = new int* [rows - 1];

	int lastRow = 0;
	for(int r = 0; r < rows; r++) 
	{
		if(r == K) {
			continue;
		}
		int *row = arr[r > K ? lastRow + 1 : lastRow];	

		newArr[lastRow++] = row;
	}

	return newArr;
}

int two() 
{
	// Двумерный массив
	int r = 5, c = 5;
	int **arr = createTwoDimensionalArray(r, c);
	logTwoDimensionalArray(r, c, arr);
	int **transformedArr = deleteRow(r, c, arr, 1);
	logTwoDimensionalArray(r - 1, c, transformedArr);
	return 0;
}

int one() 
{
	// Одномерный массив
	int length = 10;
	int *numbers = getArray(length);
	logArray(numbers, length);
	int* resultArr = addFirstELement(numbers, length);
	logArray(resultArr, length + 1);
	return 0;
}

int main() 
{
	two();

	one();
}