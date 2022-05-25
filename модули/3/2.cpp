#include <iostream>
#include<random>
#include<ctime>

using namespace std;

void Smooth(double *arr, int size){
    for(int i=0;i<size;i++){
        double sum = 0;
        int count = 0;
        if(i!=0){
            count++;
            sum+=arr[i-1];
        }
        if(i!=size-1){
            count++;
            sum+=arr[i+1];
        }
        sum+=arr[i];
        count++;
        arr[i] = sum/count;
    }
}
int main()
{
    int N=10;
    double *arr = new double[N];
    cout<<"Исходный массив: "<<endl;
    for(int i=0;i<N;i++){
        arr[i] = -10 + ( rand() % ( 20 + 1 ) );
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<5;i++){
        cout<<i+1<<" smooth:"<<endl;
        Smooth(arr, N);
        for(int j=0;j<N;j++){
            cout<<arr[j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}