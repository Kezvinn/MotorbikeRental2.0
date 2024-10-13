#ifndef USER_H
#define USER_H
#include <string>
class User{
    private:
        std::string username;
        std::string password;
    public:
        User(){}; //default constructor
        User(std::string username_ip, std::string password_ip);
        std::string getUsername();
        std::string getPassword();
        void setUsername(std::string username_ip);
        void setPassword(std::string password_ip);
};

#endif