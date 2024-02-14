#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>
#include <limits>
#include <string>

using namespace std;


class Pet {
public:
	string healthStatus, name;
	int hungerLevel, happinessLevel;
	vector<string> specialSkills;

	void displayPetDetails() {
		cout << "Health-Status: " << healthStatus << endl;
		cout << "Hunger: " << hungerLevel << endl;
		cout << "Happiness: " << happinessLevel << endl;
		cout << "Skills:" << endl;
		for (string skill : specialSkills) cout << skill << endl;
	}

	void updateHunger(int hunger) {
		hungerLevel = hunger;
		if (hunger >= 50)
			happinessLevel += rand()%10 + 1; // generate random int between 1-10
		else
			happinessLevel--;
	}

	void updateHappiness(int happiness) {
		happinessLevel = happiness; 
	}

	void updateHealth(string health) {
		healthStatus = health; 
	}
};


class Adopter {
public:
	string adopterName, adopterMobileNum;
	vector<Pet> adoptedPetRecords;

	Adopter(string name, string num) : adopterName(name), adopterMobileNum(num) {} 

	void adoptPet(Pet pet) {
		adoptedPetRecords.push_back(pet); 
	}

	void returnPet(Pet pet) {
		vector<Pet>::iterator it;
		for (it = adoptedPetRecords.begin(); it < adoptedPetRecords.end(); it++) {
			if (it->name == pet.name) adoptedPetRecords.erase(it);
		}
	}

	void displayAdoptedPets() {
		for (Pet pet : adoptedPetRecords) {
			cout << pet.name << endl;
			pet.displayPetDetails();
			cout << endl;
		}
	}
};

void menu(string name) {
	cout << "Welcome " << name << "!" << endl
		 << "Virtual Pet Adoption System" << endl
		 << "\t1. Add pet" << endl
		 << "\t2. Show all pets" << endl
		 << "\t3. Adopt pet" << endl
		 << "\t4. Show adopted pets" << endl
		 << "\t5. Interact with pet" << endl
		 << "\t6. Return pet" << endl
		 << "\t7. Exit" << endl
		 << ">> ";
}

int main()
{
	srand(time(0));

	string name;
	cout << "Enter name: ";
	getline(cin, name);
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string num;
	cout << "Enter name: ";
	getline(cin, num);
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	Adopter adopter(name, num);

	while(true) {
		menu(adopter.adopterName);
		int choice;
		cin >> choice;
	}

	return 0;
}