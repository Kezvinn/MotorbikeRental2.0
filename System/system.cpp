#include "System.h"

System::System(){}

int System::init(){
    loadMember();
    loadMotorbike();
    loadMemberReview();
    loadBikeReview();
    loadRentRequest();
}
int System::loadMember(){
    member_list.clear();
    std::string line;
    
    std::ifstream file(MEMBER_FILE);
    if (!file.is_open()){
        std::cerr << "Error: Could not open file" << std::endl;
        return 1;
    }

    while(std::getline(file, line)){
        std::vector<std::string> data;  // store substring of line
        data = splitString (line, '|');

        Member *member = new Member(data[0], data[1], data[2], data[3], 
                                    data[4], stoi(data[5]), data[6], 
                                    data[7], data[8], stoi(data[9]), 
                                    data[10], data[11],
                                    stof(data[12]));
                                    
        member_list.push_back(*member);
    }
    file.close();
    return 0;
}
int System::loadMotorbike(){
    //load motorbike from file
    motorbike_list.clear();
    std::string line;
    std::ifstream file(MOTORBIKE_FILE);
    if (!file.is_open()){
        std::cerr << "Error: Could not open file" <<std::endl;
        return 1;
    }
    while (std::getline(file,line)){
        std::vector<std::string> data;
        data = splitString(line, '|');
        Motorbike *bike = new Motorbike (data[0], data[1], data[2], stoi(data[3]), 
                                        data[4], stoi(data[5]), data[6], data[7], 
                                        stoi(data[8]), data[9], data[10], 
                                        stof(data[11]), stoi(data[12]), stoi(data[13]));
        motorbike_list.push_back(*bike);
    }
    file.close();
    return 0;
}
int System::memberLogin(){
    std::string memberID, username_ip, passwork_ip;
    std::cout << "Username: " << std::endl;
    std::getline(std::cin, username_ip);
    std::cout << "Password: " << std::endl;
    std::getline(std::cin, passwork_ip);
    
    for (Member mem : member_list){
        if(mem.getUsername() == username_ip){
            if (mem.getPassword() == passwork_ip){
                std::cout << "Login Successfully" << std::endl;
                current_member = &mem;
                for (auto bike: motorbike_list){
                    
                }
                return 1;
            }
        }
    }
    std::cout << "Login Failed" << std::endl;
    return 0; 
}
int System::signup(){
    std::string memberID, username, password, fullname, phonenumber;
    int id_type;   // 0 = Citizen ID, 1 = Passport
    std::string id_number, drv_license, exp_date;
    int credit = 20;    // default credit

    std::cin.ignore();
    std::cout << "--------------------------------------------" << std::endl; 
    do {
        std::cout << "Enter your username: ";
        std::getline(std::cin, username, '\n');
    } while (!isUsername(username));

    std::cout << "--------------------------------------------" << std::endl; 
    do {
        std::cout << "Enter your password: ";
        std::getline(std::cin, password, '\n');
    } while (!isPassword(password));
    
    std::cout << "--------------------------------------------" << std::endl; 
    do {
        std::cout << "Enter your fullname: ";
        std::getline(std::cin, fullname,'\n');
    } while (!isLetter(fullname));

    std::cout << "--------------------------------------------" << std::endl; 
    do {
        std::cout << "Enter your phone number: ";
        std::getline(std::cin, phonenumber,'\n');
    } while (!isNumber(phonenumber));    

    std::cout << "--------------------------------------------" << std::endl; 
    do {
        std::cout << "ID type (0 = Citizen ID, 1 = Passport): ";
        std::cin >> id_type;
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore();
        }
    } while (id_type != 0 && id_type != 1);
    
    std::cin.ignore();
    std::cout << "--------------------------------------------" << std::endl; 
    do {
        std::cout << "Enter your ID number: ";
        std::getline(std::cin, id_number,'\n');
    } while (!isNumber(id_number));

    std::cout << "--------------------------------------------" << std::endl; 
    do {
        std::cout << "Enter your driver license: ";
        std::getline(std::cin, drv_license, '\n');
    } while (!isNumber(drv_license));

    std::cout << "--------------------------------------------" << std::endl; 
    do {
        std::cout << "Enter your driver license expiration date (DD/MM/YYYY): ";
        std::getline(std::cin, exp_date, '\n');
    } while (!isDateValid(exp_date));

    std::cout << "--------------------------------------------" << std::endl; 
    char ans;
    do {
        std::cout << "Add new bike (Y/N)? ";
        std::cin >> ans; 
    }  while (tolower(ans) != 'y' && tolower(ans) != 'n');
    Motorbike *newbike = new Motorbike();
    if (ans == 'Y' || ans == 'y'){
        // add new bike
        bikeSignup(*newbike);
    } else if (ans == 'N' || ans == 'n'){
        std::cout << "Sign up successfully!" << std::endl;
    }

    memberID = randomIDs("member");
    
    // create new member and add to to the list 
    Member *mem = new Member(memberID, username, password, fullname,
                            phonenumber, id_type, id_number,
                            drv_license, exp_date, credit,
                            newbike->getMotorbikeID(), "", 10);
    member_list.push_back(*mem);

    return 0;
}
int System::bikeSignup(Motorbike &newbike){

    std::vector<std::string> bike_info;
    // ID
    bike_info[0] = randomIDs("motorbike");
    
    // Model
    std::cout << "Enter Motorbike model: ";
    std::getline(std::cin, bike_info[1]);

    // Color
    do {
        std::cout << "Enter color: ";
        std::getline(std::cin, bike_info[2]);
    } while (isLetter(bike_info[2]));
    
    // Engine size
    do {
        std::cout << "Enter engine size in cubic centermeter (cc): ";
        std::cin >> bike_info[3];
    } while (isNumber(bike_info[3]));
    
    // Transmission mode
    int choice = 0;
    do {
        std::cout << "Enter transmission mode: ";
        std::cout << "1. Manual" << std::endl;
        std::cout << "2. Automatic" << std::endl;    
    } while (choiceInRange(1,2));
    if (choice == 1) { bike_info[4] = "Manual"; }
    else if (choice == 2) { bike_info[4] = "Automatic"; }
    
    // Year made
    do {
        std::cout << "Enter year made: ";   
        std::cin >> bike_info[5];
    } while (isNumber(bike_info[5]));
    std::cin.ignore();
    
    // Description
    std::cout << "Enter description: ";
    std::getline(std::cin, bike_info[6]);
    
    // Location
    do {    
        std::cout << "Available location: " << std::endl;
        std::cout << "1. Hanoi (HN)" << std::endl;
        std::cout << "2. Ho Chi Minh (HCM)" << std::endl;
    } while (choiceInRange(1, 2));
    if (choice == 1) { bike_info[7] = "HN"; }
    else if (choice == 2) { bike_info[7] = "HCM"; }
    
    // Rent cost
    do {
        std::cout << "Enter rent cost: ";
        std::cin >> bike_info[8];
    } while (isNumber(bike_info[8]));

    bike_info[9] = "";  // start date
    bike_info[10] = ""; // end date
    
    // Minimum member rating
    do {
        std::cout << "Enter minimum member rating: ";
        std::cin >> bike_info[11];
    } while (isFloatNumber(bike_info[11]));

    // List or unlist
    char ans;
    do {
        std::cout << "List motorbike for rent (Y/N)? " << std::endl;
        std::cin >> ans;
    } while (tolower(ans) != 'y' && tolower(ans) != 'n');
    if (ans == 'Y' || ans == 'y'){ bike_info[12] = "1";
    } else if (ans == 'N' || ans == 'n'){ bike_info[12] = "0";
    }

    // Availability
    bike_info[13] = "1";    // available

    // set bike info
    newbike.setNewMotorbikeInfo(bike_info);
    return 0;
}

int System::saveMember(){
    std::ofstream file(MEMBER_FILE);
    if (!file.is_open()){
        std::cerr << "Error: Could not open file" << std::endl;
        return 1;
    }

    for (Member mem : member_list){
        std::vector<std::string> data = mem.getMemberinfo();
        file << mem.getUsername() << '|' << mem.getPassword() << '|' << data[2] << '|'
             << data[3] << '|' << data[4] << '|' << data[5] << '|'
             << data[6] << '|' << data[7] << '|' << data[8] << std::endl;
    }
    return 0;
}
int System::saveMotorbike(){
    std::ofstream file(MOTORBIKE_FILE);
    if (!file.is_open()){
        std::cerr << "Error: Could not open file" << std::endl;
        return 1;
    }
    for(Motorbike bike : motorbike_list){
      
    }
    return 0;
}


// Menu
int System::mainMenu(){
    std::cout << "+==============================================+" << std::endl;
    std::cout << "|                  Main Menu                   |" << std::endl;
    std::cout << "+==============================================+" << std::endl;
    std::cout << "1. Member Login" << std::endl;
    std::cout << "2. Admin Login" << std::endl;
    std::cout << "3. Sign up" << std::endl;
    std::cout << "4. View Motorbike" << std::endl;
    std::cout << "5. Exit" << std::endl;

    int choice;
    choiceInRange(1, 5);

    switch (choice){
        case 1:
            memberLogin();
            break;
        case 2:
            adminLogin();
            break;
        case 3:
            signup();
            break;
        case 4:
            viewAllMotorbike();
            break;
        case 5: 
            return 1;
    }
}

int System::memberMenu(){
    std::cout << "================================================" << std::endl;
    std::cout << "                Member Menu                     " << std::endl;
    std::cout << "================================================" << std::endl;
    std::cout << "1. View Motorbike" << std::endl;  // view owned motorbike and choose to list/unlist
    std::cout << "2. Rent Motorbike" << std::endl;  // view available motorbike and rent
    std::cout << "3. Rate Motorbike" << std::endl;  // rate motorbike
    std::cout << "4. Rate Renter" << std::endl;     // rate renter
    std::cout << "5. Logout" << std::endl;          // logout

    int choice;
    choiceInRange(1, 5);

    switch (choice){
        case 1:
            viewMotorbike();    //Done
            break;
        case 2:
            rentMotorbike();    
            break;
        case 3:
            rateMotorbike();
            break;
        case 4:
            rateRenter();
            break;
        case 5:
            logout();
            // current_member = nullptr;
            break;
    }

}

int System::adminLogin(){
    std::string admin_username, admin_pwd;
    
    std::cout << "Admin username: ";
    std::cin >> admin_username;
    std::cout << "Admin password: ";
    std::cin >> admin_pwd;

    if (ad.adminLogin(admin_username, admin_pwd)){
        adminMenu();
    } else {
        std::cout << "Login failed!" << std::endl;
        mainMenu();
    }
}
int System::adminMenu(){
    std::cout << "+==============================================+" << std::endl;
    std::cout << "|               Administrator Menu             |" << std::endl;
    std::cout << "+==============================================+" << std::endl;
    std::cout << "1. View All Member" << std::endl;
    std::cout << "2. View All Motorbike" << std::endl;
    std::cout << "3. Logout" << std::endl;

    int choice;
    choiceInRange(1, 3);
    switch (choice){
        case 1:
            ad.viewMember();
            break;
        case 2:
            ad.viewMotorbike();
            break;
        case 3:
            logout();
            break;
    }
}

int System::viewMotorbike(){
    std::cout << "+==============================================+" << std::endl;
    std::cout << "|            Motorbike Information             |" << std::endl;
    std::cout << "+==============================================+" << std::endl;
    
    std::vector<std::string> data;
    for (auto bike_info : data){
        std::cout << "Model: " << bike_info[0] << std::endl;
        std::cout << "Color: " << bike_info[1] << std::endl;
        std::cout << "Engine size: " << bike_info[2] << std::endl;
        std::cout << "Transmission mode: " << bike_info[3] << std::endl;
        std::cout << "Year made: " << bike_info[4] << std::endl;
        std::cout << "Description: " << bike_info[5] << std::endl;
        std::cout << "Location: " << bike_info[6] << std::endl;
        std::cout << "Rent cost: " << bike_info[7] << std::endl;
        std::cout << "Start date: " << bike_info[8] << std::endl;
        std::cout << "End date: " << bike_info[9] << std::endl;
        std::cout << "================================================" << std::endl;
    }
    std::cout << "Return (Y/N)? " << std::endl;
    char ans;
    do {
        std::cin >> ans;
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore();
        }
    } while (tolower(ans) != 'y' && tolower(ans) != 'n');
    if (ans == 'Y' || ans == 'y'){
        return 0;
    } 
    return 1;
}

int System::rentMotorbike(){
    std::cout << "+==============================================+" << std::endl;
    std::cout << "|                Rent Motorbike                |" << std::endl;
    std::cout << "+==============================================+" << std::endl;
    
    // check for location first
    std::cout << "Enter your location: ";
    std::cout << "1. Hanoi" << std::endl;
    std::cout << "2. Ho Chi Minh" << std::endl;
    int member_location = choiceInRange(1, 2);
    
    std::string location;
    if (member_location == 1) { location = "Hanoi"; }
    else if (member_location == 2) { location = "Ho Chi Minh"; }

    int count = 1;
    
    // sort through the motorbike vector 
    // check for availability based on location, listed/unlist and member rating point
    std::cout << "No.   Model   Color   Engine size   Transmission mode   Year made     Location   Rent cost    Description" << std::endl;
    for (auto bike : motorbike_list){ 
        if ((bike.getbikeLocation() == location) && (bike.listed() == true) 
            && (bike.available() == true) && (current_member->getMemberRating() >= bike.getMinMemRating())){
            std::vector<std::string> bike_info = bike.getMotorbikeinfo();
            std::cout << count << "   " 
                      << bike_info[0] << "   " 
                      << bike_info[1] << "   " 
                      << bike_info[2] << "   " 
                      << bike_info[3] << "   " 
                      << bike_info[4] << "   " 
                      << bike_info[6] << "   " 
                      << bike_info[7] << "   " 
                      << bike_info[5] << std::endl;
        
        }


    }
    std::cout << "Rent this bike (Y/N)? " << std::endl;
    char ans;
    do {
        std::cin >> ans;
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore();
        }
    } while (tolower(ans) != 'y' && tolower(ans) != 'n');
    // if (ans == 'Y' || ans == 'y'){
    //     // send request
    //     std::string start_date, end_date;
    //     std::cout << "Enter start date (DD/MM/YYYY): ";
    //     std::cin >> start_date;
    //     std::cout << "Enter end date (DD/MM/YYYY): ";
    //     std::cin >> end_date;
    //     // create request
    //     Request *req = new Request(current_member->getUsername(), bike_info[0], start_date, end_date);
    //     request_list.push_back(*req);
    //     std::cout << "Request sent!" << std::endl;
    //     return 0;
    // } 
    return 1;
}