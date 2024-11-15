#include "Admin.h"

// Default constructor
Admin::Admin():User("admin", "nhatn123"){};

// Parameterized constructor
Admin::Admin(std::string username_ip, std::string password_ip)
            :User(username_ip, password_ip){};

// Admin login
bool Admin::adminLogin(std::string usename, std::string pwd){
    if ((usename == this->getUsername()) && (pwd == this->getPassword())){
        return true;
    }
    return false;
}
// View all members
int Admin::viewMember(System &sys){
    std::vector<Member*> member_list = sys.getMemberList();
    int count = 1;
    std::cout << std::left;
    std::cout << "No.  "
              << std::setw(10) << "ID#"
              << std::setw(18) << "Username"
              << std::setw(15) << "PWD"
              << std::setw(20) << "Fullname"
              << std::setw(15) << "Phone#"
              << std::setw(18) << "ID type"
              << std::setw(18) << "ID#"
              << std::setw(20) << "Driver license"
              << std::setw(15) << "Exp. Date"
              << std::setw(10) << "Credits"
              << std::setw(15) << "Own Bike ID"
              << std::setw(16) << "Rent Bike ID"
              << std::setw(10) << "Rating" << std::endl;   
    std::cout <<std::string(205, '-') << std::endl;
    for (auto mem : member_list) { 
        std::vector<std::string> data = mem->getMemberInfo();
        std::cout << std::left;
        std::cout << " " << count << ".  "     
                  << std::setw(10) << data[0]           // memberID
                  << std::setw(17) << data[1]           // username
                  << std::setw(16) << data[2]           // password (8-14)
                  << std::setw(20) << data[3]           // fullname
                  << std::setw(15) << data[4]           // phone number
                  << std::setw(18) << (std::stoi(data[5]) ? "Passport" : "Citizen ID")
                  << std::setw(18) << data[6]           // ID number
                  << std::setw(20) << data[7]           // driver license
                  << std::setw(18) << data[8]           // expire date
                  << std::setw(10) << data[9]           // credit
                  << std::setw(15) << data[10]          // owned bike ID
                  << std::setw(13) << data[11]          // rent bike ID
                  << std::setw(8) << std::fixed << std::setprecision (2) << std::stof(data[12])           // rating
                  << std::endl;
        count++;
    }   
    std::cout <<std::string(205, '-') << std::endl;
    char c = returnYes();
    if (c == 'Y' || c == 'y'){ 
        sys.adminMenu();  
    } 
    return 0; 
}
// View all motorbikes
int Admin::viewMotorbike(System &sys){
    std::vector<Motorbike*> motorbike_list = sys.getMotorbikeList();
    int count = 1;
    std::cout << std::left;
    std::cout << "No.   "
              << std::setw(10) << "BikeID"
              << std::setw(18) << "Model"
              << std::setw(10) << "Color"
              << std::setw(15) << "Engine Sizes"
              << std::setw(22) << "Transmission Mode"
              << std::setw(15) << "Year Made"
              << std::setw(15) << "Location"
              << std::setw(15) << "Rent Cost"
              << std::setw(15) << "Start Date"
              << std::setw(15) << "End Date"
              << std::setw(15) << "Min Rating"
              << std::setw(10) << "Listed"
              << std::setw(16) << "Availability"
              << std::setw(16) << "Renter ID"
              << std::setw(15) << "Description" 
              << std::endl;
    std::cout << std::string(230, '-') << std::endl;
    for (auto bike: motorbike_list){
        std::vector<std::string> data = bike->getMotorbikeInfo();
        std::cout << std::left;
        std::cout << count << ".    "
                  << std::setw(9) << data[0]    // bikeID
                  << std::setw(18) << data[1]    // model
                  << std::setw(14) << data[2]    // color
                  << std::setw(16) << data[3]    // engine size
                  << std::setw(19) << data[4]    // transmission mode
                  << std::setw(15) << data[5]    // year made
                  << std::setw(17) << data[7]    // location
                  << std::setw(11) << data[8]    // rent cost
                  << std::setw(15) << data[9]    // start date
                  << std::setw(15) << data[10]   // end date
                  << std::setw(15) << std::fixed << std::setprecision(2) << std::stof(data[11])   // min rating
                  << std::setw(10) << (std::stoi(data[12])? "Listed":"Unlist")          // listed
                  << std::setw(16) << (std::stoi(data[13])? "Available":"Unavailable")  // availability
                  << std::setw(16) << data[14]
                  << std::setw(15) << data[6]    // description
                  << std::endl;
        count++;
    }   
    std::cout << std::string(230, '-') << std::endl;

    char c = returnYes();
    if (c == 'Y' || c == 'y'){ 
        sys.adminMenu();
    }
    return 0; 
}