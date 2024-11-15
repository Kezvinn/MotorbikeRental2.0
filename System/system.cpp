#include "System.h"
// Constructor
System::System(){
    admin = new Admin();
    current_member = nullptr;
    current_motorbike = nullptr;
}
// Destructor
System::~System(){
    delete admin;
    delete current_member;
    delete current_motorbike;
}
int System::init(){
    loadMember();       // load member
    loadMotorbike();    // load bike
    // std::cout << "Loading Member and Motorbike completed" << std::endl;
    
    for (auto mem : member_list) {
        for (auto bike: motorbike_list) {
            if (mem->getRentBikeID() == bike->getMotorbikeID() 
                && rentDuration(bike->getEnddate(), TODAY_DATE) < 0) {
                // create review for bike
                MotorbikeReview *bike_rev = new MotorbikeReview(mem->getMemberID(),
                                                                bike->getMotorbikeID(),
                                                                "Pending");
                bike->addBikeReview(bike_rev);
            }
            if (mem->getOwnbikeID() == bike->getMotorbikeID()) {
                // create review for member
                MemberReview *mem_rev = new MemberReview(mem->getMemberID(),
                                                         bike->getRenterID(),
                                                         "Pending");
                mem->addMemberReview(mem_rev);
            }
            // clear info in bike
            bike->setRenterID("");
            bike->setBikeStartDate("");
            bike->setBikeEndDate("");
            bike->setBikeAvailability(true);
            break;
            // // Update member rating
            // mem->setMemberRating(mem->calcMemberRating());
        }
        // clear info in member
        mem->setRentBikeID("");
        mem->setRentedBike(nullptr);

        // calculate new member rating
        mem->setMemberRating(mem->calcMemberRating());
        // check for expire requests
    }

    return 0;
}

std::vector<Member*> &System::getMemberList(){ return member_list; }
std::vector<Motorbike*> &System::getMotorbikeList(){ return motorbike_list; }
// --------------------------- Main Menu -----------------------------------------------------------//
int System::mainMenu(){
    std::cout << "+==============================================+" << std::endl;
    std::cout << "|         Motorbike Rental Application         |" << std::endl;
    std::cout << "|           Created by: Nhat Nguyen            |" << std::endl;
    std::cout << "+==============================================+" << std::endl;
    std::cout << "+==============================================+" << std::endl;
    std::cout << "|                  Main Menu                   |" << std::endl;
    std::cout << "+==============================================+" << std::endl;
    std::cout << "1. Member Login" << std::endl;
    std::cout << "2. Admin Login" << std::endl;
    std::cout << "3. Sign up" << std::endl;
    std::cout << "4. View Motorbike" << std::endl;
    std::cout << "5. Exit" << std::endl;

    int choice = choiceInRange(1, 5);
    
    switch (choice){
        case 1:
            memberLogin() ? memberMenu() : mainMenu();
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
            logout();
            std::cout << "Thank you and goodbye!" << std::endl;
            break;  
    }
    
    return 0;
}

// --------------------------- Admin Menu ---------------------------------------------------------//
int System::adminLogin(){
    std::string admin_username, admin_pwd;
    std::cout << "+==============================================+" << std::endl;
    std::cout << "|                  Admin Login                 |" << std::endl;
    std::cout << "+==============================================+" << std::endl;
    std::cout << "Admin Username: ";
    std::cin >> admin_username;
    std::cout << "Admin Password: ";
    std::cin >> admin_pwd;

    if (admin->adminLogin(admin_username, admin_pwd)){
        adminMenu();
    } else {
        std::cout << "Login failed!" << std::endl;
        mainMenu();
    }
    return 0;
}
int System::adminMenu(){
    std::cout << "+==============================================+" << std::endl;
    std::cout << "|               Administrator Menu             |" << std::endl;
    std::cout << "+==============================================+" << std::endl;
    std::cout << "1. View All Member" << std::endl;
    std::cout << "2. View All Motorbike" << std::endl;
    std::cout << "3. Logout" << std::endl;

    int choice = choiceInRange(1, 3);
    
    switch (choice){
        case 1:
            admin->viewMember(*this);
            break;
        case 2:
            admin->viewMotorbike(*this);
            break;
        case 3:
            logout();
            break;
    }
    return 0;
}
// ---------------------------Non-Member Functions------------------------------------------------//
int System::viewAllMotorbike(){
    std::cout << "+==============================================+" << std::endl;
    std::cout << "|              View All Motorbike              |" << std::endl;
    std::cout << "+==============================================+" << std::endl;
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
            //   << std::setw(15) << "Start Date"
            //   << std::setw(15) << "End Date"
            //   << std::setw(15) << "Min Rating"
            //   << std::setw(10) << "Listed"
            //   << std::setw(16) << "Availability"
              << std::setw(15) << "Description" 
              << std::endl;
    std::cout << std::string(150, '-') << std::endl;
    
    std::vector<std::string> data;
    for (auto bike : motorbike_list){
        data.clear();
        data = bike->getMotorbikeInfo();
        std::cout << std::left;
        std::cout << " " << count << ".    "
                  << std::setw(9) << data[0]    // bikeID
                  << std::setw(18) << data[1]   // model
                  << std::setw(14) << data[2]   // color
                  << std::setw(16) << data[3]   // engine size
                  << std::setw(19) << data[4]   // transmission mode
                  << std::setw(15) << data[5]   // year made
                  << std::setw(17) << data[7]   // location
                  << std::setw(11) << data[8]   // rent cost
                //   << std::setw(15) << data[9]    // start date
                //   << std::setw(15) << data[10]   // end date
                //   << std::setw(15) << std::fixed << std::setprecision(2) << std::stof(data[11])   // min rating
                //   << std::setw(10) << (std::stoi(data[12])? "Listed":"Unlist")    // listed
                //   << std::setw(16) << (std::stoi(data[13])? "Available":"Unavailable")    // availability
                  << std::setw(15) << data[6]    // description
                  << std::endl;
        count++;
    }
    std::cout << std::string(150, '-') << std::endl;
    char c = returnYesNo();
    if (c == 'Y' || c == 'y'){ 
        mainMenu();
    }
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
        std::cout << "Phone number: ";
        std::getline(std::cin, phonenumber,'\n');
    } while (!isNumber(phonenumber) && phonenumber.length() == 10);    

    std::cout << "--------------------------------------------" << std::endl; 
        std::cout << "ID type:" << std::endl;
        std::cout << "0 = Citizen ID" << std::endl; 
        std::cout << "1 = Passport" << std::endl;
        id_type = choiceInRange(0, 1);
        // std::cin >> id_type;
        
    std::cin.ignore();
    std::cout << "--------------------------------------------" << std::endl; 
    if (id_type == 0){
        do{
            std::cout << "Citizen ID number: ";
            std::getline(std::cin, id_number,'\n');
        } while (!isNumber(id_number) && id_number.length() == 12);
    } else if (id_type == 1){
        do {
            std::cout << "Passport number: ";
            std::getline(std::cin, id_number,'\n');
        } while (!isPassport(id_number));
    }

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
        newbike = bikeSignup();
    } else if (ans == 'N' || ans == 'n'){
        std::cout << "Sign up successfully!" << std::endl;
    }

    memberID = randomIDs("member");
    
    // create new member and add to to the list 
    Member *mem = new Member(memberID, username, password, fullname,
                             phonenumber, id_type, id_number,
                             drv_license, exp_date, credit,
                             newbike->getMotorbikeID(), "", 10);
    member_list.push_back(mem);
    mainMenu();
    return 0;
}

//---------------------------Member Functions-----------------------------------------------------//
int System::memberLogin(){
    std::cout << "+==============================================+" << std::endl;
    std::cout << "|                  Member Login                |" << std::endl;
    std::cout << "+==============================================+" << std::endl;
    std::cin.ignore();
    std::string username_ip, passwork_ip;
    std::cout << "Username: ";
    std::getline(std::cin, username_ip);
    std::cout << "Password: ";
    std::getline(std::cin, passwork_ip);
    
    for (auto mem : member_list){
        if (mem->memberLogin(username_ip, passwork_ip) == true){
            current_member = mem;
            // mem->init();
            break;
        }
    }
    // check for bike that own and bike that currently rentinng (check by date)
    bool ownbike_flag = false;
    bool rentbike_flag = false;
    if (current_member != nullptr){
        for (auto bike : motorbike_list) {
            if (current_member->getMemberInfo()[10] == bike->getMotorbikeID()){
                current_member->setOwnedBike(bike);
                ownbike_flag = true;
            } 
            
            if (current_member->getMemberInfo()[11] == bike->getMotorbikeID()){     //check for the id saved in rentbikeID
                current_member->setRentedBike(bike);
                rentbike_flag = true;
            } 
        }
        if (!ownbike_flag){
            current_member->setOwnedBike(nullptr);
        }
        if (!rentbike_flag){
            current_member->setRentedBike(nullptr);
        }
        // current_member->init();
        
        
        std::cout << "+==============================================+" << std::endl;
        std::cout << "|         Login Successfully. Welcome!!        |" << std::endl;
        std::cout << "+==============================================+" << std::endl;
        return true;
    }
    std::cout << "+==============================================+" << std::endl;
    std::cout << "|   Login Failed! Wrong Username or Password   |" << std::endl;
    std::cout << "+==============================================+" << std::endl;
    return false; 
}
Motorbike* System::bikeSignup(){

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

    // add new bike to the list
    Motorbike *newbike = new Motorbike(bike_info[0], bike_info[1], 
                                       bike_info[2], std::stoi(bike_info[3]),
                                       bike_info[4], std::stoi(bike_info[5]), 
                                       bike_info[6], bike_info[7],
                                       std::stoi(bike_info[8]), bike_info[9], 
                                       bike_info[10], std::stof(bike_info[11]),
                                       std::stoi(bike_info[12]), std::stoi(bike_info[13]),
                                       "");
    motorbike_list.push_back(newbike);

    std::cout << "Add new bike successfully!" << std::endl;
    return newbike;
}
//---------------------------- Member Menu ------------------------------------------------------//
int System::memberMenu(){
    std::cout << "+==============================================+" << std::endl;
    std::cout << "|                  Member Menu                 |" << std::endl;
    std::cout << "+==============================================+" << std::endl;
    std::cout << "1. View Personal Info " << std::endl;     // view personal info
    std::cout << "2. View Motorbike Info" << std::endl;     // view motorbike info -> choose to list or unlist or leave new Descriptions
    std::cout << "3. View Renting Requests" << std::endl;    // view renting request -> approve or deny
    std::cout << "4. Review Rented Motorbikes" << std::endl;   // 
    std::cout << "5. Review Renters" << std::endl;      
    std::cout << "6. Rent Motorbike" << std::endl;              // completed but need to test
    std::cout << "7. Add Credits" << std::endl;                 // this work    
    std::cout << "8. Edit Motorbike." << std::endl;
    std::cout << "9. Logout" << std::endl;
    
    int choice = choiceInRange(1, 9);
    char c;
    switch (choice){
        case 1:
            current_member->showMemberInfo();
            c = returnYes();
            if (c == 'Y' || c == 'y'){
                memberMenu();
            }
            break;
        case 2:
            if (current_member->getOwnedBike() == nullptr) {
                std::cout << "You don't have any bike yet!" << std::endl;
                break;
            }
            current_member->getOwnedBike()->showMotorbikeInfo();
            c = returnYes();
            if (c == 'Y' || c == 'y'){
                memberMenu();
            }
            break;
        case 3:
            current_member->rentRequestMenu();
            memberMenu();
            break;
        case 4:
            current_member->rateMotorbikeMenu();
            break;
        case 5:
            current_member->rateRenterMenu();
            std::cout << "Return to Member Menu?" << std::endl;
            c = returnYes();
            if (c == 'y'){
                memberMenu();
            }
            break;
        case 6:
            rentMotorbikeMenu();          
            break;
        case 7:
            current_member->addCredits();
            break;
        case 8:
            editBikeMenu();
            c = returnYes();
            if (c == 'Y' || c == 'y'){
                memberMenu();
            }
        case 9: 
            logout();
            break;
    }
    return 0;   
}
int System::rentMotorbikeMenu(){
    std::cout << "+==============================================+" << std::endl;
    std::cout << "|              Rent Motorbike Menu             |" << std::endl;
    std::cout << "+==============================================+" << std::endl;

    std::cout << "Choose your location: " << std::endl;
    std::cout << "1. Hanoi (HN)" << std::endl;
    std::cout << "2. Ho Chi Minh (HCM)" << std::endl;
    
    int loc = choiceInRange(1, 2);
    std::string location = (loc == 1) ? "HN" : "HCMC";

    std::cout << std::string(180, '-') << std::endl;
    std::cout << std::left;
    std::cout << "No. "   
              << std::setw(10) << "BikeID"
              << std::setw(18) << "Model"
              << std::setw(10) << "Color"
              << std::setw(20) << "Engine Sizes (cc)"
              << std::setw(22) << "Transmission Mode"
              << std::setw(15) << "Year Made"
              << std::setw(15) << "Location"
              << std::setw(20) << "Rent Cost (CR)"
              << std::setw(15) << "Member Rating"
              << std::setw(15) << "Availability"
              << std::setw(15) << "Description" 
              << std::endl;
    std::cout << std::string(180, '-') << std::endl;
    
    int count = 1;
    std::vector<std::string> bike_data;
    for(auto bike4rent : motorbike_list){
        bike_data.clear();
        bike_data = bike4rent->getMotorbikeInfo();
        if(bike_data[7] == location             // check for location
            && std::stoi(bike_data[12]) == 1    // check for listed bike
            && std::stoi(bike_data[13]) == 1    // check for available bike
            && std::stof(bike_data[11]) <= std::stof(current_member->getMemberInfo()[12]) // check for min rating
            && bike_data[0] != current_member->getOwnbikeID()){ // check for own bike ID
            std::cout << std::left;
            std::cout << count << ".  ";
            std::cout << std::setw(10) << bike_data[0]   // bikeID
                      << std::setw(18) << bike_data[1]   // model
                      << std::setw(15) << bike_data[2]   // color
                      << std::setw(18) << bike_data[3]   // engine size
                      << std::setw(20) << bike_data[4]   // transmission mode
                      << std::setw(15) << bike_data[5]   // year made
                      << std::setw(17) << bike_data[7]   // location
                      << std::setw(18) << bike_data[8]   // rent cost
                      << std::setw(15) << std::fixed << std::setprecision(2) << std::stof(bike_data[11])   // min rating
                      << std::setw(15) << (std::stoi(bike_data[12])? "Available":"Unavailable")    // availability
                      << std::setw(15) << bike_data[6]   // description
                      << std::endl;
            count++;
        }
        // else {
        //     std::cout << "No bike available for rent" << std::endl;
        // }
    }
    std::cout << std::string(180, '-') << std::endl;

    std::cout << "Choose a bike to rent: " << std::endl;
    std::cout << "0. Return" << std::endl;
    std::cout << "1 - " << count-1 << ". Choose a bike" << std::endl;
    
    std::string start_date, end_date;
    int bike_choice = choiceInRange(1, count);
    if (bike_choice == 0){
        memberMenu();
    } else {
        current_motorbike = motorbike_list[bike_choice-1];  // set current motorbike
        std::string requestID = randomIDs("request");
        // std::string renterID = current_member->getMemberID();
        std::string ownerID;
        for(auto owner : member_list){
            if (owner->getMemberInfo()[10] == current_motorbike->getMotorbikeID()){
                ownerID = owner->getMemberID();
                break;
            }
        }
        
        std::string bikeID = current_motorbike->getMotorbikeID();

        // start date
        do {
            std::cout << "Enter start date (DD/MM/YYYY): ";
            std::cin >> start_date;
        } while (!isDateValid(start_date));
        // end date
        do {
            std::cout << "Enter end date (DD/MM/YYYY): ";
            std::cin >> end_date;
        } while (!isDateValid(end_date));

        int totalRentCost = (rentDuration(start_date, end_date)) 
                            * (std::stoi(current_motorbike->getMotorbikeInfo()[8]));
        std::cout << "Total Rent Cost " << totalRentCost << std::endl; 
        // create new request
        Request *newRequest = new Request(requestID, current_member->getMemberID(), 
                                          ownerID, bikeID, 
                                          start_date, end_date, 
                                          totalRentCost, "Pending");
        current_member->addRentRequest(newRequest);   
    }
    std::cout << "Renting request sent!" << std::endl;
    char c = returnYes();
    if (c == 'Y' || c == 'y'){
        memberMenu();
    }
    return 0;
}

// ---------------------------File Handling Functions---------------------------------------------//
// Load data from txt files
int System::loadMember(){
    member_list.clear();

    std::ifstream file;
    file.open(MEMBER_FILE, std::fstream::in);
    if (!file.is_open()){
        std::cerr << "Error: Could not open Member.txt file." << std::endl;
        return 1;
    }
    std::string line;
    // std::vector<std::string> data;
    while(std::getline(file, line)){
        if (line.empty()){
            continue;
        }
        Member *member = new Member();
        if (member->parseFromLine(line)) {
            member->init();
            member_list.push_back(member);
        } else {
            delete member;
        }
        // data.clear();  // store substring of line
        // data = splitString (line, '|');
        // Member *member = new Member(data[0], data[1], 
        //                             data[2], data[3], 
        //                             data[4], std::stoi(data[5]), 
        //                             data[6], data[7], 
        //                             data[8], std::stoi(data[9]), 
        //                             data[10], data[11], 
        //                             std::stof(data[12]));
        // member_list.push_back(member);
    }
    file.close();
    std::cout << "Loading Member completed." << std::endl;
    return 0;
}
int System::loadMotorbike(){
    motorbike_list.clear();
    std::ifstream file;
    file.open(MOTORBIKE_FILE, std::fstream::in);
    
    if (!file.is_open()){
        std::cerr << "Error: Could not open Motorbike.txt file" <<std::endl;
        return 1;
    }
    std::string line;
    // std::vector<std::string> data;
    while (std::getline(file,line)){
        if (line.empty()){
            continue;
        }
        Motorbike *motorbike = new Motorbike();
        if (motorbike->parseFromLine(line)) {
            motorbike_list.push_back(motorbike);
            motorbike->loadMotorbikeReview();
        } else {
            delete motorbike;
        }
        // data.clear();
        // data = splitString(line, '|');
        // Motorbike *bike = new Motorbike (data[0], data[1], 
        //                                  data[2], std::stoi(data[3]), 
        //                                  data[4], std::stoi(data[5]), 
        //                                  data[6], data[7], 
        //                                  std::stoi(data[8]), data[9], 
        //                                  data[10], std::stof(data[11]), 
        //                                  std::stoi(data[12]), 
        //                                  std::stoi(data[13]), data[14]);
        // motorbike_list.push_back(bike);
    }
    file.close();
    std::cout << "Loading Motorbike completed" << std::endl;
    return 0;
}
// Save data to txt files
int System::saveMember(){
    std::ofstream file;
    file.open(MEMBER_FILE, std::fstream::out);
    if (!file.is_open()){
        std::cerr << "Error: Could not open file" << std::endl;
        return 1;
    }

    std::vector<std::string> data;
    for (auto mem : member_list){
        data.clear();
        data = mem->getMemberInfo();
        int data_size = data.size();
        for (int i = 0; i < data_size; i++){
            file << data[i];
            if (i < data_size - 1){
                file << '|';
            } else {
                file << std::endl;
            }
        }
        // file << data[0] << '|' << data[1] << '|' << data[2] << '|' << data[3] << '|' 
        //      << data[4] << '|' << data[5] << '|' << data[6] << '|' << data[7] << '|' 
        //      << data[8] << '|' << data[9] << '|' << data[10] << '|' << data[11] << '|' 
        //      << data[12] << std::endl;
    }
    std::cout << "Saving Member completed" << std::endl;
    return 0;
}
int System::saveMotorbike(){
    std::ofstream file;
    file.open(MOTORBIKE_FILE, std::fstream::out);
    if (!file.is_open()){
        std::cerr << "Error: Could not open file" << std::endl;
        return 1;
    }
    std::vector<std::string> data;
    for(auto bike : motorbike_list){
        data.clear();
        data = bike->getMotorbikeInfo();
        int data_size = data.size();
        for (int i = 0;i < data_size; i++){
            file << data[i];
            if (i < data_size - 1){
                file << '|';
            } else {
                file << std::endl;
            }
        }
        // file << data[0] << '|' << data[1] << '|' << data[2] << '|' << data[3] << '|' 
        //      << data[4] << '|' << data[5] << '|' << data[6] << '|' << data[7] << '|' 
        //      << data[8] << '|' << data[9] << '|' << data[10] << '|' << data[11] << '|' 
        //      << data[12] << '|' << data[13] << std::endl;
    }
    std::cout << "Saving Motorbike completed" << std::endl;
    return 0;
}

int System::logout(){
    saveMember();
    saveMotorbike();
    current_member->logout();
    // current_member->getOwnedBike()->logout();
    // current_member->getRentedBike()->logout();
    // if (current_motorbike != nullptr){
    //     current_motorbike->logout();
    // }
    // current_motorbike->logout();

    current_member = nullptr;
    current_motorbike = nullptr;
    admin = nullptr;

    // for(auto mem : member_list){
    //     delete mem;
    // }
    // for(auto bike : motorbike_list){
    //     delete bike;
    // }
    return 0;
}
int System::removeBike(std::string bikeID) {
    for (auto bike:motorbike_list){
        if (bike->getMotorbikeID() == bikeID){
            motorbike_list.erase(std::remove(motorbike_list.begin(), motorbike_list.end(), bike), motorbike_list.end());
            delete bike;
            break;
        }
    }
}
int System:: editBikeMenu(){
    std::cout << "+==============================================+" << std::endl;
    std::cout << "|              Edit Motorbike Menu             |" << std::endl;
    std::cout << "+==============================================+" << std::endl;
    std::cout << "1. Edit Motorbike location." << std::endl;
    std::cout << "2. Edit Rent Cost." << std::endl;
    std::cout << "3. Edit Minimum Member Rating." << std::endl;
    std::cout << "4. List/Unlist Bike." << std::endl;

    int choice = choiceInRange(1,4);
    int loc;
    char c;
    std::string ans;
    switch (choice){
        case 1:
            std::cout << "Choose new location: " << std::endl;
            std::cout << "1. Hanoi (HN)" << std::endl;
            std::cout << "2. Ho Chi Minh City (HCMC)" << std::endl;
            loc = choiceInRange(1, 2);
            current_member->getOwnedBike()->setBikeLocation((loc == 1) ? "HN" : "HCMC");
            break;
        case 2:
            std::cout << "Current Rent Cost: " << current_member->getOwnedBike()->getRentCost() << " credits" << std::endl;
            do {
                std::cout << "Enter new rent cost: " ;
                std::cin >> ans;
            } while (!isNumber(ans));
            
            current_member->getOwnedBike()->setRentCost(std::stoi(ans));
            break;
        case 3:
            do {
                std::cout << "Enter new minimum member rating: ";
                std::cin >> ans;
            } while (isFloatNumber(ans));
            current_member->getOwnedBike()->setMinRating(std::stof(ans));
            break;
        case 4:
            std::cout << "List/Unlist bike (Y/N)? ";
            std::cin >> c;
            if (c == 'Y' || c == 'y'){
                current_member->getOwnedBike()->setListed(1);
            } else if (c == 'N' || c == 'n'){
                current_member->getOwnedBike()->setListed(0);
            }
            break;
    }
    return 0;
}