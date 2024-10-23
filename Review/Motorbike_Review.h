#ifndef MOTORBIKE_REVIEW_H
#define MOTORBIKE_REVIEW_H

#include "Review.h"
#include "../Functions/Functions.h"
class MotorbikeReview: public Review {
    private:
        std::string motorbikeReviewID;  // id of the review
        std::string renterID;           // member who give the review about the motorbike
        std::string motorbikeID;        // motorbike that is being reviewed
        std::string motorbikeReviewStatus;     // pending/completed
    public:
        MotorbikeReview();
        MotorbikeReview(std::string motorbikeReviewID_ip, std::string renterID_ip, 
                        std::string motorbikeID_ip, std::string motorbikeReviewStatus_ip, 
                        float rating_ip, std::string comment_ip);
        std::vector<std::string> getMotorbikeReviewInfo();

        float calMotorbikeRating();
        
};

#endif


