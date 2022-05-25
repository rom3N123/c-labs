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

void addThreeElements(int arr[], int &length) 
{
	const int ELEMENTS_LENGTH = 3;
	int copyOfArray[LENGTH];

	for(int i = 0; i < length; i++) 
	{
		copyOfArray[i] = arr[i];
	}

	for(int i = 0; i < ELEMENTS_LENGTH; i++) 
	{
		arr[i] = copyOfArray[i + 1] + 2;
	}


	for(int i = 0; i < length; i++) 
	{
		arr[i + ELEMENTS_LENGTH] = copyOfArray[i];
	}

	length += ELEMENTS_LENGTH;
}

int main() {
	int userLength;

	cout << "Введите длину массива, не больше - " << LENGTH << endl;
	cin >> userLength;

	int arr[LENGTH];
	int &realLength = userLength;



	fill(arr, userLength);
   	log(arr, realLength);
	realLength -= 5;
   	log(arr, realLength);
   	addThreeElements(arr, realLength);
   	log(arr, realLength);
}