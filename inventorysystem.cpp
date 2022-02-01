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
    cout << "Enter Book id" << endl;
    cin >> book_id;
    cout << "Enter Book author" << endl;
    cin >> book_author;
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
}
int Book::getId()
{
    return book_id;
}

int main()
{
    Book b1[MAX];
    int ch, n;
    cout << "Enter your choice"
         << "1.add books\n 2.delete book\n 3.search \n4.display\n 5.exit"
         << endl;
    cin >> ch;
    switch (ch)
    {
    case 1:
        cout << "Enter number of books" << endl;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            b1[i].addBook();
        }

        break;

    case 2:

        break;

    case 3:
        break;

    case 4:

        break;

    case 5:

        for (int i = 0; i < n; i++)
        {
            b1[i].displayBook();
        }
        break;
    default:
        break;
    }
}