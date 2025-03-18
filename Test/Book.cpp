#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Book {
private:
    int bookId;
    std::string title;
    std::string author;

public:
    // Constructor
    Book(int id = 0, const std::string& t = "", const std::string& a = "") 
        : bookId(id), title(t), author(a) {}

    // Function to add a book
    void addBook() {
        std::cout << "Enter Book ID: ";
        std::cin >> bookId;
        std::cin.ignore(); // Ignore newline character after integer input
        std::cout << "Enter Title: ";
        std::getline(std::cin, title);
        std::cout << "Enter Author: ";
        std::getline(std::cin, author);
    }

    // Function to display book details
    void display() const {
        std::cout << "Book ID: " << bookId << ", Title: " << title << ", Author: " << author << std::endl;
    }

    // Function to get book ID
    int getBookId() const {
        return bookId;
    }

    // Function to write book data to file
    void writeToFile(std::ofstream& outFile) const {
        outFile.write(reinterpret_cast<const char*>(this), sizeof(Book));
    }

    // Function to read book data from file
    void readFromFile(std::ifstream& inFile) {
        inFile.read(reinterpret_cast<char*>(this), sizeof(Book));
    }
};

// Function to add a book to the file
void addBookToFile(const std::string& filename) {
    Book book;
    book.addBook();
    std::ofstream outFile(filename, std::ios::app | std::ios::binary);
    if (outFile) {
        book.writeToFile(outFile);
        outFile.close();
        std::cout << "Book added successfully!" << std::endl;
    } else {
        std::cerr << "Error opening file for writing!" << std::endl;
    }
}

// Function to display all books from the file
void displayAllBooks(const std::string& filename) {
    Book book;
    std::ifstream inFile(filename, std::ios::binary);
    if (inFile) {
        while (inFile.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
            book.display();
        }
        inFile.close();
    } else {
        std::cerr << "Error opening file for reading!" << std::endl;
    }
}

// Function to display a specific book by position
void displayBookAtPosition(const std::string& filename, std::streampos position) {
    Book book;
    std::ifstream inFile(filename, std::ios::binary);
    if (inFile) {
        inFile.seekg(position);
        if (inFile.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
            book.display();
        } else {
            std::cerr << "No book found at the specified position!" << std::endl;
        }
        inFile.close();
    } else {
        std::cerr << "Error opening file for reading!" << std::endl;
    }
}

// Function to delete a book by BookId
void deleteBookById(const std::string& filename, int bookId) {
    std::ifstream inFile(filename, std::ios::binary);
    std::vector<Book> books;
    Book book;

    // Read all books into a vector
    if (inFile) {
        while (inFile.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
            books.push_back(book);
        }
        inFile.close();
    } else {
        std::cerr << "Error opening file for reading!" << std::endl;
        return;
    }

 // Remove the book with the specified BookId
    std::ofstream outFile(filename, std::ios::binary);
    if (outFile) {
        for (const auto& b : books) {
            if (b.getBookId() != bookId) {
                b.writeToFile(outFile);
            }
        }
        outFile.close();
        std::cout << "Book with ID " << bookId << " deleted successfully!" << std::endl;
    } else {
        std::cerr << "Error opening file for writing!" << std::endl;
    }
}

int main() {
    const string filename = "books.dat";
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Display Specific Book (by position)\n";
        cout << "4. Delete Book (by Book ID)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBookToFile(filename);
                break;
            case 2:
                displayAllBooks(filename);
                break;
            case 3: {
                streamoff position;
                cout << "Enter position (in bytes) to display the book: ";
                cin >> position;
                displayBookAtPosition(filename, std::streampos(position));
                break;
            }
            case 4: {
                int bookId;
                cout << "Enter Book ID to delete: ";
                cin >> bookId;
                deleteBookById(filename, bookId);
                break;
            }
            case 5:
                cout << "Exiting the program." << std::endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
