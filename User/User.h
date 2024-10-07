#ifndef USER_H
#define USER_H
#include <string>
using namespace std;
class User{
    private:
        string username;
        string password;
    public:
        User(string username_ip, string password_ip);
        string getUsername();
        string getPassword();
        string setUsername(string username_ip);
        string setPassword(string password_ip);
};

#endif