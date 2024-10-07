#include "Member.h"

Member::Member(string username_ip, string password_ip, string fullname_ip, 
    int phonenumber_ip, bool id_type_ip, string id_number_ip, 
    string drv_license_ip, string exp_date_ip, int credit_ip)
    :User(username_ip, password_ip), fullname(fullname_ip), 
    phonenumber(phonenumber_ip), id_type(id_type_ip), id_number(id_number_ip),
    drv_license(drv_license_ip), exp_date(exp_date_ip), credit(credit_ip){};