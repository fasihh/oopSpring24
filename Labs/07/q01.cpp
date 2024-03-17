#include <iostream>

using namespace std;

class Book {
public:
    string title, author, publisher;

    Book(string title, string author, string publisher) : 
        title(title), author(author), publisher(publisher) {}

    void display() {
        cout << "Title: " << title << "\n";
        cout << "Author: " << author << "\n";
        cout << "Publisher: " << publisher << "\n";
    }
};

class FictionalBook : public Book {
public:
    string genre, protagonist;

    FictionalBook(string title, string author, string publisher, string genre, string protagonist) :
        Book(title, author, publisher), genre(genre), protagonist(protagonist) {}

    void display() {
        cout << "Title: " << title << "\n";
        cout << "Author: " << author << "\n";
        cout << "Publisher: " << publisher << "\n";
        cout << "Genre: " << genre << "\n";
        cout << "Protagonist: " << protagonist << "\n";
    }
};

int main() {
    FictionalBook f_book("Fiction Book", "Fasih", "Fasih", "Fiction", "Fasih");
    f_book.display();

    return 0;
}