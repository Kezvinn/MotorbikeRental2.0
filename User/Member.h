#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
#include "User.h"
#include "../Motorbike\motorbike.h"
#include "../Functions/my_func.h"
class Member: public User{
    private:
        std::string fullname;
        std::string phonenumber;
        bool id_type;   // 0 = Citizen ID, 1 = Passport
        std::string id_number;
        std::string drv_license;
        std::string exp_date;
        int credit = 20;    // default credit
    
    // pointer to bike own and rent
        Motorbike *ownedbike;   // pointer to the motorbike that the member is own
        Motorbike *rentedbike;  // pointer to the motorbike that the member is renting


    public:
        Member(); //default constructor
        Member(std::string username_ip, std::string password_ip, std::string fullname_ip, 
        std::string phonenumber_ip, bool id_type_ip, std::string id_number_ip, 
        std::string drv_license_ip, std::string exp_date_ip, int credit_ip);
        ~Member();  //destructor
        int addCredit();
        void listMotorbike(int rent_cost, std::string start_date, std::string end_date);
        
        // new member register 
        int signup();

        void getinfo();
        



};


#endif