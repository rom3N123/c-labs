#include <iostream>

using namespace std;

int main()
{
	const int COLS =3;
	const int ROWS = COLS;
    int arr[ROWS][COLS] ={ {1,7,2} , {0,-2, 4} , {5,9,-8} };
    int totalSum;

    for(int i = 0; i < 3; i++){
        int sum=0;
        for(int j = 0; j < 3; j++){
            sum += arr[i][j];
        }
        if(i == 0 || sum > totalSum){
            totalSum = sum;
        }
    }
    cout << "Максимальная сумма: " << totalSum << endl;

    for(int i = 0; i < 3; i++){
        for(int j = 0 ;j < 3; j++){
            arr[i][j] *= totalSum;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}