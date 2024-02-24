#include <iostream>

using namespace std;

class Table {
private:
	unsigned total_seats;
public:
	unsigned occupied_seats, free_seats;
	bool clean;

	Table() : total_seats(4), free_seats(4), occupied_seats(0), clean(true) {} 
	Table(unsigned total) : total_seats(total > 6 ? 8 : 4), free_seats(total > 6 ? 8 : 4), occupied_seats(0), clean(true) {}

	unsigned capacity() { return total_seats; }

	bool isClean() { return clean; }

	bool isFree() { return free_seats; }

	void haveLunch() { clean = false; }

	void cleanTable() { clean = true; }

	void leaveTable() { free_seats = total_seats, occupied_seats = 0; }

	void occupyTable(unsigned people) { free_seats = total_seats - people, occupied_seats = people; }
};

void OccupyTable(Table tables[5], unsigned people) {
	for (int i = 0; i < 5; i++) {
		if (tables[i].isFree() && tables[i].isClean() && tables[i].capacity() >= people) {
			tables[i].occupyTable(people);
			return;
		}
	}
}

void EmptyTable(Table tables[5], unsigned i) {
	tables[i].leaveTable();
	tables[i].cleanTable();
}

int main()
{
	Table tables[5] = {
		Table(),
		Table(7),
		Table(9),
		Table(),
		Table()
	};

	OccupyTable(tables, 4); // table 1 gets used here
	tables[0].haveLunch();
	tables[0].leaveTable();
	tables[0].cleanTable();

	OccupyTable(tables, 6);
	EmptyTable(tables, 1);

	return 0;
}