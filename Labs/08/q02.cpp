#include <iostream>

using namespace std;

class Character {
public:
    int health, damage;

    Character(int health, int damage) : health(health), damage(damage) {}

    void display() {
        cout << "Health: " << health << "\n";
        cout << "Damage: " << damage << "\n";
    }
};

class Enemy : public Character {
public:
    Enemy(int health, int damage) : Character(health, damage) {}

    void display() {
        cout << "Enemy" << "\n";
        cout << "Health: " << health << "\n";
        cout << "Damage: " << damage << "\n";
    }
};

class Player : public Character {
public:
    Player(int health, int damage) : Character(health, damage) {}

    void display() {
        cout << "Player" << "\n";
        cout << "Health: " << health << "\n";
        cout << "Damage: " << damage << "\n";
    }
};

class Wizard : public Player {
public:
    int magic_power;
    string spells;

    Wizard(int health, int damage, int magic, string spells) : Player(health, damage), magic_power(magic), spells(spells) {}

    void display() {
        cout << "Wizard" << "\n";
        cout << "Health: " << health << "\n";
        cout << "Damage: " << damage << "\n";
        cout << "Magic Power: " << magic_power << "\n";
        cout << "Spells: " << spells << "\n";
    }
};

int main() {
    Wizard wizard(
        80,
        60,
        90,
        "Fire Water Earth Air"
    );

    wizard.display();

    return 0;
}