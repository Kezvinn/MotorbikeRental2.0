#include "Admin.h"

Admin::Admin(){};
Admin::Admin(std::string username_ip="admin", std::string password_ip="nhatn123")
            :User(username_ip, password_ip){};

bool Admin::adminLogin(std::string usename, std::string pwd){
    if ((usename == this->getUsername()) && (pwd == this->getPassword())){
        return true;
    }
    return false;
}

int Admin::viewMember(System &sys){
    std::vector<Member*> member_list = sys.getMemberList();
    int count = 1;
    for (auto mem : member_list){ 
        std::vector<std::string> data = mem->getMemberInfo();
        std::cout << "No.   Username   PWD      Fullname        Phone number   ID type   ID number   Driver license   Exp date   Credit" << std::endl;   
        std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << count << "    "<<   data[0] << "   " << data[1] << "   " << data[2] << "   " << data[3] << "   " << data[4] << "   " << data[5] << "   " << data[6] << "   " << data[7] << "   " << data[8] << std::endl;
        count++;
    }   
    std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;
    
    char c;
    do {
        std::cout << "Return (Y/N); ";
        std::cin >> c;
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore();
        } 
    } while (tolower(c) != 'y' && tolower(c) != 'n');
    if (c == 'Y' || c == 'y'){ 
        sys.adminMenu();
        return 0; 
    }
}
int Admin::viewMotorbike(System &sys){
    std::vector<Motorbike*> motorbike_list = sys.getMotorbikeList();
    int count = 1;
    for (auto bike: motorbike_list){
        std::vector<std::string> data = bike->getMotorbikeInfo();
        std::cout << "No.   Bike ID     Model   Year   Color   Price   Status" << std::endl;
        std::cout << "--------------------------------------------------------------" << std::endl;
        std::cout << count << "    " << data[0] << "   " << data[1] << "   " << data[2] << "   " << data[3] << "   " << data[4] << "   " << data[5] << "   " << data[6] << std::endl;
        count++;
    }   
    
    char c;
    do {
        std::cout << "Return (Y/N); ";
        std::cin >> c;
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore();
        } 
    } while (tolower(c) != 'y' && tolower(c) != 'n');
    if (c == 'Y' || c == 'y'){ 
        sys.adminMenu();
        return 0; 
    }
}