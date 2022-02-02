#include <cctype>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
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
    void displayBook();
    void printBook();
    int getId();
    string getTitle();
    string getAuthor();
    string getGenre();
    int getPrice();
};
void Book::addBook()
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

void Book::deleteBook()
{
}

void Book::searchBook()
{
}

void Book::displayBook()
{
    cout << "\n\nName: " << book_title << endl;
    cout << "Id: " << book_id << endl;
    cout << "Author: " << book_author << endl;
    cout << "Genre: " << book_genre << endl;
    cout << "Price: " << book_price << endl;
}

void printBook(Book arr[], int s)
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

int main()
{
    Book b1[1];
    while (true)
    {
        cout << "Enter your choice\n1. Add books\n2. Delete book\n3. Find book\n4. Display books\n5. Print file\n6. Exit\n";
        int ch, n;
        cin >> ch;
        switch (ch)
        {
        case 1: //Adding book
            cout << "Enter number of books" << endl;
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                b1[i].addBook();
            }
            break;

        case 2: //Delete
            break;

        case 3: //Search
            break;

        case 4: //Display
            for (int i = 0; i < n; i++)
            {
                b1[i].displayBook();
            }
            break;

        case 5: //Print
        {
            int len = sizeof(b1) / sizeof(b1[0]);
            printBook(b1, len);
            break;
        }

        default:
            exit(0);
        }
    }
}