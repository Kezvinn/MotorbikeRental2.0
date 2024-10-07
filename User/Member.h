#ifndef MEMBER_H
#define MEMBER_H
#include "User.h"
class Member: public User{
    private:
        string fullname;
        int phonenumber;
        bool id_type;   // 0 = Citizen ID, 1 = Passport
        string id_number;
        string drv_license;
        string exp_date;
        int credit;

    public:
        Member(string username_ip, string password_ip, string fullname_ip, 
        int phonenumber_ip, bool id_type_ip, string id_number_ip, 
        string drv_license_ip, string exp_date_ip, int credit_ip);

};


#endif