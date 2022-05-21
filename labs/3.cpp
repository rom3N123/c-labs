#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int LENGTH = 100;

class Array {
	public: 
		int arr[LENGTH];
		int userLength;
		int realLength;

		Array(int userLength) 
		{
			this->userLength = userLength;
			this->realLength = userLength;
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

int main() {
	int userLength;

	cout << "Введите длину массива, не больше - " << LENGTH << endl;

	cin >> userLength;

   	Array v(userLength);
   	v.log();
   	v.filter();
   	v.log();
   	v.addZero();
   	v.log();
}