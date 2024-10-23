#ifndef ADMIN_H
#define ADMIN_H

#include "User.h" 
#include "../System/System.h"

class System;
class Admin: public User{
    private:
    public:
        Admin();
        Admin(std::string username_ip, std::string password_ip);

        bool adminLogin(std::string username, std::string pwd);
        
        int viewMember(System &sys);
        int viewMotorbike(System &sys);
};

#endif

