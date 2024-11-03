#include "Motorbike_Review.h"

MotorbikeReview::MotorbikeReview(){};
MotorbikeReview::MotorbikeReview(std::string motorbikeReviewID_ip, std::string renterID_ip, 
                    std::string rentedMotorbikeID_ip, std::string motorbikeReviewStatus_ip):
                    motorbikeReviewID(motorbikeReviewID_ip), renterID(renterID_ip), 
                    rentedMotorbikeID(rentedMotorbikeID_ip), motorbikeReviewStatus(motorbikeReviewStatus_ip){
                        if (this->motorbikeReviewID.empty()){
                            this->motorbikeReviewID = randomIDs("motorbikeReview");
                        }
                    } 
                    
MotorbikeReview::MotorbikeReview(std::string motorbikeReviewID_ip, std::string renterID_ip, 
                    std::string rentedMotorbikeID_ip, std::string motorbikeReviewStatus_ip, 
                    float rating_ip, std::string comment_ip)
                    :motorbikeReviewID(motorbikeReviewID_ip), renterID(renterID_ip), 
                    rentedMotorbikeID(rentedMotorbikeID_ip), motorbikeReviewStatus(motorbikeReviewStatus_ip), 
                    Review(rating_ip, comment_ip)
                    {
                        if (this->motorbikeReviewID.empty()){
                            this->motorbikeReviewID = randomIDs("motorbikeReview");
                        }
                    }


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