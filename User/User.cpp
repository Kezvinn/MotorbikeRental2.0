#include "user.h"

User::User(std::string username_ip, std::string password_ip):username(username_ip), password(password_ip){};

std::string User::getUsername(){
    return username;
}
std::string User::getPassword(){
    return password;
}
void User::setUsername(std::string username_ip){
    this->username = username_ip;
}
void User::setPassword(std::string password_ip){
    this->password = password_ip;
}