#ifndef ADMIN_H
#define ADMIN_H
#include "user.h" 
class Admin: public User{
    private:
    public:
        Admin(std::string username_ip="admin", std::string password_ip="nhatn123");

        void viewMember();
        void viewMotorbike();
};

#endif