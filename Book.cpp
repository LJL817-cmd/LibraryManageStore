#include "Book.h"

Book::Book()
{
    m_id = "";
    m_name = "";
    m_author = "";
    m_stock = 0;
}

Book::Book(string id, string name, string author, int stock)
{
    m_id = id;
    m_name = name;
    m_author = author;
    m_stock = stock;
}

void Book::setId(string id) { m_id = id; }
void Book::setName(string name) { m_name = name; }
void Book::setAuthor(string author) { m_author = author; }
void Book::setStock(int stock) { m_stock = stock; }

string Book::getId() const { return m_id; }
string Book::getName() const { return m_name; }
string Book::getAuthor() const { return m_author; }
int Book::getStock() const { return m_stock; }