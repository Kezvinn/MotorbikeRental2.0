#include "Member.h"
Member::Member(){}
Member::Member(std::string memberID_ip, std::string username_ip, std::string password_ip, std::string fullname_ip, 
    std::string phonenumber_ip, bool id_type_ip, std::string id_number_ip, 
    std::string drv_license_ip, std::string exp_date_ip, int credit_ip, 
    std::string ownedbikeID_ip, std::string rentedbikeID_ip,
    float memberRating_ip)
    :User(username_ip, password_ip), memberID(memberID_ip), fullname(fullname_ip), 
    phonenumber(phonenumber_ip), id_type(id_type_ip), id_number(id_number_ip),
    drv_license(drv_license_ip), exp_date(exp_date_ip), credit(credit_ip), 
    ownedbikeID(ownedbikeID_ip), rentedbikeID(rentedbikeID_ip),
    memberRating(memberRating_ip)
    {
        if (!this->memberID.empty()){
            memberID = randomIDs("member");
        } else {
            this->memberID = memberID_ip;
        }
    };
Member::~Member(){
    delete this->ownedbike;
    delete this->rentedbike;
}
std::vector<std::string> Member::getMemberInfo(){
    std::vector<std::string> member_info;

    member_info.push_back(this->memberID);
    member_info.push_back(this->getUsername());
    member_info.push_back(this->getPassword());
    member_info.push_back(this->fullname);
    member_info.push_back(this->phonenumber);
    member_info.push_back(std::to_string(this->id_type));
    member_info.push_back(this->id_number);
    member_info.push_back(this->drv_license);
    member_info.push_back(this->exp_date);
    member_info.push_back(std::to_string(this->credit));
    member_info.push_back(this->ownedbikeID);
    member_info.push_back(this->rentedbikeID);
    member_info.push_back(std::to_string(this->memberRating));

    return member_info;
}
void Member::showMemberInfo(){
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Member ID: " << this->memberID << std::endl;
    std::cout << "Username: " << this->getUsername() << std::endl;
    std::cout << "Password: " << this->getPassword() << std::endl;
    std::cout << "Fullname: " << this->fullname << std::endl;
    std::cout << "Phone number: " << this->phonenumber << std::endl;
    std::cout << "ID type: " << (this->id_type == 0 ? "Citizen ID" : "Passport") << std::endl;
    std::cout << "ID number: " << this->id_number << std::endl;
    std::cout << "Driver license: " << this->drv_license << std::endl;
    std::cout << "Expire date: " << this->exp_date << std::endl;
    std::cout << "Credit: " << this->credit << " credits" << std::endl;
    std::cout << "Owned bike ID: " << this->ownedbikeID << std::endl;
    std::cout << "Rented bike ID: " << this->rentedbikeID << std::endl;
    std::cout << "Member rating: " << this->memberRating << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
}
std::string Member::getMemberID(){ return this->memberID; }
float Member::getMemberRating(){ return this->memberRating; }
std::string Member::getOwnedMotorbikeID(){ return this->ownedbikeID; }
std::string Member::getRentedMotorbikeID(){ return this->rentedbikeID; }

int Member::addCredits(){
    char ans;
    int credit_ip;
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
        std::cout << "Your current balance: " << this->credit << "credits" << std::endl;
    }
    return 0;
}




int Member::loadRequest(){
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
                                               std::stoi(request_info[6]));
            this->rentRequest.push_back(new_request);
        }
    }
    file.close();
    return 0;
}
int Member::loadMemberReview(){
    std::ifstream file;
    file.open(MEMBER_REVIEW_FILE);
    if (!file.is_open()){
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(file, line)){
        std::vector<std::string> review_info = splitString(line, '|');
        if (review_info[0] == this->memberID){
            MemberReview *new_review = new MemberReview(review_info[0], review_info[1], 
                                                        review_info[2], review_info[3], 
                                                        review_info[4], review_info[5]);
            this->memberReview.push_back(new_review);
        }
    }
    file.close();
    return 0;
}

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
int Member::saveMemberReview(){
    std::ofstream file;
    file.open(MEMBER_REVIEW_FILE);
    if (!file.is_open()){
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }
    for (MemberReview *review: this->memberReview){
        std::vector<std::string> review_info = review->getReviewInfo();
        for (int i = 0; i < review_info.size(); i++){
            file << review_info[i];
            if (i != review_info.size() - 1){
                file << "|";
            }
        }
        file << std::endl;
    }
    file.close();
    return 0;
}