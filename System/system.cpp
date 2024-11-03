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

    for (auto bike : motorbike_list) {
        if (rentDuration(bike->getMotorbikeInfo()[10], TODAY_DATE) < 0){ // out of date for rent
            for (auto owner : member_list) { 
                // check for owner
                if (owner->getOwnbikeID() == bike->getMotorbikeID()){
                    // create and add new reivew for member
                    MemberReview *mem_review = new MemberReview(randomIDs("memberreview"),  // review ID
                                                                owner->getMemberID(),         // reviewer
                                                                bike->getRenterID(),        // reviewee
                                                                "Pending");                 // status
                    // add member review
                    owner->addMemberReview(mem_review);   // add review for member
                }
            }
            for (auto renter : member_list){
                // check for renter
                if (renter->getMemberID() == bike->getRenterID()){
                    // Create a new review for bike
                    MotorbikeReview *bike_review = new MotorbikeReview(randomIDs("bikereview"), 
                                                                    renter->getMemberID(),
                                                                    bike->getMotorbikeID(),
                                                                    "Pending");
                    // add review for bike
                    bike->addBikeReview(bike_review);
                    // clear renter ID and pointer
                    renter->setRentBikeID("");  // clear rent bike ID
                    renter->setRentedBike(nullptr); // clear rented bike
                }
            }
            
            // Reset value for bike
            bike->setBikeStartDate(""); // clear start date
            bike->setBikeEndDate("");   // clear end date
            bike->setBikeAvailability(true);    // set bike available
            bike->setRenterID("");      // clear renter ID
        }
    }
    return 0;
}

std::vector<Member*> &System::getMemberList(){ return member_list; }
std::vector<Motorbike*> &System::getMotorbikeList(){ return motorbike_list; }
// --------------------------- Main Menu -----------------------------------------------------------//
int System::mainMenu(){
    std::cout << "+==============================================+" << std::endl;
    std::cout << "|                  Main Menu                   |" << std::endl;
    std::cout << "+==============================================+" << std::endl;
    std::cout << "1. Member Login" << std::endl;
    std::cout << "2. Admin Login" << std::endl;
    std::cout << "3. Sign up" << std::endl;
    std::cout << "4. View Motorbike" << std::endl;
    std::cout << "5. Exit" << std::endl;

    int choice = choiceInRange(1, 5);
    while (choice != 5){
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
                std::cout << "Thank you and goodbye!" << std::endl;
                break;  
        }
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
    
    for (auto bike : motorbike_list){
        std::vector<std::string> data = bike->getMotorbikeInfo();
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
        std::cout << "Enter your phone number: ";
        std::getline(std::cin, phonenumber,'\n');
    } while (!isNumber(phonenumber) && phonenumber.length() == 10);    

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
    if (id_type == 0){
        do{
            std::cout << "Enter your Citizen ID number: ";
            std::getline(std::cin, id_number,'\n');
        } while (!isNumber(id_number) && id_number.length() == 12);
    } else if (id_type == 1){
        do {
            std::cout << "Enter your Passport number: ";
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
        bikeSignup();
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
            std::cout << "Login Successfully" << std::endl;
            current_member = mem;
            break;
        }
    }
    // check for bike that own and bike that currently rentinng (check by date)
    bool ownbike_flag = false;
    bool rentbike_flag = false;
    if (current_member != nullptr){
        for (auto bike : motorbike_list){
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
        std::cout << "Login Successfully" << std::endl;
        return true;
    }
    std::cout << "Wrong Username or Password. Login Failed!" << std::endl;
    return false; 
}
int System::bikeSignup(){

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
    Motorbike *newbike = new Motorbike(bike_info[0], bike_info[1], bike_info[2], std::stoi(bike_info[3]),
                                    bike_info[4], std::stoi(bike_info[5]), bike_info[6], bike_info[7],
                                    std::stoi(bike_info[8]), bike_info[9], bike_info[10], std::stof(bike_info[11]),
                                    std::stoi(bike_info[12]), std::stoi(bike_info[13]), "");
    motorbike_list.push_back(newbike);

    std::cout << "Add new bike successfully!" << std::endl;
    return 0;
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
    std::cout << "8. Logout" << std::endl;
    
    int choice = choiceInRange(1, 8);

    switch (choice){
        case 1:
            current_member->showMemberInfo();
            memberMenu();
            break;
        case 2:
            current_member->getOwnedBike()->showMotorbikeInfo();
            memberMenu();
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
            break;
        case 6:
            rentMotorbikeMenu();
            break;
        case 7:
            current_member->addCredits();
            break;
        case 8: 
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
    std::string location = (loc == 1) ? "HN" : "HCM";

    std::cout << std::string(130, '-') << std::endl;
    std::cout << "No. "   
              << std::setw(10) << "BikeID"
              << std::setw(18) << "Model"
              << std::setw(10) << "Color"
              << std::setw(15) << "Engine Sizes"
              << std::setw(22) << "Transmission Mode"
              << std::setw(15) << "Year Made"
              << std::setw(15) << "Location"
              << std::setw(15) << "Rent Cost"
              << std::setw(15) << "Min Member Rating"
              << std::setw(15) << "Availability"
              << std::setw(15) << "Description" 
              << std::endl;
    std::cout << std::string(130, '-') << std::endl;
    int count = 1;
    for(auto bike4rent : motorbike_list){
        std::vector<std::string> bike_data = bike4rent->getMotorbikeInfo();
        if(bike_data[7] == location             // check for location
            && std::stoi(bike_data[12]) == 1    // check for listed bike
            && std::stoi(bike_data[13]) == 1    // check for available bike
            && std::stof(bike_data[11]) <= std::stof(current_member->getMemberInfo()[12])){ // check for min rating
            std::cout << " " << count << "   ";
            std::cout << std::setw(9) << bike_data[0]    // bikeID
                      << std::setw(18) << bike_data[1]   // model
                      << std::setw(14) << bike_data[2]   // color
                      << std::setw(16) << bike_data[3]   // engine size
                      << std::setw(19) << bike_data[4]   // transmission mode
                      << std::setw(15) << bike_data[5]   // year made
                      << std::setw(17) << bike_data[7]   // location
                      << std::setw(11) << bike_data[8]   // rent cost
                      << std::setw(15) << std::fixed << std::setprecision(2) << std::stof(bike_data[11])   // min rating
                      << std::setw(10) << (std::stoi(bike_data[12])? "Available":"Unavailable")    // availability
                      << std::setw(15) << bike_data[6]   // description
                      << std::endl;
            count++;
        }
    }
    std::cout << std::string(130, '-') << std::endl;

    
    std::cout << "Choose a bike to rent: ";
    std::cout << "0. Return" << std::endl;
    std::cout << "1 - " << count-1 << ". Choose a bike" << std::endl;
    
    std::string start_date, end_date;
    int bike_choice = choiceInRange(1, count);
    if (bike_choice == 0){
        memberMenu();
    } else {
        current_motorbike = motorbike_list[bike_choice-1];  // set current motorbike

        std::string requestID = randomIDs("request");
        std::string renterID = current_member->getMemberInfo()[0];
        std::string ownerID;
        for(auto owner : member_list){
            if (owner->getMemberInfo()[10] == current_motorbike->getMotorbikeID()){
                ownerID = owner->getMemberInfo()[0];
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
        
        // create new request
        Request *newRequest = new Request(requestID, renterID, 
                                          ownerID, bikeID, 
                                          start_date, end_date, 
                                          totalRentCost, "Pending");
        current_member->addRentRequest(newRequest);   
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
        std::cerr << "Error: Could not open Member.txt file" << std::endl;
        return 1;
    }
    std::string line;
    while(std::getline(file, line)){
        std::vector<std::string> data;  // store substring of line
        
        data = splitString (line, '|');
        
        Member *member = new Member(data[0], data[1], data[2], 
                                    data[3], data[4], 
                                    std::stoi(data[5]), data[6], 
                                    data[7], data[8], 
                                    std::stoi(data[9]), 
                                    data[10], data[11], 
                                    std::stof(data[12]));
        member_list.push_back(member);
    }
    file.close();
   
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
    while (std::getline(file,line)){
        std::vector<std::string> data;
        data = splitString(line, '|');
        Motorbike *bike = new Motorbike (data[0], data[1], data[2], std::stoi(data[3]), 
                                        data[4], std::stoi(data[5]), data[6], data[7], 
                                        std::stoi(data[8]), data[9], data[10], 
                                        std::stof(data[11]), std::stoi(data[12]), std::stoi(data[13]), data[14]);
        motorbike_list.push_back(bike);
    }
    file.close();
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

    for (auto mem : member_list){
        std::vector<std::string> data = mem->getMemberInfo();
        file << mem->getUsername() << '|' << mem->getPassword() << '|' << data[2] << '|'
             << data[3] << '|' << data[4] << '|' << data[5] << '|'
             << data[6] << '|' << data[7] << '|' << data[8] << std::endl;
    }
    return 0;
}
int System::saveMotorbike(){
    std::ofstream file;
    file.open(MOTORBIKE_FILE, std::fstream::out);
    if (!file.is_open()){
        std::cerr << "Error: Could not open file" << std::endl;
        return 1;
    }
    for(auto bike : motorbike_list){
        std::vector<std::string> data = bike->getMotorbikeInfo();
        file << data[0] << '|' << data[1] << '|' << data[2] << '|' << data[3] << '|' 
             << data[4] << '|' << data[5] << '|' << data[6] << '|' << data[7] << '|' 
             << data[8] << '|' << data[9] << '|' << data[10] << '|' << data[11] << '|' 
             << data[12] << '|' << data[13] << std::endl;
    }
    return 0;
}

int System::logout(){
    saveMember();
    saveMotorbike();
    current_member->logout();
    current_motorbike->logout();

    current_member = nullptr;
    current_motorbike = nullptr;
    admin = nullptr;

    for(auto mem : member_list){
        delete mem;
    }
    for(auto bike : motorbike_list){
        delete bike;
    }
    return 0;
}