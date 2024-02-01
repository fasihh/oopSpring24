/*
 * Creator: Fasih Hasan
 * Date: 1/2/24
 * Desc: Books management system with multiple options. Implemented using structs
 */

#include <iostream>

#define BOOK_NOT_FOUND -1
#define MAX_BOOKS 100

using namespace std;

struct Book {
    string title, author, genre;
    int year;

    void output_details() {
        cout << endl << "Book title: " << title << endl
             << "Book author: " << author << endl
             << "Book genre: " << genre << endl
             << "Year of publicatiion: " << year << endl << endl;
    }

    void input_details() {
        cout << endl << "Enter book title: ";
        cin >> title;

        cout << "Enter book author: ";
        cin >> author;

        cout << "Enter book genre: ";
        cin >> genre;

        cout << "Enter year of publicatiion: ";
        cin >> year;
        cout << endl;
    }
};


void menu(int c) {
    cout << "Books management system (Total books: " << c << "):" << endl
         << "\t1. Enter book(s)" << endl
         << "\t2. Update a book" << endl
         << "\t3. Output all books" << endl
         << "\t4. Exit" << endl
         << ">> ";
}

int find_by_author(Book books[MAX_BOOKS], int c) {
    string author;
    cout << "Enter author name: ";
    cin >> author;

    for (int i = 0; i < c; i++) {
        if (author == books[i].author) {
            books[i].output_details();
            return i;
        }
    }
    return BOOK_NOT_FOUND;
}

int find_by_title(Book books[MAX_BOOKS], int c) {
    string title;
    cout << "Enter book title: ";
    cin >> title;

    for (int i = 0; i < c; i++) {
        if (title == books[i].title) {
            books[i].output_details();
            return i;
        }
    }
    return BOOK_NOT_FOUND;
}

int enter_books(Book books[MAX_BOOKS], int c) {
    int s;
    cout << "Enter number of books: ";
    cin >> s;
    cout << endl;

    for (int i = c; i < c+s; i++) books[i].input_details();
    return c+s;
}

// function takes another function as a parameter
// the function is the criteria of finding a book decided by the user in main
void update_book(Book books[MAX_BOOKS], int c, int (*criteria)(Book *, int)) {
    int index = criteria(books, c);

    if (index == BOOK_NOT_FOUND) {
        cout << "Book not found" << endl;
        return;
    }

    cout << "Enter new info:" << endl;
    books[index].input_details();
}

void output_books(Book books[MAX_BOOKS], int c) {
    for (int i = 0; i < c; i++) books[i].output_details();  
}

int main()
{
    Book books[MAX_BOOKS];
    int c = 0;

    while(true) {
        menu(c);
        int choice;
        cin >> choice;
        cout << endl;

        switch(choice) {
            case 1:
                c = enter_books(books, c);
                break;
            case 2:
                int update_choice;
                cout << "Find book to update. Enter search type:" 
                     << endl << "\t1. By author" 
                     << endl << "\t2. By title"
                     << endl << ">> ";
                cin >> update_choice;

                // passing functions by reference
                if (update_choice == 1)
                    update_book(books, c, &find_by_author);
                else if (update_choice == 2) 
                    update_book(books, c, &find_by_title);
                break;
            case 3:
                output_books(books, c);
                break;
            case 4:
            default:
                return 0;
        }
    }
}
