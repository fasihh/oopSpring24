#include <iostream>

using namespace std;

class Base {
private:
	int x;
public:
	Base(int x) : x(x) {}
	
	Base& operator --(int) {
		this->x /= 4;
		return *this;
	}
	
	Base& operator --() {
		this->x *= 4;
		return *this;
	}
	
	void show() { cout << x << endl; }
};

int main() {
	Base b1(4);
	
	--b1;
	b1.show();
	b1--;
	b1.show();
	
	return 0;
}
