#ifndef ADMIN_H
#define ADMIN_H

#include "User.h" 
#include "../System/System.h"
const int colWidth[] = {5, 10, 15, 20};       //0-13 
class System;
class Admin : public User {
    public:
        Admin();
        Admin(std::string username_ip, std::string password_ip);

        bool adminLogin(std::string username, std::string pwd);

        int viewMember(System &sys);
        int viewMotorbike(System &sys);
};

#endif

