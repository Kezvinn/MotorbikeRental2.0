#include "Member.h"

// Default constructor
Member::Member(){}

// Parameterized constructor - use this to create new member
Member::Member(std::string username_ip, std::string password_ip,
               std::string fullname_ip, std::string phonenumber_ip, 
               bool id_type_ip, std::string id_number_ip, 
               std::string drv_license_ip, std::string exp_date_ip, 
               int credit_ip, 
               std::string ownedbikeID_ip, std::string rentedbikeID_ip,
               float memberRating_ip)
               : User(username_ip, password_ip), 
               fullname(fullname_ip), phonenumber(phonenumber_ip), 
               id_type(id_type_ip), id_number(id_number_ip),
               drv_license(drv_license_ip), exp_date(exp_date_ip), 
               credit(credit_ip), 
               ownedbikeID(ownedbikeID_ip), rentingbikeID(rentedbikeID_ip),
               memberRating(memberRating_ip) {
            this->memberID = randomIDs("member");
            }

// Parameterized constructor - use this to load member from file
Member::Member(std::string memberID_ip, std::string username_ip, std::string password_ip, 
               std::string fullname_ip, std::string phonenumber_ip, 
               bool id_type_ip, std::string id_number_ip, 
               std::string drv_license_ip, std::string exp_date_ip, 
               int credit_ip, 
               std::string ownedbikeID_ip, std::string rentedbikeID_ip,
               float memberRating_ip)
               : memberID(memberID_ip), User(username_ip, password_ip), 
               fullname(fullname_ip), phonenumber(phonenumber_ip), 
               id_type(id_type_ip), id_number(id_number_ip),
               drv_license(drv_license_ip), exp_date(exp_date_ip), 
               credit(credit_ip), 
               ownedbikeID(ownedbikeID_ip), rentingbikeID(rentedbikeID_ip),
               memberRating(memberRating_ip) {
                loadRequest();
                loadMemberReview();
               };

// Destructor
Member::~Member(){
    delete this->ownedbike;
    delete this->rentedbike;
}
// Member Login
bool Member::memberLogin(std::string &username_ip, std::string &pwd_ip){
    if ((username_ip == this->getUsername()) && (pwd_ip == this->getPassword())){
        return true;
    }
    return false;
}

// Getter 
Motorbike* Member::getOwnedBike() const{ return this->ownedbike; }
Motorbike* Member::getRentedBike() const{ return this->rentedbike; }
std::string Member::getOwnbikeID(){ return this->ownedbikeID; }
std::string Member::getRentBikeID(){ return this->rentingbikeID; }
std::string Member::getMemberID(){ return this->memberID; }
std::vector<std::string> Member::getMemberInfo() {
    std::vector<std::string> member_info;
    std::string uname, pwd;
    member_info.push_back(this->memberID);                      // 0
    member_info.push_back(this->User::getUsername());           // 1
    member_info.push_back(this->User::getPassword());           // 2
    member_info.push_back(this->fullname);                      // 3
    member_info.push_back(this->phonenumber);                   // 4
    member_info.push_back(std::to_string(this->id_type));       // 5
    member_info.push_back(this->id_number);                     // 6
    member_info.push_back(this->drv_license);                   // 7
    member_info.push_back(this->exp_date);                      // 8
    member_info.push_back(std::to_string(this->credit));        // 9
    member_info.push_back(this->ownedbikeID);                   // 10
    member_info.push_back(this->rentingbikeID);                 // 11
    member_info.push_back(std::to_string(this->memberRating));  // 12

    return member_info;
}

// Setter
int Member::setOwnedBike(Motorbike *bike){ this->ownedbike = bike; return 0; }
int Member::setRentedBike(Motorbike *bike){ this->rentedbike = bike; return 0; }
int Member::setOwnbikeID(std::string bikeID){ this->ownedbikeID = bikeID; return 0; }            
int Member::setRentBikeID(std::string bikeID){ this->rentingbikeID = bikeID; return 0; }

int Member::addRentRequest(Request *newRequest){ this->rentRequest.push_back(newRequest); return 0; }
int Member::addMemberReview(MemberReview *newReview){ this->memberReview.push_back(newReview); return 0; }

void Member::showMemberInfo(){
    std::cout << "+==========================================+" << std::endl;
    std::cout << "|            Member Information            |" << std::endl;
    std::cout << "+==========================================+" << std::endl;

    std::cout << std::string(30,'-') << std::endl;
    std::cout << std::left;
    std::cout << std::setw(18) << "Member ID: "         << this->memberID << std::endl;
    std::cout << std::setw(18) << "Username: "          << this->getUsername() << std::endl;
    std::cout << std::setw(18) << "Password: "          << this->getPassword() << std::endl;
    std::cout << std::setw(18) << "Fullname: "          << this->fullname << std::endl;
    std::cout << std::setw(18) << "Phone number: "      << this->phonenumber << std::endl;
    std::cout << std::setw(18) << "ID type: "           << (this->id_type == 0 ? "Citizen ID" : "Passport") << std::endl;
    std::cout << std::setw(18) << "ID number: "         << this->id_number << std::endl;
    std::cout << std::setw(18) << "Driver license: "    << this->drv_license << std::endl;
    std::cout << std::setw(18) << "Expire date: "       << this->exp_date << std::endl;
    std::cout << std::setw(18) << "Credit: "            << this->credit << " credits" << std::endl;
    std::cout << std::setw(18) << "Owned bike ID: "     << this->ownedbikeID << std::endl;
    std::cout << std::setw(18) << "Rented bike ID: "    << this->rentingbikeID << std::endl;
    std::cout << std::setw(18) << "Member rating: "     << std::fixed << std::setprecision(2) << this->memberRating << std::endl;
    std::cout << std::string(30, '-') << std::endl;
}

int Member::rentRequestMenu(){
    // view all request based on the this member ID
    std::cout << "+==========================================+" << std::endl;
    std::cout << "|              Request Menu                |" << std::endl;
    std::cout << "+==========================================+" << std::endl;
    int count = 1;
    std::cout << std::string(130, '-') << std::endl;
    std::cout << "No. "   
              << std::setw(15) << "Request ID"
              << std::setw(15) << "Renter ID"   
              << std::setw(15) << "Owner ID"     
              << std::setw(15) << "Motorbike ID"    
              << std::setw(15) << "Start Date"
              << std::setw(15) << "End Date"  
              << std::setw(15) << "Rent Cost"   
              << std::setw(10) << "Status" <<  std::endl;
    std::vector<std::string> rqst_data;    
    for(auto rqst : this->rentRequest) {
        rqst_data.clear();
        rqst_data = rqst->getRequestInfo();
        if (rqst_data[2] == this->memberID && rqst_data[3] == this->ownedbikeID) {  
            std::cout << " " << count << "   ";
            std::cout << std::setw(15) << rqst_data[0]  // Request ID
                      << std::setw(15) << rqst_data[1]  // Renter ID
                      << std::setw(15) << rqst_data[2]  // Owner ID
                      << std::setw(15) << rqst_data[3]  // Motorbike ID
                      << std::setw(15) << rqst_data[4]  // Start Date
                      << std::setw(15) << rqst_data[5]  // End Date
                      << std::setw(15) << rqst_data[6]  // Rent Cost
                      << std::setw(10) << rqst_data[7]  // Status
                      << std::endl;
            std::cout << std::string(130,'-') << std::endl;
            count++;
        }
    }
    // Member can choose which request to approvel and denied then return back to 
    int choice = choiceInRange(0, count-1);
    std::cout << "0. Return" << std::endl;
    std::cout << "1 - " << count-1 << ". Approve/Deny the request" << std::endl;
    if (choice == 0) {
        return 0;
    } else {
        if (rentRequest[choice-1]->getRequestInfo()[7] == "Pending") {
            std::cout << "Action: " << std::endl;
            std::cout << "1. Approve request." << std::endl;
            std::cout << "2. Deny request." << std::endl;
            int action = choiceInRange(1, 2);
            if (action == 1){
                rentRequest[choice-1]->getRequestInfo()[7] = "Approved";
                std::cout << "Request Approved!" << std::endl;
            } else if (action == 2){
                rentRequest[choice-1]->getRequestInfo()[7] = "Denied";
                std::cout << "Request Denied!" << std::endl;
            }
        } else {
            std::cout << "Request already " << rentRequest[choice-1]->getRequestInfo()[7] << "!" << std::endl;
            rentRequestMenu();
        }
    }
    return 0;
}

// Rate Rented Motorbike
int Member::rateMotorbikeMenu(){
    std::cout << "+==========================================+" << std::endl;
    std::cout << "|            Rate Motorbike Menu           |" << std::endl;
    std::cout << "+==========================================+" << std::endl;
    
    int count = 1;
    // get bike view into vector based on the bike iD of the object
    std::vector<MotorbikeReview*> review = this->rentedbike->getMotorbikeReview();
    std::vector<std::string> rev_data;
    for (auto rev : review){
        rev_data.clear();
        rev_data = rev->getMotorbikeReviewInfo();
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << "No.       Review ID       Renter ID       Motorbike ID    Rating       Comment     Status" << std::endl;
        std::cout << count << "     " 
                  << rev_data[0] << "    "
                  << rev_data[1] << "    " 
                  << rev_data[2] << "    "
                  << rev_data[3] << "    " 
                  << rev_data[4] << "    "
                  << rev_data[5] << std::endl; 
        count++;
    }
    // member can choose which review to rate
    std::cout << "0. Return" << std::endl;
    std::cout << "1 - " << count-1 << ". Motorbike to Review" << std::endl;
    int choice = choiceInRange(0, count-1);
    
    float rating;
    std::string comment;

    if (choice == 0){
        return 0;
    } else {
        do {
            std::cout << "Enter Rating (1-10): ";
            std::cin >> rating;
            if (std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
            }
        } while (rating < 1 || rating > 10);
        
        std::cin.ignore();
        std::cout << "Enter Comment: ";
        std::cin >> comment;
        
        // update the review
        std::string reviewID = randomIDs("review");
        MotorbikeReview *bikeReview = new MotorbikeReview(reviewID, this->memberID,
                                                          this->rentingbikeID, "Complete", 
                                                          rating, comment);
        this->rentedbike->getMotorbikeReview().push_back(bikeReview);
    }
    return 0;
}

// Rate Renter
int Member::rateRenterMenu(){
    std::cout << "+==========================================+" << std::endl;
    std::cout << "|              Rate Renter Menu            |" << std::endl;
    std::cout << "+==========================================+" << std::endl;
    
    int count = 1;
    // get bike view into vector based on the bike iD of the object
    std::vector<MemberReview*> review = this->memberReview;
    std::vector<std::string> rev_data;
    for (auto rev : review){
        rev_data.clear();
        rev_data = rev->getMemberReviewInfo();
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << "No.       Review ID       Reviewee ID       Rating       Comment     Status" << std::endl;
        std::cout << count << "     " 
                  << rev_data[0] << "    "
                  << rev_data[1] << "    " 
                  << rev_data[2] << "    "
                  << rev_data[3] << "    " 
                  << rev_data[4] << "    "
                  << rev_data[5] << std::endl; 
        count++;
    }
    // member can choose which review to rate
    std::cout << "0. Return" << std::endl;
    std::cout << "1 - " << count-1 << ". Renter to Review" << std::endl;
    int choice = choiceInRange(0, count-1);
    
    float rating;
    std::string comment;

    if (choice == 0){
        return 0;
    } else {
        do {
            std::cout << "Enter Rating (1-10): ";
            std::cin >> rating;
            if (std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
            }
        } while (rating < 1 || rating > 10);
        
        std::cin.ignore();
        std::cout << "Enter Comment: ";
        std::cin >> comment;
        
        // update the review
        std::string reviewID = randomIDs("review");
        MemberReview *memberReview = new MemberReview(reviewID, this->memberID,
                                                      this->rentingbikeID, "Complete", 
                                                      rating, comment);
        this->memberReview.push_back(memberReview);
    }
    return 0;
}
// Top up credit
int Member::addCredits(){
    std::cout << "+==========================================+" << std::endl;
    std::cout << "|              Add Credits Menu            |" << std::endl;
    std::cout << "+==========================================+" << std::endl;
    
    int credit_ip;
    
    std::cout << "Current Credits: " << this->credit << " credits" << std::endl;
    std::cout << std::string(44, '-') << std::endl;
    do {    
        std::cout << "Enter amount of credits to add (> 0): ";
        std::cin >> credit_ip;
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore();
        }
    } while (credit_ip <= 0);

    std::cout << std::string(44, '-') << std::endl;
    char ans;
    do {
        std::cout << "Credit add: " << credit_ip << " credits" <<  std::endl;
        std::cout << "Confirmation (Y/N): ";
        std::cin >> ans;
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore();
        }
    } while (tolower(ans) != 'y' && tolower(ans) != 'n');

    std::cout << std::string(44, '-') << std::endl;
    if ((ans == 'Y' || ans == 'y') && credit_ip > 0){
        this->credit += credit_ip;
        std::cout << "You had add " << credit_ip << " credits"<< std::endl;
        std::cout << "Your current balance: " << this->credit << " credits" << std::endl;
    } else if (ans == 'N' || ans == 'n'){
        std::cout << "Transaction canceled!" << std::endl;
    }
    return 0;
}
// Logout and save info
int Member::logout(){
    saveRequest();
    saveMemberReview();
    return 0;
}

int Member::loadRequest(){
    // Clear the vector
    rentRequest.clear();
    // Open file
    std::ifstream file;
    file.open(MEMBER_REQUEST_FILE, std::ios::in);
    if (!file.is_open()){
        std::cerr << "1. Error opening file " << MEMBER_REQUEST_FILE << std::endl;
        return 1;
    }

    if (isFileEmpty(MEMBER_REQUEST_FILE)){
        file.close();
        return 0;
    } else {
        // Read file
        std::string line;
        std::vector<std::string> request_info;
        while (std::getline(file, line)){
            // if (line.empty()){
            //     continue;
            // }

            request_info.clear();   
            request_info = splitString(line, '|');
            // load request base on owner ID
            if (request_info[2] == this->memberID) {    
                // if (rqst->parseFromLine(line)) {
                //     rentRequest.push_back(rqst);
                // } else {
                //     delete rqst;
                // }
                
                Request *new_request = new Request(request_info[0], request_info[1], 
                                                request_info[2], request_info[3], 
                                                request_info[4], request_info[5], 
                                                std::stoi(request_info[6]), request_info[7]);
                this->rentRequest.push_back(new_request);
            }
        }
        file.close();
    }
    
    return 0;
}
int Member::loadMemberReview(){
    std::ifstream file;
    file.open(MEMBER_REVIEW_FILE, std::ios::in);
    if (!file.is_open()){
        std::cerr << "1. Error opening file " << MEMBER_REVIEW_FILE << std::endl;
        return 1;
    }
    if (isFileEmpty(MEMBER_REVIEW_FILE)){
        file.close();
        return 0;
    } else {
        std::string line;
        std::vector<std::string> review_info;
        while (std::getline(file, line)){
            // if (line.empty()){
            //     continue;
            // }
            review_info.clear();
            review_info = splitString(line, '|');
            MemberReview *review = new MemberReview();
            if (review_info[1] == this->memberID || review_info[2] == this->memberID){
                // if (review->parseFromLine(line)){
                //     memberReview.push_back(review);
                // } else {
                //     delete review;
                // }
                MemberReview *new_review = new MemberReview(review_info[0], review_info[1], 
                                                            review_info[2], review_info[3],
                                                            std::stof(review_info[4]), review_info[5]);
                this->memberReview.push_back(new_review);
            }
        }
        file.close();
    }
    return 0;
}

int Member::saveRequest(){
    std::ofstream file;
    file.open(MEMBER_REQUEST_FILE, std::ios::app);
    if (!file.is_open()){
        std::cerr << "2. Error opening file " << MEMBER_REQUEST_FILE << std::endl;
        return 1;
    }
    std::vector<std::string> request_info;
    for (Request *request: this->rentRequest) {
        request_info.clear();
        request_info = request->getRequestInfo();
        int data_size = request_info.size();
        for (int i = 0; i < data_size; i++){
            file << request_info[i];
            if (i != data_size - 1){
                file << "|";
            }
        }
        file << std::endl;
    }
    file.close();
    std::cout << "Requests saved successfully!" << std::endl;
    return 0;
}
int Member::saveMemberReview(){
    std::ofstream file;
    file.open(MEMBER_REVIEW_FILE, std::ios::app);
    if (!file.is_open()){
        std::cerr << "2. Error opening file " << MEMBER_REVIEW_FILE << std::endl;
        return 1;
    }
    std::vector<std::string> review_info;
    for (MemberReview *review: this->memberReview){
        review_info.clear();
        review_info = review->getMemberReviewInfo();
        int data_size = review_info.size();
        for (int i = 0; i < data_size; i++){
            file << review_info[i];
            if (i != data_size - 1){
                file << "|";
            }
        }
        file << std::endl;
    }
    file.close();
    std::cout << "Member Review saved successfully!" << std::endl;
    return 0;
}
float Member::calcMemberRating(){
    float total_rating = 0;
    int count = 0;
    for (auto review : this->memberReview){
        std::vector<std::string> rev_data = review->getMemberReviewInfo();
        if (rev_data[2] == this->getMemberID() && rev_data[3] == "Complete"){
            total_rating += std::stof(rev_data[4]);
            count++;
        }
    }
    return total_rating/count;
}

bool Member::parseFromLine(const std::string& line){
    std::istringstream iss(line);
    std::string token;
    std::string username_ip, pwd_ip;
    try {
        std::getline(iss, memberID, '|');         // MemID
        std::getline(iss, username_ip, '|');      // username
        this->setUsername(username_ip);
        std::getline(iss, pwd_ip, '|');           // password 
        this->setPassword(pwd_ip);

        std::getline(iss, fullname, '|');         // fullname
        std::getline(iss, phonenumber, '|');      // phone number
        
        std::getline(iss, token, '|');            // id type
        id_type = std::stoi(token);

        std::getline(iss, id_number, '|');        // ID number
        std::getline(iss, drv_license, '|');      // drv_license
        std::getline(iss, exp_date, '|');         // exp date

        std::getline(iss, token, '|');            // credit
        credit = std::stoi(token);

        std::getline(iss, ownedbikeID, '|');      // ownedbikeID
        std::getline(iss, rentingbikeID, '|');    // rentingbikeID
        
        std::getline(iss, token, '|');            // mem rating
        memberRating = std::stof(token);


    } catch (const std::exception& e) {
        std::cerr << "Error parsing line: " << line << "\nException: " << e.what() << std::endl;
        return false;
    }

    return true;
}