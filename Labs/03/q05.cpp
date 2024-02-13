/*
 * Creator: Fasih Hasan Khan 23K0018
 */

#include <iostream>

#define MAX_ITEMS 100

using namespace std;

class StationaryShop {
private:
    string items[MAX_ITEMS];
    float prices[MAX_ITEMS];
    int count = 0;
public:
    void add_item(string item, float price) {
        items[count] = item;
        prices[count++] = price;
        cout << count << endl;
    }

    string get_item(int item) {
        return items[item-1];
    }

    float get_price(int item) {
        return prices[item-1];
    }

    int get_count() {
        return count;
    }

    void modify_price(int price, int item_num) {
        prices[item_num-1] = price;
    }

    void show_all() {
        for (int i = 0; i < count; i++) cout << items[i] << ": " << prices[i] << endl;
    }
};

void menu() {
    cout << "Stationary Shop Menu:" << endl
         << "\t1. Enter shop item" << endl
         << "\t2. Modify item price" << endl
         << "\t3. Show items" << endl
         << "\t4. Buy item" << endl
         << "\t5. Generate receipt" << endl
         << "\t6. Exit" << endl
         << ">> ";
}

void enter_item(StationaryShop &shop) {
    string item;
    float price;

    cout << "Enter item name: ";
    cin >> item;
    cout << "Enter item price: ";
    cin >> price;

    shop.add_item(item, price);
}

void change_price(StationaryShop &shop) {
    int item_num;
    float price;

    cout << "Enter item number: ";
    cin >> item_num;
    cout << "Enter new item price: ";
    cin >> price;

    shop.modify_price(price, item_num);
}

void buy_item(string items[MAX_ITEMS], float prices[MAX_ITEMS], int &c, StationaryShop &shop) {
    int item;

    cout << "Enter item to buy: ";
    cin >> item;

    items[c] = shop.get_item(item);
    prices[c] = shop.get_price(item);
    c++;
}

float find_sum(float arr[MAX_ITEMS], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return sum;
}

void generate_receipt(string items[MAX_ITEMS], float prices[MAX_ITEMS], int c) {
    for (int i = 0; i < c; i++) cout << items[i] << ": " << prices[i] << endl;
    cout << "Total: " << find_sum(prices, c);
}

int main()
{
    StationaryShop shop;
    string receipt_items[MAX_ITEMS];
    float receipt_prices[MAX_ITEMS];
    int receipt_count = 0;

    bool flag = true;
    while(flag) {
        menu();
        int choice;
        cin >> choice;

        switch(choice) {
            case 1:
                enter_item(shop);
                break;
            case 2:
                change_price(shop);
                break;
            case 3:
                shop.show_all();
                break;
            case 4:
                if (!shop.get_count()) {
                    cout << "No items entered by the shop keeper yet" << endl;
                    break;
                }
                buy_item(receipt_items, receipt_prices, receipt_count, shop);
                break;
            case 5:
                generate_receipt(receipt_items, receipt_prices, receipt_count);
            default:
                flag = false;
        }
    }

    return 0;
}
