#pragma once
#include <string>
using namespace std;

class Book
{
public:
    Book();
    Book(string id, string name, string author, int stock);

    void setId(string id);
    void setName(string name);
    void setAuthor(string author);
    void setStock(int stock);

    string getId() const;
    string getName() const;
    string getAuthor() const;
    int getStock() const;

private:
    string m_id;
    string m_name;
    string m_author;
    int m_stock;
};
