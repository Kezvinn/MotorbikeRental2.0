#include "user.h"

User::User(string username_ip, string password_ip):username(username_ip), password(password_ip){};

string User::getUsername(){
    return username;
}
string User::getPassword(){
    return password;
}
string User::setUsername(string username_ip){
    this->username = username_ip;
}
string User::setPassword(string password_ip){
    this->password = password_ip;
}