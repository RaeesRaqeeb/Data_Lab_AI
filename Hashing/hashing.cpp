#include <iostream>
#include <string>

using namespace std;

// Book class definition
class Book
{
public:
    string isbn;
    string title;
    string author;
    int publicationYear;

    Book(string isbn, string title, string author, int year)
        : isbn(isbn), title(title), author(author), publicationYear(year) {}
};

// Node class for the linked list (separate chaining)
class Node
{
public:
    Book *book;
    Node *next;

    Node(Book *book) : book(book), next(nullptr) {}
};

// HashTable class using separate chaining
class HashTable
{
private:
    Node **table;
    int size;

    // Simple hash function for ISBN
    int hashFunction(string isbn)
    {
        unsigned long hash = 0;
        for (char ch : isbn)
        {
            hash = (hash * 31) + ch;
        }
        return hash % size;
    }

public:
    // Constructor
    HashTable(int tableSize)
    {
        size = tableSize;
        table = new Node *[size];
        for (int i = 0; i < size; i++)
            table[i] = nullptr;
    }

    // Insert a new book into the hash table
    void insert(Book *book)
    {
        int index = hashFunction(book->isbn);
        Node *newNode = new Node(book);
        newNode->next = table[index];
        table[index] = newNode;
        cout << "Book \"" << book->title << "\" inserted successfully.\n";
    }

    // Search for a book by ISBN
    Book *search(string isbn)
    {
        int index = hashFunction(isbn);
        Node *curr = table[index];
        while (curr != nullptr)
        {
            if (curr->book->isbn == isbn)
                return curr->book;
            curr = curr->next;
        }
        return nullptr;
    }

    // Delete a book by ISBN
    void deleteBook(string isbn)
    {
        int index = hashFunction(isbn);
        Node *curr = table[index];
        Node *prev = nullptr;

        while (curr != nullptr && curr->book->isbn != isbn)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr)
        {
            cout << "Book with ISBN " << isbn << " not found.\n";
            return;
        }

        if (prev == nullptr)
            table[index] = curr->next;
        else
            prev->next = curr->next;

        cout << "Book \"" << curr->book->title << "\" deleted successfully.\n";
        delete curr->book;
        delete curr;
    }

    // Destructor to clean up memory
    ~HashTable()
    {
        for (int i = 0; i < size; i++)
        {
            Node *curr = table[i];
            while (curr != nullptr)
            {
                Node *temp = curr;
                curr = curr->next;
                delete temp->book;
                delete temp;
            }
        }
        delete[] table;
    }
};

int main()
{
    HashTable library(10);
    int choice;
    string isbn, title, author;
    int year;

    do
    {
        cout << "\nLibrary Management System Menu:\n";
        cout << "1. Insert a new book\n";
        cout << "2. Search for a book by ISBN\n";
        cout << "3. Delete a book by ISBN\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        cin.ignore(); // To consume the newline character after reading choice

        switch (choice)
        {
        case 1:
            cout << "Enter ISBN: ";
            getline(cin, isbn);
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            cout << "Enter Publication Year: ";
            cin >> year;
            cin.ignore(); // Consume newline
            library.insert(new Book(isbn, title, author, year));
            break;
        case 2:
            cout << "Enter ISBN to search: ";
            getline(cin, isbn);
            {
                Book *book = library.search(isbn);
                if (book != nullptr)
                {
                    cout << "\nBook found:\n";
                    cout << "ISBN: " << book->isbn << endl;
                    cout << "Title: " << book->title << endl;
                    cout << "Author: " << book->author << endl;
                    cout << "Publication Year: " << book->publicationYear << endl;
                }
                else
                {
                    cout << "Book with ISBN " << isbn << " not found.\n";
                }
            }
            break;
        case 3:
            cout << "Enter ISBN to delete: ";
            getline(cin, isbn);
            library.deleteBook(isbn);
            break;
        case 4:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 4.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}