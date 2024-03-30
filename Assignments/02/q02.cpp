#include <iostream>
#include <vector>

using namespace std;

const string default_weapons[5] = { "Sword", "Axe", "Bow", "Spear", "Hammer" };
const string experience_str[3] = { "Beginner", "Intermediate", "Advanced" };

class Player {
private:
    int id, health;
    string name;
public:
    Player(int id, string name) : id(id), name(name), health(100) {}

    void setHealth(int health) { this->health = health; }
    int getHealth() { return this->health; }
};

class Weapon {
private:
    vector<string> weapons;
public:
    Weapon(vector<string> weapons) : weapons(weapons.begin(), weapons.end()) {
        if (weapons.size() < 5) {
            for (int i = 0; i < 5-weapons.size(); i++)
                this->weapons.push_back(default_weapons[i]);
        }
    }

    void display() {
        for (int i = 0; i < this->weapons.size(); i++)
            cout << i+1 << ": " << this->weapons[i] << '\n';
        cout << endl;
    }

    string use() {
        int i;
        cout << "Which weapon would you like to use? (Enter its number)\n>> ";
        cin >> i;

        if (i >= this->weapons.size() || i < 0)
            return this->weapons[0];
        return this->weapons[i];
    }
};

class Enemy;
class Character : public Player {
private:
    int level, points;
    string experience;
public:
    Character(int id, string name) : Player(id, name), level(0), points(0), experience("Beginner") {}

    void levelUp(int increment) {
        if (increment < 10) return;

        this->level++;
        this->experience = experience_str[level];
    }

    void playGame(Weapon weapons, Enemy& enemy); 

    string getExperience() { return this->experience; }
};

class Enemy : public Player {
private:
    int damage;
public:
    Enemy(int id, string name, int damage) : Player(id, name), damage(damage) {
        if (damage > 10 || damage < 1)
            damage = 5;
    }

    void attacks(Weapon weapons, Character& player) {
        cout << "Enemy\n";
        string weapon = weapons.use();

        cout << "Enemy used '" << weapon << "' to attack player\n";
        player.setHealth(player.getHealth() - damage);
    }
};

void Character::playGame(Weapon weapons, Enemy& enemy) {
    cout << "Character\n";
    string weapon = weapons.use();

    cout << "Player used '" << weapon << "' to attack the enemy\n";
    enemy.setHealth(enemy.getHealth() - 5);
    this->levelUp(10);
}

int main() {
    Weapon weapons({
        "Mjölnir",
        "Funny Sword"
    });
    weapons.display();

    Character character(0, "Bob");
    Enemy enemy(1, "Golem", 30);

    for (int i = 0; i < 3; i++) {
        cout << "Character experience: " << character.getExperience() << "\n";
        cout << "Character health: " << character.getHealth() << "\n";
        character.playGame(weapons, enemy);
        cout << "Enemy health: " << enemy.getHealth() << "\n";
        enemy.attacks(weapons, character);
    }

    return 0;
}