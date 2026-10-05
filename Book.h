#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book
{
public:
    string id;
    string name;
    bool available;
    Book(string i, string n);
    void showInfo();
};

class Library
{
public:
    vector<Book> bookList;
    void addBook();
    void searchBook();
    void borrowBook();
    void returnBook();
    void menu();
};
#endif