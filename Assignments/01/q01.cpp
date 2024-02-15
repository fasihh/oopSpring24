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

	void returnPet(string name) {
		vector<Pet>::iterator it;
		for (it = adoptedPetRecords.begin(); it < adoptedPetRecords.end(); it++) {
			if (it->name == name) adoptedPetRecords.erase(it);
		}
	}

	void displayAdoptedPets() {
		for (Pet pet : adoptedPetRecords) {
			cout << "Name: " << pet.name << endl;
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

string inputPetName() {
	char name[100];
	cout << "Enter pet name: ";
	cin.getline(name, sizeof(name));

	return string(name);
}

Pet addPet() {
	Pet pet;

	pet.name = inputPetName();
	pet.healthStatus = "Healthy";
	pet.happinessLevel = 60;
	pet.hungerLevel = 60;

	return pet;
}

void showAllPets(vector<Pet> list) {
	for (Pet pet : list) {
		cout << "Name: " << pet.name << endl;
		pet.displayPetDetails();
		cout << endl;
	}
}

void adoptPet(Adopter &adopter, vector<Pet> &list) {
	string name = inputPetName();

	for (vector<Pet>::iterator it = list.begin(); it < list.end(); it++) {
		if (it->name == name) {
			adopter.adoptPet(*it);
			list.erase(it);

			cout << "Pet adopted" << endl;
			return;
		}
	}

	cout << "Pet not found" << endl;
}

void returnPet(Adopter &adopter, vector<Pet> &list) {
	string name = inputPetName();

	for (Pet pet : adopter.adoptedPetRecords) {
		if (pet.name == name) {
			list.push_back(pet);
			adopter.returnPet(name);
			cout << "Pet returned" << endl;
			return;
		}
	}

	cout << "Pet not found" << endl;
}

int main()
{
	srand(time(0));
	vector<Pet> petsList;

	char name[100];
	cout << "Enter name: ";
	cin.getline(name, sizeof(name));

	char num[100];
	cout << "Enter phone number: ";
	cin.getline(num, sizeof(num));

	Adopter adopter(name, num);

	while(true) {
		menu(adopter.adopterName);
		int choice;
		cin >> choice;

		switch(choice) {
		case 1: // add pet to pets list
			cin.ignore();
			
			petsList.push_back(addPet());
			break;
		case 2: // show all pets in the list
			showAllPets(petsList);
			break;
		case 3: // add pet to adopted list and remove from pets list
			cin.ignore();
			adoptPet(adopter, petsList);
			break;
		case 4:
			adopter.displayAdoptedPets(); // show all pets in adopted pets list
			break;
		case 5:
			// add pet interactions
			break;
		case 6:
			cin.ignore();
			returnPet(adopter, petsList); // remove pet from adopted list and add back to pets list
			break;
		default:
			cout << "Incorrect option" << endl;
		}
	}

	return 0;
}
