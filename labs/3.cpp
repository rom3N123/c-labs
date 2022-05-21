#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Vector {
	public: 
		int arr[100];
		int userLength = 10;
		int realLength = this->userLength;

		Vector() 
		{
			this->fill();
		}

		void filter() 
		{
			int lastInsertedIndex = 0;

			for(int i = 0; i < this->userLength; i++) 
			{
				int el = this->arr[i];
				
				if(el % 4 != 0) 
				{
					this->arr[lastInsertedIndex++] = el;
				} else 
				{
					this->realLength -= 1;
				}
			}
		}

		void addZero() 
		{
			int transformed[100];
			int lastInsertedIndex = 0;
			int addedLength = 0;

			for(int i = 0; i < this->realLength; i++, lastInsertedIndex++) 
			{
				int el = this->arr[i];
				transformed[lastInsertedIndex] = el;

				if(i == 0 || i % 2 == 1) 
				{
					transformed[++lastInsertedIndex] = 0;
					addedLength++;
				}
			}

			this->realLength += addedLength;

			for(int i = 0; i < this->realLength; i++) 
			{
				int el = transformed[i];
				this->arr[i] = el;
			}
		}

		void log()
		{
			for(int i = 0; i < this->realLength; i++) 
			{
				cout << this->arr[i] << "\t";
			}

			cout << endl;
		}

	private:

		void fill() 
		{
			for(int i = 0; i < this->userLength; i++) 
			{
				int randomNumber = rand() % 11;
				this->arr[i] = randomNumber;
			}
		}
};

// int* insertX(int n, int arr[],
//              int x, int pos)
// {
//     int i;
  
//     // increase the size by 1
//     n++;
  
//     // shift elements forward
//     for (i = n; i >= pos; i--)
//         arr[i] = arr[i - 1];
  
//     // insert x at pos
//     arr[pos - 1] = x;
  
//     return arr;
// }

int main() {
   Vector v;
   v.log();
   v.filter();
   v.log();
   v.addZero();
   v.log();
}