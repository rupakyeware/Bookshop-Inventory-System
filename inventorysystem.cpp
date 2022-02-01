#include <cctype>
#include <string>
#include <algorithm>
#include <iostream>

#define MAX 20
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
    int getId();
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
    cout << "Name: " << book_title << endl;
    cout << "Id: " << book_id << endl;
    cout << "Author: " << book_author << endl;
    cout << "Genre: " << book_genre << endl;
    cout << "Price: " << book_price << endl;
}

int Book::getId()
{
    return book_id;
}

int main()
{
    Book b1[MAX];
    while (true)
    {
        cout << "Enter your choice\n1. Add books\n2. Delete book\n3. Find book\n4. Print books\n5. Exit\n";
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

        case 5: //Exit
            break;

        default:
            break;
        }
    }
}