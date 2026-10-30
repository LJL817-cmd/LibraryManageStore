#pragma once
#include <string>
using namespace std;

class User
{
public:
    User();
    User(string account, string password, string name);

    void setAccount(string account);
    void setPassword(string password);
    void setName(string name);

    string getAccount() const;
    string getPassword() const;
    string getName() const;

protected:
    string m_account;
    string m_password;
    string m_name;
};