#include <iostream>
#include "Library.h"
#include "Utils.h"

using namespace std;

void showMainMenu()
{
    cout << "===== Library Management System =====" << endl;
    cout << "1. Admin Login" << endl;
    cout << "2. Reader Login" << endl;
    cout << "3. Reader Register" << endl;
    cout << "0. Exit" << endl;
    cout << "Please choose:";
}

int main()
{
    Library lib;
    //初始化一个管理员
    Admin admin("admin", "123456", "SystemAdmin");
    lib.setAdmin(admin);

    //初始化几本图书测试数据
    lib.addBook(Book("B001", "C++ Primer", "Lippman", 5));
    lib.addBook(Book("B002", "Data Structures", "YanWeimin", 3));

    //测试读者
    lib.addReader(Reader("r001", "111111", "ZhangSan", 3));

    int choice;
    while (true)
    {
        Utils::clearScreen();
        showMainMenu();
        cin >> choice;
        if (choice == 0)
        {
            cout << "System Exit!" << endl;
            break;
        }
        else if (choice == 1)
        {
            string acc, pwd;
            cout << "\nAdmin Login\nAccount: ";
            cin >> acc;
            cout << "Password: ";
            cin >> pwd;
            if (acc == "admin" && pwd == "123456")
            {
                cout << "Admin login success!" << endl;
                int adminChoice;
                while (true)
                {
                    Utils::clearScreen();
                    cout << "\n===== Admin Menu =====\n";
                    cout << "1. Add Book\n";
                    cout << "2. Delete Book\n";
                    cout << "3. Modify Book\n";
                    cout << "4. Query Book\n";
                    cout << "0. Back to Main Menu\n";
                    cout << "Please choose:";
                    cin >> adminChoice;

                    if (adminChoice == 0)
                    {
                        break; // 返回主菜单
                    }
                    else if (adminChoice == 1)
                    {
                        string bookId, title, author;
                        int stock;
                        cout << "\n==== Add New Book ====\n";
                        cout << "Enter book ID: ";
                        cin >> bookId;
                        cout << "Enter book title: ";
                        cin >> title;
                        cout << "Enter author: ";
                        cin >> author;
                        cout << "Enter stock quantity: ";
                        cin >> stock;

                        Book newBook(bookId, title, author, stock);
                        lib.addBook(newBook);
                        cout << "\nBook added successfully!\n";
                    }
                    else if (adminChoice == 2)
                    {
                        string bookId;
                        cout << "\n==== Delete Book ====\n";
                        cout << "Enter book ID to delete: ";
                        cin >> bookId;
                        if (lib.delBook(bookId))
                            cout << "\nBook deleted!\n";
                        else
                            cout << "\nBook not found!\n";
                    }
                    else if (adminChoice == 3)
                    {
                        string bookId, newTitle, newAuthor;
                        int newStock;
                        cout << "\n==== Modify Book ====\n";
                        cout << "Enter book ID: ";
                        cin >> bookId;
                        cout << "New title: ";
                        cin >> newTitle;
                        cout << "New author: ";
                        cin >> newAuthor;
                        cout << "New stock: ";
                        cin >> newStock;
                        if (lib.modifyBook(bookId, newTitle, newAuthor, newStock))
                            cout << "\nBook modified!\n";
                        else
                            cout << "\nBook not found!\n";
                    }
                    else if (adminChoice == 4)
                    {
                        cout << "\n===== Book List =====\n";
                        vector<Book>& bookList = lib.getAllBooks();
                        if (bookList.empty())
                        {
                            cout << "No books available.\n";
                        }
                        else
                        {
                            for (auto& b : bookList)
                            {
                                cout << "ID: " << b.getId() << endl;
                                cout << "Name: " << b.getName() << endl;
                                cout << "Author: " << b.getAuthor() << endl;
                                cout << "Stock: " << b.getStock() << endl;
                                cout << "--------------------\n";
                            }
                        }
                    }
                    else
                    {
                        cout << "\nInvalid option!\n";
                    }
                    cout << "\nPress any key to continue...";
                    cin.ignore();
                    cin.get();
                }
            }
            system("pause");
        }

        else if (choice == 2)
        {
            string acc, pwd;
            cout << "\nReader Login\nAccount: ";
            cin >> acc;
            cout << "Password: ";
            cin >> pwd;

            Reader* r = lib.findReader(acc);
            if (r != nullptr && r->getPassword() == pwd)
            {
                cout << "Reader login success! Welcome " << r->getName() << endl;
                int readerChoice;
                while (true)
                {
                    cout << "\n==== Reader Menu ====\n";
                    cout << "1. Search books\n";
                    cout << "2. Borrow book\n";
                    cout << "3. Return book\n";
                    cout << "4. View borrow records\n";
                    cout << "0. Logout (back main menu)\n";
                    cout << "Please choose: ";
                    cin >> readerChoice;

                    if (readerChoice == 0)
                    {
                        cout << "Logout success!\n";
                        break;
                    }
                    else if (readerChoice == 1)
                    {
                        // Search books
                        string bid;
                        cout << "Enter book ID: ";
                        cin >> bid;
                        Book* b = lib.findBook(bid);
                        if (b != nullptr)
                        {
                            cout << "Title: " << b->getName() << ", Stock: " << b->getStock() << endl;
                        }
                        else
                        {
                            cout << "Book not found." << endl;
                        }
                        system("pause");
                    }
                    else if (readerChoice == 2)
                    {
                        // Borrow book
                        string bid;
                        cout << "Enter book ID to borrow: ";
                        cin >> bid;
                        bool res = lib.borrowBook(acc, bid);
                        if (res)
                        {
                            cout << "Borrow success!\n";
                        }
                        else
                        {
                            cout << "Borrow failed! (No book / out of stock / already borrowed)\n";
                        }
                        system("pause");
                    }
                    else if (readerChoice == 3)
                    {
                        // Return book
                        string bid;
                        cout << "Enter book ID to return: ";
                        cin >> bid;
                        bool res = lib.returnBook(acc, bid);
                        if (res)
                        {
                            cout << "Return success!\n";
                        }
                        else
                        {
                            cout << "Return failed! No valid borrow record.\n";
                        }
                        system("pause");
                    }
                    else if (readerChoice == 4)
                    {
                        // View borrow records
                        lib.showReaderRecords(acc);
                        system("pause");
                    }
                    else
                    {
                        cout << "Invalid option!\n";
                        system("pause");
                    }
                }
            }
            else
            {
                cout << "Account or password wrong!\n";
                system("pause");
            }
        }

        else if (choice == 3)
        {
            string acc, pwd, name;
            cout << "\n==== Reader Register ====\n";
            cout << "Account: ";
            cin >> acc;
            if (lib.findReader(acc) != nullptr)
            {
                cout << "This account already exists!\n";
                system("pause");
            }
            else
            {
                cout << "Password: ";
                cin >> pwd;
                cout << "Name: ";
                cin >> name;
                Reader newR(acc, pwd, name, 3);
                lib.addReader(newR);
                cout << "Register success! You can login now.\n";
                system("pause");
            }
        }

        else
        {
            cout << "Invalid option!" << endl;
            system("pause");
        }
    }
    return 0;
}
