#include <iostream>

using namespace std;

int main()
{
    int N=10;

	int **arr = new int* [N];

	for(int i = 0; i < N; i++) 
	{
		arr[i] = new int[N];

		int rowSum = 0;
		for(int k = 0; k < N; k++) 
		{
			int el = arr[i][k] = rand() % 10;
			rowSum += el;

			cout << el << "\t";
		}

		cout << "\t" << "Sum - " << rowSum;
		cout << endl; 
	}

	for(int i = 1; i < N; i++) 
	{
		for(int k = 1; k < N; k++) 
		{
			int currentSum = 0;
			int prevSum = 0;
			int *currentArr = arr[k];
			int *prevArr = arr[k - 1];

			for(int j = 0; j < N; j++) 
			{
				currentSum += currentArr[j];
				prevSum += prevArr[j];
			}

			if(currentSum < prevSum) 
			{
				arr[k - 1] = currentArr;
				arr[k] = prevArr;
			}
		}
	}

	cout << "===============" << endl;

	for(int i = 0; i < N; i++) 
	{

		int rowSum = 0;
		for(int k = 0; k < N; k++) 
		{
			int el = arr[i][k];
			rowSum += el;

			cout << el << "\t";
		}

		cout << "\t" << "Sum - " << rowSum;
		cout << endl; 
	}

	delete[] arr;
}