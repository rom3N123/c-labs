#include <iostream>
#include <random>
#include <ctime>

using namespace std;

void bubbleSort(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        for (int j = 1; j < size; j++) {
			int current = arr[j];
			int prev = arr[j - 1];

            if (current < prev) {
                arr[j - 1] = current;
				arr[j] = prev;
            }
        }
    }
}

int main()
{
    int N=10;
    int *arr = new int[N];
    cout<<"Исходный массив: "<<endl;
    for(int i=0;i<N;i++){
        arr[i] = -10 + (rand() % ( 20 + 1 ) );
        cout<<arr[i]<<" ";
    }
    cout << endl;
    bubbleSort(arr,N);

    int lastInsertedIndex = 0;
    int *newArr = new int;
    for(int i = 0; i < N; i++) 
    {
        int el = arr[i];
        
        if(el >= 0) 
        {
            newArr[lastInsertedIndex++] = el;
        }
    }

    for(int i = 0; i < lastInsertedIndex; i++) 
    {
        cout << newArr[i] << " ";
    }
}