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
			int lastZeroElementIndex = -1;

			for(int i = 0; i < this->userLength; i++) 
			{
				int el = this->arr[i];
				
				if(el == 0) 
				{
					lastZeroElementIndex = i;
				}
			}

			if(lastZeroElementIndex == -1) 
			{
				cout << endl;
				cout << "Элемент со значением 0 отсутствует в массиве" << endl;
				cout << endl;
			} else 
			{
				bool wasDeleted = false;

				for(int i = 0; i < this->realLength; i++) 
				{
					if(i == lastZeroElementIndex) 
					{
						wasDeleted = true;
					} else 
					{
						int insertIndex = wasDeleted ? i - 1 : i;
						this->arr[insertIndex] = this->arr[i];
					}
				}

				this->realLength -= 1;
			}
		}

		void insertValueAfterIndex(int idx) 
		{
			if(idx > this->realLength) 
			{
				cout << "Введите корректный индекс" << endl;
			}

			int increasedLength = this->realLength + 1;
			int transformed[increasedLength];
			bool wasInserted = false;

			for(int i = 0; i < this->realLength; i++) 
			{
				int value = this->arr[i];
				int insertIndex = wasInserted ? i + 1 : i;

				transformed[insertIndex] = value;

				if(idx == i) 
				{
					wasInserted = true;
					transformed[i + 1] = 100;
				}
			}

			for(int i = 0; i < increasedLength; i++) 
			{
				this->arr[i] = transformed[i];
			}

			this->realLength = increasedLength;
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
	int userLength = 0;

	cout << "Введите длину массива, не больше - " << LENGTH << endl;
	cin >> userLength;

   	Array v(userLength);
   	v.log();
   	v.filter();
   	v.log();
   	v.insertValueAfterIndex(1);
   	v.log();
}