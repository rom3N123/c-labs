	#include <iostream>

using namespace std;

void logArray(int arr[], int length) 
{
	for(int i = 0; i < length; i++) 
	{
		int el = arr[i];
		cout << el << "\t";
	}

	cout << "=======================================" << endl;
}

int *bubbleSort(int arr[], int length, bool isAscending = true) 
{
	int sorted[length];

	for(int i = 1; i < length; i++) 
	{
		for(int k = 1; k < length; k++) 
		{
			int prev = arr[k - 1];
			int current = arr[k];

			if(isAscending ? current < prev : current > prev) 
			{
				arr[k - 1] = current;
				arr[k] = prev;
			}
		}
	}

	return arr;
}

int main() 
{
	const int LENGTH = 15;
	int arr[LENGTH];
	int lessThanZero[LENGTH];
	int greaterThanZero[LENGTH];

	for(int i = 0; i < LENGTH; i++) 
	{
		cin >> arr[i];
	}

	int lessThanZeroLastIndex = 0;
	int greaterThanZeroLastIndex = 0;

	for(int i = 0; i < LENGTH; i++) 
	{
		int el = arr[i];
		int isLowerThanZero = el < 0;
		int *targetArray = isLowerThanZero ? lessThanZero : greaterThanZero;
		int &targetIndex = isLowerThanZero ? lessThanZeroLastIndex : greaterThanZeroLastIndex;
		targetArray[targetIndex++] = el;
	}

	int *sortedLessThanZero = bubbleSort(lessThanZero, lessThanZeroLastIndex);
	int *sortedGreaterThanZero = bubbleSort(greaterThanZero, greaterThanZeroLastIndex, false);
	int merged[lessThanZeroLastIndex + greaterThanZeroLastIndex];

	for(int i = 0; i < lessThanZeroLastIndex; i++) 
	{
		merged[i] = sortedLessThanZero[i];
	}

	for(int i = lessThanZeroLastIndex, k = 0; i < LENGTH; i++, k++) 
	{
		merged[i] = sortedGreaterThanZero[k];
	}

	logArray(merged, lessThanZeroLastIndex + greaterThanZeroLastIndex);
}