#include "Reader.h"

Reader::Reader() : User()
{
    m_maxBorrow = 3;
}

Reader::Reader(string account, string password, string name, int maxBorrow)
    : User(account, password, name)
{
    m_maxBorrow = maxBorrow;
}

void Reader::setMaxBorrow(int max)
{
    m_maxBorrow = max;
}

int Reader::getMaxBorrow() const
{
    return m_maxBorrow;
}