#ifndef ADMIN_H
#define ADMIN_H
#include "user.h" 
class Admin: public User{
    private:
    public:
        Admin();
        bool adminLogin(std::string username, std::string pwd);
        void viewMember();
        void viewMotorbike();
};

#endif