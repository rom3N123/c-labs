#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Vector {
	public: 
		vector<int> list;

		Vector(int length) 
		{
			this->create(length);
		}

		void filter() 
		{
			vector<int> filtered;

			copy_if(this->list.begin(), this->list.end(), back_inserter(filtered), [](int number) -> bool {
				return number % 4 != 0;
			});

			this->list = filtered;
		}

		void addZero() 
		{
			vector<int> transformed;

			for(int i = 0; i < this->list.size(); i++) {
				transformed.push_back(this->list[i]);

				if(i == 0 || i % 2 == 1) {
					transformed.push_back(0);
				}
			}

			this->list = transformed;
		}

		void log()
		{
			for(int i = 0; i < this->list.size(); i++) {
				cout << "Element: " << this->list[i] << "\t" << endl;
			}

			this->logDivider();
		}

	private:
		int initialLength;

		void logDivider() {
			cout << "================" << endl;
		}

		void create(int length) 
		{
    		vector<int> numbers(length);

			for(int i = 0; i < length; i++) {
				int randomNumber = rand() % 11;
				numbers[i] = randomNumber;
			}

			this->list = numbers;
		}
};

int main() {
	Vector v(10);
	v.log();
	v.filter();
	v.log();
	v.addZero();
	v.log();
}