//A basic C++ program that manages a bookshop inventory

//Header files
#include <cctype>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#define MAX 2

//Book class to handle all member functions and variables
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
    void searchBook();
    void displayBook(Book[], int);
    void printBook(Book[], int);

    int getId();
    string getTitle();
    string getAuthor();
    string getGenre();
    int getPrice();
};

void Book::addBook() //Add book to array
{
    cout << "Enter Book name" << endl;
    cin >> book_title;
    transform(book_title.begin(), book_title.end(), book_title.begin(), ::tolower);

    cout << "Enter Book id" << endl;
    cin >> book_id;

    cout << "Enter Book author" << endl;
    cin >> book_author;
    transform(book_author.begin(), book_author.end(), book_author.begin(), ::tolower);

    cout << "Enter Book genre" << endl;
    cin >> book_genre;
    transform(book_genre.begin(), book_genre.end(), book_genre.begin(), ::tolower);

    cout << "Enter Book price" << endl;
    cin >> book_price;
}

void Book::deleteBook() //Delete book from array
{
    //ksnfklewn sharal
}

void Book::searchBook() //Find book in arrat
{
}

void displayBook(Book arr[], int s) //Display all books in console window
{
    for (int i = 0; i < s; i++)
    {
        cout
            << left
            << setw(10)
            << arr[i].getTitle()
            << left
            << setw(10)
            << arr[i].getId()
            << left
            << setw(10)
            << arr[i].getAuthor()
            << left
            << setw(10)
            << arr[i].getGenre()
            << left
            << setw(10)
            << arr[i].getPrice()
            << endl;
    }
}

void printBook(Book arr[], int s) //Print all books in a text file
{
    string outFile = "book_details.txt";
    ofstream out;
    out.open(outFile, std::ios::out);

    out
        << left
        << setw(10)
        << "Title"
        << left
        << setw(10)
        << "Id"
        << left
        << setw(10)
        << "Author"
        << left
        << setw(10)
        << "Genre"
        << left
        << setw(10)
        << "Price"
        << endl;
    out << "---------------------------------------------" << endl;

    for (int i = 0; i < s; i++)
    {
        out
            << left
            << setw(10)
            << arr[i].getTitle()
            << left
            << setw(10)
            << arr[i].getId()
            << left
            << setw(10)
            << arr[i].getAuthor()
            << left
            << setw(10)
            << arr[i].getGenre()
            << left
            << setw(10)
            << arr[i].getPrice()
            << endl;
    }
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

//Driver
int main()
{
    int booksAdded = 0;

    Book book[MAX];
    while (true)
    {
        cout << "Enter your choice\n1. Add books\n2. Delete book\n3. Find book\n4. Display books\n5. Print file\n6. Exit\n";
        int ch;
        cin >> ch;
        switch (ch)
        {
        case 1: //Adding book
            book[booksAdded].addBook();
            booksAdded++;
            break;

        case 2: //Delete
            break;

        case 3: //Search
            break;

        case 4: //Display
            cout
                << left
                << setw(10)
                << "Title"
                << left
                << setw(10)
                << "Id"
                << left
                << setw(10)
                << "Author"
                << left
                << setw(10)
                << "Genre"
                << left
                << setw(10)
                << "Price"
                << endl;
            cout << "---------------------------------------------" << endl;

            displayBook(book, booksAdded);

            break;

        case 5: //Print
        {
            printBook(book, booksAdded);
            break;
        }

        default:
            return false;
        }
    }

    return 0;
}