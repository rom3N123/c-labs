#include <iostream>
#include <map>
using namespace std;

int main()
{
    const int N=5;
    const int M=5;
    int arr[N][M]={{1,2,3,4,4},{5,0,1,1,5},{1,2,3,4,5},{1,2,4,5,6},{4,5,3,4,4}};

    cout<<"Исходный массив: "<<endl;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    int max=0;
    int index=0;
    for(int i=0;i<N;i++){
        map<int,int> numbers;
        int localMax=1;
        for(int j=0;j<M;j++){
            if(numbers.count(arr[i][j])){
                numbers[arr[i][j]]++;
                if(numbers[arr[i][j]]>localMax){
                    localMax=numbers[arr[i][j]];
                }
            }
            else{
                numbers.insert({arr[i][j],0});
            }
        }
        if(localMax > max) {
            max=localMax;
            index=i;
        }
    }
    cout<<"Индекс строки, которая содержит максимальное количество одинаковых элементов: "<<index+1<<endl;
}
