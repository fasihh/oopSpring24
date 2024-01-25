#include <iostream>
#include <limits>

typedef struct {
    std::string name;
    std::string date;
    std::string venue;
    std::string organizer;
} Event;

Event event_input() {
    Event e;

    std::cout << "Event name: ";
    std::cin >> e.name;

    std::cout << "Event date (dd/mm/yy): ";
    std::cin >> e.date;

    std::cout << "Event venue: ";
    std::cin >> e.venue;

    std::cout << "Event organizer: ";
    std::cin >> e.organizer;

    return e;
}

int main() {
    int events;

    std::cout << "Enter number of events: ";
    std::cin >> events;
    Event *event_arr = new Event[events];

    for (int i = 0; i < events; i++) {
        std::cout << "Event " << i+1 << std::endl;
        event_arr[i] = event_input();
        std::cout << std::endl;
    }


    std::string date;
    std::cout << "Enter date to search for an event (dd/mm/yy): ";
    std::cin >> date;

    for (int i = 0; i < events; i++) {
        if (event_arr[i].date == date) {
            std::cout << "Event name: " << event_arr[i].name << std::endl;
            std::cout << "Event date: " << event_arr[i].date << std::endl;
            std::cout << "Event venue: " << event_arr[i].venue << std::endl;
            std::cout << "Event organizer: " << event_arr[i].organizer << std::endl;

            break;
        }
    }

    return 0;
}
