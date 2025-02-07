#include <iostream>
#include <algorithm>
using namespace std;

class Library {
    private:
        string bookList[100];
        string borrowedBooks[100];
        string availableBooks[100];
        int bookCount;
        int borrowedCount;
        int availableCount;
    public:
        Library() {
            bookCount = 0;
            borrowedCount = 0;
            availableCount = 0;
        }

        void addBook(const string& book) {
            bookList[bookCount++] = book;
            availableBooks[availableCount++] = book;
        }

        void lendBook(const string& book) {
            for (int i = 0; i < availableCount; ++i) {
                if (availableBooks[i] == book) {
                    borrowedBooks[borrowedCount++] = book;
                    for (int j = i; j < availableCount - 1; ++j) {
                        availableBooks[j] = availableBooks[j + 1];
                    }
                    --availableCount;
                    cout << "Book borrowed: " << book << endl;
                    return;
                }
            }
            cout << "Book not available: " << book << endl;
        }

        void returnBook(const string& book) {
            for (int i = 0; i < borrowedCount; ++i) {
                if (borrowedBooks[i] == book) {
                    availableBooks[availableCount++] = book;
                    for (int j = i; j < borrowedCount - 1; ++j) {
                        borrowedBooks[j] = borrowedBooks[j + 1];
                    }
                    --borrowedCount;
                    cout << "Book returned: " << book << endl;
                    return;
                }
            }
            cout << "Book not borrowed: " << book << endl;
        }

        void displayAvailableBooks() const {
            cout << endl << "--- Available books --- " << endl;
            for (int i = 0; i < availableCount; ++i) {
                cout << i + 1 << ". " << availableBooks[i] << endl;
            }
            cout << endl;
        }
};

int main() {
    Library myLibrary;
    while (true) {
        cout << "1. Add Book" << endl;
        cout << "2. Lend Book" << endl;
        cout << "3. Return Book" << endl;
        cout << "4. Display Available Books" << endl;
        cout << "0. Exit" << endl;
        
        int choice;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character left in the buffer
        
        switch (choice) {
            case 1: {
                string book;
                cout << "Enter book name: ";
                getline(cin, book);
                myLibrary.addBook(book);
                break;
            }
            case 2: {
                string book;
                cout << "Enter book name: ";
                getline(cin, book);
                myLibrary.lendBook(book);
                break;
            }
            case 3: {
                string book;
                cout << "Enter book name: ";
                getline(cin, book);
                myLibrary.returnBook(book);
                break;
            }
            case 4:
                myLibrary.displayAvailableBooks();
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }

    return 0;
}

