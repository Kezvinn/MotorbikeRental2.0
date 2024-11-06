#include "Motorbike_Review.h"
// Default constructor
MotorbikeReview::MotorbikeReview(){};
// Parameterized constructor - use for creating new review
MotorbikeReview::MotorbikeReview(std::string renterID_ip, 
                                 std::string rentedMotorbikeID_ip, 
                                 std::string motorbikeReviewStatus_ip):
                                 renterID(renterID_ip), 
                                 rentedMotorbikeID(rentedMotorbikeID_ip), 
                                 motorbikeReviewStatus(motorbikeReviewStatus_ip){
                            this->motorbikeReviewID = randomIDs("motorbikeReview");
                    } 
// Parameterized constructor - use for loading review from file 
MotorbikeReview::MotorbikeReview(std::string motorbikeReviewID_ip, 
                                 std::string renterID_ip, 
                                 std::string rentedMotorbikeID_ip, 
                                 std::string motorbikeReviewStatus_ip, 
                                 float rating_ip, std::string comment_ip)
                                 : motorbikeReviewID(motorbikeReviewID_ip), 
                                 renterID(renterID_ip), 
                                 rentedMotorbikeID(rentedMotorbikeID_ip), 
                                 motorbikeReviewStatus(motorbikeReviewStatus_ip), 
                                 Review(rating_ip, comment_ip) {}

std::vector<std::string> MotorbikeReview::getMotorbikeReviewInfo(){
    std::vector<std::string> motorbikeReview_info;

    motorbikeReview_info.push_back(this->motorbikeReviewID);                // 0
    motorbikeReview_info.push_back(this->renterID);                         // 1      
    motorbikeReview_info.push_back(this->rentedMotorbikeID);                // 2
    motorbikeReview_info.push_back(this->motorbikeReviewStatus);            // 3     
    motorbikeReview_info.push_back(std::to_string(this->getRating()));      // 4
    motorbikeReview_info.push_back(this->getComment());                     // 5
    
    return motorbikeReview_info;
}

bool MotorbikeReview::parseFromLine(const std::string &line){
    std::istringstream iss(line);
    std::string token;
    std::string rating_ip, comment_ip;
    try {
        std::getline(iss, motorbikeReviewID, '|');         // motorbikeReviewID
        std::getline(iss, renterID, '|');                  // renterID
        std::getline(iss, rentedMotorbikeID, '|');         // rentedMotorbikeID
        std::getline(iss, motorbikeReviewStatus, '|');     // motorbikeReviewStatus
        
        std::getline(iss, rating_ip, '|');                     // rating
        this->setRating(std::stof(rating_ip));
        
        std::getline(iss, token, '|');                     // comment
        this->setComment(token);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    return true;
}