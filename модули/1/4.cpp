#include <iostream>

using namespace std;

struct range {
	int from;
	int to;
};


struct area {
	range x;
	range y;
};

class Area {
	public:
		
		Area() {
			this->_area.x.from = 1;
			this->_area.x.to = 3;

			this->_area.y.from = -2;
			this->_area.y.to = -1;
		}

		bool isInArea(int x, int y) {
			return  this->isNumberInRange(this->_area.x, x) && 					   
			this->isNumberInRange(this->_area.y, y);
		}
	private:
		area _area;

		bool isNumberInRange(range _range, int number) {
			return number >= _range.from && number <= _range.to;
		}
	
};

int main() 
{
	int a, b;

	cout << "Введите координаты: a, b" << endl;
	cin >> a >> b;

	Area area;
	
	cout << area.isInArea(a, b) << endl;
}