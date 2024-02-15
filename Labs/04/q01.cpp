/*
 * Creator: Fasih Hasan Khan 23K-0018
 */ 

#include <iostream>

using namespace std;

class Book {
public:
    string name, author, isbn_number;
    int page_count, pages_read;

    Book() : name("NO_NAME"), author("NO_AUTHOR"), isbn_number("NO_ISBN_NUM"), page_count(0), pages_read(0) {
        if (pages_read >= page_count) 
            cout << "You have read the book" << endl;
    }

    Book(string name, string author, string isbn_number, int page_count, int pages_read)
     : name(name), author(author), isbn_number(isbn_number), page_count(page_count), pages_read(pages_read) {}

    void update_read(int new_pages_read) {
        pages_read += new_pages_read;
        if (pages_read >= page_count)
            cout << "You have read the book" << endl;
    }
};

void output_book(Book book) {
    cout << book.name << endl
         << book.author << endl
         << book.isbn_number << endl
         << book.page_count << endl
         << book.pages_read << endl;
}

int main()
{
    Book empty_book; // create empty book (defailt constructor)
    Book book("Mein Kampf", "Adolf Hitler", "9780977476077", 727, 0); // create book (param constructor)
    Book test_book("Test Book", "Test Author", "0000000000000", 1, 1); // create book (param constructor)
    cout << endl;

    output_book(empty_book); // show empty book
    cout << endl;
    output_book(book);
    cout << endl;

    book.update_read(300); // update pages
    cout << endl;
    output_book(book);
    cout << endl;

    book.update_read(427); // update pages to finish book
    cout << endl;
    output_book(book);
    cout << endl;

    return 0;
}