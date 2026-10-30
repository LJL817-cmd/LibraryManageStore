#pragma once
#include "User.h"

class Reader : public User
{
public:
    Reader();
    Reader(string account, string password, string name, int maxBorrow);

    void setMaxBorrow(int max);
    int getMaxBorrow() const;

private:
    int m_maxBorrow;
};
