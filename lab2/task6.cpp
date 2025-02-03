#include <iostream>
#include <string>
using namespace std;

// Define the structure for Book
struct Book {
    int bookID;
    string title;
    string author;
    bool isAvailable;  
};

void inputBookDetails(Book &book) {
    cout << "Enter Book ID: ";
    cin >> book.bookID;
    cin.ignore(); 
    cout << "Enter Book Title: ";
    cin >> book.title;  
    cout << "Enter Book Author: ";
    cin >> book.author;  

    book.isAvailable = true;
}

void displayBookDetails(const Book &book) {
    cout << "\nBook ID: " << book.bookID << "\n";
    cout << "Title: " << book.title << "\n";
    cout << "Author: " << book.author << "\n";
    cout << "Status: " << (book.isAvailable ? "Available" : "Not Available") << "\n";
}

void displayAvailableBooks(Book* books, int numBooks) {
    cout << "\nList of Available Books:\n";
    bool foundAvailable = false;
    for (int i = 0; i < numBooks; i++) {
        if (books[i].isAvailable) {
            displayBookDetails(books[i]);
            foundAvailable = true;
        }
    }
    if (!foundAvailable) {
        cout << "No books are currently available.\n";
    }
}

Book* searchBookByID(Book* books, int numBooks, int bookID) {
    for (int i = 0; i < numBooks; i++) {
        if (books[i].bookID == bookID) {
            return &books[i];  
        }
    }
    return nullptr;  // Return null if not found
}

void removeBook(Book* &books, int &numBooks, int bookID) {
    Book* bookToRemove = searchBookByID(books, numBooks, bookID);
    if (bookToRemove != nullptr) {
        int indexToRemove = bookToRemove - books; 
        for (int i = indexToRemove; i < numBooks - 1; i++) {
            books[i] = books[i + 1];  
        }

        numBooks--;
        Book* temp = new Book[numBooks];  
        for (int i = 0; i < numBooks; i++) {
            temp[i] = books[i];  
        }

        delete[] books;  
        books = temp;  
        cout << "Book removed successfully.\n";
    } else {
        cout << "Book with ID " << bookID << " not found.\n";
    }
}

void addBook(Book* &books, int &numBooks) {
    Book* temp = new Book[numBooks + 1];  
    for (int i = 0; i < numBooks; i++) {
        temp[i] = books[i];  
    }

    delete[] books;  
    books = temp; 

    cout << "\nEnter details for the new book:\n";
    inputBookDetails(books[numBooks]); 
    numBooks++;  
    cout << "Book added successfully.\n";
}

int main() {
    int numBooks = 0;  
    Book* books = nullptr;  
    int choice;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add a new book\n";
        cout << "2. Remove a book\n";
        cout << "3. Search for a book by ID\n";
        cout << "4. Display all available books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(books, numBooks);
                break;
            case 2: {
                int bookID;
                cout << "Enter Book ID to remove: ";
                cin >> bookID;
                removeBook(books, numBooks, bookID);
                break;
            }
            case 3: {
                int bookID;
                cout << "Enter Book ID to search: ";
                cin >> bookID;
                Book* foundBook = searchBookByID(books, numBooks, bookID);
                if (foundBook != nullptr) {
                    displayBookDetails(*foundBook);
                } else {
                    cout << "Book with ID " << bookID << " not found.\n";
                }
                break;
            }
            case 4:
                displayAvailableBooks(books, numBooks);
                break;
            case 5:
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);

    delete[] books;  
    return 0;
}

