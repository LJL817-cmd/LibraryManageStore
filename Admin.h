#pragma once
#include "User.h"

class Admin : public User
{
public:
    Admin();
    Admin(string account, string password, string name);

    //管理员权限标记
    bool isAdmin() const;
};
