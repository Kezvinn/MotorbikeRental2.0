#include "Motorbike_Review.h"

MotorbikeReview::MotorbikeReview(){};
MotorbikeReview::MotorbikeReview(std::string motorbikeReviewID_ip, std::string renterID_ip, 
                    std::string motorbikeID_ip, std::string motorbikeReviewStatus_ip, 
                    float rating_ip, std::string comment_ip)
                    :motorbikeReviewID(motorbikeReviewID_ip), renterID(renterID_ip), 
                    motorbikeID(motorbikeID_ip), motorbikeReviewStatus(motorbikeReviewStatus_ip), 
                    Review(rating_ip, comment_ip){
                        if (this->motorbikeReviewID.empty()){
                            this->motorbikeReviewID = randomIDs("motorbikeReview");
                        }
                    }


std::vector<std::string> MotorbikeReview::getMotorbikeReviewInfo(){
    std::vector<std::string> motorbikeReview_info;
    motorbikeReview_info.push_back(this->motorbikeReviewID);
    motorbikeReview_info.push_back(this->renterID);
    motorbikeReview_info.push_back(this->motorbikeID);
    motorbikeReview_info.push_back(this->motorbikeReviewStatus);
    motorbikeReview_info.push_back(std::to_string(this->getRating()));
    motorbikeReview_info.push_back(this->getComment());
    return motorbikeReview_info;

}
float MotorbikeReview::calMotorbikeRating(){
    float total = 0;   

}
    