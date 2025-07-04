#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;


struct Book {
    string title;
    string author;
    string isbn;
    bool isIssued = false;
    time_t issueDate;
};

// List of books
vector<Book> library;


const int FINE_PER_DAY = 5;

time_t getToday() {
    return time(0);
}

// Add a book
void addBook() {
    Book newBook;
    cin.ignore(); 

    cout << "\nEnter book title: ";
    getline(cin, newBook.title);

    cout << " Enter author name: ";
    getline(cin, newBook.author);

    cout << " Enter ISBN: ";
    getline(cin, newBook.isbn);

    newBook.isIssued = false;

    library.push_back(newBook);
    cout << " Book added successfully!\n";
}

// Show all books
void viewBooks() {
    cout << "\n📖 List of Books:\n";
    if (library.empty()) {
        cout << "No books available in the library yet.\n";
        return;
    }

    for (int i = 0; i < library.size(); ++i) {
        Book& b = library[i];
        cout << i + 1 << ". " << b.title << " by " << b.author
             << " | ISBN: " << b.isbn
             << " | Status: " << (b.isIssued ? "Issued" : "Available") << endl;
    }
}

// Issue a book
void issueBook() {
    string isbn;
    cin.ignore();
    cout << "\n📘 Enter ISBN of book to issue: ";
    getline(cin, isbn);

    for (Book& b : library) {
        if (b.isbn == isbn) {
            if (b.isIssued) {
                cout << "⚠ Book is already issued.\n";
                return;
            }
            b.isIssued = true;
            b.issueDate = getToday();
            cout << "✅ Book issued successfully! Return within 14 days to avoid fine.\n";
            return;
        }
    }
    cout << " Book not found.\n";
}

// Return a book
void returnBook() {
    string isbn;
    cin.ignore();
    cout << "\n Enter ISBN of book to return: ";
    getline(cin, isbn);

    for (Book& b : library) {
        if (b.isbn == isbn && b.isIssued) {
            time_t today = getToday();
            double days = difftime(today, b.issueDate) / (60 * 60 * 24);
            b.isIssued = false;

            if (days > 14) {
                int fine = (days - 14) * FINE_PER_DAY;
                cout << " Book returned late by " << (int)(days - 14)
                     << " days. Fine = ₹" << fine << endl;
            } else {
                cout << " Book returned on time. No fine!\n";
            }
            return;
        }
    }
    cout << " Book not found or not issued.\n";
}

// Main menu
void showMenu() {
    int choice;

    do {
        cout << "\n=========  Library Menu =========\n";
        cout << "1. Add a new book\n";
        cout << "2. View all books\n";
        cout << "3. Issue a book\n";
        cout << "4. Return a book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: issueBook(); break;
            case 4: returnBook(); break;
            case 5: cout << " Thank you for using the library system!\n"; break;
            default: cout << " Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}

int main() {
    cout << "Welcome to  Library System!\n";
    showMenu();
    return 0;
}


