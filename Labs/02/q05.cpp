/*
 * Creator: Fasih Hasan
 * Date: 6/2/24
 * Desc: product management system with various functions
 */

#include <iostream>

#define MAX_PRODUCTS 100

using namespace std;

struct Product {
    string name;
    float price;
    int quantity, id;
};

void menu(int c) {
    cout << "Menu (Products count: " << c << "):" << endl
         << "\t1. Add product" << endl
         << "\t2. Update product" << endl
         << "\t3. Output product" << endl
         << "\t4. Exit" << endl
         << ">> ";
}

int input_id() {
    int id;
    cout << "Enter product ID: ";
    cin >> id;

    return id;
}

Product &find_by_id(Product products[MAX_PRODUCTS], int c, int id) {
    for (int i = 0; i < c; i++)
        if (products[i].id == id) return products[i];
    
    Product *null_product = new Product();
    null_product->name = "NOT_FOUND";
    return *null_product;
}

void input_product(Product products[100], int i) {
    Product new_product;
    new_product.id = i;

    cout << "Product ID: " << i << endl;
    cout << "Enter product name: ";
    cin >> new_product.name;

    cout << "Enter product price: ";
    cin >> new_product.price;

    cout << "Enter product quantity: ";
    cin >> new_product.quantity;

    products[i] = new_product;
}

void output_product(Product products[MAX_PRODUCTS], int c, int id) {
    Product product = find_by_id(products, c, id);
    cout << endl;

    if (product.name == "NOT_FOUND") {
        cout << "Product not found" << endl;
        return;
    }

    cout << "ID    >> " << product.id << endl
         << "name  >> " << product.name << endl
         << "price >> " << product.price << endl
         << "qty.  >> " << product.quantity << endl;
}

void update_product(Product products[MAX_PRODUCTS], int c, int id) {
    Product product = find_by_id(products, c, id);

    if (product.name == "NOT_FOUND") {
        cout << "Product not found" << endl;
        return;
    }

    input_product(products, id);
}

int main() {
    Product products[MAX_PRODUCTS];
    int c = 0;

    bool flag = true;
    while(flag) {
        int choice;
        menu(c);
        cin >> choice;
        cout << endl;

        switch(choice) {
            case 1:
                input_product(products, c++);
                break;
            case 2:
                update_product(products, c, input_id());
                break;
            case 3:
                output_product(products, c, input_id());
                break;
            case 4:
            default:
                flag = false;
        }
        cout << endl;
    }

    return 0;
}