#include <iostream>

using namespace std;

template <typename T>
class Pet {
private:
    string name;
    int age;
public:
    Pet(string name, int age) : name(name), age(age) {}

    // void setAge(int newAge) { age = newAge; }
    // void setName(string newName) { name = newName; }

    // int getAge() { return age; }
    // string getName() { return name; }

    void display() { cout << "Name: " << name << "\nAge: " << age << endl; }

    virtual void makeSound() = 0;
};

class Cat : public Pet<int> {
public:
    Cat(string name, int age) : Pet<int>(name, age) {}

    void makeSound() override { cout << "Meow!" << endl; }
};

class Dog : public Pet<double> {
public:
    Dog(string name, int age) : Pet<double>(name, age) {}

    void makeSound() override { cout << "Woof!" << endl; }
};

class Bird : public Pet<char> {
public:
    Bird(string name, int age) : Pet<char>(name, age) {}

    void makeSound() override { cout << "Chirp!" << endl; }
};

int main() {
    Cat cat("Fluffy", 5);
    Dog dog("Pooch", 9);
    Bird bird("Claude", 1);

    cat.display();
    cat.makeSound();
    dog.display();
    dog.makeSound();
    bird.display();
    bird.makeSound();

    return 0;
}