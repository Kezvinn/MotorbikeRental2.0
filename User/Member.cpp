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
int Member::init(){
    loadRequest();
    loadMemberReview();
    // this->getOwnedBike()->loadMotorbikeReview();
    return 0;
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
int Member::setMemberRating(float rating){ this->memberRating = rating; return 0; }
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
    std::cout << "1. View Past Requests" << std::endl;
    std::cout << "2. View Pending Requests" << std::endl;
    std::cout << "3. Return" << std::endl;
    int choice_1 = choiceInRange(1, 3);
    
    int count = 1;
    int count_1 = 1;
    std::cout << std::string(125, '-') << std::endl;
    std::cout << std::left;
    std::cout << std::setw(10) << "No. "   
              << std::setw(15) << "Request ID"
              << std::setw(15) << "Renter ID"   
              << std::setw(15) << "Owner ID"     
              << std::setw(15) << "Motorbike ID"    
              << std::setw(15) << "Start Date"
              << std::setw(15) << "End Date"  
              << std::setw(15) << "Rent Cost"   
              << std::setw(10) << "Status" <<  std::endl;
    
    std::vector<std::string> rqst_data;
// past request 
    if (choice_1 == 1) {
        for(auto rqst : this->rentRequest) {
            rqst_data.clear();
            rqst_data = rqst->getRequestInfo();
            if (rqst_data[2] == this->memberID 
                && rqst_data[3] == this->ownedbikeID
                && rqst_data[7] != "Pending") {  
                std::cout << std::left;
                std::cout << count << "." <<std::string(10,' ');
                std::cout << std::setw(15) << rqst_data[0]  // Request ID
                        << std::setw(15) << rqst_data[1]  // Renter ID
                        << std::setw(16) << rqst_data[2]  // Owner ID
                        << std::setw(12) << rqst_data[3]  // Motorbike ID
                        << std::setw(15) << rqst_data[4]  // Start Date
                        << std::setw(18) << rqst_data[5]  // End Date
                        << std::setw(12) << rqst_data[6]  // Rent Cost
                        << std::setw(10) << rqst_data[7]  // Status
                        << std::endl;
                count++;
            }
        }
        std::cout << std::string(125,'-') << std::endl;
        if (count - 1 == 0){
            std::cout << "No request available!" << std::endl;
            return 0;
        }
        std::cout << "Return to Member Menu? (Y/N): " << std::endl;
        char rtn = returnYes();
        if (rtn == 'Y' || rtn == 'y'){
            return 0;
        }
    }
// current pending request 
    else if (choice_1 == 2) {  // current pending request
        for(auto rqst : this->rentRequest) {
            rqst_data.clear();
            rqst_data = rqst->getRequestInfo();
            if (rqst_data[2] == this->memberID 
                && rqst_data[3] == this->ownedbikeID
                && rqst_data[7] == "Pending") {  
                std::cout << std::left;
                std::cout << count_1 << "." <<std::string(10,' ');
                std::cout << std::setw(15) << rqst_data[0]  // Request ID
                        << std::setw(15) << rqst_data[1]  // Renter ID
                        << std::setw(16) << rqst_data[2]  // Owner ID
                        << std::setw(12) << rqst_data[3]  // Motorbike ID
                        << std::setw(15) << rqst_data[4]  // Start Date
                        << std::setw(18) << rqst_data[5]  // End Date
                        << std::setw(12) << rqst_data[6]  // Rent Cost
                        << std::setw(10) << rqst_data[7]  // Status
                        << std::endl;
                count_1++;
            }
        }
        std::cout << std::string(125,'-') << std::endl;
        if (count_1 - 1 == 0){
            std::cout << "No request available!" << std::endl;
            return 0;
        }
        // Member can choose which request to approvel and denied then return back to 
        std::cout << "Choose request to approve/deny: " << std::endl;
        std::cout << "0. Return" << std::endl;
        std::cout << "1 - " << count_1 - 1 << ". Approve/Deny the request" << std::endl;
        int choice = choiceInRange(0, count_1-1);
        if (choice == 0) {
            return 0;
        } else {
            if (rentRequest[choice]->getRequestInfo()[7] == "Pending") {
                std::cout << "Action: " << std::endl;
                std::cout << "1. Approve request." << std::endl;
                std::cout << "2. Deny request." << std::endl;
                int action = choiceInRange(1, 2);
                if (action == 1){
                    rentRequest[choice]->setRqstStt("Approved");
                    std::cout << rentRequest[choice-1]->getRequestInfo()[7] << std::endl;
                    std::cout << "Request Approved!" << std::endl;
                } else if (action == 2){
                    rentRequest[choice]->setRqstStt("Denied");
                    std::cout << rentRequest[choice-1]->getRequestInfo()[7] << std::endl;
                    std::cout << "Request Denied!" << std::endl;
                }
            }
        }
    } else if (choice_1 == 3){
        return 0;
    }
    return 0;
}

// Rate Rented Motorbike
int Member::rateMotorbikeMenu(){
    std::cout << "+==========================================+" << std::endl;
    std::cout << "|            Rate Motorbike Menu           |" << std::endl;
    std::cout << "+==========================================+" << std::endl;
    std::cout << "1. Review Rented Motorbike." << std::endl;
    std::cout << "2. View Past Review." << std::endl;
    std::cout << "3. Return." << std::endl;
    int count = 1;
    // get bike view into vector based on the bike iD of the object
    std::cout << std::string(100, '-') << std::endl;
    std::cout << std::left;
    std::cout << std::setw(10) << "No."       
                << std::setw(15) << "Review ID"
                << std::setw(15) << "Renter ID "
                << std::setw(15) << "Motorbike ID"    
                << std::setw(15) << "Rating"       
                << std::setw(15) << "Comment"    
                << std::setw(15) << "Status" 
                << std::endl;
    
    
    // std::vector<MotorbikeReview*> review = this->getRentedBike()->getMotorbikeReview();
    // std::vector<std::string> rev_data;
    // for (auto rev : review){
    //     rev_data.clear();
    //     rev_data = rev->getMotorbikeReviewInfo();
    //     std::cout << std::left;
    //     std::cout << std::setw(10) << count  
    //               << std::setw(15) << rev_data[0]
    //               << std::setw(15) << rev_data[1] 
    //               << std::setw(15) << rev_data[2]
    //               << std::setw(15) << rev_data[3] 
    //               << std::setw(15) << rev_data[4]
    //               << std::setw(15) << rev_data[5] << std::endl; 
    //     count++;
    // }
    std::cout << std::string(100, '-') << std::endl;
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
    std::cout << "1. View Past Review" << std::endl;
    std::cout << "2. View Pending Review" << std::endl;
    std::cout << "3. View Received Review" << std::endl;
    std::cout << "4. Return" << std::endl;
    int choice_1 = choiceInRange(1, 4);
    int count = 1;
    
    std::vector<std::string> rev_data;
    std::cout << std::left;
    if (choice_1 == 1){
        count = 1;
        std::cout << std::setw(10) << "No."       
              << std::setw(15) << "Review ID"
              << std::setw(15) << "Reviewer ID"              
              << std::setw(15) << "Reviewee ID"       
              << std::setw(15) << "Status" 
              << std::setw(15) << "Rating" 
              << std::setw(15) << "Comment"     
              << std::endl;
        std::cout << std::string(100,'-') << std::endl;
        for (auto rev : this->memberReview){
            rev_data.clear();
            rev_data = rev->getMemberReviewInfo();
            if (rev->getMemRevStt() == "Complete"){
                std::cout << std::left;
                std::cout << count << "." << std::string(8, ' ') 
                        << std::setw(15) << rev_data[0]
                        << std::setw(15) << rev_data[1] 
                        << std::setw(15) << rev_data[2]
                        << std::setw(15) << rev_data[3] 
                        << std::setw(15) << std::fixed << std::setprecision(2) << std::stof(rev_data[4])
                        << std::setw(15) << rev_data[5] << std::endl; 
                count++;
            }
        }
        std::cout << "Return?" << std::endl;
        char c = returnYes();
        if (c == 'Y' || c == 'y'){
            rateRenterMenu();
        }
    } else if (choice_1 == 2){
        count = 1;
        std::cout << std::setw(10) << "No."       
              << std::setw(15) << "Review ID"
              << std::setw(15) << "Reviewer ID"              
              << std::setw(15) << "Reviewee ID"       
              << std::setw(15) << "Status" 
              << std::setw(15) << "Rating" 
              << std::setw(15) << "Comment"     
              << std::endl;
        std::cout << std::string(100,'-') << std::endl;
        for (auto rev : this->memberReview){
            rev_data.clear();
            rev_data = rev->getMemberReviewInfo();
            if (rev->getMemRevStt() == "Pending"){
                std::cout << std::left;
                std::cout << count << "." << std::string(8, ' ') 
                        << std::setw(15) << rev_data[0]
                        << std::setw(15) << rev_data[1] 
                        << std::setw(15) << rev_data[2]
                        << std::setw(15) << rev_data[3] 
                        << std::setw(15) << std::fixed << std::setprecision(2) << std::stof(rev_data[4])
                        << std::setw(15) << rev_data[5] << std::endl; 
                count++;
            }
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
            std::getline(std::cin, comment);
            
            // update review
            this->memberReview[choice-1]->setRating(rating);
            this->memberReview[choice-1]->setComment(comment);
            this->memberReview[choice-1]->setMemRevStt("Complete");
        }
    } else if (choice_1 == 3){
        count = 1;
        std::cout << std::setw(10) << "No."       
              << std::setw(15) << "Review ID"
              << std::setw(15) << "Reviewer ID"              
              << std::setw(15) << "Reviewee ID"       
              << std::setw(15) << "Status" 
              << std::setw(15) << "Rating" 
              << std::setw(15) << "Comment"     
              << std::endl;
        std::cout << std::string(100,'-') << std::endl;
        for (auto rev : this->memberReview){
            rev_data.clear();
            rev_data = rev->getMemberReviewInfo();
            if (rev_data[2] == this->memberID){
                std::cout << std::left;
                std::cout << count << "." << std::string(8, ' ') 
                        << std::setw(15) << rev_data[0]
                        << std::setw(15) << rev_data[1] 
                        << std::setw(15) << rev_data[2]
                        << std::setw(15) << rev_data[3] 
                        << std::setw(15) << std::fixed << std::setprecision(2) << std::stof(rev_data[4])
                        << std::setw(15) << rev_data[5] << std::endl; 
                count++;
            }
        }
        std::cout << "Return?" << std::endl;
        char c = returnYes();
        if (c == 'Y' || c == 'y'){
            rateRenterMenu();
        }
    } else if (choice_1 == 4){
        return 0;
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
    char ans = returnYesNo();
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
        std::cout << "File is empty!" << std::endl;
        return 0;
    } else {
        // Read file
        std::string line;
        std::vector<std::string> request_info;
        while (std::getline(file, line)){
            request_info.clear();   
            request_info = splitString(line, '|');
            // load request base on owner ID
            if (request_info[2] == this->getMemberID()) { 
                Request *new_request = new Request(request_info[0], request_info[1], 
                                                   request_info[2], request_info[3], 
                                                   request_info[4], request_info[5], 
                                                   std::stoi(request_info[6]), request_info[7]);
                this->rentRequest.push_back(new_request);
                std::cout << "Requested added" << std::endl;
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
            if (line.empty()){
                continue;
            }
            review_info.clear();
            review_info = splitString(line, '|');
            MemberReview *review = new MemberReview();
            // load both reviewee and reviewer into memberReview vector
            if (review_info[1] == this->memberID || review_info[2] == this->memberID){
                if (review->parseFromLine(line)){
                    memberReview.push_back(review);
                } else {
                    delete review;
                }
                // MemberReview *new_review = new MemberReview(review_info[0], review_info[1], 
                //                                             review_info[2], review_info[3],
                //                                             std::stof(review_info[4]), review_info[5]);
                // this->memberReview.push_back(new_review);
            }
        }
        file.close();
    }
    return 0;
}

int Member::saveRequest() {
// read every request from file into vector
    std::vector <Request*> rqst_file;
    std::ifstream file_in;
    file_in.open(MEMBER_REQUEST_FILE, std::ios::in);
    
    if (!file_in.is_open()){
        std::cerr << "1. Error opening file " << MEMBER_REQUEST_FILE << std::endl;
        return 1;
    }
    std::string line;
    std::vector<std::string> request_info;
    while(std::getline(file_in, line)){
        request_info.clear();
        request_info = splitString(line, '|');
        Request *rqst = new Request(request_info[0], request_info[1], 
                                    request_info[2], request_info[3], 
                                    request_info[4], request_info[5], 
                                    std::stoi(request_info[6]), request_info[7]);
        rqst_file.push_back(rqst);
    }
    file_in.close();

// compare data
    std::vector <Request*> rqst_vec_op;
    rqst_vec_op.clear();
    bool flag = false;
    for (auto rqst_fl : rqst_file) {       // all from file
        for (auto rqst : this->rentRequest){ // from current memeber vector
            if (*rqst == *rqst_fl) {
                flag = true;
                if (rqst->getRqstStt() == "Denied" || rqst->getRqstStt() == "Approved"){
                    rqst_vec_op.push_back(rqst);
                    break;
                } 
                if (rqst->getRqstStt() == "Pending" && rqst_fl->getRqstStt() == "Pending"){
                    rqst_vec_op.push_back(rqst);
                    break;
                }
                
            } else {
                flag = false;
            } 
        }
        if (flag == true){
            continue;
        } else {
            rqst_vec_op.push_back(rqst_fl);
        }
    }
// save data to file
    std::ofstream file;
    file.open(MEMBER_REQUEST_FILE, std::ios::out);
    if (!file.is_open()){
        std::cerr << "2. Error opening file " << MEMBER_REQUEST_FILE << std::endl;
        return 1;
    }
    
    request_info.clear();
    for (Request *request : rqst_vec_op) {    // from file
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
// load the current review into object to compare
    std::vector <MemberReview*> review_file;
    std::ifstream file_in;
    file_in.open(MEMBER_REVIEW_FILE, std::ios::in);
    if (!file_in.is_open()){
        std::cerr << "1. Error opening file " << MEMBER_REQUEST_FILE << std::endl;
        return 1;
    }
    std::string line;
    std::vector<std::string> review_info;
    while(std::getline(file_in, line)){
        review_info.clear();
        review_info = splitString(line, '|');
        MemberReview *review = new MemberReview();
        if (review->parseFromLine(line)){
            review_file.push_back(review);
        } else {
            delete review;
        }
    }
    file_in.close();
// compare the 2 and between the one in vector and in file
    std::vector <MemberReview*> review_vec_op;
    review_vec_op.clear();
    bool flag = false;
    for (auto review_fl : review_file) {       // all from file
        for (auto review : this->memberReview){ // from current memeber vector
            if (*review == *review_fl) {
                flag = true;
                if (review->getMemRevStt() == "Complete"){
                    review_vec_op.push_back(review);
                    break;
                } 
                // if (review->getMemRevStt() == "Pending" && review_fl->getMemRevStt() == "Pending"){
                //     review_vec_op.push_back(review);
                //     break;
                // }
                
            } else {
                flag = false;
            } 
        }
        if (flag == true){
            continue;
        } else {
            review_vec_op.push_back(review_fl);
        }
    }
// save to a new vector -> save to file

    std::ofstream file;
    file.open(MEMBER_REVIEW_FILE, std::ios::out);
    if (!file.is_open()){
        std::cerr << "2. Error opening file " << MEMBER_REVIEW_FILE << std::endl;
        return 1;
    }
    review_info.clear();

    for (MemberReview *review : review_vec_op ){
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
    if (this->memberReview.empty()){
        return 10;
    } else {
        std::vector<std::string> rev_data;
        for (auto review : this->memberReview){
            rev_data.clear();
            rev_data = review->getMemberReviewInfo();
            if (rev_data[2] == this->getMemberID() && rev_data[3] == "Complete"){
                total_rating += std::stof(rev_data[4]);
                count++;
            }
        }
    }
    // this->memberRating = total_rating/count;
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