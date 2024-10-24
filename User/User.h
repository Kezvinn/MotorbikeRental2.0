#ifndef USER_H
#define USER_H

#include <bits/stdc++.h>

class User{
    private:
        std::string username;
        std::string password;
    public:
        User(); //default constructor
        User(std::string username_ip, std::string password_ip);
        // Getter
        std::string getUsername();
        std::string getPassword();
        // Setter
        void setUsername(std::string username_ip);
        void setPassword(std::string password_ip);
};

#endif
