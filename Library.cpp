#include "Library.h"
#include <iostream>
using namespace std;

Library::Library()
{}

void Library::addBook(const Book& b)
{
    m_bookList.push_back(b);
}

bool Library::delBook(string bookId)
{
    for (auto it = m_bookList.begin(); it != m_bookList.end(); ++it)
    {
        if (it->getId() == bookId)
        {
            m_bookList.erase(it);
            return true;
        }
    }
    return false;
}

Book* Library::findBook(string bookId)
{
    for (auto& b : m_bookList)
    {
        if (b.getId() == bookId)
        {
            return &b;
        }
    }
    return nullptr;
}

vector<Book>& Library::getAllBooks()
{
    return m_bookList;
}

bool Library::modifyBook(string bookId, string newTitle, string newAuthor, int newStock)
{
    Book* p = findBook(bookId);
    if (p == nullptr)
    {
        return false;
    }
    p->setName(newTitle);
    p->setAuthor(newAuthor);
    p->setStock(newStock);
    return true;
}

void Library::addReader(const Reader& r)
{
    m_readerList.push_back(r);
}

Reader* Library::findReader(string account)
{
    for (auto& r : m_readerList)
    {
        if (r.getAccount() == account)
        {
            return &r;
        }
    }
    return nullptr;
}

void Library::setAdmin(const Admin& a)
{
    m_admin = a;
}

Admin* Library::getAdmin()
{
    return &m_admin;
}

void Library::addBorrowRecord(const BorrowRecord& rec)
{
    m_recordList.push_back(rec);
}

vector<BorrowRecord>& Library::getAllRecords()
{
    return m_recordList;
}

//借书
bool Library::borrowBook(string readerAcc, string bookId)
{
    Book* pBook = findBook(bookId);
    Reader* pReader = findReader(readerAcc);
    if (pBook == nullptr || pReader == nullptr)
        return false;
    if (pBook->getStock() <= 0)
        return false;

    //检查：这本书是否已经借了还没还
    auto& records = getAllRecords();
    for (auto& rec : records)
    {
        if (rec.getReaderAccount() == readerAcc
            && rec.getBookId() == bookId
            && rec.getReturnDate() == "") //returnDate为空=未归还
        {
            return false;
        }
    }
    //库存-1
    pBook->setStock(pBook->getStock() - 1);
    //新建借阅记录，归还日期初始为空字符串
    BorrowRecord newRec(readerAcc, bookId, "2026-10-30", "");
    addBorrowRecord(newRec);
    return true;
}

//还书
bool Library::returnBook(string readerAcc, string bookId)
{
    Book* pBook = findBook(bookId);
    if (pBook == nullptr)
        return false;

    auto& records = getAllRecords();
    for (auto& rec : records)
    {
        if (rec.getReaderAccount() == readerAcc
            && rec.getBookId() == bookId
            && rec.getReturnDate() == "")
        {
            //找到这条未归还记录，设置归还日期
            rec.setReturnDate("2026-10-30");
            pBook->setStock(pBook->getStock() + 1);
            return true;
        }
    }
    return false;
}

//查看借阅记录
void Library::showReaderRecords(string readerAcc)
{
    auto& records = getAllRecords();
    bool haveRecord = false;
    cout << "\n==== Your Borrow Records ====\n";
    for (auto& rec : records)
    {
        if (rec.getReaderAccount() == readerAcc)
        {
            haveRecord = true;
            Book* b = findBook(rec.getBookId());
            string status;
            if (rec.getReturnDate() == "")
            {
                status = "Borrowed";
            }
            else
            {
                status = "Returned";
            }
            cout << "BookID: " << rec.getBookId()
                << " | Name: " << b->getName()
                << " | BorrowDate: " << rec.getBorrowDate()
                << " | ReturnDate: " << rec.getReturnDate()
                << " | Status: " << status << endl;
        }
    }
    if (!haveRecord)
    {
        cout << "No borrow records.\n";
    }
}
