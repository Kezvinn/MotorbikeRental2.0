#include "Admin.h"

Admin::Admin():User("admin", "nhatn123"){};
Admin::Admin(std::string username_ip, std::string password_ip)
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
    std::cout << "No."
              << std::setw(colWidth[0]) << "ID#"
              << std::setw(colWidth[2]) << "Username"
              << std::setw(colWidth[2]) << "PWD"
              << std::setw(colWidth[2]) << "Fullname"
              << std::setw(colWidth[2]) << "Phone#"
              << std::setw(colWidth[2]) << "ID type"
              << std::setw(colWidth[2]) << "ID #"
              << std::setw(colWidth[2]) << "Driver license"
              << std::setw(colWidth[2]) << "Exp date"
              << std::setw(colWidth[2]) << "Credit"
              << std::setw(colWidth[2]) << "Own Bike ID"
              << std::setw(colWidth[2]) << "Rent Bike ID"
              << std::setw(colWidth[2]) << "Rating" << std::endl;   
    std::cout <<std::string(200, '-') << std::endl;
    
    for (auto mem : member_list){ 
        std::vector<std::string> data = mem->getMemberInfo();
        std::cout << count 
                  << std::setw(colWidth[1]) << data[0] 
                  << std::setw(colWidth[2]) << data[1]  
                  << std::setw(colWidth[2]) << data[2] 
                  << std::setw(colWidth[2]) << data[3] 
                  << std::setw(colWidth[2]) << data[4]            
                  << std::setw(colWidth[2]) << (std::stoi(data[5]) ? "Passport" : "Citizen ID")
                  << std::setw(colWidth[2]) << data[6] 
                  << std::setw(colWidth[2]) << data[7] 
                  << std::setw(colWidth[2]) << data[8] 
                  << std::setw(colWidth[2]) << data[9] 
                  << std::setw(colWidth[2]) << data[10]  
                  << std::setw(colWidth[2]) << data[11] 
                  << std::setw(colWidth[2]) << data[12] << std::endl;
        count++;
    }   
    std::cout <<std::string(200, '-') << std::endl;
    char c = returnYesNo();
    if (c == 'Y' || c == 'y'){ 
        sys.adminMenu();  
    } 
    return 0; 
}
int Admin::viewMotorbike(System &sys){
    std::vector<Motorbike*> motorbike_list = sys.getMotorbikeList();
    int count = 1;
    std::cout << "No.\tBike ID\tModel\tColor\tEngine Size\tTransmission Mode\tYearMade\tLocation\tRentCost\tStart Date\tEnd Date\tMin Rating\tListed\tAvailablibility\tDescription" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    for (auto bike: motorbike_list){
        std::vector<std::string> data = bike->getMotorbikeInfo();
        std::cout << count << "\t" 
                  << data[0] << "\t" << data[1] << "\t" << data[2] << "\t" 
                  << data[3] << "\t" << data[4] << "\t" << data[5] << "\t" 
                  << data[7] << "\t" << data[8] << "\t" << data[9] << "\t" 
                  << data[10] << "\t" << data[11] << "\t" << data[12] << "\t"
                  << data[13] << "\t" << data[6] << "\t" << std::endl;
        count++;
    }   
    std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;

    char c = returnYesNo();
    if (c == 'Y' || c == 'y'){ 
        sys.adminMenu();
    }
    return 0; 
}