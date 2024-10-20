#include "Admin.h"

Admin::Admin(){
    this->setUsername("admin");
    this->setPassword("nhatn123");
};

bool Admin::adminLogin(std::string usename, std::string pwd){
    if ((usename == this->getUsername()) && (pwd == this->getPassword())){
        return true;
    }
    return false;
}

// void Admin::viewMember(){
    
// }
// void Admin::viewMotorbike(){

// }