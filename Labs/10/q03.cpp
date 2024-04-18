#include <iostream>

using namespace std;

class shape {
private:
	float x;
public:
	shape(float y) : x(y) {}
	
	float area() const { return x*x; }
	
	float operator + (const shape& obj) {
		return this->area() + obj.area();
	}
};

int main() {
	shape shape1(3), shape2(4);
	
	cout << shape1 + shape2 << endl;
	
	return 0;
}