// A basic C++ program that manages a bookshop inventory

// Header files
#include <cctype>    //for converting to lowercase
#include <algorithm> //for transform
#include <iostream>  //standard
#include <fstream>   //io stream
#include <iomanip>   //for table style output
using namespace std;

#define MAX 50

// Book class to handle all member functions and variables
class Book
{
private:
    int book_id;
    string book_title;
    string book_author;
    string book_genre;
    int book_price;

public:
    void addBook();
    void deleteBook();

    int getId();
    string getTitle();
    string getAuthor();
    string getGenre();
    int getPrice();
};

void Book::addBook() // Add book to array
{
    cout << "Enter Book name: ";
    cin >> book_title;
    transform(book_title.begin(), book_title.end(), book_title.begin(), ::tolower);

    cout << "Enter Book id: ";
    cin >> book_id;

    cout << "Enter Book author: ";
    cin >> book_author;
    transform(book_author.begin(), book_author.end(), book_author.begin(), ::tolower);

    cout << "Enter Book genre: ";
    cin >> book_genre;
    transform(book_genre.begin(), book_genre.end(), book_genre.begin(), ::tolower);

    cout << "Enter Book price: ";
    cin >> book_price;
}

void Book::deleteBook() // Delete book from array
{
}

int Book::getId()
{
    return book_id;
}

string Book::getTitle()
{
    return book_title;
}
string Book::getAuthor()
{
    return book_author;
}
string Book::getGenre()
{
    return book_genre;
}
int Book::getPrice()
{
    return book_price;
}

void printHeader()
{

    cout
        << left
        << setw(15)
        << "Title"
        << left
        << setw(15)
        << "Id"
        << left
        << setw(15)
        << "Author"
        << left
        << setw(15)
        << "Genre"
        << left
        << setw(10)
        << "Price"
        << endl;
    cout << "---------------------------------------------------------------------------" << endl;
}

void printHeader(int ch)
{
    string outFile = "book_details.txt";
    ofstream hout;
    hout.open(outFile, std::ios::out);

    hout
        << left
        << setw(15)
        << "Title"
        << left
        << setw(15)
        << "Id"
        << left
        << setw(15)
        << "Author"
        << left
        << setw(15)
        << "Genre"
        << left
        << setw(15)
        << "Price"
        << endl;
    hout << "---------------------------------------------------------------------------" << endl;
}

void displayBook(Book book)
{
    printHeader();
    cout
        << left
        << setw(15)
        << book.getTitle()
        << left
        << setw(15)
        << book.getId()
        << left
        << setw(15)
        << book.getAuthor()
        << left
        << setw(15)
        << book.getGenre()
        << left
        << setw(15)
        << book.getPrice()
        << endl;
}

void displayBook(Book arr[], int s) // Display all books in console window
{
    for (int i = 0; i < s; i++)
    {
        cout
            << left
            << setw(15)
            << arr[i].getTitle()
            << left
            << setw(15)
            << arr[i].getId()
            << left
            << setw(15)
            << arr[i].getAuthor()
            << left
            << setw(15)
            << arr[i].getGenre()
            << left
            << setw(15)
            << arr[i].getPrice()
            << endl;
    }
}

void displayBook(Book arr[], int s, int ch) // Display all books in txt file
{
    string outFile = "book_details.txt";
    ofstream out;
    out.open(outFile, ios::app);
    printHeader(1);
    for (int i = 0; i < s; i++)
    {
        out
            << left
            << setw(15)
            << arr[i].getTitle()
            << left
            << setw(15)
            << arr[i].getId()
            << left
            << setw(15)
            << arr[i].getAuthor()
            << left
            << setw(15)
            << arr[i].getGenre()
            << left
            << setw(15)
            << arr[i].getPrice()
            << endl;
    }

    out.close();
}

void clearFile()
{
    string outFile = "book_details.txt";
    ofstream out;
    out.open(outFile, ios::out);
    out << "";
    out.close();
}

void searchBook(Book arr[], string s2, int n) // Find book in array
{
    for (int i = 0; i < n; i++)
    {
        if (s2.compare(arr[i].getTitle()) == 0)
        {
            cout << "Book found!" << endl;
            displayBook(arr[i]);
            break;
        }
    }
}

// Driver
int main()
{
    int booksAdded = 0;

    Book book[MAX];
    while (true)
    {
        int ch;
        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << "Enter your choice\n1. Add books\n2. Delete book\n3. Find book\n4. Display books\n5. Print file\n6. Clear file\n7. Exit\n";
        cin >> ch;
        cout << "------------------------------------------------------------------------------------------------" << endl;
        switch (ch)
        {
        case 1: // Add book
            int n;
            cout << "Enter number of books to add: ";
            cin >> n;
            cout << "------------------------------------------------------------------------------------------------" << endl;
            while (n--)
            {
                cout << "\nEnter details for book " << booksAdded + 1 << endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                book[booksAdded].addBook();
                booksAdded++;
            }
            break;

        case 2: // Delete
            break;

        case 3: // Search
        {
            string name;
            cout << "Enter name of book to search: ";
            cin >> name;
            transform(name.begin(), name.end(), name.begin(), ::tolower);
            searchBook(book, name, booksAdded);
            break;
        }

        case 4: // Display
            printHeader();
            displayBook(book, booksAdded);
            break;

        case 5: // Print text file
        {
            cout << "Printing..." << endl;
            try
            {
                displayBook(book, booksAdded, 1);
            }
            catch (exception &e)
            {
                cout << e.what() << endl;
            }
            cout << "Printed successfully!" << endl;
            break;
        }

        case 6: // Erase text file
        {
            clearFile();
            break;
        }

        default:
            return false;
        }
    }

    return 0;
}