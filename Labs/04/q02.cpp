/*
 * Creator: Fasih Hasan Khan 23K-0018
 */

#include <iostream>

using namespace std;

class Book {
    string name, author, isbn_number;
    int page_count, pages_read;
public:
    Book() : page_count(1000), pages_read(0) {}

    void set_name(string book_name) { name = book_name; }

    void set_author(string book_author) { author = book_author; }

    void set_isbn(string book_isbn) { isbn_number = book_isbn; }

    void update_read(int new_pages_read) {
        pages_read += new_pages_read;
        if (pages_read >= page_count)
            cout << "You have read the book" << endl;
    }

    // showBookInfo
    void show_book_info() {
        cout << "Name: " << name << endl
             << "Author: " << author << endl
             << "ISBN: " << isbn_number << endl
             << "Page Count: " << page_count << endl
             << "Pages Read: " << pages_read << endl;
    }
};

int main()
{
    Book my_book;
    my_book.set_name("Mein Kampf");
    my_book.set_author("Adolf Hitler");
    my_book.set_isbn("727272727");

    my_book.show_book_info();

    return 0;
}
