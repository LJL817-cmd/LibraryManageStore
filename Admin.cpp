#include "Admin.h"

Admin::Admin() : User()
{

}

Admin::Admin(string account, string password, string name)
    : User(account, password, name)
{

}

bool Admin::isAdmin() const
{
    return true;
}