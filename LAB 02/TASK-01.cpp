#include <iostream>
using namespace std;

struct BOOKS {
    string title;
    string author;
    int year;
};

void allocateBooks(BOOKS **b, int num){
    *b = new BOOKS[num];
}

void inputValues (BOOKS *b, int num){
    for (int i = 0; i < num; i++){
        cout << "---Details of the books " << i + 1 << "---" << endl;
        cout << "Enter the title of the book: ";
        cin >> b[i].title;
        cout << "Enter the author of the book: ";
        cin >> b[i].author;
        cout << "Enter the year of the book: ";
        cin >> b[i].year;
    }
}

void displayValuesByYear(BOOKS *b, int num){
    int year;
    cout << "Enter the year to display the books: ";
    cin >> year;
        cout << "---Details of the books with year " << year << "---" << endl;
    for (int i = 0, j = 0; i < num; i++){
        if (b[i].year > year){j++;
        cout << "--BOOK " << j << "--" << endl;
            cout << "Title: " << b[i].title << endl;
            cout << "author: " << b[i].author << endl;
            cout << "year: " << b[i].year << endl;
        }
    }
}

void freeMemory(BOOKS *b){
    delete [] b;
}

int main (){
    int num;
    BOOKS *b;
    
    cout << "Enter the number of books: ";
    cin >> num;

    allocateBooks(&b, num);
    inputValues(b, num);
    displayValuesByYear(b, num);
    freeMemory(b);

}
