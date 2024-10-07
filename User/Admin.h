#ifndef ADMIN_H
#define ADMIN_H
#include "user.h" 
class Admin: public User{
    private:
    public:
        Admin(string username_ip, string password_ip);

};

#endif