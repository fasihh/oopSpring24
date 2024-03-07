#include <iostream>
#include <vector>

using namespace std;

class MenuItem {
public:
    string name;
    float price;

    MenuItem(string n = "", float p = 0.f) : name(n), price(p) {}
};

class Menu {
private:
    // menu can't exist without menu items
    vector<MenuItem> menuList;
public:
    void addItem(MenuItem& item) {
        menuList.push_back(item);
    }

    void removeItem(int index) {
        menuList.erase(next(menuList.begin(), index));
    }

    MenuItem getItem(string name) {
        for (MenuItem item : menuList)
            if (name == item.name) return item;
    }

    void display() {
        for (MenuItem item : menuList)
            cout << "Name: " << item.name << "\nPrice: " << item.price << "\n\n";
    }
};

class Payment {
public:
    float amount;

    Payment(float a = 0.f) : amount(a) {}
};

class Order {
private:
    // order could have no items - aggregation
    vector<MenuItem> items;
    // order needs to have a payment - composition
    Payment payment;
public:
    void addItem(MenuItem item) {
        items.push_back(item);
        payment.amount += item.price;
    }

    float getTotal() {
        return payment.amount;
    }
};

class Restaurant {
    // a restaurant cannot exist without menu
    Menu menu;
public:
    void addMenuItem(MenuItem item) {
        menu.addItem(item);
    }

    void removeMenuItem(int index) {
        menu.removeItem(index);
    }

    MenuItem getItem(string name) {
        return menu.getItem(name);
    }

    void displayMenu() {
        menu.display();
    }

    Order placeOrder(vector<MenuItem> items) {
        Order order;
        for (MenuItem& item : items)
            order.addItem(item);
        return order;
    }
};

int main() {
    Restaurant restaurant;
    Order order;

    restaurant.addMenuItem(MenuItem{"Burger", 5.99f});
    restaurant.addMenuItem(MenuItem{"Pizza", 8.99f});
    restaurant.addMenuItem(MenuItem{"Salad", 6.49f});

    cout << "Menu:\n";
    restaurant.displayMenu();

    while(true) {
        int choice;
        cout << "\t1. Enter menu item\n\t2. Place Order\n";
        cin >> choice;

        if (choice == 1) {
            string name;
            cout << "Enter name: ";
            cin >> name;
            order.addItem(restaurant.getItem(name));
        } else if (choice == 2) {
            cout << "Total: " << order.getTotal() << endl;
            break;
        } else {
            cout << "Incorrect input\n";
            continue;
        }
    }

    return 0;
}
