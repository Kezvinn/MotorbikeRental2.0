#include "Member.h"
Member::Member(){}
Member::Member(std::string memberID_ip, std::string username_ip, std::string password_ip, 
               std::string fullname_ip, std::string phonenumber_ip, 
               bool id_type_ip, std::string id_number_ip, 
               std::string drv_license_ip, std::string exp_date_ip, 
               int credit_ip, 
               std::string ownedbikeID_ip, std::string rentedbikeID_ip,
               float memberRating_ip)
               :memberID(memberID_ip), User(username_ip, password_ip), 
               fullname(fullname_ip), phonenumber(phonenumber_ip), 
               id_type(id_type_ip), id_number(id_number_ip),
               drv_license(drv_license_ip), exp_date(exp_date_ip), 
               credit(credit_ip), 
               ownedbikeID(ownedbikeID_ip), rentingbikeID(rentedbikeID_ip),
               memberRating(memberRating_ip)
    {
        if (this->memberID.empty()){
            memberID = randomIDs("member");
        } else {
            this->memberID = memberID_ip;
        }
    };
Member::~Member(){
    delete this->ownedbike;
    delete this->rentedbike;
}

int Member::memberLogin(std::string &username_ip, std::string &pwd_ip){
    if ((username_ip == this->getUsername()) && (pwd_ip == this->getPassword())){
        return true;
    }
    return false;
}
Motorbike* Member::getOwnedBike() const{ return this->ownedbike; }
Motorbike* Member::getRentedBike() const{ return this->rentedbike; }
int Member::setOwnedBike(Motorbike *bike){ this->ownedbike = bike; return 0; }
int Member::setRentedBike(Motorbike *bike){ this->rentedbike = bike; return 0; }



std::vector<std::string> Member::getMemberInfo(){
    std::vector<std::string> member_info;

    member_info.push_back(this->memberID);                      // 0    
    member_info.push_back(this->getUsername());                 // 1
    member_info.push_back(this->getPassword());                 // 2
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

int Member::addRentRequest(Request *newRequest){
    this->rentRequest.push_back(newRequest);
    return 0;
}
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
            
    for(auto rqst : this->rentRequest) {
        std::vector <std::string> rqst_data = rqst->getRequestInfo();
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
            std::cout << "1. Approve" << std::endl;
            std::cout << "2. Deny" << std::endl;
            int action = choiceInRange(1, 2);
            if (action == 1){
                rentRequest[choice-1]->getRequestInfo()[7] = "Approved";
                std::cout << "Request Approved!" << std::endl;
            } else {
                rentRequest[choice-1]->getRequestInfo()[7] = "Denied";
                std::cout << "Request Denied!" << std::endl;
            }
        } else {
            std::cout << "Request already " << rentRequest[choice-1]->getRequestInfo()[7] << std::endl;
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
    for (auto rev : review){
        std::vector<std::string> rev_data = rev->getMotorbikeReviewInfo();
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
        // return to previous menu
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
}

// Top up credit
int Member::addCredits(){
    std::cout << "+==========================================+" << std::endl;
    std::cout << "|              Add Credits Menu            |" << std::endl;
    std::cout << "+==========================================+" << std::endl;
    
    int credit_ip;
    
    std::cout << "Current Credits: " << this->credit << " credits" << std::endl;
    std::cout << "--------------------------------------------" << std::endl; 
    do {    
        std::cout << "Enter amount of credits to add (> 0): ";
        std::cin >> credit_ip;
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore();
        }
    } while (credit_ip <= 0);

    std::cout << "--------------------------------------------" << std::endl; 
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

    std::cout << "--------------------------------------------" << std::endl; 
    if ((ans == 'Y' || ans == 'y') && credit_ip > 0){
        this->credit += credit_ip;
        std::cout << "You had add " << credit_ip << " credits"<< std::endl;
        std::cout << "Your current balance: " << this->credit << " credits" << std::endl;
    } else if (ans == 'N' || ans == 'n'){
        std::cout << "Transaction canceled!" << std::endl;
    }
    return 0;
}

int Member::loadRequest(){
    rentRequest.clear();
    
    std::ifstream file;
    file.open(MEMBER_REQUEST_FILE);
    if (!file.is_open()){
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }
    
    std::string line;
    while (std::getline(file, line)){
        std::vector<std::string> request_info = splitString(line, '|');
        if (request_info[0] == this->memberID) {
            Request *new_request = new Request(request_info[0], request_info[1], 
                                               request_info[2], request_info[3], 
                                               request_info[4], request_info[5], 
                                               std::stoi(request_info[6]), request_info[7]);
            this->rentRequest.push_back(new_request);
        }
    }
    file.close();

    return 0;
}
// int Member::loadMemberReview(){
//     std::ifstream file;
//     file.open(MEMBER_REVIEW_FILE);
//     if (!file.is_open()){
//         std::cerr << "Error opening file" << std::endl;
//         return 1;
//     }
//     std::string line;
//     while (std::getline(file, line)){
//         std::vector<std::string> review_info = splitString(line, '|');
//         if (review_info[0] == this->memberID){
//             MemberReview *new_review = new MemberReview(review_info[0], review_info[1], 
//                                                         review_info[2], review_info[3],
//                                                         std::stof(review_info[4]), review_info[5]);
//             this->memberReview.push_back(new_review);
//         }
//     }
//     file.close();
//     return 0;
// }

int Member::saveRequest(){
    std::ofstream file;
    file.open(MEMBER_REQUEST_FILE);
    if (!file.is_open()){
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }
    for (Request *request: this->rentRequest){
        std::vector<std::string> request_info = request->getRequestInfo();
        for (int i = 0; i < request_info.size(); i++){
            file << request_info[i];
            if (i != request_info.size() - 1){
                file << "|";
            }
        }
        file << std::endl;
    }
    file.close();
    return 0;
}
// int Member::saveMemberReview(){
//     std::ofstream file;
//     file.open(MEMBER_REVIEW_FILE);
//     if (!file.is_open()){
//         std::cerr << "Error opening file" << std::endl;
//         return 1;
//     }
//     for (MemberReview *review: this->memberReview){
//         std::vector<std::string> review_info = review->getMemberReviewInfo();
//         for (int i = 0; i < review_info.size(); i++){
//             file << review_info[i];
//             if (i != review_info.size() - 1){
//                 file << "|";
//             }
//         }
//         file << std::endl;
//     }
//     file.close();
//     return 0;
// }

