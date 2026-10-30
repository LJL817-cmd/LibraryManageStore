#include "User.h"

User::User()
{
    m_account = "";
    m_password = "";
    m_name = "";
}

User::User(string account, string password, string name)
{
    m_account = account;
    m_password = password;
    m_name = name;
}

void User::setAccount(string account) { m_account = account; }
void User::setPassword(string password) { m_password = password; }
void User::setName(string name) { m_name = name; }

string User::getAccount() const { return m_account; }
string User::getPassword() const { return m_password; }
string User::getName() const { return m_name; }