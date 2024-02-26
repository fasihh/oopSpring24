#include <iostream>
#include <vector>

using namespace std;

const int now = 8;

class Restaurant {
public:
    string restaurant_name, location;
    vector<string> menu_list, valid_coupon_codes_list;
    vector<float> price_list;
    static int redeemed_coupons;
    string restaurant_code;

    vector<int> bill; // stores indices of purchased items
    float total;

    Restaurant(string name, string location, string code, vector<string> menu, vector<float> price) 
    : restaurant_name(name), location(location), restaurant_code(code), menu_list(menu), price_list(price), total(0)  {}

    void display_menu() {
        for (int i = 0; i < menu_list.size(); i++)
            cout << "[" << i << "]: " <<  menu_list[i] << " - $" << price_list[i] << endl; 
    }

    void generate_bill() {
        for (int i : bill) {
            cout << "[" << i << "]: " <<  menu_list[i] << " - $" << price_list[i] << endl;
            total += price_list[i];
        }

        cout << "Total: $" << total << endl;
    }

    void apply_discount() {
        int count = 0;
        for (int i : bill) {
            for (int j : bill)
                if (i == j) count++;

            if (count >= 2) {
                cout << "Discounted: $" << total - price_list[i] << endl;
                return;
            }
        }
    }
};

int Restaurant::redeemed_coupons = 0;

class BOGOCoupon {
public:
    string coupon_code, restaurant_code;
    int valid_from, valid_until;

    BOGOCoupon(string c_code, string res_code, int from, int until)
    : coupon_code(c_code), restaurant_code(res_code), valid_until(until), valid_from(from) {}

    bool is_valid(string res_code) {
        return (res_code != restaurant_code && now >= valid_from && now <= valid_until) ? false : true;
    }
};

class User {
public:
    string name, mobile_number;
    int age;
    vector<BOGOCoupon> coupons, redeemed_coupons;

    User(string name, string phone, int age) : name(name), mobile_number(phone), age(age) {}

    void accumulate_coupon(BOGOCoupon coupon) { coupons.push_back(coupon); }

    bool is_redeemed(BOGOCoupon coupon) {
        for (BOGOCoupon redeemed : redeemed_coupons)
            if (coupon.coupon_code == redeemed.coupon_code) return true;
        return false;
    }

    int has_valid_coupon(string res_code) {
        for (int i = 0; i < coupons.size(); i++)
            if (!is_redeemed(coupons[i]) && coupons[i].is_valid(res_code)) return i;
        return -1;
    }

    bool redeem_coupon(int coupon, string res_code) {
        if (!is_redeemed(coupons[coupon]) && coupons[coupon].is_valid(res_code)) {
            redeemed_coupons.push_back(coupons[coupon]);
            return true;
        }

        return false;
    }
};

void menu() {
    cout << "Welcome:\n"
         << "\t1. Menus\n"
         << "\t2. Receipt\n"
         << "\t3. Add Item\n"
         << "\t4. Exit Menu\n"
         << ">> ";
}

void get_receipt(User &user, Restaurant &res) {
    int index = user.has_valid_coupon(res.restaurant_code);

    cout << "Coupon available" << endl;
    cout << user.coupons[index].restaurant_code << "-BOGO-" << user.coupons[index].coupon_code << endl;
    cout << "Would you like to avail? (Y/N): ";
    char choice;
    cin >> choice;

    if (choice == 'N' || choice == 'n') {
        res.generate_bill();
        return;
    }

    res.generate_bill();
    res.apply_discount();
    res.bill.clear();
}

User create_user() {
    char name[100], phone[100];
    int age;

    cout << "Enter user name: ";
    cin.getline(name, 100);

    cout << "Enter user phone number: ";
    cin.getline(phone, 100);

    cout << "Enter user age: ";
    cin >> age;

    return { name, phone, age };
}

int restaurant_select() {
    int res;
    cout << "Select restaurant\n"
         << "\t1. Food Haven\n"
         << "\t2. Pixel Bites\n"
         << ">> ";
    cin >> res;
    return res;
}

int main()
{
    Restaurant fh("Food Haven", "City Center", "FH",
        { "Sushi", "Pad Thai", "Mango Tango" },
        { 5.99, 9.99, 3.69 }
    );
    Restaurant pb("Pixel Bites", "Cyber Street", "PB",
        { "Binary Burger", "Quantum Quinoa", "Data Donuts" },
        { 5.99, 12.99, 6.99 }
    );

    User user = create_user();
    user.accumulate_coupon(BOGOCoupon("12345", "FH", 0, 30));
    user.accumulate_coupon(BOGOCoupon("33367", "PB", 0, 30));

    bool flag = true;
    while(flag) {
        int choice;
        menu();
        cin >> choice;

        int res;
        switch(choice) {
        case 1:
            res = restaurant_select();

            if (res == 1) fh.display_menu();
            else if (res == 2) pb.display_menu();
            break;
        case 2:
            res = restaurant_select();

            if (res == 1) get_receipt(user, fh);
            else if (res == 2) get_receipt(user, pb);

            break;
        case 3:
            res = restaurant_select();

            int item;
            cout << "Enter item number: ";
            cin >> item;

            if (res == 1) fh.bill.push_back(item);
            else if (res == 2) fh.bill.push_back(item);

            break;
        case 4:
            flag = false;
            break;
        default:
            cout << "Incorrect option" << endl;
        }
    }

    return 0;
}