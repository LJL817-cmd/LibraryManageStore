#pragma once
#include <string>
using namespace std;

class BorrowRecord
{
public:
    BorrowRecord();
    BorrowRecord(string readerAccount, string bookId, string borrowDate, string returnDate);

    void setReaderAccount(string acc);
    void setBookId(string bid);
    void setBorrowDate(string date);
    void setReturnDate(string date);

    string getReaderAccount() const;
    string getBookId() const;
    string getBorrowDate() const;
    string getReturnDate() const;

private:
    string m_readerAccount;
    string m_bookId;
    string m_borrowDate;
    string m_returnDate;
};
