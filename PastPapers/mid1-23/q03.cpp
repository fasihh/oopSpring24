#include <iostream>

using namespace std;

class Staff {
public:
	int staffID;
	float salary;
	string type;

	Staff(int id, string type, float salary) : staffID(id), type(type), salary(salary) {}

	static float totalSalaries;

	double trackProject(double currentCost) {
		if (currentCost > 200000) cout << "warning: that cost is exceeding budget" << endl;
		return currentCost;
	}

	double animate(double currentCost) { return currentCost + 10000; }
};

class Project {
public:
	int movieID;
	float cost;
	string title;
	Staff lead, chiefAnimator;

	static float budget;

	Project(int id, float cost, string title) : movieID(id), cost(cost), title(title), 
		lead(0, "Lead", 500000), chiefAnimator(1, "Chief Animator", 400000) {}

	void production() {
		cost = lead.trackProject(cost), cost = chiefAnimator.animate(cost);
		cout << "Task is in production" << endl;
	}
};

float Project::budget = 200000;
float Staff::totalSalaries = 0;

int main() {
	Project project(0, 190000, "WOW");
	project.production();
	project.production();
	project.production();

	return 0;
}