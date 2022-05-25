#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int LENGTH = 100;

void fill(int arr[], int length) {
	for(int i = 0; i < length; i++) 
	{
		int randomNumber = rand() % 11;
		arr[i] = randomNumber;
	}
};

void log(int arr[], int length)
{
	for(int i = 0; i < length; i++) 
	{
		cout << arr[i] << "\t";
	}

	cout << endl;
}

void addElements(int arr[], int &length) 
{
	int newArr[LENGTH];
	int lastInsertedIndex = 0;
	int addSize = 0;
	for(int i = 0; i < length; i++) 
	{
		int el = arr[i];
		bool shouldAdd = i % 2 == 0;
		newArr[lastInsertedIndex++] = el;
		if(shouldAdd) 
		{
			newArr[lastInsertedIndex++] = 0;
			addSize++;
		}

	}

	for(int i = 0; i < lastInsertedIndex; i++) 
	{
		arr[i] = newArr[i];
	}

	length += addSize;
}

void deleteItem(int arr[], int length, int k) 
{
	int newArr[length - 1];

	bool hasSkipped = false;

	for(int i = 0; i < length; i++) 
	{
		if(i == k) {
			hasSkipped = true;
			continue;
		} 

		newArr[hasSkipped ? i - 1 : i] = arr[i];
	}

	for(int i = 0; i < length - 1; i++) 
	{
		int el = newArr[i];
		arr[i] = el;
	}
}

int main() {
	int userLength;

	cout << "Введите длину массива, не больше - " << LENGTH << endl;
	cin >> userLength;

	int arr[LENGTH];
	int &realLength = userLength;

	fill(arr, userLength);
   	log(arr, realLength);
	deleteItem(arr, realLength, 1);
	realLength -= 1;
	log(arr, realLength);
   	addElements(arr, realLength);
   	log(arr, realLength);
}