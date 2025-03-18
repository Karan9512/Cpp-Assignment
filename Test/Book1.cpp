#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Book {
public:
    int BookId;
    string Title;
    string Author;

    // Constructor
    Book(int id = 0, const string& title = "", const string& author = "")
        : BookId(id), Title(title), Author(author) {}

    // Function to write book data to a file
    void writeToFile(ofstream& outFile) const {
        outFile << BookId << "\n" << Title << "\n" << Author << "\n";
    }

    // Function to read book data from a file
    void readFromFile(ifstream& inFile) {
        inFile >> BookId;
        inFile.ignore(); // Ignore the newline after BookId
        getline(inFile, Title);
        getline(inFile, Author);
    }
};

class BookManager {
private:
    const string filename = "books.txt";

public:
    void addBook(const Book& book) {
        ofstream outFile(filename, ios::app);
        if (outFile) {
            book.writeToFile(outFile);
            cout << "Book added successfully.\n";
        } else {
            cerr << "Error opening file for writing.\n";
        }
    }

    void displayAllBooks() {
        ifstream inFile(filename);
        if (inFile) {
            Book book;
            while (inFile.peek() != EOF) {
                book.readFromFile(inFile);
                cout << "Book ID: " << book.BookId << ", Title: " << book.Title << ", Author: " << book.Author << "\n";
            }
        } else {
            cerr << "Error opening file for reading.\n";
        }
    }

    void displayBookAtPosition(int pos) {
        ifstream inFile(filename);
        if (inFile) {
            Book book;
            int currentPos = 0;
            while (inFile.peek() != EOF) {
                book.readFromFile(inFile);
                if (currentPos == pos) {
                    cout << "Book ID: " << book.BookId << ", Title: " << book.Title << ", Author: " << book.Author << "\n";
                    return; // Exit after displaying the book at the specified position
                }
                currentPos++;
            }
            cout << "No book found at position " << pos << ".\n"; // Handle case where position is out of bounds
        } else {
            cerr << "Error opening file for reading.\n";
        }
    }

    void deleteBookById(int bookId) {
        ifstream inFile(filename);
        vector<Book> books;
        if (inFile) {
            Book book;
            while (inFile.peek() != EOF) {
                book.readFromFile(inFile);
                books.push_back(book);
            }
        } else {
            cerr << "Error opening file for reading.\n";
            return;
        }

        ofstream outFile(filename);
        if (outFile) {
            for (const auto& b : books) {
                if (b.BookId != bookId) {
                    b.writeToFile(outFile);
                }
            }
            cout << "Book with ID " << bookId << " deleted successfully.\n";
        } else {
            cerr << "Error opening file for writing.\n";
        }
    }
};

int main() {
    BookManager manager;
    int choice;

    while (true) {
        cout << "1. Add Book\n2. Display All Books\n3. Display Book at Position\n4. Delete Book by ID\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                string title, author;
                cout << "Enter Book ID: ";
                cin >> id;
                cin.ignore(); // Ignore the newline after ID
                cout << "Enter Title: ";
                getline(cin, title);
                cout << "Enter Author: ";
                getline(cin, author);
                manager.addBook(Book(id, title, author));
                break;
            }
            case 2:
                manager.displayAllBooks();
                break;
            case 3: {
                int pos;
                cout << "Enter position: ";
                cin >> pos;
                manager.displayBookAtPosition(pos);
                break;
            }
            case 4: {
                int id;
                cout << "Enter Book ID to delete: ";
                cin >> id;
                manager.deleteBookById(id);
                break;
            }
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
