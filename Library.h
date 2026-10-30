#pragma once
#include "Book.h"
#include "Reader.h"
#include "Admin.h"
#include "BorrowRecord.h"
#include <vector>
#include <string>
using namespace std;

class Library
{
public:
    Library();

    //图书操作
    void addBook(const Book& b);
    bool delBook(string bookId);
    Book* findBook(string bookId);
    vector<Book>& getAllBooks();
    bool modifyBook(string bookId, string newTitle, string newAuthor, int newStock);

    //读者
    void addReader(const Reader& r);
    Reader* findReader(string account);

    //管理员
    void setAdmin(const Admin& a);
    Admin* getAdmin();

    //借阅记录
    void addBorrowRecord(const BorrowRecord& rec);
    vector<BorrowRecord>& getAllRecords();

    //===== 新增借还书、查看记录函数声明 =====
    bool borrowBook(string readerAcc, string bookId);
    bool returnBook(string readerAcc, string bookId);
    void showReaderRecords(string readerAcc);


private:
    vector<Book> m_bookList;
    vector<Reader> m_readerList;
    Admin m_admin;
    vector<BorrowRecord> m_recordList;
};
