#include <iostream>

using namespace std;

class printClass;
class Perimeter {
private:
	float length, breadth;
	
	friend class printClass;
public:
	Perimeter(float l, float b) : length(l), breadth(b) {}
};

class printClass {
public:
	static void print(const Perimeter& obj) {
		cout << 2*obj.length + 2*obj.breadth << endl;
	}
};

int main() {
	Perimeter p1(1, 2);
	printClass::print(p1);
	
	return 0;
}