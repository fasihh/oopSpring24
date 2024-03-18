#include <iostream>

using namespace std;

class Position {
public:
    float x, y, z;

    Position(float x, float y, float z) : x(x), y(y), z(z) {}
};

class Health {
public:
    int health;

    Health(int hp) : health(hp) {}
};

class Player : public Position, public Health {
public:
    Player() : Health(100), Position(0.f, 0.f, 0.f) {}

    void move(int dx, int dy, int dz) {
        x += dx, y += dy, z += dz;
    }

    void heal(int hp) {
        health = (health + hp >= 100) ? 100 : health+hp;
    }
    
    void display() {
        cout << "Health: " << health << "\n";
        cout << "Position:\nx: " << x << "\ny: " << y << "\nz: " << z << "\n";
    }
};

int main() {
    Player player;
    player.health = 72;
    player.display();

    player.heal(30);
    player.move(2, 3, -1);
    player.display();

    return 0;
}