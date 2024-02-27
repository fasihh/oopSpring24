#include <iostream>

using namespace std;

class Robot {
private:
	int x, y;
public:
	Robot(int x = 0, int y = 0) : x(x), y(x) {}
	Robot(const Robot &obj) { x = obj.y, y = obj.x; }

	void moveLeft(int d) { x -= d; }
	void moveRight(int d) { x += d; }
	void moveForward(int d) { y += d; }
	void moveReverse(int d) { y -= d; }

	void commands(string act, int d) {
		for (char c : act) {
			switch(c) {
			case 'L':
				moveLeft(d);
				break;
			case 'R':
				moveRight(d);
				break;
			case 'F':
				moveForward(d);
				break;
			case 'B':
				moveReverse(d);
				break;
			}
		}
	}

	void display() {
		cout << "x: " << x << "\ny: " << y << endl;
	}
};

int main()
{
	Robot robot1;
	robot1.commands("RRRBB", 1);
	robot1.display();
	cout << "\n";

	Robot robot2 = robot1;
	robot2.display();

	return 0;
}