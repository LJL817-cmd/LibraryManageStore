#include "BorrowRecord.h"

BorrowRecord::BorrowRecord()
{
    m_readerAccount = "";
    m_bookId = "";
    m_borrowDate = "";
    m_returnDate = "";
}

BorrowRecord::BorrowRecord(string readerAccount, string bookId, string borrowDate, string returnDate)
{
    m_readerAccount = readerAccount;
    m_bookId = bookId;
    m_borrowDate = borrowDate;
    m_returnDate = returnDate;
}

void BorrowRecord::setReaderAccount(string acc) { m_readerAccount = acc; }
void BorrowRecord::setBookId(string bid) { m_bookId = bid; }
void BorrowRecord::setBorrowDate(string date) { m_borrowDate = date; }
void BorrowRecord::setReturnDate(string date) { m_returnDate = date; }

string BorrowRecord::getReaderAccount() const { return m_readerAccount; }
string BorrowRecord::getBookId() const { return m_bookId; }
string BorrowRecord::getBorrowDate() const { return m_borrowDate; }
string BorrowRecord::getReturnDate() const { return m_returnDate; }