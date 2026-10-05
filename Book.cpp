#include "Book.h"

Book::Book(string i, string n)
{
    id = i;
    name = n;
    available = true;
}

void Book::showInfo()
{
    cout << "ID:" << id << " Name:" << name;
    if (available)
        cout << " Status:Available" << endl;
    else
        cout << " Status:Borrowed" << endl;
}

void Library::addBook()
{
    string bid, bname;
    cout << "Input book id:";
    cin >> bid;
    cout << "Input book name:";
    cin >> bname;
    bookList.emplace_back(bid, bname);
    cout << "Add success!" << endl;
}

void Library::searchBook()
{
    string bid;
    cout << "Input book id to search:";
    cin >> bid;
    for (auto& b : bookList)
    {
        if (b.id == bid)
        {
            b.showInfo();
            return;
        }
    }
    cout << "Book not found!" << endl;
}

void Library::borrowBook()
{
    string bid;
    cout << "Input book id to borrow:";
    cin >> bid;
    for (auto& b : bookList)
    {
        if (b.id == bid)
        {
            if (b.available)
            {
                b.available = false;
                cout << "Borrow success!" << endl;
            }
            else
            {
                cout << "This book is borrowed!" << endl;
            }
            return;
        }
    }
    cout << "Book not found!" << endl;
}

void Library::returnBook()
{
    string bid;
    cout << "Input book id to return:";
    cin >> bid;
    for (auto& b : bookList)
    {
        if (b.id == bid)
        {
            b.available = true;
            cout << "Return success!" << endl;
            return;
        }
    }
    cout << "Book not found!" << endl;
}

void Library::menu()
{
    int op;
    while (true)
    {
        cout << "\n====Library System====" << endl;
        cout << "1 Add Book" << endl;
        cout << "2 Search Book" << endl;
        cout << "3 Borrow Book" << endl;
        cout << "4 Return Book" << endl;
        cout << "0 Exit" << endl;
        cout << "Please choose:";
        cin >> op;
        switch (op)
        {
        case 1: addBook(); break;
        case 2: searchBook(); break;
        case 3: borrowBook(); break;
        case 4: returnBook(); break;
        case 0: cout << "Exit program" << endl; return;
        default: cout << "Wrong input!" << endl;
        }
    }
}

int main()
{
    Library lib;
    lib.menu();
    return 0;
}