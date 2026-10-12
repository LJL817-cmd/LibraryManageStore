#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Media//基类
{
public:
    string id;
    string name;
};
//派生类Book,公有继承Media
class Book:public Media
{
public:
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