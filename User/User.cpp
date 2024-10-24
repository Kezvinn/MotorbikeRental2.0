#include "User.h"

// Constructor
User::User(){}; //default constructor
User::User(std::string username_ip, std::string password_ip)
            :username(username_ip), password(password_ip){};

// Getter
std::string User::getUsername(){ return username; }
std::string User::getPassword(){ return password; }

// Setter
void User::setUsername(std::string username_ip) { this->username = username_ip; }
void User::setPassword(std::string password_ip) { this->password = password_ip; }