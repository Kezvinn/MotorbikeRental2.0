#ifndef ADMIN_H
#define ADMIN_H

#include "User.h" 
#include "../System/System.h"
class System;
class Admin : public User {
    public:
        // Default constructor
        Admin();
        // Parameterized constructor
        Admin(std::string username_ip, std::string password_ip);
        // Admin login
        bool adminLogin(std::string username, std::string pwd);
        // View all members
        int viewMember(System &sys);
        // View all motorbikes
        int viewMotorbike(System &sys);
};

#endif